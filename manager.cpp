#include "manager.h"

Manager::Manager()
{
    // Подключаем сигнал таймера timeout к слоту checkChanges() этого объекта Manager
    // Это означает, что метод checkChanges() будет вызываться каждый раз по истечении заданного времени (1000 миллисекунд, т.е. 1 секунда)
    connect(&timer, &QTimer::timeout, this, &Manager::checkChanges);

    // Начинаем таймер с интервалом 1000 миллисекунд (1 секунда)
    timer.start(1000); // Устанавливаем интервал в 1 секунду для мониторинга
}

// Метод для проверки изменений в файлах
void Manager::checkChanges()
{
    // Перебираем все файлы в векторе files и проверяем изменения
    for (int i = 0; i < files.size(); ++i)
    {
        FileInfo& file = files[i]; // Получаем ссылку на текущий файл
        QFileInfo fileInfo(file.getPath()); // Создаем объект QFileInfo для работы с файлом

        // Если существование файла изменилось (файл создан или удален)
        if (fileInfo.exists() != file.getExistence())
        {
            file.setExistence(fileInfo.exists()); // Обновляем существование файла

            // Если файл снова существует, обновляем его размер и вызываем сигнал о создании файла
            if (fileInfo.exists())
            {
                file.setSize(fileInfo.size());
                emit fileCreated(file.getPath(), fileInfo.size());
            }
            // Если файл больше не существует, вызываем сигнал об удалении файла
            else {
                emit fileDeleted(file.getPath()); // Вызываем сигнал об удалении файла
            }
        }
        // Если файл существует и его размер изменился
        else
        {
            if (fileInfo.exists() && fileInfo.size() != file.getSize())
            {
                file.setSize(fileInfo.size());
                emit fileSizeChanged(file.getPath(), fileInfo.size()); // Вызываем сигнал об изменении размера файла
            }
        }
    }
}

// Метод для добавления нового файла в вектор files
void Manager::addFile(const QString& path)
{
    files.push_back(FileInfo(path));
}

// Метод для удаления файла из вектора files
void Manager::deleteFile(const QString& path)
{
    // Ищем файл с указанным путем в векторе и удаляем его, если он найден
    for (int i = 0; i < files.size(); ++i)
    {
        if (files[i].getPath() == path)
        {
            files.remove(i);
            emit fileDeleted(path); // Вызываем сигнал об удалении файла
            break; // Прерываем цикл, так как файл найден и удален
        }
    }
}
