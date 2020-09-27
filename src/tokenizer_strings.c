#include "tokenizer.h"
#include "stdio.h"
#include "malloc.h"

int string_length(char *str)
{
  int count = 0;
  while(str[count] != '\0')
  {
    count++;
  }
  return count;
}

int valid_character(char c)
{
  if(c >= 33 && c <= 122)
  {
    return 1;
  }
  return 0;
}

int space_char(char c)
{
  if((c == ' '|| c == '\t') && c != '\0')
    return 1;
  return 0;
}

int non_space_char(char c)
{
  if((c == ' '|| c == '\t') && c != '\0')
    return 0;
  return 1;
}

char *word_start(char *str)
{
  int count = 0;
  int len = string_length(str);
  while(space_char(str[count]) && count <= len)
  {
    count++;
  }
  if(count > len){ return &str[0]; }
  return &str[count];
}

char *word_terminator(char *word)
{
  int count = 0;
  int len = string_length(word);
  while(non_space_char(word[count]) && count < len)
  {
    count++;
  }
  return &word[count];
}

int count_words(char *str)
{
  int word = 1;
  int count = 0;
  char *start = word_start(str);
  int len = string_length(start);
  while(count < len)
  {
    if(space_char(str[count]) && count+1 < len)
    {
      if(non_space_char(str[count+1]))
	{
	  word++;
     	}
    }
    count++;
  }
  return word;
}

char *copy_str(char *inStr, short len)
{
  char *copy =(char*) malloc(len * sizeof(char));
  int i;
  for(i = 0; i<len; i++)
  {
    copy[i] = inStr[i];
  }
  return &copy[0];
}

void print_tokens(char **tokens)
{
  int counter = 0;
  while(*tokens)
  {
    printf("Token[%d] = %s", counter, *tokens);
    tokens++;
    counter++;
  }
}

char **tokenize(char *str)
{
  char *start = word_start(str);
  int words = count_words(str);
  char **tokens = (char**) malloc(words+1 * sizeof(char*));
  int len = string_length(str);
  short count = 0;
  int i = 0;
  for(i = 0; i < words-1; i++)
  {
    while(non_space_char(start[count]))
    {
      count++;
    }
    tokens[i] = copy_str(start, count);
    start = word_start(&str[count+1]);
    count = 0;
  }
  while(non_space_char(start[count]))
  {
    count++;
  }
  tokens[words-1] = copy_str(start, count);
  return tokens;
}


