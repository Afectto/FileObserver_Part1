#include "filetypestrategy.h"
#include <QDir>
#include <QMap>
#include <QFileInfoList>
#include <QDebug>

std::vector<QPair<QString, QString>> FileTypeStrategy::calculate(const QString &path)
{
    QDir dir(path);
    if (!dir.exists()) {
        qWarning() << "Directory does not exist.";
        return {};
    }

    QMap<QString, qint64> sizeMap;
    qint64 totalSize = 0;

    QFileInfoList list = dir.entryInfoList(QDir::NoDotAndDotDot | QDir::AllEntries);
    for (const QFileInfo& fileInfo : list) {
        if (fileInfo.isFile()) {
            QString fileType = fileInfo.suffix().isEmpty() ? "[No Extension]" : "*." + fileInfo.suffix();
            sizeMap[fileType] += fileInfo.size();
            totalSize += fileInfo.size();
        } else if (fileInfo.isDir()) {
            qint64 dirSize = calculateDirectorySize(fileInfo.absoluteFilePath());
            sizeMap["[DIR] " + fileInfo.fileName()] += dirSize;
            totalSize += dirSize;
        }
    }

    if (totalSize == 0) {
        qInfo() << "Directory is empty.";
        return {};
    }

    std::vector<QPair<QString, QString>> displayList;
    for (auto it = sizeMap.constBegin(); it != sizeMap.constEnd(); ++it) {
        double percentage = static_cast<double>(it.value()) / totalSize * 100;
        QString percentageStr = QString::number(percentage, 'f', 2) + "%";
        displayList.emplace_back(it.key(), percentageStr);
    }

    return displayList;
}

qint64 FileTypeStrategy::calculateDirectorySize(const QString &path)
{
    qint64 size = 0;
    QDir dir(path);
    QFileInfoList list = dir.entryInfoList(QDir::NoDotAndDotDot | QDir::AllEntries);
    for (const QFileInfo& fileInfo : list) {
        if (fileInfo.isFile()) {
            size += fileInfo.size();
        } else if (fileInfo.isDir()) {
            size += calculateDirectorySize(fileInfo.absoluteFilePath());
        }
    }
    return size;
}
