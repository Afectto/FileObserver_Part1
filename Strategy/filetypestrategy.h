#ifndef FILETYPESTRATEGY_H
#define FILETYPESTRATEGY_H

#include "isizecalculationstrategy.h"

#include <QDir>

class FileTypeStrategy : public ISizeCalculationStrategy
{
public:
    void calculate(const QString& path) override;

private:
    //Считает размер файлов которые лежат в папке, которая лежит в директории указаной в calculate
    qint64 calculateDirectorySize(const QString& path);
};

#endif // FILETYPESTRATEGY_H
