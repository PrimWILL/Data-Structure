#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode n7 = { 25, NULL, NULL };
TreeNode n6 = { 16, NULL, NULL };
TreeNode n4 = { 1, NULL, NULL };
TreeNode n3 = { 20, &n6, &n7 };
TreeNode n2 = { 4, &n4, NULL };
TreeNode n1 = { 15, &n2, &n3 };
TreeNode *root = &n1;
 
void inorder(TreeNode *root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("[%d] ", root->data);
        inorder(root->right);
    }
}

void preorder(TreeNode *root)
{
    if (root != NULL) {
        printf("[%d] ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(TreeNode *root)
{
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("[%d] ", root->data);
    }
}

int main(void)
{
    printf("inorder = ");
    inorder(root);
    printf("\n");

    printf("preorder = ");
    preorder(root);
    printf("\n");

    printf("postorder = ");
    postorder(root);
    printf("\n");

    return 0;
}