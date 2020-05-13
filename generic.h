#ifndef GENERIC_H_ /* Guard for it already being defined. */
#define GENERIC_H_

typedef struct node
{
    void *object;
    struct node *next;
} node;

node *newListOfObject(void *object);

void appendObject(node **head, void *object);

void *getObject(node *head, int index);

int countObject(node *head);

void removeObject(node **head, void *object);

void removeObjectAtIndex(node **head, int index);

void removeObjectLast(node **head);

#endif