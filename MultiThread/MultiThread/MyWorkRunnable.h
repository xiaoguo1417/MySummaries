#pragma once

#include <QObject>
#include <QRunnable>
#include <QThread>
#include <Qdebug>

class MyWorkRunnable : public QObject , public QRunnable
{
    Q_OBJECT
public:
    explicit MyWorkRunnable(QObject* parent = nullptr)
    {
        // 任务执行完毕,该对象自动销毁
        setAutoDelete(true);
    }
    ~MyWorkRunnable();

    void run() override;

signals:
    void sig_time(int);
};

