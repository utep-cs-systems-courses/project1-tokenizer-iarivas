#include "tokenizer.h"
#include "stdio.h"

int space_char(char c)
{
  if(c == ' '|| c == '\t')
    return 1;
  return 0;
}

int non_space_char(char c)
{
  if(c == ' '|| c == '\t')
    return 0;
  return 1;
}

char word_start(char *str)
{
  while(space_char(str[0]) && str[0] != 0)
  {
    str++;
  }
  if(str[0] == 0)
    return 0;
  return str[0];
}

char *word_terminator(char *word)
{
  while(word[0] != 0 || word[0] != ' ')
    word++;
  return word;
}

int count_words(char *str)
{
  int count = 0;
  while(word_start(str) != 0)
  {
    count++;
  }
  return count;
}
