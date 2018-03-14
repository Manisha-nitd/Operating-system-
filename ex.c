#include<stdio.h>
#include<unistd.h>

int main()
{
  execlp("./eg","/.eg",NULL);
  printf("This statement is not executed\n");
}
