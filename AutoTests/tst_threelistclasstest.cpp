#include <QtTest>

// add necessary includes here
#include "../SiberSystemsTestTask/threelistclass.h"
#include <QSharedPointer>
#include <QVector>


class ThreeListClassTest : public QObject
{
    Q_OBJECT
    QSharedPointer<ThreeListClass> threeListClass;
    QVector<int> idealValues;
public:
    ThreeListClassTest();
    ~ThreeListClassTest();

private slots:
    void initTestCase();
    // Consider all permutations of 3 lists
    // 1,2,3; 1,3,2; 2,1,3; 3,1,2; 3,2,1; 2,3,1
    void test_case1();
    void test_case2();
    void test_case3();
    void test_case4();
    void test_case5();
    void test_case6();
};

void ThreeListClassTest::initTestCase()
{
    /*
     * Ideal values correspond to elements of three lists in ascending order and one zero element

        int list_2[] = {1,8,15,16,35,80,91};
        int list_1[] = {2,7,12,40,54};
        int list_3[] = {10,13,14,17};

    */
    idealValues.append(1);
    idealValues.append(2);
    idealValues.append(7);
    idealValues.append(8);
    idealValues.append(10);
    idealValues.append(12);
    idealValues.append(13);
    idealValues.append(14);
    idealValues.append(15);
    idealValues.append(16);
    idealValues.append(17);
    idealValues.append(35);
    idealValues.append(40);
    idealValues.append(54);
    idealValues.append(80);
    idealValues.append(91);
    idealValues.append(0);
}

ThreeListClassTest::ThreeListClassTest()
{

}

ThreeListClassTest::~ThreeListClassTest()
{

}

void ThreeListClassTest::test_case1()
{
    QVector<int> values;
    int list_1[] = {10,13,14,17};
    int list_2[] = {2,7,12,40,54};
    int list_3[] = {1,8,15,16,35,80,91};
    int list_1_size = sizeof(list_1) / sizeof(list_1[0]);
    int list_2_size = sizeof(list_2) / sizeof(list_2[0]);
    int list_3_size = sizeof(list_3) / sizeof(list_3[0]);
    threeListClass.reset(new ThreeListClass(list_1, list_1_size, list_2, list_2_size, list_3, list_3_size));

    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());

    QVERIFY(idealValues == values);
}

void ThreeListClassTest::test_case2()
{
    QVector<int> values;
    int list_1[] = {10,13,14,17};
    int list_2[] = {1,8,15,16,35,80,91};
    int list_3[] = {2,7,12,40,54};
    int list_1_size = sizeof(list_1) / sizeof(list_1[0]);
    int list_2_size = sizeof(list_2) / sizeof(list_2[0]);
    int list_3_size = sizeof(list_3) / sizeof(list_3[0]);
    threeListClass.reset(new ThreeListClass(list_1, list_1_size, list_2, list_2_size, list_3, list_3_size));

    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());

    QVERIFY(idealValues == values);
}

void ThreeListClassTest::test_case3()
{
    QVector<int> values;
    int list_1[] = {2,7,12,40,54};
    int list_2[] = {10,13,14,17};
    int list_3[] = {1,8,15,16,35,80,91};
    int list_1_size = sizeof(list_1) / sizeof(list_1[0]);
    int list_2_size = sizeof(list_2) / sizeof(list_2[0]);
    int list_3_size = sizeof(list_3) / sizeof(list_3[0]);
    threeListClass.reset(new ThreeListClass(list_1, list_1_size, list_2, list_2_size, list_3, list_3_size));

    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());

    QVERIFY(idealValues == values);
}

void ThreeListClassTest::test_case4()
{
    QVector<int> values;
    int list_1[] = {1,8,15,16,35,80,91};
    int list_2[] = {10,13,14,17};
    int list_3[] = {2,7,12,40,54};
    int list_1_size = sizeof(list_1) / sizeof(list_1[0]);
    int list_2_size = sizeof(list_2) / sizeof(list_2[0]);
    int list_3_size = sizeof(list_3) / sizeof(list_3[0]);
    threeListClass.reset(new ThreeListClass(list_1, list_1_size, list_2, list_2_size, list_3, list_3_size));

    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());

    QVERIFY(idealValues == values);
}

void ThreeListClassTest::test_case5()
{
    QVector<int> values;
    int list_1[] = {1,8,15,16,35,80,91};
    int list_2[] = {2,7,12,40,54};
    int list_3[] = {10,13,14,17};
    int list_1_size = sizeof(list_1) / sizeof(list_1[0]);
    int list_2_size = sizeof(list_2) / sizeof(list_2[0]);
    int list_3_size = sizeof(list_3) / sizeof(list_3[0]);
    threeListClass.reset(new ThreeListClass(list_1, list_1_size, list_2, list_2_size, list_3, list_3_size));

    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());

    QVERIFY(idealValues == values);
}

void ThreeListClassTest::test_case6()
{
    QVector<int> values;
    int list_1[] = {2,7,12,40,54};
    int list_2[] = {1,8,15,16,35,80,91};
    int list_3[] = {10,13,14,17};
    int list_1_size = sizeof(list_1) / sizeof(list_1[0]);
    int list_2_size = sizeof(list_2) / sizeof(list_2[0]);
    int list_3_size = sizeof(list_3) / sizeof(list_3[0]);
    threeListClass.reset(new ThreeListClass(list_1, list_1_size, list_2, list_2_size, list_3, list_3_size));

    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());
    values.append(threeListClass->getNext());

    QVERIFY(idealValues == values);
}

QTEST_APPLESS_MAIN(ThreeListClassTest)

#include "tst_threelistclasstest.moc"
