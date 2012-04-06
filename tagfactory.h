#ifndef TAGFACTORY_H
#define TAGFACTORY_H

#include "tag.h"
#include "xmlmanager.h"

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
    // HAVE TO GET right map thing hereint process_tags(Map * dict);
};

#endif // TAGFACTORY_H
