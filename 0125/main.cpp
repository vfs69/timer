#include <QApplication>
#include "mywindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
MyWindow *x = new MyWindow();
x->show();

    return a.exec();
}
