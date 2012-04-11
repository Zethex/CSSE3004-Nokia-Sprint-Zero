#include "controller.h"

Controller::Controller()
{
}
void Controller::request_filepath(){
    //ask user through ui to give us their filepath
    //save it to this string
    string s = "filepath";
    TagFactory::get_instance(s);
}

vector<string> Controller::get_related_tags(string s){
    vector<string> s;
    vector<FileTag> f =TagFactory::get_related_tags(s);
    for(int i=0; i<f.size(); i++){
        s.push_back(f.at(i).get_name());
    }
    return s;
}
