#include <QtGui/QApplication>
#include "qmlapplicationviewer.h"
#include "filereader.h"
#include <iostream>
#include <map>

using namespace std;

Q_DECL_EXPORT int main(int argc, char *argv[])
{

    FileReader test1 = FileReader("C:\\Users\\Awesumo\\Zethex-CSSE3004-Nokia-Sprint-Zero\\music");
    for (multimap<string, string>::reverse_iterator rit=test1.get_multimap().rbegin() ; rit != test1.get_multimap().rend(); rit++ )
        cout << rit->first << " => " << rit->second << endl;

    QScopedPointer<QApplication> app(createApplication(argc, argv));

    QmlApplicationViewer viewer;
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/CSSE3004NokiaSprintZero/main.qml"));
    viewer.showExpanded();

    return app->exec();
}
