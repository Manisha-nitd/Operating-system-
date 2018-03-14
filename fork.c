#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<sys/types.h>
void forkex()
{
  if(!fork())
  printf("\n\t Child\n");
  else
  printf("\n\t Parent\n");

}
int main()
{
  forkex();
}
