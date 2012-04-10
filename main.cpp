#include <QtGui/QApplication>
#include "qmlapplicationviewer.h"
#include "filereader.h"
#include <iostream>
#include <map>
#include "tagfactory.h"
#include "mainwindow.h"

using namespace std;

TagFactory * TagFactory::factory_singleton;

Q_DECL_EXPORT int main(int argc, char *argv[])
{

    /*TagFactory::get_instance("C:\\Users\\Awesumo\\Zethex-CSSE3004-Nokia-Sprint-Zero\\music");

    //checks how many tags were made :: working
    vector<FileTag> temp1 =TagFactory::get_instance("")->get_tag_array();
    for(int i=0; i< temp1.size(); i++){
        cout<<temp1.at(i).get_name()<<endl;
    }
    cout<<temp1.size()<<endl;

    //checks how mana Datas were made  :: working

    vector<Data> temp2 = TagFactory::get_instance("")->get_data_array();
    for(int i=0; i< temp2.size(); i++){
        cout<<temp2.at(i).get_filepath()<<endl;
    }
    cout<<temp2.size()<<endl;

    //check if each data has 2 tags on it :: working
    vector<Data> temp4 = TagFactory::get_instance("")->get_data_array();
    for(int i=0; i< temp4.size(); i++){
        cout<<temp4.at(i).get_tags().size()<<endl;
    }*/



    QScopedPointer<QApplication> app(createApplication(argc, argv));

    MainWindow w;
    w.show();

    /*QmlApplicationViewer viewer;
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/CSSE3004NokiaSprintZero/main.qml"));
    viewer.showExpanded();*/

    return app->exec();
}
