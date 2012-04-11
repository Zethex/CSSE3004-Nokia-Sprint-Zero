#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "tagfactory.h"

class Controller
{
public:
    Controller();
    void request_filepath();//populates the Tagfactory with input string
    vector<string> get_related_tags(string s); // passes call to tagfactory
};

#endif // CONTROLLER_H
