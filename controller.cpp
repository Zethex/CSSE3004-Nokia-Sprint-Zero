#include "controller.h"
#include <stdio.h>

Controller::Controller(QObject *parent)
{
    this->display_splash_screen();
}

void Controller::display_splash_screen(void){

}

void Controller::request_filepath(void){
    //ask user through ui to give us their filepath
    //save it to this string
    string s = "filepath";
    TagFactory::get_instance(s);
}

vector<string> Controller::get_related_tags(string s){
    return TagFactory::get_instance("")->get_related_tags(s);
}


void Controller::onLabelClick(int label_index){
    printf("IN THE CONTROLLER, CLICKED A LABEL!");
    //emit setNewCentreTag(vector<string> related_tag_names);
}

