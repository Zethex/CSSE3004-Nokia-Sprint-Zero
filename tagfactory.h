#ifndef TAGFACTORY_H
#define TAGFACTORY_H

#include "filetag.h"
#include <map>
#include "filereader.h"
#include "data.h"

class TagFactory
{
public:

    TagFactory get_instance();
    FileTag * get_tag_array();
    void set_tag_array(FileTag * tag_array);
    TagFactory get_instance(string filepath);
    void print();
    void set_fileTagData(multimap<string, string> ftd);
    multimap<string, string> get_fileTagData();
private:
    FileTag * tag_array;
    int process_tags(multimap<string , string> * dict);
    multimap<string, string> fileTagData;
};

#endif // TAGFACTORY_H
