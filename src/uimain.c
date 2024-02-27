#include <stdio.h>
#inlcude "history.h"
#include "tokenizer.h"



int main() {


  while (1) {

    char test[50];

    printf("please enter something\n");

    printf(">");

    fgets(test, sizeof(test), stdin);

    printf(test);

    return 0;

  }


  return 0;
 
}
