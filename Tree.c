#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "Tree.h"
#include "parametrStruct.h"

void* initTree(){
    struct Tree* tree = malloc(sizeof(struct Tree));

    tree->root = NULL;

    tree->createStudent = createStudent;
    tree->createTreeNode = createTreeNode;
    tree->insert = insert;

}

void* insert(void* _insertStruct) {
    struct InsertStruct* insertStruct = _insertStruct;
    if (insertStruct->root == NULL) {
        return createTreeNode(insertStruct->student);
    }

    int cmp = strcmp(insertStruct->student->lastName, insertStruct->root->student->lastName);
    if (cmp < 0) {
        struct InsertStruct insertStruct1 = {
                .root = insertStruct->root->left,
                .student = insertStruct->student
        };
        insertStruct->root->left = insert(&insertStruct1);
    } else {
        struct InsertStruct insertStruct1 = {
                .root = insertStruct->root->right,
                .student = insertStruct->student
        };
        insertStruct->root->right = insert(&insertStruct1);
    }

    return insertStruct->root;
}

void inOrderTraversal(void* _root) {
    struct TreeNode* root = (struct TreeNode*)_root;
    if (root != NULL) {
        inOrderTraversal(root->left);
        root->student->print(root->student);
        inOrderTraversal(root->right);
    }
}
