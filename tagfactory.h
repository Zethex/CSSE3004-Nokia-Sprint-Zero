#ifndef TAGFACTORY_H
#define TAGFACTORY_H

#include "filetag.h"
#include <map>
#include "filereader.h"
#include "data.h"

class TagFactory
{

public:

    TagFactory* get_instance();

    vector<FileTag> get_tag_array();
    void set_tag_array(vector<FileTag> tag_array);
    void print();
    void set_fileTagData(multimap<string, string> ftd);
    multimap<string, string> get_fileTagData();
private:
    TagFactory();
    static TagFactory * factory_singleton;

    vector<FileTag> tag_array;
    int process_tags(multimap<string , string> * dict);
    multimap<string, string> fileTagData;
};

#endif // TAGFACTORY_H
