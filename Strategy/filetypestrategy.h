#ifndef FILETYPESTRATEGY_H
#define FILETYPESTRATEGY_H

#include "isizecalculationstrategy.h"

#include <QDir>

class FileTypeStrategy : public ISizeCalculationStrategy {
public:
    std::vector<QPair<QString, QString>> calculate(const QString &path) override;

private:
    qint64 calculateDirectorySize(const QString &path);
};
#endif // FILETYPESTRATEGY_H
