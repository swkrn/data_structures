#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int   data;
    Node *left;
    Node *right;

} Node;


void Insert(Node **root_pointer, int data)
{
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    if (*root_pointer == NULL)
    {
        *root_pointer = new_node;
        return;
    }

    Node *temp = *root_pointer;
    while (temp != NULL)
    {
        if (data < temp->data)
        {
            if (temp->left != NULL)
            {
                temp = temp->left;
            }
            else
            {
                temp->left = new_node;
                break;
            }
            
        }
        else if (data >= temp->data)
        {
            if (temp->right != NULL)
            {
                temp = temp->right;
            }
            else
            {
                temp->right = new_node;
                break;
            }
        }
    }
}


void PrintHelper(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    printf("%d ", node->data);
    PrintHelper(node->left);
    PrintHelper(node->right);
}


void Print(Node *node)
{
    PrintHelper(node);
    printf("\n");
}


int SearchUsingRecursion(Node *node, int data)
{
    if (node == NULL)
    {
        return 0;
    }

    if (data == node->data)
    {
        return 1;
    }
    else if (data < node->data)
    {
        return SearchUsingRecursion(node->left, data);
    }
    else
    {
        return SearchUsingRecursion(node->right, data);
    }
}


int SearchUsingIterative(Node *node, int data)
{
    while (node != NULL)
    {
        if (data == node->data)
        {
            return 1;
        }
        else if (data < node->data)
        {
            node = node->left;
        }
        else if (data > node->data)
        {
            node = node->right;
        }
    }

    return 0;
}


int Search(Node *node, int data, int mode)
{
    if (mode == 0)
    {
        return SearchUsingIterative(node, data);
    }
    else
    {
        return SearchUsingRecursion(node, data);
    }
}


int Min(Node *node)
{
    if (node == NULL)
    {
        return -1;
    }

    while (node->left != NULL)
    {
        node = node->left;
    }

    return node->data;
}


int Max(Node *node)
{
    if (node == NULL)
    {
        return -1;
    }

    while (node->right != NULL)
    {
        node = node->right;
    }

    return node->data;
}


int Height(Node *node)
{
    if (node == NULL)
    {
        return -1;
    }

    int left_height = Height(node->left);
    int right_height = Height(node->right);

    return left_height > right_height ? left_height + 1 : right_height + 1;
}


int main()
{
    Node *bst = NULL;

    int x, cmd;
    ;
    while (scanf("%d", &cmd) && cmd != 0)
    {
        switch (cmd)
        {
            case 1:
                scanf("%d", &x);
                Insert(&bst, x);
                break;
            case 2:
                Print(bst);
                break;
            case 3:
                scanf("%d", &x);
                printf("%d\n", Search(bst, x, 0));
                break;
            case 4:
                printf("%d\n", Min(bst));
                break;
            case 5:
                printf("%d\n", Max(bst));
                break;
            case 6:
                printf("%d\n", Height(bst));
                break;
        }
    }

    

    return 0;
}