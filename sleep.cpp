#include "sleep.h"

#include <QWaitCondition>
#include <QMutex>


Sleeper::Sleeper(){

}

// Causes the current thread to sleep for msecs milliseconds.
void Sleeper::msleep(unsigned long msecs)
{
    QMutex mutex;
    mutex.lock();

    QWaitCondition waitCondition;
    waitCondition.wait(&mutex, msecs);

    mutex.unlock();
}
