#include "data.h"

Data::Data(string filepath, vector<FileTag> tags)
{
    this->filepath = filepath;
    this->tags = tags;
}
void Data::add_tag(FileTag* f){
    this->tags.push_back(*f);
}

string Data::get_filepath()
{
    return this->filepath;
}
void Data::set_file(string filepath)
{
    this->filepath = filepath;
}
vector<FileTag> Data::get_tags()
{
    return this->tags;
}

