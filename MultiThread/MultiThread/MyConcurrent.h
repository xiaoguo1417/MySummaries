#pragma once
#include <QObject>
#include <QThread>
#include <QDebug>

//�����Զ�����������
struct myData 
{
	int test = 2;
};

class MyConcurrent : public QObject
{
	Q_OBJECT
public:
	myData work();

signals:
	void sig_time(int);
	void sig_finished();
};

