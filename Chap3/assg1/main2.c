#include <stdio.h>
#include "copy2.h"
#include <string.h>
char line[MAXLINE];
char longest[MAXLINE];
char sentences[MAXLINE][MAXLINE];

int main(){
  int len;
  int max;
  max = 0;

  while(gets(line) != NULL) {
    len = strlen(line);

    if(len > max) {
       max = len;
       copy(line, longest);
      }

      strcpy(sentences[len], line); // save the sentence in array
    }

  if(max > 0)
    printf("Sorted sentences: \n");

  // using the bubble sort
  for (int i =0; i < MAXLINE - 1; i++) {
      for (int j =0; j < MAXLINE - i - 1; j++) {
         if (strlen(sentences[j]) < strlen(sentences[j + 1])) {
	     // switching sentence
	     char temp[MAXLINE];
	     strcpy(temp, sentences[j]);
	     strcpy(sentences[j], sentences[j + 1]);
	     strcpy(sentences[j + 1], temp);
	 }
      }
  }
// printf result of sentences what sorted

  for (int i = 0; i < MAXLINE; i ++) {
      if (strlen(sentences[i]) > 0 ) {
         printf("%s\n", sentences[i]);
      }
  }
  return 0;

}
