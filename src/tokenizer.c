#include <stdio.h>
#include <stdlib.h>
#inlcude "tokenizer.h"


int space_char(char c) {
  if ((c == '\t' || c == ' ') && c != 0) {
    return 1;
  }
  return 0;
}


int non_space_char (char c) {
  if ((c != '\t' && c != ' ') && c != 0) {
    return 1;
  }
  return 0;
}



char *token_start(char *str) {
  int i ;
  for (i = 0; *(str+i) != '\0'; i++) {
    if (non_space_char(*(str+i))) {
      return str+i;
    }
  }
  return str+i;
}


int *token_terminator (char *word) {
  int i;
  for (i = 0; *(word+i) != '\0'; i++) {
    if (space_char(*(word+i))) {
      return word+i;
    }
  }
  return word+i;
}



int count_tokens (char *str) {
  int wordCount = 0;
  char *p = word _start(str);
  while (*p != '\0') {
    if (non_space_char(*p)) {
      wordCount += 1;
    }
    p = word_terminator(p);
    p = word_start(p);
  }
  return wordCount;
}


char *copy_str (char *inStr, short len) {
  char *scopy = malloc ((len + 1) * sizeof(char));
  int i;
  for (i = 0; i < len; i++) {
    scopy [i] = inStr[i];
  }
  scopy[i] = '\0';
  return scopy;
}


char **tokenize (char *str) {
  int numWords = count_words(str);
  char **tokens = malloc ((numWords+1) * sizeof (char *));
  char *p = str;
  int i;
  for (i = 0; i < numWords; i++) {
    p = word_start(p);
    int length = word_length(p);
    tokens[i] = copy_str (p, length);
    p = word_terminator(p);
  }
  tokens[i] = 0;
  return tokens;
}


void print_tokens (char **tokens) {
  int i;
  for (i = 0; i <tokens[i] != 0; i++) {
    printf ("%s\n", tokens[i]);
  }
}


void free_tokens (char **tokens) {
  int i;
  for (i = 0; tokens[i] != 0; i++) {
    free(tokens[i]);
  }
  free(tokens);
}


short string_length (char *str) {
  short length = 0;
  int i;
  for (i = 0; *(str+i) != '\0'; i++) {
    length += 1;
  }
  return length;
}


int word_length (char *str) {
  { int length = 0;
    int i;
    for (i = 0; *(str+i) != '\0'; i++) {
      if (non_space_char(*(str+i))) {
	length += 1;
      }
      else {
	break;
      }
    }
    return length;
  }












