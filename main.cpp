#include <QCoreApplication>
#include <QDir>
#include <QFileInfoList>
#include <QTextStream>
#include <QMap>
#include <QFileInfo>
#include <fcntl.h>

#include "directorysizecalculator.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    _setmode(_fileno(stdout), _O_U16TEXT);
    setlocale(LC_ALL, "Russian");

    DirectorySizeCalculator calculator;
    calculator.run();

    return 0;
}
