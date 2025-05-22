#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int rollDice()
{
  return (rand() % 6) + 1;
}

int playYahtzee();
int enabledPrintStms = 0;

int main()
{
  int startTime = time(NULL);
  srand(time(NULL));

  int yahtzeeCount = 0;
  int totalYahtzeeTries = 1000000;

  for (int attempt = 0; attempt < totalYahtzeeTries; attempt++)
  {
    if (enabledPrintStms) printf("Attempt %d\n", attempt + 1);
    if (playYahtzee() == 5) {
      if (enabledPrintStms) printf("********** You have a Yahtzee! ********** \n");
      yahtzeeCount++;
    } 
    else {
      if (enabledPrintStms) printf("No Yahtzee this time.\n");
    }
  }
  int endTime = time(NULL);
  printf("Elapsed time: %d seconds\n", endTime - startTime);
  printf("You rolled a Yahtzee %d times out of %d three roll attempts. %f\n", yahtzeeCount, totalYahtzeeTries, (double)yahtzeeCount/(double)totalYahtzeeTries);
}

int* reRollLeastFrequent(int dice[], int numberCount[])
{
  int leastFrequent = 0;
  int leastFrequentCount = 6;
  for (int i = 1; i < 6; i++)
  {
    if (numberCount[dice[i]] < leastFrequentCount)
    {
      leastFrequent = dice[i];
      leastFrequentCount = numberCount[dice[i]];
    }
  }
  for (int i = 1; i < 6; i++)
  {
    if (dice[i] == leastFrequent)
    {
      dice[i] = rollDice();
    }
  }
  return dice;
}

int playYahtzee()
{
  int dice[6] = {0, rollDice(), rollDice(), rollDice(), rollDice(), rollDice()};
  int numberCount[7] = {0, 0, 0, 0, 0, 0, 0};
  if (enabledPrintStms) printf("dice: %d %d %d %d %d\n", dice[1], dice[2], dice[3], dice[4], dice[5]);

  int i = 0;
  int mostFrequent = 0;
  int mostFrequentCount = 0;
  for (i = 1; i < 6; i++)
  {
    numberCount[dice[i]]++;

    if (numberCount[dice[i]] > mostFrequentCount)
    {
      mostFrequent = dice[i];
      mostFrequentCount = numberCount[dice[i]];
    }
  }
  memset(numberCount, 0, sizeof(numberCount));
  if (mostFrequentCount == 5)
  {
    return 5;
  }
  else
  {
    for (i = 1; i < 6; i++)
    {

      if (dice[i] == mostFrequent)
      {
        //printf("Keeping die %d (%d)\n", i, dice[i]);
      }
      else
      {
        dice[i] = rollDice();
        //printf("Rolling die %d -> %d\n", i, dice[i]);
      }
    }
    if (enabledPrintStms) printf("dice: %d %d %d %d %d\n", dice[1], dice[2], dice[3], dice[4], dice[5]);
  }
  mostFrequentCount = 0;
  mostFrequent = 0;
  for (i = 1; i < 6; i++)
  {
    numberCount[dice[i]]++;

    if (numberCount[dice[i]] > mostFrequentCount)
    {
      mostFrequent = dice[i];
      mostFrequentCount = numberCount[dice[i]];
    }
  }
  memset(numberCount, 0, sizeof(numberCount));
  if (mostFrequentCount == 5)
  {
    return 5;
  }
  else
  {
    for (i = 1; i < 6; i++)
    {
      numberCount[i] = 0;
      if (dice[i] == mostFrequent)
      {
        //printf("Keeping die %d (%d)\n", i, dice[i]);
      }
      else
      {
        dice[i] = rollDice();
        //printf("Rolling die %d -> %d\n", i, dice[i]);
      }
    }
    if (enabledPrintStms) printf("dice: %d %d %d %d %d\n", dice[1], dice[2], dice[3], dice[4], dice[5]);
  }
  mostFrequentCount = 0;
  mostFrequent = 0;
  for (i = 1; i < 6; i++)
  {
    numberCount[dice[i]]++;

    if (numberCount[dice[i]] > mostFrequentCount)
    {
      mostFrequent = dice[i];
      mostFrequentCount = numberCount[dice[i]];
    }
  }

  return mostFrequentCount;
}