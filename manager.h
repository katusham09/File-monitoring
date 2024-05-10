#ifndef MANAGER_H
#define MANAGER_H
#include <QObject>
#include <QMap>
#include <QTimer>
#include "fileInfo.h"
#include "logger.h"

class Manager : public QObject
{
    Q_OBJECT // Макрос для поддержки сигналов и слотов в Qt

public:
    Manager(); // Конструктор класса
    void addFile(const QString& path); // Метод для добавления файла в список отслеживаемых файлов
    void deleteFile(const QString& path); // Метод для удаления файла из списка отслеживаемых файлов
    void checkChanges(); // Метод для проверки изменений в отслеживаемых файлах

private:
    QVector<FileInfo> files; // Вектор для хранения информации о файлах
    QTimer timer; // Таймер для периодической проверки изменений в файлах
signals:
    void fileSizeChanged(const QString& path, int size); // Сигнал об изменении размера файла
    void fileCreated(const QString& path, int size); // Сигнал о создании файла
    void fileDeleted(const QString& path); // Сигнал об удалении файла
};


#endif // MANAGER_H
