#include "MyConcurrent.h"

myData MyConcurrent::work()
{
    qDebug() << "Concurrent���̶߳���ĵ�ַ: " << QThread::currentThread();
    int num = 0;
    while (1)
    {
        emit sig_time(++num);
        qDebug() << num << "\n";
        if (num == 10)
        {
            break;
        }
        QThread::sleep(1);
    }
    emit sig_finished();
    myData m;
    m.test = 1;
    return m;
}