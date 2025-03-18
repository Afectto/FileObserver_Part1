#ifndef DIRECTORYSIZECALCULATOR_H
#define DIRECTORYSIZECALCULATOR_H
#include <QCoreApplication>
#include <QTextStream>
#include <QDebug>
#include <QDir>
#include <QFileInfo>
#include <fcntl.h>
#include <io.h>
#include "Strategy/ISizeCalculationStrategy.h"
#include "Strategy/FileListStrategy.h"
#include "Strategy/FileTypeStrategy.h"

class DirectorySizeCalculator {
public:
    void run();

private:
    QString requestDirectoryPath(QTextStream& qin, const QString& currentPath);

    ISizeCalculationStrategy* selectStrategy(QTextStream& qin);
};

#endif // DIRECTORYSIZECALCULATOR_H
