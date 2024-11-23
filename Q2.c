/*
Q2. Write a C/C++ program to implement single linked list.
Implement below metioned functions. Apply all required condition
check & validation like list empty or not, while inserting/deleting by
position validate the position.
a)insertAtEnd b) insertAtBeg c) insertAtPos d) displayList
e)listNodeCount f) deleteFromEnd g) deleteFromBeg
h)deleteFromPos i) deleteByElement j) reverseDisplay
k)freeAllNode l) reverseList m)sortedList

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct patient
{
    char name[20];
    int age;
    int ward_num;
};

struct node
{
    struct patient p;
    struct node *next;
};

void addAtBeg(struct node **);
void addAtEnd(struct node **);
void addAtPos(struct node **, int);
void deleteFromBeg(struct node **);
void deleteFromEnd(struct node **);
void deletePos(struct node **, int);
void deleteElement(struct node **);
void freeNodes(struct node **);
void countNodes(struct node **);
void reverseList(struct node **);
void reverseDisplay(struct node *);
void sortList(struct node **);
void display(struct node *);

int main()
{
    struct node *head = NULL;
    int choice, pos;

    while (1)
    {
        printf("\n*************************\n");
        printf(" 1. Add at Beginning\n 2. Add at End\n 3. Add at Position\n 4. Delete from Beginning\n 5. Delete from End\n 6. Delete a Position\n 7. Delete by Element\n 8. Free all Nodes\n 9. Count Nodes\n 10. Reverse List\n 11. Display\n 12. Reverse Display\n 13. Sort List\n 14. Quit\n");
        printf("Enter a choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addAtBeg(&head);
            break;
        case 2:
            addAtEnd(&head);
            break;
        case 3:
            printf("Enter Position to Add: ");
            scanf("%d", &pos);
            addAtPos(&head, pos);
            break;
        case 4:
            deleteFromBeg(&head);
            break;
        case 5:
            deleteFromEnd(&head);
            break;
        case 6:
            printf("Enter Position to Delete: ");
            scanf("%d", &pos);
            deletePos(&head, pos);
            break;
        case 7:
            deleteElement(&head);
            break;
        case 8:
            freeNodes(&head);
            break;
        case 9:
            countNodes(&head);
            break;
        case 10:
            reverseList(&head);
            break;
        case 11:
            display(head);
            break;
        case 12:
            reverseDisplay(head);
            break;
        case 13:
            sortList(&head);
            break;
        case 14:
            printf("Quitting...\n");
            freeNodes(&head); // Free nodes before exiting
            return 0;
        default:
            printf("Enter a Valid Choice\n");
            break;
        }
    }
    return 0;
}

void addAtBeg(struct node **q)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (!temp)
    {
        printf("Memory Allocation Failed!\n");
        return;
    }
    printf("Enter Patient's Name: ");
    scanf("%19s", temp->p.name);
    printf("Enter Patient's Age: ");
    scanf("%d", &temp->p.age);
    printf("Enter Patient's Ward Number: ");
    scanf("%d", &temp->p.ward_num);

    temp->next = *q;
    *q = temp;
}

void addAtEnd(struct node **q)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (!temp)
    {
        printf("Memory Allocation Failed!\n");
        return;
    }
    printf("Enter Patient's Name: ");
    scanf("%19s", temp->p.name);
    printf("Enter Patient's Age: ");
    scanf("%d", &temp->p.age);
    printf("Enter Patient's Ward Number: ");
    scanf("%d", &temp->p.ward_num);

    temp->next = NULL;

    if (*q == NULL)
    {
        *q = temp;
    }
    else
    {
        struct node *t1 = *q;
        while (t1->next != NULL)
        {
            t1 = t1->next;
        }
        t1->next = temp;
    }
}

void addAtPos(struct node **q, int pos)
{
    if (pos < 1)
    {
        printf("Invalid Position!\n");
        return;
    }
    if (*q == NULL || pos == 1)
    {
        addAtBeg(q);
        return;
    }

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (!temp)
    {
        printf("Memory Allocation Failed!\n");
        return;
    }
    printf("Enter Patient's Name: ");
    scanf("%19s", temp->p.name);
    printf("Enter Patient's Age: ");
    scanf("%d", &temp->p.age);
    printf("Enter Patient's Ward Number: ");
    scanf("%d", &temp->p.ward_num);

    struct node *t1 = *q;
    int counter = 1;
    while (t1->next != NULL && counter < pos - 1)
    {
        t1 = t1->next;
        counter++;
    }

    temp->next = t1->next;
    t1->next = temp;
}

void deleteFromBeg(struct node **q)
{
    if (*q == NULL)
    {
        printf("List is Empty, nothing to delete\n");
        return;
    }

    struct node *t1 = *q;
    *q = t1->next;
    free(t1);
    printf("Node Deleted from the List\n");
}

void deleteFromEnd(struct node **q)
{
    if (*q == NULL)
    {
        printf("List is Empty, nothing to delete\n");
        return;
    }

    struct node *t1 = *q;
    struct node *t2 = NULL;

    while (t1->next != NULL)
    {
        t2 = t1;
        t1 = t1->next;
    }

    free(t1);
    if (t2 != NULL)
    {
        t2->next = NULL;
    }
    else
    {
        *q = NULL; // List is now empty
    }
    printf("Node Deleted from the List\n");
}

void deletePos(struct node **q, int pos)
{
    if (*q == NULL)
    {
        printf("List is Empty, nothing to delete\n");
        return;
    }

    struct node *t1 = *q;
    struct node *t2 = NULL;

    if (pos == 1)
    {
        *q = t1->next;
        free(t1);
        printf("Node Deleted from the List\n");
        return;
    }

    int counter = 1;
    while (t1 != NULL && counter < pos)
    {
        t2 = t1;
        t1 = t1->next;
        counter++;
    }

    if (t1 == NULL)
    {
        printf("Position %d does not Exist\n", pos);
        return;
    }

    t2->next = t1->next;
    free(t1);
    printf("Node Deleted from the List\n");
}

void deleteElement(struct node **q)
{
    if (*q == NULL)
    {
        printf("List is Empty, nothing to delete\n");
        return;
    }

    char name[20];
    printf("Enter Patient's Name to Delete Record: ");
    scanf("%19s", name);

    struct node *t1 = *q;
    struct node *t2 = NULL;
    int found = 0;

    while (t1 != NULL)
    {
        if (strcmp(t1->p.name, name) == 0)
        {
            found = 1;
            if (t2 == NULL) // Deleting the first node
            {
                *q = t1->next;
            }
            else
            {
                t2->next = t1->next;
            }
            free(t1);
            printf("Node Deleted from the List\n");
            return; // Exit after deleting the first match
        }
        t2 = t1;
        t1 = t1->next;
    }

    if (!found)
    {
        printf("Record does not Exist\n");
    }
}

void freeNodes(struct node **q)
{
    struct node *t1 = *q;
    while (t1 != NULL)
    {
        struct node *t2 = t1;
        t1 = t1->next;
        free(t2);
    }
    *q = NULL; // Set the head to NULL after freeing
    printf("All Nodes Deleted from the List\n");
}

void countNodes(struct node **q)
{
    if (*q == NULL)
    {
        printf("List is Empty, nothing to count\n");
        return;
    }

    struct node *t1 = *q;
    int counter = 0;

    while (t1 != NULL)
    {
        counter++;
        t1 = t1->next;
    }

    printf("Number of Nodes are: %d\n", counter);
}

void display(struct node *p)
{
    struct node *t1 = p;
    if (t1 == NULL)
    {
        printf("The List is Empty\n");
        return;
    }
    while (t1 != NULL)
    {
        printf("---> Name: %s, Age: %d, Ward Number: %d ", t1->p.name, t1->p.age, t1->p.ward_num);
        t1 = t1->next;
    }
    printf("\n");
}

void reverseList(struct node **q)
{
    if (*q == NULL)
    {
        printf("The List is Empty\n");
        return;
    }

    struct node *prev = NULL;
    struct node *current = *q;
    struct node *next = NULL;

    while (current != NULL)
    {
        next = current->next; // Store next node
        current->next = prev; // Reverse the link
        prev = current;       // Move prev to current
        current = next;       // Move to next node
    }

    *q = prev; // Reset head to new first node
    printf("List Reversed\n");
}

void reverseDisplay(struct node *t1)
{
    if (t1 == NULL)
    {
        return;
    }
    reverseDisplay(t1->next);
    printf("---> Name: %s, Age: %d, Ward Number: %d ", t1->p.name, t1->p.age, t1->p.ward_num);
}

void sortList(struct node **q)
{
    if (*q == NULL)
    {
        printf("List is Empty, nothing to sort\n");
        return;
    }

    struct node *i, *j;
    struct patient temp;

    for (i = *q; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (strcmp(i->p.name, j->p.name) > 0)
            {
                // Swap data
                temp = i->p;
                i->p = j->p;
                j->p = temp;
            }
        }
    }
    printf("List Sorted by Patient's Name\n");
}
