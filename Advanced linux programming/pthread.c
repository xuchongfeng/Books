#include <pthread.h>
pthread_create(pthread_t &,pthread_attr_t,(void *)(*)(void *),(void *));
pthread_join(pthread_t,(void *));

atomic operation: indivisible and uninterruptible


1 critical sections;
2 mutex;
3 semaphore;
4 condition variables;
