/*
Q3. Write a C/C++ program to implement single linked list in sorted
order. Implement below metioned functions. Apply all required
condition check & validation like list empty or not, while
inserting/deleting by position validate the position. Implement a policy
for duplicate value input.
a)insert b) displayList c)listNodeCount d) deleteFromEnd
e) deleteFromBeg f)deleteFromPos g) reverseDisplay
*/
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL; // List head

// Functions
void insertNode(int ele);
void display();
void nodeCount();
void deleteAtEnd();
void deleteAtBeg();
void deleteAtPos(int pos);
void reverseDisplay(struct node *current);
int isDuplicate(int ele);

int main()
{
    int choice, ele, pos;

    while (1)
    {
        // Menu options
        printf("\nMenu:");
        printf("\n1 -> Insert node \n2 -> Display all \n3 -> Count of nodes \n4 -> Delete last element \n5 -> Delete from beginning \n6 -> Delete from position \n7 -> Reverse display \n8 -> Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to insert: ");
            scanf("%d", &ele);
            insertNode(ele); // Insert element
            break;
        case 2:
            display(); // Display list
            break;
        case 3:
            nodeCount(); // Count nodes
            break;
        case 4:
            deleteAtEnd(); // Delete last node
            break;
        case 5:
            deleteAtBeg(); // Delete first node
            break;
        case 6:
            printf("Enter the position: ");
            scanf("%d", &pos);
            deleteAtPos(pos); // Delete at position
            break;
        case 7:
            reverseDisplay(head); // Reverse display
            break;
        case 8:
            exit(0); // Exit
            break;
        }
    }
    return 0;
}

void insertNode(int ele) // Insert at end
{
    if (isDuplicate(ele))
    {
        printf("Duplicate value not allowed.\n");
        return;
    }
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    temp->data = ele;
    temp->next = NULL;

    if (head == NULL || head->data > ele)
    {
        temp->next = head;
        head = temp; // If it is the first node
    }
    else
    {
        struct node *t1 = head;
        struct node *t2 = NULL;

        while (t1 != NULL && t1->data < ele)
        {
            t2 = t1;       // Track previous node
            t1 = t1->next; // Traverse to end
        }

        temp->next = t1; // New node points to the next node
        if (t2 != NULL)
        {
            t2->next = temp; // Add node
        }
    }
}

void display() // Display nodes
{
    if (head == NULL)
    {
        printf("\nList is empty!!!\n");
        return;
    }
    struct node *t1 = head;
    printf("\n");
    while (t1 != NULL)
    {
        printf("--->%d", t1->data); // Print node
        t1 = t1->next;
    }
    printf("\n");
}

void nodeCount() // Count nodes
{
    struct node *t1 = head;
    int count = 0;
    while (t1 != NULL)
    {
        count++; // Increment count
        t1 = t1->next;
    }
    printf("\nThe count of nodes in list is: %d\n", count);
}

void deleteAtEnd() // Delete last node
{
    if (head == NULL)
    {
        printf("\nList is empty. Cannot delete from end\n");
        return;
    }
    struct node *t1 = head, *t2 = NULL;
    while (t1->next != NULL)
    {
        t2 = t1; // Track previous node
        t1 = t1->next;
    }
    free(t1); // Free last node

    if (t2 != NULL)
    {
        t2->next = NULL; // Set second last to NULL
    }
    else
    {
        head = NULL; // Empty list
    }
    printf("\nLast element deleted!!!\n");
}

void deleteAtBeg() // Delete first node
{
    if (head == NULL)
    {
        printf("The list is empty. Cannot delete from beginning.\n");
        return;
    }
    struct node *t1 = head;
    head = t1->next; // Move head
    free(t1);        // Free old head
    printf("\nFirst element deleted!!!\n");
}

void deleteAtPos(int pos) // Delete node at position
{
    if (head == NULL)
    {
        printf("The list is empty. Cannot delete from position.\n");
        return;
    }
    if (pos < 1)
    {
        printf("\nInvalid position.\n");
        return;
    }
    struct node *t1 = head, *t2 = NULL;
    int counter = 1;
    while (counter < pos)
    {
        t2 = t1; // Track previous node
        t1 = t1->next;
        counter++;

        if (t1 == NULL) // Position exceeds length
        {
            printf("\nPosition exceeds list length.\n");
            return;
        }
    }
    t2->next = t1->next; // move next node address to t2
    free(t1);            // Free node
    printf("\nThe position %d element is deleted!!!\n", pos);
}

void reverseDisplay(struct node *current) // Reverse display
{
    if (current == NULL)
    {
        return; // Base case when node is null
    }
    reverseDisplay(current->next);       // Recursive call
    printf("\n--->%d\n", current->data); // Print node
}

int isDuplicate(int ele) // Check for duplicates
{
    struct node *t1 = head;
    while (t1 != NULL)
    {
        if (t1->data == ele)
            return 1;  // Duplicate found
        t1 = t1->next; // Move to next node
    }
    return 0; // No duplicate
}
