#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>

void f1(int signum)
{
    printf("process id=%d caught signal %d\n",getpid(),signum);
    exit(1);	
}
int main()
{
	pid_t x;
	x=fork();
	if(x==0)
	{
		printf("parent pid=%d and process pid=%d\n",getppid(),getpid());
		int status;
		pid_t v=fork();
		if(v==0)
		{
			signal(SIGFPE,f1);
			int f=8;
			printf("Handle floating point exception\n");
			printf("parent pid=%d and process pid=%d\n",getppid(),getpid());
			printf("\n\n\n");
			printf("%d\n",f/0);
		}
		else if(v>0)
		{
			waitpid(v,&status,0);
			signal(SIGSEGV,f1);
			int a[100];
			printf("Segmentation fault handling\n");
			printf("process pid=%d and child pid=%d\n",getpid(),v);
			printf("\n\n\n");
			printf("%d\n",a[10000]);
		}
	}
	else
	{
		int status2;
		waitpid(x,&status2,0);
		signal(SIGINT,f1);
		printf("Handle sigill exception\n");
		printf("process pid=%d and child pid=%d\n",getpid(),x);
		while(1)
		{
			printf("Hello\n");
			sleep(2);
		}
		printf("\n\n\n");
	}
  return 0;
		
}
