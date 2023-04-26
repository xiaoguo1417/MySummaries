#pragma once
#include <QObject>
#include <QThread>
#include <QDebug>

//测试自定义数据类型
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

