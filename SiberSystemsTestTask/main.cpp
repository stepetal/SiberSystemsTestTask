#include <QCoreApplication>
#include <QDebug>
#include "threelistclass.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int list_2[] = {1,8,15,16,35,80,91};
    int list_1[] = {2,7,12,40,54};
    int list_3[] = {10,13,14,17};
    int list_1_size = sizeof(list_1) / sizeof(list_1[0]);
    int list_2_size = sizeof(list_2) / sizeof(list_2[0]);
    int list_3_size = sizeof(list_3) / sizeof(list_3[0]);
    ThreeListClass tlc(list_1, list_1_size, list_2, list_2_size, list_3, list_3_size);
    qDebug() << tlc.getNext();
    qDebug() << tlc.getNext();
    qDebug() << tlc.getNext();
    qDebug() << tlc.getNext();
    qDebug() << tlc.getNext();
    qDebug() << tlc.getNext();
    qDebug() << tlc.getNext();
    qDebug() << tlc.getNext();
    qDebug() << tlc.getNext();
    qDebug() << tlc.getNext();
    qDebug() << tlc.getNext();
    qDebug() << tlc.getNext();
    qDebug() << tlc.getNext();
    qDebug() << tlc.getNext();
    qDebug() << tlc.getNext();
    qDebug() << tlc.getNext();
    qDebug() << tlc.getNext();
    return a.exec();
}
