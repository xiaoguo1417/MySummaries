#include "MyWorkRunnable.h"

MyWorkRunnable::~MyWorkRunnable()
{

}

void MyWorkRunnable::run()
{
    qDebug() << "子线程对象的地址: " << QThread::currentThread();
    int num = 0;
    while (1)
    {
        emit sig_time(++num);
        qDebug() << num << "\n";
        if (num == 99)
        {
            break;
        }
        QThread::sleep(1);
    }
}