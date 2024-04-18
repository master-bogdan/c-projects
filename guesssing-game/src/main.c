#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomNumber(int min, int max) {
  return min + rand() % (max - min + 1);
}

int main() {
  // Seed the random number generator ONCE
  srand(time(NULL));

  int secretNumber = randomNumber(1, 100);
  int userNumber;
  int userTries = 0;
  const int MAX_USER_TRIES = 5;

  while (userNumber != secretNumber) {
    printf("Enter a number between 1 and 100: ");
    scanf("%d", &userNumber);

    userTries++;

    if (userNumber > secretNumber) {
      printf("Your number is more, you have %d tries\n", MAX_USER_TRIES - userTries);
    } else if (userNumber < secretNumber) {
      printf("Your number is less, you have %d tries \n", MAX_USER_TRIES - userTries);
    } else if (userTries >= MAX_USER_TRIES) {
      printf("You loose!");
      break;
    }
  }
  printf("You Win!");

  return 0;
}
