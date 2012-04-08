#include "tagfactory.h"


void TagFactory::set_tag_array(Tag * tag_array) {
    this->tag_array = tag_array;
}

Tag * TagFactory::get_tag_array() {
    return this->tag_array;
}


/**
  Returns a tag factory by acting as its own constructor so there is only one copy
  **/
TagFactory TagFactory::get_instance() {

    TagFactory *tf = new TagFactory();
    //FileReader *fr = new FileReader("what do we put here");




    return *tf;
}
