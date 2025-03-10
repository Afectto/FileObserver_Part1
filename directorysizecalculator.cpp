#include "directorysizecalculator.h"

void DirectorySizeCalculator::run() {
    QTextStream qin(stdin);
    QString path;
    bool continueProgram = true;

    while (continueProgram) {
        path = requestDirectoryPath(qin, path);
        ISizeCalculationStrategy* strategy = selectStrategy(qin);

        if (strategy) {
            strategy->calculate(path);
            delete strategy;
        }

        qDebug() << "Хотите выполнить ещё одну операцию? (y/n):";
        continueProgram = (qin.readLine().trimmed().toLower() == "y");
    }
}

QString DirectorySizeCalculator::requestDirectoryPath(QTextStream &qin, const QString &currentPath) {
    QString path = currentPath;
    bool validPath = false;

    if (!path.isEmpty()) {
        qDebug() << "Текущий путь: " << path;
        qDebug() << "Хотите изменить директорию? (y/n):";
        if (qin.readLine().trimmed().toLower() == "y") {
            QString newPath;
            return requestDirectoryPath(qin, newPath);
        }
        else {
            return path;
        }
    }

    while (!validPath) {
        qDebug() << "Введите путь к директории: ";
        path = qin.readLine().trimmed();

        if (QDir(path).exists()) {
            validPath = true;
        } else {
            qWarning() << "Директория не существует. Попробуйте снова.";
        }
    }

    return path;
}

ISizeCalculationStrategy *DirectorySizeCalculator::selectStrategy(QTextStream &qin) {
    ISizeCalculationStrategy* strategy = nullptr;
    while (!strategy) {
        qDebug() << "Выберите стратегию (1 - Список файлов, 2 - Типы файлов)";
        int strategyChoice = qin.readLine().trimmed().toInt();

        switch (strategyChoice) {
        case 1:
            strategy = new FileListStrategy();
            break;
        case 2:
            strategy = new FileTypeStrategy();
            break;
        default:
            qWarning() << "Неверный выбор стратегии. Пожалуйста, выберите корректную стратегию.";
            break;
        }
    }

    return strategy;
}
