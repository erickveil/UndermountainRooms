#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);
    /*
    QFont font = qApp->font();
    font.setPixelSize(11);
    qApp->setFont(font);
    */
    MainWindow w;
    w.show();

    return a.exec();
}
