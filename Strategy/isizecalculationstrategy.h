#ifndef ISIZECALCULATIONSTRATEGY_H
#define ISIZECALCULATIONSTRATEGY_H

#include <QString>


// Интерфейс стратегии для расчета размера директории
class ISizeCalculationStrategy {
public:
    virtual ~ISizeCalculationStrategy() = default;
    // Чисто виртуальный метод для реализации разных стратегий
    virtual void calculate(const QString& path) = 0;
};

#endif // ISIZECALCULATIONSTRATEGY_H
