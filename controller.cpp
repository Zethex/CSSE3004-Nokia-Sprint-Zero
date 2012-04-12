#include "controller.h"

Controller::Controller()
{
    this->display_splash_screen();
}

void Controller::display_splash_screen(){

}

void Controller::request_filepath(){
    //ask user through ui to give us their filepath
    //save it to this string
    string s = "filepath";
    TagFactory::get_instance(s);
}

vector<string> Controller::get_related_tags(string s){
    return TagFactory::get_instance("")->get_related_tags(s);
}
