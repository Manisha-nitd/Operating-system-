#include<pthread.h>
#include<stdio.h>
void *printmsg(char *s)
{
  printf("%s",s);
  printf("In thread");
  pthread_exit(NULL);
}

int main()
{
  pthread_t thread1,thread2;
  pthread_create(&thread1,NULL,(void*)printmsg,(void*)"Hello");
  pthread_create(&thread2,NULL,(void*)printmsg,(void*)"World");
  return 0;
}
