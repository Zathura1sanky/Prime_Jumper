#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

long long mulmod(long long a, long long b, long long mod)
{
    long long x = 0,y = a % mod;
    while (b > 0)
    {
        if (b % 2 == 1)
        {    
            x = (x + y) % mod;
        }
        y = (y * 2) % mod;
        b /= 2;
    }
    return x % mod;
}



long long modulo(long long base, long long exponent, long long mod)
{
    long long x = 1;
    long long y = base;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            x = (x * y) % mod;
        y = (y * y) % mod;
        exponent = exponent / 2;
    }
    return x % mod;
}
 


int Miller(long long p,int iteration)
{
 
    int i=0;
    long long s;
    if (p < 2)
    {
        return 0;
    }
    if (p != 2 && p % 2==0)
    {
        return 0;
    }
     s = p - 1;
    while (s % 2 == 0)
    {
        s /= 2;
    }
    srand(time(0));
    for (i = 0; i < iteration; i++)
    {   
        long long a = rand() % (p - 1) + 1, temp = s;
        long long mod = modulo(a, temp, p);
        while (temp != p - 1 && mod != 1 && mod != p - 1)
        {
            mod = mulmod(mod, mod, p);
            temp *= 2;
        }
        if (mod != p - 1 && temp % 2 == 0)
        {
            return 0;
        }
    }
    return 1;
}

void changestr(char str[], int n)
{
    str[n] = '|';
}

void delay(int number_of_seconds)
{
	// Converting time into milli_seconds
	int milli_seconds = 1000 * number_of_seconds;

	// Storing start time
	clock_t start_time = clock();

	// looping till required time is not achieved
	while (clock() < start_time + milli_seconds)
		;
}

void loader()
{
    int i, j, n = 0;
    char str[] = "                                                 ";
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\n\t\t\t\t\t\t\t\t>--PRIME JUMPER--<\n");
    printf("\n\t\t\t\t\t\t\t\t------LOADING-----\n");
    printf("\n");
    for(i = 0 ; i < 50 ; i++)
    {
        printf("\r\t\t\t\t\t\t[%-50s]", str);
        changestr(str, n);
        n++;
        delay(100);
    }
    printf("\n\n\t\t\t\t\t\t\t    press Enter to start game");
    getchar();
    return;
}



void printBoard(int player1,int computer){
    int l=1;
    int temp;
    system("clear");
    for(int i=0;i<10;i++){
        printf("\n\n");
        
        for(int k=0;k<10;k++){
        
         if(l==player1&&l==computer){
             printf("*@\t");
         }
         else if(l==player1){
           printf("*\t"); 
        }
         else if(l==computer){
           printf("@\t"); 
        }
        if(l!=player1&&l!=computer){
           printf("%d\t",l); 
        }
        l++;
        }
        if(i==3)
        printf("\t\t\t\a<--SCORE BOARD-->");
        if(i==4)
        printf("\t\t\tPLAYER score is %d",player1);
        if(i==5)
        printf("\t\t\tCOMPUTER score is %d",computer);
    printf("\n");    
        
      
    }
}

int main()
{ 

    srand(time(0));
    int number;
    int player=1,computer=1;
    bool mycontinue=true;
    system("clear");
    loader();
    printBoard(player,computer);
    while(mycontinue){
        printf("\nPlayer Input press Enter to roll dice");
        number=rand()%14+1;
        getchar();
        printf("\nDice is rolling");
        delay(1000);
        printf("\nPlayer number is %d",number);
        delay(300);
        if(Miller(number,3)&&player+number>100)
         player=100;
        else if(Miller(number,3))
         player+=number;
        else{
            if(player==1)
            player=1;
            else
            player-=1;
        }
        system("clear");
        printBoard(player,computer);
        delay(300);
        printf("\nComputer Input ");
        printf("\nDice is rolling");
        number=rand()%14+1;
        delay(1000);
        printf("\nComputer number is %d",number);
        delay(300);
        if(Miller(number,3)&&computer+number>100)
         computer=100;
        else if(Miller(number,3))
         computer+=number;
        else{
            if(computer==1)
            computer=1;
            else
            computer-=1;
        }
        system("clear");
        printBoard(player,computer);
        if(computer>=100||player>=100)
        mycontinue=false;
    }
      system("clear");
    printf("\n\t\t\t\t\t\t\t         Game Completed");
    printf("\n\n\t\t\t\t\t\t\t         Final Score");
    printf("\n\t\t\t\t\t\t\t         Player %d",player);
    printf("\n\t\t\t\t\t\t\t         Computer %d",computer);
    
    if(player==100){
        printf("\n\n\t\t\t\t\t\t\t!!!   Player won the game  !!!");
    }
    if(computer==100){
        printf("\n\n\t\t\t\t\t\t\t|||  Computer won the game  |||");
        printf("\n\n\t\t\t\t\t\t\t          Try next time");
    }
    

    return 0;
}
