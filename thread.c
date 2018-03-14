#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#define num  8
char *messages[num];
struct thread_data
{
 int id;
 int sum;
 char *message;
};

struct thread_data thread_data_array[num];

void *function(void *arg)
{
 int taskid,sum;
 char *msg;
 struct thread_data *mydata;
 

 mydata=(struct thread_data *) arg;
 taskid=mydata->id;
 sum=mydata->sum;
 msg=mydata->message;
 printf("Thread%d: %s Sum=%d\n", taskid,msg,sum);
 pthread_exit(NULL);
}

int main(int argc , char *argv[])
{
 pthread_t threads[num];
 int *taskids[num];
 int rc,t,sum;
 sum=0;
 messages[0]="aa";
 messages[1]="bb";
 messages[2]="cc";
 messages[3]="dd";
 messages[4]="ee";
 messages[5]="ff";
 messages[6]="gg";
 messages[7]="hh";

 for(t=0; t<num; t++)
 {
  sum=sum+t;
  thread_data_array[t].id=t;
  thread_data_array[t].sum=sum;
  thread_data_array[t].message=messages[t];
  rc=pthread_create(&threads[t],NULL,function,(void *) &thread_data_array[t]);
  if (rc)
  {
   printf("ERROR: return code from pthread_create() is %d \n" , rc);
   exit(-1);
  }
 }
 pthread_exit(NULL);
}
