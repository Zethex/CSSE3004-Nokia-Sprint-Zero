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
vector<Data> TagFactory::get_data_array() {
    return this->data_array;
}

void TagFactory::set_fileTagData(map<string, std::vector<string> > ftd) {
    this->fileTagData = ftd;
}

map<string, std::vector<string> > TagFactory::get_fileTagData() {
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
int TagFactory::process_tags(map<string, std::vector<string> > * dict){

    int tag_count =0;
    map<string, std::vector<string> >::iterator it;

    for(it = dict->begin(); it!= dict->end(); it++){
        //iterate through keys
        //create a tag per key
        tag_count+=1;
        create_tag(it->first);
        for(int i=0; i<(*dict)[it->first].size(); i++){
            //iterate through Data in keys
            FileTag* temp_tag = &this->tag_array.back();
            Data* temp_data = get_data_from_string((*dict)[it->first].at(i));

            if(temp_data!=NULL){
                //if data array already holds filepath adds tag to filepath and adds the filepath to the tag
                temp_data->add_tag(temp_tag);
                temp_tag->add_file(temp_data);
                cout<<temp_tag->get_files().size()<<endl;



            } else {
                //if data does not exist
                create_data((*dict)[it->first].at(i), *temp_tag);
                Data* d = &this->data_array.back();
                temp_tag->add_file(d);


            }



        }
            //iterate through each data in key
            //create data for each filepath
    }

    return tag_count;
}


Data * TagFactory::get_data_from_string(string filepath){
    for(int i=0 ; i< this->data_array.size(); i++){
        if(this->data_array.at(i).get_filepath()==filepath){
            return &this->data_array.at(i);
        }
    }
    return NULL;
}
FileTag * TagFactory::get_FileTag_from_string(string name){
    for(int i=0 ; i< this->tag_array.size(); i++){
        if(this->tag_array.at(i).get_name()==name){
            return &this->tag_array.at(i);
        }
    }
    return NULL;
}

void TagFactory::create_tag(string name){
    //creates a new tag in the taglist and in memory with an empty data array
    vector<Data> temp;
    this->tag_array.push_back(FileTag(name, temp));
}

void TagFactory::create_data(string filepath, FileTag f){
    vector<FileTag> temptag;
    temptag.push_back(f);
    this->data_array.push_back(Data(filepath, temptag));
}

