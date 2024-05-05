#include "fileInfo.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    files w;
    w.show();
    return a.exec();
}
