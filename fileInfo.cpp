#include "fileInfo.h"

FileInfo::FileInfo(const QString& filePath)
{
    path = filePath;
    QFileInfo file(path);
    if (file.exists())
    {
        size = file.size();
        existence = true;
    }
}

QString FileInfo::getPath() const
{
    return path;
}

int FileInfo::getSize() const
{
    return size;
}
