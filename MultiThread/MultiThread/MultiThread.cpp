#include "MultiThread.h"

MultiThread::MultiThread(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    myqthread = new MyQThread;
    threadCnt = 0;

    myqthread1 = new MyQThread;
    myqthread2 = new MyQThread;
    myqthread3 = new MyQThread;

    sub = new QThread;
    work = new MyWork;
    work->moveToThread(sub);
    sub->start();
    //connect(ui.bt_thread1, SIGNAL(clicked()), this, SLOT(OnBtThread1Clicked()));
    connect(ui.bt_thread1, &QPushButton::clicked, work, &MyWork::working);//只能通过主线程的信号开启子线程的函数，直接使用work对象调用working函数不行
    connect(work, SIGNAL(sig_time(int)), this, SLOT(OnSigReceived1(int)));
   

    connect(ui.bt_start1, SIGNAL(clicked()), this, SLOT(OnBtStart1Clicked()));
    connect(ui.bt_start2, SIGNAL(clicked()), this, SLOT(OnBtStart2Clicked()));
    connect(myqthread, SIGNAL(sig_down()), this, SLOT(OnSigEndReceived()));
    connect(myqthread1, SIGNAL(sig_down()), this, SLOT(OnSigEndReceived1()));
    connect(myqthread2, SIGNAL(sig_down()), this, SLOT(OnSigEndReceived2()));
    connect(myqthread3, SIGNAL(sig_down()), this, SLOT(OnSigEndReceived3()));

    
    connect(ui.bt_thread2, SIGNAL(clicked()), this, SLOT(OnBtThread2Clicked()));
    connect(ui.bt_thread3, SIGNAL(clicked()), this, SLOT(OnBtThread3Clicked()));
}

MultiThread::~MultiThread()
{}

void MultiThread::OnBtStart1Clicked()
{
    timer.start();
    myqthread->start();
}

void MultiThread::OnBtStart2Clicked()
{
    timer.start();
    myqthread1->start();
    myqthread2->start();
    myqthread3->start();
}

void MultiThread::OnSigEndReceived()
{
    int t = timer.elapsed();
    ui.lineEdit_1->setText(QString::number(t));
}

void MultiThread::OnSigEndReceived1()
{
    threadCnt++;
    if (threadCnt == 3)
    {
        int t = timer.elapsed();
        ui.lineEdit_2->setText(QString::number(t));
    }
}
void MultiThread::OnSigEndReceived2()
{
    threadCnt++;
    if (threadCnt == 3)
    {
        int t = timer.elapsed();
        ui.lineEdit_2->setText(QString::number(t));
    }
}

void MultiThread::OnSigEndReceived3()
{
    threadCnt++;
    if (threadCnt == 3)
    {
        int t = timer.elapsed();
        ui.lineEdit_2->setText(QString::number(t));
    }
}

void MultiThread::OnBtThread1Clicked()
{
    qDebug() << "主线程对象的地址: " << QThread::currentThread();
    work->working();
}

void MultiThread::OnSigReceived1(int num)
{
    QString strTime = num < 10 ? "0" + QString::number(num) : QString::number(num);
    ui.label_time->setText(strTime);
    qDebug() << strTime << "\n";
}

void MultiThread::OnBtThread2Clicked()
{
    // 线程池初始化，设置最大线程池数
    QThreadPool::globalInstance()->setMaxThreadCount(4);
    // 添加任务
    MyWorkRunnable* task = new MyWorkRunnable;
    QThreadPool::globalInstance()->start(task);
    connect(task, SIGNAL(sig_time(int)), this, SLOT(OnSigReceived1(int)));
}

void MultiThread::OnBtThread3Clicked()
{
    qDebug() << "主线程对象的地址: " << QThread::currentThread();
    MyConcurrent* mythread3 = new MyConcurrent;
    connect(mythread3, SIGNAL(sig_time(int)), this, SLOT(OnSigReceived1(int)));
    connect(mythread3, SIGNAL(sig_finished()), this, SLOT(OnSigFinished()));
    future = QtConcurrent::run(mythread3, &MyConcurrent::work);
    //future.waitForFinished();
}

void MultiThread::thiswork()
{
    qDebug() << "子线程对象的地址: " << QThread::currentThread();
    int num = 0;
    while (1)
    {
        qDebug() << num << "\n";
        if (num == 99)
        {
            break;
        }
        QThread::sleep(1);
    }
}

void MultiThread::OnSigFinished()
{
    if (future.isFinished())
    {
        myData&& m = future.result();
    }    
}