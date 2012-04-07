#include "tag.h"

Tag::Tag(string name, vector<Data> d)
{
    this->name = name;
    this->files = d;
}
void Tag::add_file(Data d)
{
    this->files.push_back(d);
}
int Tag::remove_file(Data d)
{
    for (unsigned int iPos = 0 ; iPos < this->files.size() ; iPos++) {
        if(this->files.at(iPos).get_file()==d.get_file()) {
            this->files.erase(this->files.begin() + iPos);
            return 1;
        }
    }
    return 0;
}
string Tag::get_name()
{
    return this->name;
}
void Tag::set_name(string s)
{
    this->name = s;
}
vector<Data> Tag::get_files()
{
    return this->files;
}
void Tag::set_files(vector<Data> d)
{
    this->files = d;
}

vector<Tag> Tag::get_related_tags()
{
//iterate through all "Datas" and return all tags associated with all "Datas" uniquely
    //return new vector<Tag>();

}
