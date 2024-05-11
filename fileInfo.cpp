#include "fileInfo.h"

FileInfo::FileInfo(const QString& filePath)
{
    path = filePath; // Устанавливаем путь к файлу из переданного параметра filePath
    QFileInfo file(path); // Создаем объект QFileInfo для работы с файлом
    isExistence = file.exists(); // Устанавливаем флаг существования файла

    if (isExistence)
    {
        size = file.size(); // Если файл существует, устанавливаем его размер
    }
    else
    {
        size = 0; // Если файл не существует, устанавливаем размер файла в 0
    }
}

QString FileInfo::getPath() const
{
    return path; // Возвращаем путь к файлу
}

int FileInfo::getSize() const
{
    return size; // Возвращаем размер файла
}

bool FileInfo::getExistence() const
{
    return isExistence; // Возвращаем флаг существования файла
}

void FileInfo::update()//Обновление размера и флага существования файла
{
    QFileInfo file(path);
    isExistence = file.exists();
    size = file.size();
}
