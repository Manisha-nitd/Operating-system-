#include<stdio.h>
#include<sys/shm.h>
#include<unistd.h>
#include<sys/wait.h>
#include <stdlib.h>

int main()
{
   char c;
   int shmid;
   key_t key;
   char *shm,*s;
   key=1234;
   int smid=shmget(key,27*sizeof(char),IPC_CREAT|0777);
   shm=(char *)shmat(smid,0,0);
   s=(char *)shmat(smid,0,0);
   s=shm;
   for(c='a';c<='z';c++)
   {
     *s=c;
     s++;
   }
   *s='\0';
   printf("done serv\n");
   while(*shm!='*')
   {
     printf("%c ",*shm);
     sleep(1);
     shm++;
   }
   exit(0);
 }
