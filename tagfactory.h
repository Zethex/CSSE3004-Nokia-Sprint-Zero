#ifndef TAGFACTORY_H
#define TAGFACTORY_H

#include "filetag.h"
#include <map>
#include "filereader.h"
#include "data.h"
#include <iostream>

using namespace std;

class TagFactory
{

public:

    static TagFactory* get_instance(string filepath);


    vector<FileTag> get_tag_array();
    vector<Data> get_data_array();
    void set_tag_array(vector<FileTag> tag_array);
    void set_fileTagData(map<string, std::vector<string> > ftd);
    map<string, std::vector<string> > get_fileTagData();
    void print();
    Data * get_data_from_string(string filepath);
    vector<string> get_related_tags(string s);

    int process_tags(map<string, std::vector<string> > * dict);
private:
    TagFactory(string filepath);
    static TagFactory * factory_singleton;
    vector<FileTag> tag_array;
    vector<Data> data_array;

    FileTag *get_FileTag_from_string(string name);
    void create_tag(string name);
    void create_data(string filepath, FileTag f);


    map<string, std::vector<string> > fileTagData;
};

#endif // TAGFACTORY_H
