#ifndef BASESIZECALCULATIONSTRATEGY_H
#define BASESIZECALCULATIONSTRATEGY_H

#include <QMap>
#include "isizecalculationstrategy.h"

class BaseSizeCalculationStrategy : public ISizeCalculationStrategy {
public:

    // Оставляем чисто виртуальный метод, чтобы класс стал абстрактным
    virtual std::vector<QPair<QString, QString>> calculate(const QString &path) = 0;

protected:

    qint64 calculateSize(const QString &path);
    std::vector<QPair<QString, QString>> calculatePercentage(const QMap<QString, qint64>& sizeMap, qint64 totalSize);

};
#endif // BASESIZECALCULATIONSTRATEGY_H
