#include "FileTag.h"

FileTag::FileTag(string name, vector<Data> d)
{
    this->name = name;
    this->files = d;
}
void FileTag::add_file(Data d)
{
    this->files.push_back(d);
}
int FileTag::remove_file(Data d)
{
    for (unsigned int iPos = 0 ; iPos < this->files.size() ; iPos++) {
        if(this->files.at(iPos).get_file()==d.get_file()) {
            this->files.erase(this->files.begin() + iPos);
            return 1;
        }
    }
    return 0;
}
string FileTag::get_name()
{
    return this->name;
}
void FileTag::set_name(string s)
{
    this->name = s;
}
vector<Data> FileTag::get_files()
{
    return this->files;
}
void FileTag::set_files(vector<Data> d)
{
    this->files = d;
}

vector<FileTag> FileTag::get_related_FileTags()
{
//iterate through all "Datas" and return all FileTags associated with all "Datas" uniquely
    //return new vector<FileTag>();

}
