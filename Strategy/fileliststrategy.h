#ifndef FILELISTSTRATEGY_H
#define FILELISTSTRATEGY_H

#include "basesizecalculationstrategy.h"

#include <QDir>

// Стратегия вывода списка файлов и папок верхнего уровня
class FileListStrategy : public BaseSizeCalculationStrategy {
public:
    std::vector<QPair<QString, QString>> calculate(const QString &path) override;
};

#endif // FILELISTSTRATEGY_H
