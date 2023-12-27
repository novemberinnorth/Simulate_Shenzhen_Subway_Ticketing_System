#include "welcome.h"
#include<QImageReader>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QImageReader::setAllocationLimit(500);
    Welcome w;
    w.show();
    return a.exec();
}
