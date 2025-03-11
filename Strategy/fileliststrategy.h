#ifndef FILELISTSTRATEGY_H
#define FILELISTSTRATEGY_H

#include "isizecalculationstrategy.h"

#include <QDir>

// Стратегия вывода списка файлов и папок верхнего уровня
class FileListStrategy : public ISizeCalculationStrategy {
public:
    std::vector<QPair<QString, QString>> calculate(const QString &path) override;

private:
    void scanDirectory(const QDir &dir, std::vector<QPair<QString, QString>> &dataList, int level = 0);
};

#endif // FILELISTSTRATEGY_H
