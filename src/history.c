#include "stdio.h"
#include "history.h"
#include "tokenizer.h"

List *init_history()
{
  List *history = malloc(sizeof(list));
  history->head = malloc(sizeof(Item));
}

void add_history()
{
  Item *temp = list->head;
  int id = 1;
  while(temp->next != 0)
  {
    temp = temp->next;
    id++;
  }
  temp->next = malloc(sizeof(Item));
  temp->next->id = id;
  temp->nest->str = copy_str(str, string_length(str))
}

char *get_history(List *list, int id)
{
  
}

void print_history()
{
  Item *temp = list->head->next;
  while(temp != 0)
  {
    printf("ID = %d, String = %s\n", temp->id, temp->str);
    temp = temp->next;
  }
}

void free_history()
{
  
}
