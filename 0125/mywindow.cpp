#include "mywindow.h"

MyWindow::MyWindow(QWidget *parent) : QWidget(parent)
{
    this->setGeometry(20,30,400,300);

    lcd = new QLCDNumber(this);
    lcd->setGeometry(50,50,200,30);


    btnStart = new QPushButton(this);
    btnStart ->setGeometry(200,100,100,30);
    btnStart->setText("Старт");

    edt = new QLineEdit(this);
    edt->setGeometry(100,10,100,30);

    btnUp = new QRadioButton(this);
    btnUp->setGeometry(10,300,200,30);
    btnUp->setText("Прямой");
    btnUp->setChecked(true);

    btnDown = new QRadioButton(this);
    btnDown->setGeometry(200,300,200,30);
    btnDown->setText("Обратимый");


    timer = new QTimer(this);
    timer->setInterval(1000);

    second = 0;

   connect(btnStart, SIGNAL(pressed()),this, SLOT(start()));
   connect(timer, SIGNAL(timeout()), this, SLOT(time()));
   connect(edt, SIGNAL(textEdited(QString)), this, SLOT(change(QString)));

}

void MyWindow::time(){
    if(btnUp->isChecked()){
    second++;
    }
    else {
        second--;
    }
    lcd->display(second);

}

void MyWindow::start() {
    if (timer->isActive()){
        timer->stop();
        btnStart->setText("Старт");
    }

    else {
        timer->start();
        btnStart->setText("Стоп");
}
}

void MyWindow::change(QString newText) {
    timer->stop();

    btnStart->setText("Старт");

    second = newText.toInt();
    lcd->display(second);
}





