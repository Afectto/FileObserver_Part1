#include "filetypestrategy.h"

void FileTypeStrategy::calculate(const QString &path) {
    QDir dir(path);
    if (!dir.exists()) {
        qWarning() << "Directory does not exist.";
        return;
    }
    qInfo() << "Calculating sizes in directory: " << path;

    QMap<QString, qint64> sizeMap;
    qint64 totalSize = 0;

    //Собрали все файлы и папки по указаному пути
    QFileInfoList list = dir.entryInfoList(QDir::NoDotAndDotDot | QDir::AllEntries);
    for (const QFileInfo& fileInfo : list) {
        if (fileInfo.isFile()) {
            //Нашли файл, добавили его размер в мапу по ключу типа
            QString fileType = fileInfo.suffix().isEmpty() ? "[No Extension]" : "[FILE] *." + fileInfo.suffix();
            sizeMap[fileType] += fileInfo.size();
            totalSize += fileInfo.size();
        } else if (fileInfo.isDir()) {
            //Нашли директорию и посчитали её полный размер
            qint64 dirSize = calculateDirectorySize(fileInfo.absoluteFilePath());
            sizeMap["[DIR] " + fileInfo.fileName()] += dirSize;
            totalSize += dirSize;
        }
    }

    //Ничего не нашли (директория пуста)
    if (totalSize == 0) {
        qInfo() << "Directory is empty.";
        return;
    }

    //Иначе прошли по мапе, посчитали процентное соотножение обьекта с общим весом директории
    for (auto it = sizeMap.constBegin(); it != sizeMap.constEnd(); ++it) {
        double percentage = static_cast<double>(it.value()) / totalSize * 100;
        QString percentageStr = (percentage < 0.01 && it.value() > 0) ? "< 0.01%" : QString::number(percentage, 'f', 2) + "%";
        qInfo() << it.key() << ":" << percentageStr;
    }
}

qint64 FileTypeStrategy::calculateDirectorySize(const QString &path) {
    qint64 size = 0;
    QDir dir(path);
    QFileInfoList list = dir.entryInfoList(QDir::NoDotAndDotDot | QDir::AllEntries);
    for (const QFileInfo& fileInfo : list) {
        if (fileInfo.isFile()) {
            //Нашли файл, добавили его вес
            size += fileInfo.size();
        } else if (fileInfo.isDir()) {
            //Нашли ещё 1 вложеную папку, пошли считать её вес рекурсивно
            size += calculateDirectorySize(fileInfo.absoluteFilePath());
        }
    }
    //Вернули общий вес текушей папки
    return size;
}

