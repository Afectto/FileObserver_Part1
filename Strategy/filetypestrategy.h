#ifndef FILETYPESTRATEGY_H
#define FILETYPESTRATEGY_H

#include "basesizecalculationstrategy.h"

#include <QDir>

class FileTypeStrategy : public BaseSizeCalculationStrategy {
public:
    std::vector<QPair<QString, QString>> calculate(const QString &path) override;
};

#endif // FILETYPESTRATEGY_H
