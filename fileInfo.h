#ifndef FILEINFO_H
#define FILEINFO_H

#include <QString>
#include <QFileInfo>

class FileInfo
{
private:
    QString path;//путь к файлу
    int size;//размер файла
    bool isExistence;//флаг существования файла
public:
    FileInfo(const QString& filePath);//конструктор
    QString getPath() const;//получение пути к файлу
    int getSize() const;//получение размера файла
    bool getExistence() const;//получение флага существования файла
    void setExistence(bool existence);//установка существования файла
    void setSize(int newSize);//установка размера файла
};

#endif // FILEINFO_H
