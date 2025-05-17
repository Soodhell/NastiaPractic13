#include "node.h"

struct Tree {
    struct TreeNode* root;

    void* (*createStudent)(void*);
    void* (*createTreeNode)(void*);
    void* (*insert)(void*);
};

void* insert(void*);
void inOrderTraversal(void*);
void* initTree();
