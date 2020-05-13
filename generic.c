#include <stdio.h>
#include <stdlib.h>

#include "generic.h"

node *newListOfObject(void *object)
{
    node *head = NULL;
    head = (node *)calloc(1, sizeof(node));

    head->object = object;
    head->next = NULL;
    return head;
}

void appendObject(node **head, void *object)
{
    node *current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    node *new = (node *)calloc(1, sizeof(node));
    new->object = object;
    new->next = NULL;

    int length = countObject(current);
    if (length == 0)
    {
        *head = new;
    }
    else
    {
        current->next = new;
    }
}

int countObject(node *head)
{
    int length;
    node *current = head;
    if (current == NULL || current->object == NULL)
    {
        length = 0;
    }
    else
    {
        length = 1;
        while (current->next != NULL)
        {
            current = current->next;
            length++;
        }
    }

    return length;
}

void *getObject(node *head, int index)
{
    if (index < 0)
    {
        return NULL;
    }
    int objectCount = countObject(head);
    if (index + 1 > objectCount)
    {
        return NULL;
    }
    if (index == 0)
    {
        return head->object;
    }

    node *current = head;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }
    return current->object;
}

void removeObject(node **head, void *object)
{
    if (object == NULL)
    {
        return;
    }

    node *currennode = *head;
    int length = countObject(currennode);

    //first pass
    if (currennode->object == object)
    {
        if (length > 1)
        {
            node *nexnode = NULL;
            nexnode = (*head)->next;

            free(*head);

            *head = nexnode;
        }

        else
        {
            free(*head);
            node *new = (node *)calloc(1, sizeof(node));
            *head = new;
        }

        return;
    }

    // guard, if one person left, no match.
    int count = 1;
    if (length == 1)
    {
        return;
    }

    // if not role next node forward
    while (count < length && currennode->next->object != object)
    {
        currennode = currennode->next;
        count++;
    }

    //subsequent passes
    while (currennode->next->object == object)
    {
        node *temp_node;
        temp_node = currennode->next;
        currennode->next = temp_node->next;
        free(temp_node);
        return;
    }
}

void removeObjectAtIndex(node **head, int index)
{
    node *object = (node *)getObject(*head, index);
    removeObject(head, object);
}

void removeObjectLast(node **head)
{
    int length = countObject(*head);
    node *object = (node *)getObject(*head, length - 1);
    removeObject(head, object);
}