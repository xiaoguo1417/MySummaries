#include "MyQThread.h"

MyQThread::MyQThread(QObject* parent) : QThread(parent)
{

}

void MyQThread::run()
{
    for (int i = 0; i <= 30; i++)//ģ���ʱ����
    {
        QThread::msleep(50);
    }
    emit sig_down();
}