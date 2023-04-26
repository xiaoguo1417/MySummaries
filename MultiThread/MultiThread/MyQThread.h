#pragma once

#include <QThread>

class MyQThread :
    public QThread
{
    Q_OBJECT
public:
    explicit MyQThread(QObject* parent = nullptr);

protected:
    void run() override;

signals:
    void sig_down();
};

