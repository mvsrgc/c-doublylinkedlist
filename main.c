#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct Node {
  struct Node *prev;
  struct Node *next;
  char *data;
};

struct DoublyLinkedList {
  struct Node *first;
  struct Node *last;
};

struct Node *find(struct DoublyLinkedList *list, char *data) {
  struct Node *node = list->first;
  do {
    if (strcmp(node->data, data) == 0) {
      return node;
    } else {
      node = node->next;
    }
  } while (node != NULL);

  return NULL;
}

void delete(struct DoublyLinkedList *list, struct Node *node) {
  if (node->prev != NULL) {
    node->prev->next = node->next;
  } else {
    list->first = node->next;
  }
  if (node->next != NULL) {
    node->next->prev = node->prev;
  } else {
    list->last = node->prev;
  }
}

void insertAfter(struct DoublyLinkedList *list, struct Node *node,
                 struct Node *newNode) {
  newNode->prev = node;

  if (node->next == NULL) {
    newNode->next = NULL;
    list->last = newNode;
  } else {
    node->next->prev = newNode;
  }

  node->next = newNode;
}

void insertBefore(struct DoublyLinkedList *list, struct Node *node,
                  struct Node *newNode) {
  newNode->next = node;

  if (node->prev == NULL) {
    newNode->prev = NULL;
    list->first = newNode;
  } else {
    newNode->prev = node->prev;
    node->prev->next = newNode;
  }

  node->prev = newNode;
}

void insertBeginning(struct DoublyLinkedList *list, struct Node *node) {
  if (list->first == NULL) {
    list->first = node;
    list->last = node;
    node->prev = NULL;
    node->next = NULL;
  } else {
    insertBefore(list, list->first, node);
  }
}

void insertEnd(struct DoublyLinkedList *list, struct Node *node) {
  if (list->last == NULL) {
    insertBeginning(list, node);
  } else {
    insertAfter(list, list->last, node);
  }
}

int main() {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  char *myString = malloc(strlen("Hello world!") + 1);
  strcpy(myString, "Hello world!");
  newNode->data = myString;

  struct DoublyLinkedList *list = (struct DoublyLinkedList *)malloc(sizeof(struct DoublyLinkedList));
  insertBeginning(list, newNode);

  assert(strcmp(list->first->data, "Hello world!") == 0);

  newNode = (struct Node *)malloc(sizeof(struct Node));
  myString = malloc(strlen("Bye world!") + 1);
  strcpy(myString, "Bye world!");
  newNode->data = myString;

  insertEnd(list, newNode);

  assert(strcmp(list->first->data, "Hello world!") == 0);
  assert(strcmp(list->last->data, "Bye world!") == 0);

  assert(strcmp(list->first->next->data, "Bye world!") == 0);
  assert(strcmp(list->last->prev->data, "Hello world!") == 0);
}
