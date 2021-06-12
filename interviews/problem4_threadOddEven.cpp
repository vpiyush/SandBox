#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int MAX = 10;
int count = 0;

void *even(void *arg)
{
    printf("This is even thread()\n");
/*    while(count < MAX)
        if(count % 2 == 0)
            printf("%d ", count++);
    pthread_exit(0);
    */
}

void *odd(void *arg)
{
    printf("This is odd thread()\n");
    /*
    while(count < MAX)
        if(count % 2 == 1)
            printf("%d ", count++);
    pthread_exit(0);
    */
}

int main()
{
    pthread_t t1;
    pthread_t t2;

    pthread_create(&t1, 0, &even, NULL);
    pthread_create(&t2, 0, &odd, NULL);

    pthread_join(t1, 0);
    pthread_join(t2, 0);

    return  0;
}
