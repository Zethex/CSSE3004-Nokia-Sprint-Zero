#include "tagfactory.h"

/**
  *setters and getters
  **/


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
  singleton method
  Returns a tag factory by acting as its own constructor so there is only one copy
  **/
TagFactory* TagFactory::get_instance() {
    if (factory_singleton == NULL){
        factory_singleton = new TagFactory();
    }
    return factory_singleton;

}
TagFactory::TagFactory() {}


/**
  other functions
  **/


//returns the amount of tags added
int TagFactory::process_tags(multimap<string , string> * dict){

    int tag_count =0;
    multimap<string,string>::iterator it;

    for(it = dict->begin(); it!= dict->end(); it++){
        //iterate through keys
        //create a tag per key
            //iterate through each data in key
            //create data for each filepath
    }

    return tag_count;
}

void TagFactory::create_tag(string name){
    //creates a new tag in the taglist and in memory with an empty data array
    vector<Data>* empty = new vector<Data>();
    FileTag* temp = new FileTag(name, *empty);
    this->tag_array.push_back(*temp);
}
