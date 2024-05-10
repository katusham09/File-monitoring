#include "fileInfo.h"
#include "manager.h"
#include "logger.h"
#include <QApplication>
#include <QTimer>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Manager manager;
    Logger logger;

    manager.addFile("C:/file/file1.txt");
    manager.addFile("C:/file/file2.txt");

    manager.connectLogger(logger);

    return a.exec();
}
