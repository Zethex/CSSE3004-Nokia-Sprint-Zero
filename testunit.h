#ifndef TESTUNIT_H
#define TESTUNIT_H
#include <QtTest/QtTest>
#include "tagfactory.h"

class TestUnit: public QObject{

        Q_OBJECT
    public:
        static void runTests();
    private slots:
            void data_test_1();

    };

//QTEST_MAIN(TestUnit)


#endif // TESTUNIT_H
