#ifndef GENERIC_H_ /* Guard for it already being defined. */
#define GENERIC_H_

typedef struct Game
{
    char *name;
    int year;
} Game;

typedef struct g_node
{
    void *object;
    struct g_node *next;
    struct g_node *previous;
} t_node;

t_node *newListOfObject(void *object);

void appendObject(t_node *head, void *object);

void *getObject(t_node *head, int index);

int countObject(t_node *head);

void removeObject(t_node **head, void *object);

#endif