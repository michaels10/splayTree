#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

struct Node{
    struct Node *grandparent;
    struct Node *parent;
    struct Node *childLeft;
    struct Node *childRight;
    int value;
};

struct Node addNode(int value, struct Node *node);
struct Node* findNode(int value, struct Node *node);
struct Node* splay(struct Node *node);
struct Node* zigL(struct Node *node);
struct Node* zigR(struct Node *node);
struct Node* zigZagL(struct Node *node);
struct Node* zigZagR(struct Node *node);
struct Node* zigZigL(struct Node *node);
struct Node* zigZigR(struct Node *node);

int main(){ 
    struct Node root = {NULL, NULL, NULL, NULL, 30};
    addNode(15, &root);
    addNode(35, &root);
    assert(findNode(35, &root) != NULL);

    return 0;    

}


struct Node addNode(int value, struct Node *node){
    if(value == node->value){
        return *node;
    }

    struct Node toAdd = {node->parent, node, NULL, NULL, value};
    if(value < node->value){
        if(node->childLeft == NULL){
            node->childLeft = &toAdd;
            return toAdd;
        }
        return addNode(value, node->childLeft);
    }
    if(value > node->value){
        if(node->childRight == NULL){
            node->childRight = &toAdd;
            return toAdd;
        }
        return addNode(value, node->childRight);
    }
}

struct Node* findNode(int value, struct Node *node){
    if( value == node->value){
        return node;
    }
    if( value < node->value){
        if(node->childLeft == NULL){
            return NULL;
        }
        return findNode(value, node->childRight);
    }
    if(node->childRight == NULL){
        return NULL;
    }
    return findNode(value, node->childRight);
}


