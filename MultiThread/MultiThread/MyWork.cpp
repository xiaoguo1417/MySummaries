#include "MyWork.h"

MyWork::MyWork(QObject* parent) : QObject(parent)
{

}

void MyWork::working()
{
    qDebug() << "���̶߳���ĵ�ַ: " << QThread::currentThread();
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