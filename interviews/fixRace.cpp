#include <iostream>
#include <assert.h>
#include <pthread.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

static int
s_random_int( int max)
{
    return rand() / ( RAND_MAX + 1.0) * max;
}

static int  s_value = 0;

static pthread_mutex_t  s_mutex = PTHREAD_MUTEX_INITIALIZER;

static void*
s_threadfn( void*)
{
    for ( int it=0;; ++it)
    {
        pthread_mutex_lock( &s_mutex);
        if ( it % (10*1000) == 0)
        {
            std::cout << __FUNCTION__ << ": it=" << it << "\n";
        }
        int old_value = s_value;
        int a = s_random_int( 5);
        s_value += a;
        assert( s_value == old_value + a);
        pthread_mutex_unlock( &s_mutex);
    }
    return NULL;
}

static void*
s_threadfn2( void*)
{
    for ( int it=0;; ++it)
    {
        if ( it % (100) == 0)
        {
            std::cout << __FUNCTION__ << ": it=" << it << "\n";
        }
        s_value += 1;
        usleep(10*1000);
    }
    return NULL;
}

int
main()
{
    pthread_t   t1;
    pthread_t   t2;
    pthread_t   t3;
    pthread_create( &t1, NULL, s_threadfn, NULL);
    pthread_create( &t2, NULL, s_threadfn, NULL);
    pthread_create( &t3, NULL, s_threadfn2, NULL);

    pthread_join( t1, NULL);
    pthread_join( t2, NULL);
    pthread_join( t3, NULL);

    return 0;
}
