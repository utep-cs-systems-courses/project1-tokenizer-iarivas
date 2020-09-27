#include "stdio.h"
#include "malloc.h"
#include "history.h"
#include "tokenizer.h"

List *init_history()
{
  List *history = malloc(sizeof(List));
  history->root = malloc(sizeof(Item));
}

void add_history(List *list, char *str)
{
  Item *temp = list->root;
  int id = 1;
  while(temp->next != 0)
  {
    temp = temp->next;
    id++;
  }
  temp->next = malloc(sizeof(Item));
  temp->next->id = id;
  temp->next->str = copy_str(str, string_length(str));
}

char *get_history(List *list, int id)
{
  Item *temp = list->root;
  while(temp != 0)
  {
    if(temp->id == id) return temp->str;
    temp = temp->next;
  }
  return "String not found!";
}

void print_history(List *list)
{
  Item *temp = list->root->next;
  while(temp != 0)
  {
    printf("ID = %d, String = %s\n", temp->id, temp->str);
    temp = temp->next;
  }
}

void free_history(List *list)
{
  
}
