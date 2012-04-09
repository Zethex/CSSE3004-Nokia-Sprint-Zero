#include "tagfactory.h"


void TagFactory::set_tag_array(vector<FileTag> tag_array) {
    this->tag_array = tag_array;
}

vector<FileTag> TagFactory::get_tag_array() {
    return this->tag_array;
}

void TagFactory::set_fileTagData(multimap<string, string> ftd) {
    this->fileTagData = ftd;
}

multimap<string, string> TagFactory::get_fileTagData() {
    return this->fileTagData;
}

/**
  Returns a tag factory by acting as its own constructor so there is only one copy
  **/
TagFactory* TagFactory::get_instance() {
    if (factory_singleton == NULL){
        factory_singleton = new TagFactory();
    }
    return factory_singleton;

}
TagFactory::TagFactory() {}
