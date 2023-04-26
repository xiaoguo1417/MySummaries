#pragma once
#include <QObject>
#include <QThread>
#include <QDebug>

class MyWork : public QObject
{
	Q_OBJECT

public:
	explicit MyWork(QObject* parent = nullptr);
	//¹¤×÷º¯Êý
	void working();

signals:
	void sig_time(int num);

};

