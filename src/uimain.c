#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
  List *history = init_history();
  while(1){
    printf("'q' is to quit, 'i' is to input, 'h' is to view history, '$' is to view a certin histoy\n");
      fputs("Input Here:", stdout);
      fflush(stdout);
      int c;
      while((c = getchar()) == '\n');
      if(c == EOF)
	goto done;

      char input[50];
      switch(c){
      case 'i':
	puts("Please enter a string:\n>");
	fgets(input, 50, stdin);
	char **token = tokenize(input);
	add_history(history, input);
	print_tokens(token);
	free_tokens(token);
      case 'h':
	print_history(history);
	break;
      case '$':
	puts("Please enter an id:\n>");
	fgets(input);
	char *temp = get_history(history, atoi(input+1));
	chat **tokencopy = tokenize(temp);
	print_tokens(tokencopy);
	break;
      case 'q':
	puts("Goodbye");
	free_history(history);
	goto done;
      default:
	printf("Unrecognized option '%c', please try again!\n", c);
      }
  }
  done:
  return 0;
}
