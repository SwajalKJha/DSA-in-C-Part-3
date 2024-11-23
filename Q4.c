/*
Q4. Write a C/C++ program to implement single linked list to store
Student Information ( StudentName and StudentPRN).
Implement below metioned functions. Apply all required condition
check & validation like list empty or not, while inserting/deleting by
position validate the position.
a)insertAtEnd b) insertAtBeg c) insertAtPos d) displayList
e)listNodeCount f) deleteFromEnd g) deleteFromBeg
h)deleteFromPos i) deleteByElement j) reverseDisplay
k)freeAllNode
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    char name[20];
    int prn;
};

struct node
{
    struct student p;
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
void display(struct node *);
void reverseDisplay(struct node *);

int main()
{
    struct node *head = NULL;
    int choice, pos;

    while (1)
    {
        printf("\n*************************\n");
        printf(" 1. Add at Beginning\n 2. Add at End\n 3. Add at Position\n 4. Delete from Beginning\n 5. Delete from End\n 6. Delete a Position\n 7. Delete by Element\n 8. Free all Nodes\n 9. Count Nodes\n 10. Display\n 11. Reverse Display\n 12. Quit\n");
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
            display(head);
            break;
        case 11:
            reverseDisplay(head);
            break;
        case 12:
            printf("Quiting...\n");
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
    if (temp == NULL)
    {
        printf("Memory Allocation Failed!\n");
        return;
    }
    printf("Enter Student's Name: ");
    scanf("%19s", temp->p.name);
    printf("Enter Student's PRN: ");
    scanf("%d", &temp->p.prn);

    temp->next = *q;
    *q = temp;
}

void addAtEnd(struct node **q)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Memory Allocation Failed!\n");
        return;
    }
    printf("Enter Student's Name: ");
    scanf("%19s", temp->p.name);
    printf("Enter Student's PRN: ");
    scanf("%d", &temp->p.prn);

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
    if (temp == NULL)
    {
        printf("Memory Allocation Failed!\n");
        return;
    }
    printf("Enter Student's Name: ");
    scanf("%19s", temp->p.name);
    printf("Enter Student's PRN: ");
    scanf("%d", &temp->p.prn);

    struct node *t1 = *q;

    int counter = 1;
    while (t1->next != NULL && counter < pos - 1)
    {
        t1 = t1->next;
        counter++;
    }
    if (counter < pos - 1)
    {
        printf("Position exceeded the current list size, Inserting at the end.");
    }
    temp->next = t1->next;
    t1->next = temp;
}

void deleteFromBeg(struct node **q)
{
    struct node *t1 = *q;
    *q = t1->next;
    free(t1);
    printf("Node Deleted from the List");
}

void deleteFromEnd(struct node **q)
{
    struct node *t1 = *q;
    struct node *t2 = NULL;

    while (t1->next != NULL)
    {
        t2 = t1;
        t1 = t1->next;
    }

    free(t1);
    t2->next = NULL;
    printf("Node Deleted from the List");
}

void deletePos(struct node **q, int pos)
{
    if (*q == NULL)
    {
        printf("List is Empty, nothing to Delete");
        return;
    }

    struct node *t1 = *q;
    struct node *t2 = NULL;

    if (pos == 1)
    {
        *q = t1->next;
        free(t1);
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
        printf("Position %d does not Exist", pos);
        return;
    }

    t2->next = t1->next;
    free(t1);
    printf("Node Deleted from the List");
}

void deleteElement(struct node **q)
{
    if (*q == NULL)
    {
        printf("List is Empty, nothing to Delete");
        return;
    }
    char name[20];
    getchar();
    printf("Enter Patient's Name to Delete Record: ");
    scanf("%19s", name);
    getchar();

    struct node *t1 = *q;
    struct node *t2 = NULL;

    while (t1 != NULL)
    {
        if (strcmp(t1->p.name, name) == 0)
        {
            if (t2 == NULL)
            {
                *q = t1->next;
                free(t1);
                printf("Node Deleted from the List");
            }
            else
            {
                t2->next = t1->next;
                free(t1);
                printf("Node Deleted from the List");
            }
        }
        t2 = t1;
        t1 = t1->next;
    }
    if (t1 == NULL)
    {
        printf("Record does not Exist");
        return;
    }
}
void freeNodes(struct node **q)
{
    if (*q == NULL)
    {
        printf("List is Empty, nothing to delete");
        return;
    }
    struct node *t1 = *q;

    int counter = 1;
    while (t1 != NULL)
    {
        struct node *t2 = *q;
        *q = t1->next;
        t1 = t1->next;
        free(t2);
        counter++;
    }
    printf("All Nodes Deleted from the List");
}
void countNodes(struct node **q)
{
    if (*q == NULL)
    {
        printf("List is Empty, nothing to Delete");
        return;
    }
    struct node *t1 = *q;

    int counter = 1;
    while (t1 != NULL)
    {
        t1 = t1->next;
        counter++;
    }

    printf("Number of Nodes are: %d", counter - 1);
}
void display(struct node *p)
{
    struct node *t1 = p;
    if (t1 == NULL)
    {
        printf("The List is Empty");
        return;
    }
    while (t1 != NULL)
    {
        printf("---> Name: %s, PRN: %d ", t1->p.name, t1->p.prn);
        t1 = t1->next;
    }
}
void reverseDisplay(struct node *t1)
{
    if (t1 == NULL)
    {
        return;
    }
    reverseDisplay(t1->next);
    printf("---> Name: %s, PRN: %d ", t1->p.name, t1->p.prn);
}
