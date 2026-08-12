#ifndef PTHREAD_H
#define PTHREAD_H

// pthread wrapper for Windows by Shadowdara under MIT License 27.07.2026

#include <windows.h>
#include <process.h>
#include <time.h>

typedef HANDLE pthread_t;

typedef CRITICAL_SECTION pthread_mutex_t;

typedef CONDITION_VARIABLE pthread_cond_t;

typedef struct {
    int dummy;
} pthread_attr_t;


#define PTHREAD_MUTEX_INITIALIZER {0}

#define PTHREAD_CREATE_DETACHED 1


static inline int pthread_mutex_init(
    pthread_mutex_t *m,
    void *attr)
{
    InitializeCriticalSection(m);
    return 0;
}


static inline int pthread_mutex_lock(
    pthread_mutex_t *m)
{
    EnterCriticalSection(m);
    return 0;
}


static inline int pthread_mutex_unlock(
    pthread_mutex_t *m)
{
    LeaveCriticalSection(m);
    return 0;
}


static inline int pthread_mutex_destroy(
    pthread_mutex_t *m)
{
    DeleteCriticalSection(m);
    return 0;
}


static inline int pthread_cond_init(
    pthread_cond_t *c,
    void *attr)
{
    InitializeConditionVariable(c);
    return 0;
}


static inline int pthread_cond_wait(
    pthread_cond_t *c,
    pthread_mutex_t *m)
{
    SleepConditionVariableCS(c, m, INFINITE);
    return 0;
}


static inline int pthread_cond_signal(
    pthread_cond_t *c)
{
    WakeConditionVariable(c);
    return 0;
}


static inline int pthread_cond_destroy(
    pthread_cond_t *c)
{
    return 0;
}


static inline int pthread_create(
    pthread_t *thread,
    pthread_attr_t *attr,
    void *(*func)(void *),
    void *arg)
{
    *thread = (HANDLE)_beginthreadex(
        NULL,
        0,
        (unsigned (__stdcall *)(void *))func,
        arg,
        0,
        NULL
    );

    return (*thread != NULL) ? 0 : -1;
}


static inline int pthread_attr_init(
    pthread_attr_t *attr)
{
    return 0;
}


static inline int pthread_attr_setdetachstate(
    pthread_attr_t *attr,
    int state)
{
    return 0;
}


static inline int pthread_attr_destroy(
    pthread_attr_t *attr)
{
    return 0;
}


static inline int pthread_cond_timedwait(
    pthread_cond_t *cond,
    pthread_mutex_t *mutex,
    const struct timespec *ts)
{
    SleepConditionVariableCS(
        cond,
        mutex,
        INFINITE
    );

    return 0;
}

#define CLOCK_REALTIME 0

static inline int clock_gettime(
    int clk,
    struct timespec *ts)
{
    timespec_get(ts, TIME_UTC);
    return 0;
}


#endif
