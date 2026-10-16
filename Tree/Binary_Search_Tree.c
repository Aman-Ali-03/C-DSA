#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root=NULL,*new;
void add_node(struct node *,struct node *);
void preorder_traversal(struct node *);
void postorder_traversal(struct node *);
void inorder_traversal(struct node *);
void main()
{
    int choice=0;
    do
    {
        printf("\n===========================================================");
        printf("\n1. Add node.");
        printf("\n2. Preorder Traversal.");
        printf("\n3. Post Order Traversal.");
        printf("\n===========================================================");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                new = (struct node *)malloc(sizeof(struct node));
                printf("Enter your Elemetn: ");
                scanf("%d",&new->data);
                new->left = NULL;
                new->right = NULL;
                if(root==NULL)
                {
                    root = new;
                }
                else{
                    add_node(new,root);
                }
                break;
            case 2:
                preorder_traversal(root);
                break;
            case 3:
                postorder_traversal(root);
                break;
        }
    } while (choice!=22);
    return;
}

void add_node(struct node *new,struct node *rooot)
{
    if(rooot->left==NULL && rooot->data>new->data)
    {
        rooot->left=new;
    }
    else if (rooot->right==NULL && rooot->data<=new->data)
    {
        rooot->right = new;
    }
    else if (rooot->left!=NULL && rooot->data>new->data)
    {
        add_node(new,rooot->left);
    }
    else if (rooot->right!=NULL && rooot->data<=new->data)
    {
        add_node(new,rooot->right);
    }
    return;
}

void preorder_traversal(struct node *rooot)
{
    if(rooot==NULL) return;
    printf("%d    ",rooot->data);
    preorder_traversal(rooot->left);
    preorder_traversal(rooot->right);
}

void postorder_traversal(struct node *rooot)
{
    if(rooot==NULL) return;
    postorder_traversal(rooot->left);
    postorder_traversal(rooot->right);
    printf("%d  ",rooot->data);
}

void inorder_traversal(struct node *rooot)
{
    if(rooot==NULL) return;
    inorder_traversal(rooot->left);
    printf("%d   ",rooot->data);
    inorder_traversal(rooot->right);
}