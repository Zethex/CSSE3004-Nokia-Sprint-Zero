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
    cout<<"Tag instances created :"<<temp1.size()<<endl;

    cout<<endl;

    //check if each data has 2 tags on it :: working
    vector<FileTag> temp3 = TagFactory::get_instance("")->get_tag_array();
    for(int i=0; i< temp3.size(); i++){
        cout<<temp3.at(i).get_name()<<" has "<<temp3.at(i).get_files().size()<<" associated Data"<<endl;
    }

    cout<<endl;

    //checks how mana Datas were made  :: working

    vector<Data> temp2 = TagFactory::get_instance("")->get_data_array();
    for(int i=0; i< temp2.size(); i++){
        cout<<temp2.at(i).get_filepath()<<endl;
    }
    cout<<"Data instances created :"<<temp2.size()<<endl;

    cout<<endl;

    //check if each data has 2 tags on it :: working
    vector<Data> temp4 = TagFactory::get_instance("")->get_data_array();
    for(int i=0; i< temp4.size(); i++){
        cout<<temp4.at(i).get_filepath()<<" has "<<temp4.at(i).get_tags().size()<<" associated tags"<<endl;
    }

    cout<<endl;

    //check if returns right tags :: working
    for(int z=0; z<temp1.size(); z++){
        vector<FileTag> temp5 = temp1.at(z).get_related_FileTags();
        //cout<<"tag 3 data 1 has "<<temp1.at(2).get_files().at(0).get_tags().size()<<" many tags"<<endl;
        //vector<FileTag>* temp5 = temp1.at(0).get_related_FileTags();


        cout<<temp1.at(z).get_name()<<" is related to:"<<endl;
        for(int i=0; i< temp5.size(); i++){
            cout<<temp5.at(i).get_name()<<", ";
        }
        cout<<endl;
    }

    cout<<endl;*/

    QScopedPointer<QApplication> app(createApplication(argc, argv));

    MainWindow w;
    w.show();

    /*QmlApplicationViewer viewer;
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/CSSE3004NokiaSprintZero/main.qml"));
    viewer.showExpanded();*/

    return app->exec();
}
