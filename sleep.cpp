#include "sleep.h"

#include <QWaitCondition>
#include <QMutex>


Sleep::Sleep(){

}

// Causes the current thread to sleep for msecs milliseconds.
void Sleep::msleep(unsigned long msecs)
{
    QMutex mutex;
    mutex.lock();

    QWaitCondition waitCondition;
    waitCondition.wait(&mutex, msecs);

    mutex.unlock();
}
