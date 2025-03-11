#include "fileliststrategy.h"


std::vector<QPair<QString, QString>> FileListStrategy::calculate(const QString &path)
{
    QDir dir(path);
    if (!dir.exists()) {
        qWarning() << "Directory does not exist.";
        return {};
    }

    qInfo() << "Scanning directory: " << path;
    std::vector<QPair<QString, QString>> dataList;
    scanDirectory(dir, dataList);
    return dataList;
}

void FileListStrategy::scanDirectory(const QDir &dir, std::vector<QPair<QString, QString>> &dataList, int level)
{
    QFileInfoList list = dir.entryInfoList(QDir::NoDotAndDotDot | QDir::AllEntries);
    for (const QFileInfo& fileInfo : list) {
        QString type = fileInfo.isDir() ? "[DIR]" : "[FILE]";
        dataList.emplace_back(type + " " + fileInfo.fileName(), "N/A");

        if (fileInfo.isDir()) {
            scanDirectory(QDir(fileInfo.absoluteFilePath()), dataList, level + 1);
        }
    }
}
