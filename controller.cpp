#include "controller.h"
#include <stdio.h>

Controller::Controller(QObject *parent)
{
    this->display_splash_screen();
    filename = "./music"; // **** REPLACE YOUR PATH HERE! ****
}

void Controller::display_splash_screen(void){

}

void Controller::setFirstTag(void){
    TagFactory *tf = TagFactory::get_instance(filename);
    vector<FileTag> tags = tf->get_tag_array();
    FileTag firstTag = tags.front();
    current_tag_name = firstTag.get_name();
    vector<string> related_tag_names = this->get_related_tags(current_tag_name);
    cout << related_tag_names.front() << endl;
    printf("sending signal");
    emit setNewCentreTag(current_tag_name, related_tag_names);
}

void Controller::request_filepath(void){
    //ask user through ui to give us their filepath
    //save it to this string
    string s = "filepath";
    TagFactory::get_instance(s);
}

vector<string> Controller::get_related_tags(string s){
    vector<string> related_tags = TagFactory::get_instance("")->get_related_tags(s);
    return related_tags;
}


void Controller::onLabelClick(int label_index){
    printf("IN THE CONTROLLER, CLICKED A LABEL!");
    vector<string> tag_names = TagFactory::get_instance(filename)->get_related_tags(current_tag_name);
    printf("size %i", tag_names.size());
    printf("label index %i", label_index);
    if (label_index >= tag_names.size()){return;}
    string clicked_tag_name = tag_names.at(label_index);
    cout << clicked_tag_name << endl;
    vector<string> related_tag_names = this->get_related_tags(clicked_tag_name);
    current_tag_name = clicked_tag_name;
    cout << related_tag_names.front() << endl;
    emit setNewCentreTag(clicked_tag_name, related_tag_names);
}

