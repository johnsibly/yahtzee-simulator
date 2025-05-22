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
  int totalYahtzeeTries = 20000000;

  for (int attempt = 0; attempt < totalYahtzeeTries; attempt++)
  {
    if (enabledPrintStms) printf("Attempt %d\n", attempt + 1);
    if (playYahtzee()) {
      if (enabledPrintStms) printf("********** You have a Yahtzee! ********** \n");
      yahtzeeCount++;
    } 
    else {
      if (enabledPrintStms) printf("No Yahtzee this time.\n");
    }
  }
  int endTime = time(NULL);
  printf("Elapsed time: %d seconds\n", endTime - startTime);
  printf("You rolled a Yahtzee %d times out of %d three roll attempts.\nPercentage of rolls: %f%%\n", yahtzeeCount, totalYahtzeeTries, 100.0*(double)yahtzeeCount/(double)totalYahtzeeTries);
}


int getMostFrequentCount(int dice[], int* mostFrequent)
{
  *mostFrequent = 0;
  int mostFrequentCount = 0;
  int numberCount[7] = {0, 0, 0, 0, 0, 0, 0};

  for (int i = 1; i < 6; i++)
  {
    numberCount[dice[i]]++;

    if (numberCount[dice[i]] > mostFrequentCount)
    {
      *mostFrequent = dice[i];
      mostFrequentCount = numberCount[dice[i]];
    }
  }
  
  return mostFrequentCount;
}

int reRollLeastFrequent(int* dice, int mostFrequent)
{
  for (int i = 1; i < 6; i++)
  {
    if (dice[i] != mostFrequent)
    {
      dice[i] = rollDice();
    }
  }
  return 0;
}

int playYahtzee()
{
  int gotYahtzee = 0;
  int dice[6] = {0, rollDice(), rollDice(), rollDice(), rollDice(), rollDice()};

  if (enabledPrintStms) printf("dice: %d %d %d %d %d\n", dice[1], dice[2], dice[3], dice[4], dice[5]);

  int i = 0;
  int mostFrequent = 0;
  gotYahtzee = getMostFrequentCount(dice, &mostFrequent) == 5;

  if (!gotYahtzee)
  {
    reRollLeastFrequent(dice, mostFrequent);
    gotYahtzee = getMostFrequentCount(dice, &mostFrequent) == 5;
    if (!gotYahtzee)
    {
      reRollLeastFrequent(dice, mostFrequent); 
      gotYahtzee = getMostFrequentCount(dice, &mostFrequent) == 5;
    }
  }
  return gotYahtzee;
}