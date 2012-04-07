#ifndef TAGFACTORY_H
#define TAGFACTORY_H

#include "tag.h"
#include "xmlmanager.h"
#include <map>
#include "filereader.h"
#include "data.h"
#include "tag.h"

class TagFactory
{
public:
    TagFactory get_instance();
    Tag * get_tag_array();
    void set_tag_array(Tag * tag_array);
    void print();
private:
    Tag * tag_array;
    XMLManager * xml;
    int process_tags(multimap<string , FILE*> * dict);
};

#endif // TAGFACTORY_H
