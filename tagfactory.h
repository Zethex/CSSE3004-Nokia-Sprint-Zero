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
    void set_tag_array(vector<FileTag> tag_array);
    void set_fileTagData(multimap<string, string> ftd);
    multimap<string, string> get_fileTagData();

    void print();

    int process_tags(multimap<string , string> * dict);
private:
    TagFactory(string filepath);
    static TagFactory * factory_singleton;

    vector<FileTag> tag_array;
    vector<Data> data_array;
    void create_tag(string name);
    void create_data(string filepath, vector<FileTag> tags);

    multimap<string, string> fileTagData;
};

#endif // TAGFACTORY_H
