#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    Node *next;

} Node;


void Unhift(Node **head_pointer, int data)
{
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = data;
    if (*head_pointer != NULL)
    {
        new_node->next = *head_pointer;
    }
    else
    {
        new_node->next = NULL;
    }
    *head_pointer = new_node;
}


int Shift(Node **head_pointer)
{
    Node *temp = *head_pointer;

    if (temp == NULL)
    {
        return -1;
    }

    int temp_data = temp->data;
    if (temp->next != NULL)
    {
        *head_pointer = temp->next;
    }
    else
    {
        *head_pointer = NULL;
    }
    free(temp);

    return temp_data;
}


void Push(Node **head_pointer, int data)
{
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head_pointer == NULL)
    {
        *head_pointer = new_node;
    }
    else
    {
        Node *temp = *head_pointer;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = new_node;
    }
}


int Pop(Node **head_pointer)
{
    Node *temp = *head_pointer;

    if (temp == NULL)
    {
        return -1;
    }

    if (temp->next == NULL)
    {
        *head_pointer = NULL;
        int temp_data = temp->data;
        free(temp);
        return temp_data;
    }

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    int temp_data = temp->next->data;
    free(temp->next);
    temp->next = NULL;

    return temp_data;
}


void InsertAt(Node **head_pointer, int data, int position)
{
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    Node *temp = *head_pointer;
    for (int i = 0; i < position - 1; i++)
    {
        temp = temp->next;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}


void Print(Node **head_pointer)
{
    Node *temp = *head_pointer;

    printf("List: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main()
{
    Node *head = NULL;

    Unhift(&head, 10);
    Unhift(&head, 25);
    Unhift(&head, 30);
    
    Print(&head);
    InsertAt(&head, 99, 1);
    Print(&head);
    InsertAt(&head, 505, 4);
    Print(&head);


    printf("(Shift: %d)\n", Shift(&head));
    Print(&head);
    printf("(Shift: %d)\n", Shift(&head));
    Print(&head);
    printf("(Shift: %d)\n", Shift(&head));
    Print(&head);
    printf("(Shift: %d)\n", Shift(&head));

    Push(&head, 11);
    Print(&head);
    Push(&head, 22);
    Print(&head);

    printf("(Pop: %d)\n", Pop(&head));
    Print(&head);
    printf("(Pop: %d)\n", Pop(&head));
    Print(&head);
    printf("(Pop: %d)\n", Pop(&head));
    Print(&head);

    return 0;
}