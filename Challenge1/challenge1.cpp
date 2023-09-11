#include <stdio.h>
#include <string.h>
#include <math.h>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// ANSI escape codes for text colors
#define RED_TEXT "\033[1;31m"
#define GREEN_TEXT "\033[1;32m"
#define RESET_TEXT "\033[0m"
#define YELLOW_TEXT "\033[1;33m"

int main()
{
  cout<<GREEN_TEXT<<"Welcome to the bank of CTF"<<RESET_TEXT<<endl;
  cout<<GREEN_TEXT<<"We are the most secure bank in the world"<<RESET_TEXT<<endl;
  cout<<GREEN_TEXT<<"You have $4000000000 in your bank"<<RESET_TEXT<<endl;
  cout<<GREEN_TEXT<<"We have the best security system in the world"<<RESET_TEXT<<endl;
  cout<<GREEN_TEXT<<"We want you to somehow hack our bank system and increase your account balance"<<RESET_TEXT<<endl;
  unsigned int amount = 4000000000;
  
  while (1)
  {
    printf("%sCurrent account balance: $%u%s\n", RED_TEXT, amount, RESET_TEXT);
    printf("%sWhat would you like to do? \n 1. Deduct money \n 2. Reset Money \n 3. Exit \n%s", GREEN_TEXT, RESET_TEXT);

    int choice;
    scanf("%d", &choice);
    int flag = 0;

    if (choice == 3)
    {
      printf("Exiting... \n");
      break;
    }
    else if (choice == 2)
    {
      amount = 4000000000;
    }
    else if (choice == 1)
    {
      printf("%sEnter amount to deduct: %s", YELLOW_TEXT, RESET_TEXT);
      double ded;
      scanf("%lf", &ded);

      if (ded < 0)
      {
        printf("%sOOPS we don't allow negative value, think more \n (Keep in mind that money is non-negative)\n%s", RED_TEXT, RESET_TEXT);
        continue;
      }

      unsigned int temp = amount;
      temp -= ded;

      if (temp > amount)
      {
        unsigned int tmp1 = (unsigned int)amount;
        unsigned int cnt1 = 0;
        while (tmp1 != 0)
        {
          tmp1 /= 10;
          cnt1++;
        }
        int tmp2 = (unsigned int)temp;
        int cnt2 = 0;
        while (tmp2 != 0)
        {
          tmp2 /= 10;
          cnt2++;
        }
        printf("%sBalanced changed from $%u to $%u (anamoly of increase in money)%s\n", GREEN_TEXT, amount, temp, RESET_TEXT);
        printf("%sA suspicious transaction has been detected. \n%s", RED_TEXT, RESET_TEXT);
        printf("%sAuthentication required to continue. \n%s", RED_TEXT, RESET_TEXT);
        printf("%sPlease enter the secret key to continue: %s", RED_TEXT, RESET_TEXT);

        string input;
        cin >> input;
        string command="challenge1_help.exe "+input;
        FILE *pipe = popen(command.c_str(), "r");

        char buffer[128];
        string result = "";

        while (!feof(pipe))
        {
          if (fgets(buffer, 128, pipe) != nullptr)
          {
            result += buffer;
          }
        }
        int output = pclose(pipe);
        if (output)
        {
          printf("%sYou are authenticated \n%s", GREEN_TEXT, RESET_TEXT);
          printf("%sYou hacked the bank, Great job, Congrats!! \n%s", GREEN_TEXT, RESET_TEXT);
          exit(0);
        }
        else
        {
          printf("%sWrong key, exiting... \n%s", RED_TEXT, RESET_TEXT);
          continue;
        }
      }

      amount -= (unsigned int)ded;
    }
    else
    {
      printf("You found a hint- \n");
      printf("%sU need buffer overflow to get the flag \n%s", GREEN_TEXT, RESET_TEXT);
    }
  }

  return 0;
}
