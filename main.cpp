#include <QtGui/QApplication>
#include "qmlapplicationviewer.h"
#include "filereader.h"
#include <iostream>
#include <map>
#include "tagfactory.h"
#include "mainwindow.h"
#include "testunit.h"
#include <QSplashScreen>
#include "sleep.h"


using namespace std;

TagFactory * TagFactory::factory_singleton;

Q_DECL_EXPORT int main(int argc, char *argv[])
{


    //::TestUnit::runTests();
    /*
    QScopedPointer<QApplication> app(createApplication(argc, argv));

    MainWindow w;
    w.show();
    */

    /*QmlApplicationViewer viewer;
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/CSSE3004NokiaSprintZero/main.qml"));
    viewer.showExpanded();*/

    //return app->exec();

    // TEST
    QApplication a(argc, argv);

    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap("splash_screen.png")); // fix - need this to work with relative paths
    splash->show();

    Qt::Alignment topRight = Qt::AlignRight | Qt::AlignTop;
    splash->showMessage(QObject::tr("Loading Application..."),
                               topRight, Qt::white);

    Sleep s;
    s.msleep(1000);

    MainWindow w;
    w.resize(320, 480);
    splash->finish(&w);
    delete splash;
    w.show();

    return a.exec();
}
