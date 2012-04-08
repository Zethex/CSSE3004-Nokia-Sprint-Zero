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
    void print();
private:
    FileTag * tag_array;
    int process_tags(multimap<string , string> * dict);
};

#endif // TAGFACTORY_H
