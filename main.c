#include <stdio.h>
#include <stdlib.h>

typedef struct {
  void *next;
  int data;
} Node;

Node *head = NULL;

void print_menu() {
  printf("(a) Add a node to the beginning.\n");
  printf("(i) Insert a node in the middle.\n");
  printf("(r) Remove a node.\n");
  printf("(p) Print nodes.\n");
  printf("(q) Exit.\n");
}

Node *add_node(int data) {
  Node *new = malloc(sizeof(Node));
  if (new == NULL)
    return NULL;

  new->data = data;
  new->next = head;
  head = new;

  return new;
}

Node *insert_node(int position, int data) {
  Node *curr = head;
  while (curr != NULL && position > 0) {
    curr = curr->next;
    position--;
  }
  if (position > 0) {
    printf("Requested position is too far into list.\n");
    return NULL;
  }

  Node *new = malloc(sizeof(Node));
  if (new == NULL)
    return NULL;

  new->data = data;
  new->next = curr->next;
  curr->next = new;

  return new;
}

int remove_node(int data) {
  Node *prev;
  Node *curr = head;

  while (curr != NULL) {
    if (curr->data == data) {
      if (curr == head)
        head = curr->next;
      else
        prev->next = curr->next;

      free(curr);
      return 1;
    }

    prev = curr;
    curr = curr->next;
  }

  return 0;
}

void print_nodes() {
  Node *curr = head;

  while (curr != NULL) {
    printf("%d->", curr->data);
    curr = curr->next;
  }

  printf("NULL\n");
}

int main(int argc, char *argv[]) {
  char option = '\0';
  while (option != 'q') {
    print_menu();
    printf("\nChoice: ");

    int num_receivd = scanf(" %c", &option);
    if (num_receivd != 1)
      break;

    int input;
    int input2;
    switch (option) {
    case 'a':
      printf("Data to be added: ");
      scanf("%d", &input);

      add_node(input);
      break;

    case 'i':
      printf("Position to be inserted at: ");
      scanf("%d", &input);
      printf("Data to be inserted: ");
      scanf("%d", &input2);

      insert_node(input, input2);
      break;

    case 'r':
      printf("Data to be removed: ");
      scanf("%d", &input);

      int result = remove_node(input);
      if (!result)
        printf("Data not found!\n");

      break;

    case 'p':
      print_nodes();
      break;

    case 'q':
      break;

    default:
      printf("Unknown option.\n");
      break;
    }

    printf("\n\n");
  }

  return 0;
}
