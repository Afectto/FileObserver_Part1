#include "fileliststrategy.h"


void FileListStrategy::calculate(const QString &path) {
    QDir dir(path);
    if (!dir.exists()) {
        qWarning() << "Directory does not exist.";
        return;
    }
    qInfo() << "Scanning directory: " << path;
    scanDirectory(dir, 0);
}

void FileListStrategy::scanDirectory(const QDir &dir, int level) {
    QFileInfoList list = dir.entryInfoList(QDir::NoDotAndDotDot | QDir::AllEntries);
    //Идем по всем обьектам в указаной директории
    for (const QFileInfo& fileInfo : list) {
        QString indent = QString("  ").repeated(level);
        //Вывели что это (папка/Файл) и его имя
        qInfo() << indent << (fileInfo.isDir() ? "[DIR]" : "[FILE]") << fileInfo.fileName();
        //Если найли папку рекурсивно заходим в неё и показываем её содержимое
        if (fileInfo.isDir()) {
            scanDirectory(QDir(fileInfo.absoluteFilePath()), level + 1);
        }
    }
}
