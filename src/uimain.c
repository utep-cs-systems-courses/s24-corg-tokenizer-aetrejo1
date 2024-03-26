#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

void token_to_history(List *history, char **tokens);


int main() {

  List *history = init_history();


  while (1) {
    printf("\n Select an input please");

    printf("1.Input 'q' to quit\n 2.Input 'i' to enter your word/sentence\n 3.Input '!' and then put the number of the token you want to recall\n Input 'h' to see stored history\n");
    printf(">");
    fgets(input, 100, stdin);


    if (input[0] == 'q') {
      printf("damn okay : (\n");
      free_history (history);
      return 0;
    }
    else if (input[0] == '!') {
      char *hist = get_history(history, atoi(input+1));
      char **tokens = tokenize(hist);
      printf("history : %s\n", hist);
      printf("history token\n");
      print_tokens(tokens);
      free_tokens(tokens);
    }

    else if (input[0] == 'h') {
      print_history(history);
    }
    else if (input[0] == 'i') {
      printf ("Enter your word\n");
      fgets(input, 100, stdin);
      char **tokens = tokenize(input);
      print_tokens(tokens);
      add_history(history, input);
      free_tokens(tokens);
    }
    else {
      printf("??????????? try again pls\n");
    }
  }
}
