#ifndef LOGGER_H
#define LOGGER_H
#include <QObject>
#include <QDebug>

class Logger : public QObject
{
    Q_OBJECT
public slots:
    void logFileCreated(const QString& path, int size); // Слот для логирования создания файла
    void logFileDeleted(const QString& path); // Слот для логирования удаления файла
    void logFileSizeChanged(const QString& path, int size); // Слот для логирования изменения размера файла
};


#endif // LOGGER_H
