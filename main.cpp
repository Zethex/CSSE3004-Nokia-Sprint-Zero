#include <QtGui/QApplication>
#include "qmlapplicationviewer.h"
#include "filereader.h"
#include <iostream>
#include <map>
#include "tagfactory.h"

using namespace std;

TagFactory * TagFactory::factory_singleton;

Q_DECL_EXPORT int main(int argc, char *argv[])
{

    TagFactory::get_instance("C:\\Users\\Awesumo\\Zethex-CSSE3004-Nokia-Sprint-Zero\\music");

    vector<FileTag> temp1 =TagFactory::get_instance("")->get_tag_array();
    for(int i=0; i< temp1.size(); i++){
        cout<<temp1.at(i).get_name()<<endl;
    }
    cout<<temp1.size()<<endl;

    vector<Data> temp2 = TagFactory::get_instance("")->get_data_array();
    for(int i=0; i< temp2.size(); i++){
        cout<<temp2.at(i).get_filepath()<<endl;
    }
    cout<<temp2.size()<<endl;

    vector<FileTag> * temp3 = temp1.at(1).get_related_FileTags();
    for(int i=0; i< (*temp3).size(); i++){
        cout<<(*temp3).at(i).get_name()<<endl;
    }
    cout<<(*temp3).size()<<endl;

    QScopedPointer<QApplication> app(createApplication(argc, argv));

    QmlApplicationViewer viewer;
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/CSSE3004NokiaSprintZero/main.qml"));
    viewer.showExpanded();

    return app->exec();
}
