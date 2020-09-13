#include <pthread.h>
#include <stdio.h>

int count; /* общие данные для потоков */
int atoi(const char *nptr);
void *potok(void *param); /* потоковая функция */

int main(int argc, char *argv[])
{
  pthread_t tid; /* идентификатор потока */

if (argc != 2) {
  fprintf(stderr,"usage: progtest <integer value>\n");
  return -1;
}

if (atoi(argv[1]) < 0) {
  fprintf(stderr,"Аргумент %d не может быть отрицательным числом\n",atoi(argv[1]));
  return -1;
}

/* создаем новый поток */
  pthread_create(&tid,NULL,potok,argv[1]);
    printf("Before => count = %d\n",count);
/* ждем завершения исполнения потока */
  pthread_join(tid,NULL);
  printf("After => count = %d\n",count);
}

/* Контроль переходит потоковой функции */
void *potok(void *param) 
{
  count = atoi(param) + 1000;
  printf("In potok => count = %d\n",count);
  return(0);
}