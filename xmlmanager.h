#ifndef XMLMANAGER_H
#define XMLMANAGER_H

#include <map>
#include

class XMLManager
{
public:
    XMLManager();
    XMLManager(multimap<string , string> tag_list);
private:
    multimap<string, string> tag_list;

};

#endif // XMLMANAGER_H
