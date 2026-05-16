#include <stdio.h>
#include <stdlib.h>
#include <time.h>




#define RESET "\033[0m"
#define BOLD "\033[01m"
#define CYAN "\033[36m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RED "\033[31m"



void print_header() {
  printf(CYAN BOLD);
  printf("[=====================]\n");
  printf("|    GUESS NUMBER     |\n");
  printf("|      by xmdie       |\n");
  printf("[=====================]\n");
  printf(RESET);
}


int main() {
  srand(time(NULL));
  int secret = rand() % 100 +1;
  int guess = 0;
  int attempts = 0;
  
  print_header();
  printf(CYAN " I ordered num from 1 to 100 \n" RESET);
  printf(CYAN "_____________________________\n" RESET);

  do {
    printf(YELLOW "Your variant: " RESET);
    scanf("%d", &guess);
    attempts++;

    if (guess < secret)
        printf(RED "More!\n" RESET);
    else if (guess > secret)
        printf(RED "LESS!\n" RESET);
    else 
        printf(GREEN "\n CORRECT! Tried: %d \n" RESET, attempts);

  } while (guess != secret);

  return 0;
}

