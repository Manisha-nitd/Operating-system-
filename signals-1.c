#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<sys/types.h>
void f1(int s)
{
  printf("\n\t Signal %d received",s);
  signal(SIGINT,SIG_DFL);
}
int main()
{
  pid_t x;
  signal(SIGINT,f1);
  x=fork();
  if(x)
  {
    printf("\n\t Within Parent");
    kill(x,SIGINT);
    exit(1);
  }
  else
  {
    while(1)
    {
      printf("\nWithin Child");
      sleep(10);
    }
  }

}
