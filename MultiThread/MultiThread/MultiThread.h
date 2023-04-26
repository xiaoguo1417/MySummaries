#pragma once

#include <QtWidgets/QWidget>
#include <QElapsedTimer>
#include <QDebug>
#include <QThreadPool>
#include <QtConcurrent>
#include "ui_MultiThread.h"
#include "MyQThread.h"
#include "MyWork.h"
#include "MyWorkRunnable.h"
#include "MyConcurrent.h"

class MultiThread : public QWidget
{
    Q_OBJECT

public:
    MultiThread(QWidget *parent = nullptr);
    ~MultiThread();
    void thiswork();

private:
    Ui::MultiThreadClass ui;
    MyQThread* myqthread;
    QElapsedTimer timer;
    int threadCnt;
    MyWork* work;
    QThread* sub;

    MyQThread* myqthread1;
    MyQThread* myqthread2;
    MyQThread* myqthread3;

    QFuture<myData> future;

private slots:
    void OnBtStart1Clicked();
    void OnBtStart2Clicked();
    void OnSigEndReceived();
    void OnSigEndReceived1();
    void OnSigEndReceived2();
    void OnSigEndReceived3();

    void OnBtThread1Clicked();
    void OnBtThread2Clicked();
    void OnBtThread3Clicked();

    void OnSigReceived1(int);
    void OnSigFinished();
};
