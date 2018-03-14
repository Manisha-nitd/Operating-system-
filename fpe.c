#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include<sys/types.h>
void floating(int signum)
{
  printf("\n\t FPE %d received\n",signum);
  exit(signum);
}
void segmentation(int signum)
{
  printf("\n\t segmentation fault %d received\n",signum);
  exit(signum);
}
int main()
{
  signal(SIGFPE,floating);
  signal(SIGSEGV,segmentation);
  pid_t pid;
  pid=fork();
  if(!pid)
  {
    int a=5,b=0,c;
    c=a/b;
  }
  else
  {
    int *p;
    printf("%d",*p);
  }
}
