#ifndef TAGFACTORY_H
#define TAGFACTORY_H

#include "filetag.h"
#include <map>
#include "filereader.h"
#include "data.h"
#include "filetag.h"

class TagFactory
{
public:

    TagFactory get_instance();
    FileTag * get_tag_array();
    void set_tag_array(FileTag * tag_array);
    TagFactory get_instance(string filepath);
    Tag * get_tag_array();
    void set_tag_array(Tag * tag_array);
    void print();
    void set_fileTagData(multimap<string, string> ftd);
    multimap<String, String> get_fileTagData();
private:
    FileTag * tag_array;
    int process_tags(multimap<string , string> * dict);
    Tag * tag_array;
    XMLManager * xml;
    int process_tags(multimap<string , FILE*> * dict);
    multimap<string, string> fileTagData;
};

#endif // TAGFACTORY_H
