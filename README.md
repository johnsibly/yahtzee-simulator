# yahtzee-simulator#Build

Programme to simulate the game of Yahtzee.
I.e. you roll 5 dice and try to get the best combination of numbers.
After the first roll you can choose to keep some of the dice and re-roll the others, up to a maximum of three rolls in total.
A Yahtzee is when you get all 5 dice to show the same number.

I was interested in the game and wanted to simulate it to see how often you get certain combinations, and test out the theoretical prodictions from this article: https://www.datagenetics.com/blog/january42012/

#Build
```gcc yahtzee-simulator.c -o yahtzee-simulator```

#Run
```./yahtzee-simulator```