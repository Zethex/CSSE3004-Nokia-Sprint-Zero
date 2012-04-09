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
 TagFactory* TagFactory::get_instance(string filepath) {
    if (factory_singleton == NULL){
        factory_singleton = new TagFactory(filepath);
    }
    return factory_singleton;

}
TagFactory::TagFactory(string filepath) {
    FileReader temp = FileReader(filepath);
    cout<<"added "<<this->process_tags(&temp.get_multimap())<<" tags"<<endl;
}


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
    this->tag_array.push_back(FileTag(name, *new vector<Data>()));
}

void TagFactory::create_data(string filepath, vector<FileTag> tags){
    this->data_array.push_back(Data(filepath, tags));
}
