#include "testunit.h"
#define NUMDATA 1 // for tests that use get_instance(filepath)
#define NUMTAGS 2

void TestUnit::data_test_1(){

    // get_instance( *NEED FULL PATH* )
    TagFactory::get_instance("\\music");
    QCOMPARE("hi", "hi");
}

// check Data
void TestUnit::checkData() {
    cout<<endl;
    vector<FileTag> tags;
    Data temp = Data("data_testname", tags);

    // test filepath getter
    QVERIFY(temp.get_filepath() == "data_testname");

    // test filepath setter
    temp.set_file("data_newname");
    QVERIFY(temp.get_filepath() == "data_newname");

    // test no tags
    QVERIFY(temp.get_tags().size() == 0);

    // test adding tag *TO DO*

}

//check FileTag
void TestUnit::checkFileTag() {
    cout<<endl;
    vector<Data> temp_data;
    FileTag temp = FileTag("tag_test", temp_data);

    // test name getter
    QVERIFY(temp.get_name() == "tag_test");

    // test name setter
    temp.set_name("tag_newname");
    QVERIFY(temp.get_name() == "tag_newname");

    // test files getter *TO DO*

    // test files setter *TO DO*

}

// TagFactory - check number of tags made
void TestUnit::checkNumberTagsMade() {
    cout<<endl;
    vector<FileTag> temp = TagFactory::get_instance("")->get_tag_array();
    cout<<"Tag instances created: "<<temp.size()<<endl;
    QVERIFY(temp.size() == NUMTAGS);
}

// TagFactory - check how many datas each tag has
void TestUnit::checkEachTag() {
    cout<<endl;
    vector<FileTag> temp = TagFactory::get_instance("")->get_tag_array();
    for(int i=0; i < temp.size(); i++) {
        cout<<temp.at(i).get_name()<<" has "<<temp.at(i).get_files().size()<<" associated Data"<<endl;
        QVERIFY(temp.at(i).get_files().size() == 1);
    }
}

// TagFactory - check how many datas were made
void TestUnit::checkNumberDatasMade() {
    cout<<endl;
    vector<Data> temp = TagFactory::get_instance("")->get_data_array();
    cout<<"Data instances created: "<<temp.size()<<endl;
    QVERIFY(temp.size() == NUMDATA);
}

// TagFactory - check how many tags each data has
void TestUnit::checkEachData() {
    cout<<endl;
    vector<Data> temp = TagFactory::get_instance("")->get_data_array();
    for(int i=0; i < temp.size(); i++) {
        cout<<temp.at(i).get_filepath()<<" has "<<temp.at(i).get_tags().size()<<" associated tags"<<endl;
        QVERIFY(temp.at(i).get_tags().size() == 2);
    }
}

// TagFactory - check related tags
void TestUnit::checkCorrectTags() {
    cout<<endl;
    vector<FileTag> temp = TagFactory::get_instance("")->get_tag_array();
    for(int i=0; i < temp.size(); i++) {
        vector<FileTag> tempR = temp.at(i).get_related_FileTags();
        cout<<temp.at(i).get_name()<<" has related tags: "<<endl;
        for(int j=0; j < tempR.size(); j++) {
            cout<<tempR.at(j).get_name()<<endl;
        }
    }
}

void TestUnit::runTests(){
    TestUnit * test = new TestUnit();
    QTest::qExec(test);
    delete test;
}

//Everything below here is to be converted into tests

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
*/
