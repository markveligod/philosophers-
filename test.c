#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <pthread.h>
 
int sum=0;
pthread_mutex_t turn = PTHREAD_MUTEX_INITIALIZER;
int nthreads; 
 
void * calculate() { 
    int i=0;
    for (i; i< 100000 ; i++) { 
        pthread_mutex_lock(&turn);
        sum++;
        pthread_mutex_unlock(&turn);
    }
}
 
int main(int argc, char** argv) {    
 
    int i;
    pthread_t * ids;
    struct timeval start_time;
    struct timeval end_time;

    gettimeofday(&start_time, NULL); //currente time
	  printf("FIRST: time sec: %ld | time microsec %ld | RES: %ld\n", start_time.tv_sec, start_time.tv_usec, start_time.tv_sec * 1000 + start_time.tv_usec / 1000);
    nthreads=atol(argv[1]); // принять аргумент 
    ids=malloc(nthreads*sizeof(pthread_t)); 
    for(i=0; i< nthreads; i++) { 
            pthread_create(ids+i, NULL, calculate, NULL); 
    }
    for(i=0; i<nthreads; i++) { // (барьер) 
            pthread_join(ids[i], NULL); //ожид. и запись в res
    }
    gettimeofday(&end_time, NULL);
	  printf("time sec: %ld | time microsec %ld | RES: %ld\n", end_time.tv_sec - start_time.tv_sec, end_time.tv_usec - start_time.tv_usec, end_time.tv_sec * 1000 + end_time.tv_usec / 1000);
    printf ("Результат sum = %d\n", sum);
}