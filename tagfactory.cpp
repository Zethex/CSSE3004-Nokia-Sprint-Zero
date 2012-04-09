#include "tagfactory.h"


void TagFactory::set_tag_array(FileTag * tag_array) {
    this->tag_array = tag_array;
}

FileTag * TagFactory::get_tag_array() {
    return this->tag_array;
}

void TagFactory::set_fileTagData(multimap<string, string> ftd) {
    this->fileTagData = ftd;
}

multimap<String, String> TagFactory::get_fileTagData() {
    return this->fileTagData;
}

/**
  Returns a tag factory by acting as its own constructor so there is only one copy
  **/
TagFactory TagFactory::get_instance(string filepath) {
    TagFactory *tf = new TagFactory();
    FileReader *fr = new FileReader(filepath);
    fr->read_file();
    this->set_fileTagData(fr->get_multimap());
    return *tf;
}
