#ifndef FILELISTSTRATEGY_H
#define FILELISTSTRATEGY_H

#include "isizecalculationstrategy.h"

#include <QDir>

// Стратегия вывода списка файлов и папок верхнего уровня
class FileListStrategy : public ISizeCalculationStrategy
{
public:
    void calculate(const QString& path) override;

private:
    //Рекурсивно проходим по всем обьекам внитри пути
    void scanDirectory(const QDir& dir, int level);
};

#endif // FILELISTSTRATEGY_H
