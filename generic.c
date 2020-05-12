#include <stdio.h>
#include <stdlib.h>

#include "generic.h"

t_node *newListOfObject(void *object)
{
    t_node *head = NULL;
    head = (t_node *)calloc(1, sizeof(t_node));

    head->object = object;
    head->next = NULL;
    head->previous = NULL;
    return head;
}

void appendObject(t_node *head, void *object)
{
    t_node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    t_node *new = (t_node *)calloc(1, sizeof(t_node));
    new->object = object;

    current->next = new;
    new->next = NULL;
    new->previous = current;
}

int countObject(t_node *head)
{
    int length;
    t_node *current = head;
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

void *getObject(t_node *head, int index)
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

    t_node *current = head;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }
    return current->object;
}

void removeObject(t_node **head, void *object)
{
    if (object == NULL)
    {
        return;
    }

    t_node *current = *head;

    if (current->object == object)
    {
        t_node *next_node = (*head)->next;
        if (next_node != NULL)
        {
            next_node->previous = (void *)NULL;
        }

        free(*head);
        *head = next_node;
        return;
    }
}