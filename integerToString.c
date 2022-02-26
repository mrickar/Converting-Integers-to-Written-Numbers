#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BILLION 1000000000
#define MILLION 1000000
#define THOUSAND 1000
#define HUNDRED 100
char zero_twenty[][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
char decimals[][10] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

char *convertString(int n)
{
    char *str = malloc(sizeof(char) * 20);
    if (n < 20)
    {
        strcpy(str, zero_twenty[n]);
    }
    else
    {
        strcpy(str, decimals[n / 10]);
        if (n % 10 != 0)
        {
            strcat(str, " ");
            strcat(str, zero_twenty[n % 10]);
        }
    }
    return str;
}
char *convertStringHundred(int n)
{
    char *str;
    if (n < 100)
    {
        return convertString(n);
    }
    else
    {
        str = malloc(sizeof(char) * 35);
        strcpy(str, zero_twenty[n / HUNDRED]);
        strcat(str, " hundred ");
        if (n % HUNDRED != 0)
        {
            strcat(str, convertString(n % HUNDRED));
        }
    }
    return str;
}
char *convertStringThousand(int n)
{
    char *str;
    if (n < THOUSAND)
    {
        return convertStringHundred(n);
    }
    else
    {
        str = malloc(sizeof(char) * 75);
        strcpy(str, convertStringHundred(n / THOUSAND));
        strcat(str, " thousand ");
        if (n % THOUSAND != 0)
        {
            strcat(str, convertStringHundred(n % THOUSAND));
        }
    }
    return str;
}
char *convertStringMillion(int n)
{
    char *str;

    if (n < MILLION)
    {
        return convertStringThousand(n);
    }
    else
    {
        str = malloc(sizeof(char) * 130);
        strcpy(str, convertStringHundred(n / MILLION));
        strcat(str, " million ");
        if (n % MILLION != 0)
        {
            strcat(str, convertStringThousand(n % MILLION));
        }
    }
    return str;
}
char *convertStringBillion(unsigned long long int n)
{
    char *str;

    if (n < BILLION)
    {
        return convertStringMillion(n);
    }
    else
    {
        str = malloc(sizeof(char) * 200);
        strcpy(str, convertStringHundred(n / BILLION));
        strcat(str, " billion ");
        if (n % BILLION != 0)
        {
            strcat(str, convertStringMillion(n % BILLION));
        }
    }
    return str;
}
int main(int argc, char **argv)
{
    //int i;
    unsigned long long int wantedNum, digitCnt;
    //char number[15];
    //digitCnt = 1;
    //i = 0;
    printf("Write a number (MAX:999999999999): ");
    scanf("%lld",&wantedNum);
//     scanf("%s", number);
//     for (i = 0; number[i] != '\0'; i++)
//     {
//         if (i != 0)
//         {
//             digitCnt *= 10;
//         }
//     }

//     wantedNum = 0;
//     for (i = 0; digitCnt != 0; digitCnt /= 10, i++)
//     {
//         int charToInt = number[i] - '0';
//         wantedNum += digitCnt * charToInt;
//     }

    printf("Number = %s\n", convertStringBillion(wantedNum));

    return 0;
}
