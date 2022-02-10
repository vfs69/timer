#ifndef MYWINDOW_H
#define MYWINDOW_H

#include<QObject>
#include<QWidget>
#include<QLineEdit>
#include<QPushButton>
#include <QLCDNumber>
#include <QTimer>
#include <QRadioButton>

class MyWindow : public QWidget
{
    Q_OBJECT
private:
    QLCDNumber *lcd;
    QTimer *timer;
    QPushButton *btnStart;
    QLineEdit *edt;
    QRadioButton *btnUp;
    QRadioButton *btnDown;
    int second;

public:
     explicit MyWindow(QWidget *parent = nullptr);
public slots:
    void time();
    void start();
    void change(QString);
};

#endif // MYWINDOW_H
