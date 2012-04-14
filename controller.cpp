#include "controller.h"
#include <stdio.h>

Controller::Controller(QObject *parent)
{
    this->display_splash_screen();

}

void Controller::display_splash_screen(void){

}

void Controller::setFirstTag(void){
    TagFactory *tf = TagFactory::get_instance("C:\\Users\\Ania\\Documents\\csse3004\\grouprepository\\music"); // **** REPLACE YOUR PATH HERE! ****
    vector<FileTag> tags = tf->get_tag_array();
    FileTag firstTag = tags.front();
    string name = firstTag.get_name();
    vector<string> related_tag_names = get_related_tags(name);
    cout << related_tag_names.front() << endl;
    printf("sending signal");
    emit setNewCentreTag(related_tag_names);
}

void Controller::request_filepath(void){
    //ask user through ui to give us their filepath
    //save it to this string
    string s = "filepath";
    TagFactory::get_instance(s);
}

vector<string> Controller::get_related_tags(string s){
    vector<string> related_tags = TagFactory::get_instance("")->get_related_tags(s);
    //if (related_tags.size()==0){
        related_tags.push_back("Happy");
        related_tags.push_back("Artist 1");
        related_tags.push_back("Energetic");
        related_tags.push_back("Genre 2");
    //}
    return related_tags;
}


void Controller::onLabelClick(int label_index){
    printf("IN THE CONTROLLER, CLICKED A LABEL!");

    //emit setNewCentreTag(vector<string> related_tag_names);
}

