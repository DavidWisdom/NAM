#include "MainWindow.h"
#include <QtWidgets/QApplication>
#include<QDesktopWidget>

int main(int argc, char *argv[])
{
#if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif 
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.move((a.desktop()->width() - w.width()) / 2 , (a.desktop()->height() - w.height()) / 2 + 95);
    return a.exec();
}
