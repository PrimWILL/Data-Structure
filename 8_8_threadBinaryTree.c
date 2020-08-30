#include <stdio.h>
#define TRUE 1
#define FALSE 0

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
    int is_thread; // 스레드이면 TRUE
} TreeNode;

TreeNode n1 = { 'A', NULL, NULL, 1 };
TreeNode n2 = { 'B', NULL, NULL, 1 };
TreeNode n3 = { 'C', &n1, &n2, 0 };
TreeNode n4 = { 'D', NULL, NULL, 1 };
TreeNode n5 = { 'E', NULL, NULL, 0 };
TreeNode n6 = { 'F', &n4, &n5, 0 };
TreeNode n7 = { 'G', &n3, &n6, 0 };
TreeNode *exp = &n7;

TreeNode* find_successor(TreeNode *p)
{
    // 'q' is right pointer of 'p'
    TreeNode *q = p->right;
    // if right pointer is NULL or thread, then return right pointer
    if (q == NULL || p->is_thread == TRUE){
        return q;
    }
    
    // if is_thread is FALSE, move to the eastest node
    while (q->left != NULL) {
        q = q->left;
    }
    return q;
}

void thread_inorder(TreeNode *t)
{
    TreeNode *q;

    q = t;
    while (q->left) q = q->left; // move to the eastest node
    do {
        printf("%c -> ", q->data); // print data
        q = find_successor(q);     // print successor function
    } while(q);                    // if q != NULL
}

int main(void)
{
    n1.right = &n3;
    n2.right = &n7;
    n4.right = &n6;

    // inorder traversal
    thread_inorder(exp);
    printf("\n");
    return 0;
}

