#include "logger.h"
#include <qdebug.h>

// Слот для логирования создания файла
void Logger::logFileCreated(const QString& path, int size)
{
    qDebug() << "File created: " << path << ", size: " << size;
}

// Слот для логирования удаления файла
void Logger::logFileDeleted(const QString& path)
{
    qDebug() << "File deleted: " << path;
}

// Слот для логирования изменения размера файла
void Logger::logFileSizeChanged(const QString& path, int size)
{
    qDebug() << "File size changed: " << path << ", new size: " << size;
}
