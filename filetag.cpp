#include "FileTag.h"
#include "tagfactory.h"

FileTag::FileTag(string name, vector<Data> d)
{
    this->name = name;
    this->files = d;
}
void FileTag::add_file(Data* d)
{

    this->files.push_back(*d);
}
int FileTag::remove_file(Data d)
{
    for (unsigned int iPos = 0 ; iPos < this->files.size() ; iPos++) {
        if(this->files.at(iPos).get_filepath()==d.get_filepath()) {
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

vector<FileTag> make_unique(vector<FileTag> f, string s){
    vector<FileTag> temp;
    int flag=0;
    for(int i=0; i<f.size(); i++){
        for( int z=0; z<temp.size(); z++){
            if(f.at(i).get_name()==temp.at(z).get_name())
                flag=1;

        }
        if(flag==0){
            temp.push_back(f.at(i));

        } else {flag=0;}
    }
    return temp;
}

vector<FileTag> FileTag::get_related_FileTags(){

    vector<FileTag> unique;
    vector<FileTag> returner;
    for(int i=0; i<this->get_files().size(); i++){
        vector<FileTag> b = TagFactory::get_instance("")->get_data_from_string(this->get_files().at(i).get_filepath())->get_tags();
        returner.insert(returner.begin(), b.begin(), b.end());
    }
    unique = make_unique(returner, this->get_name());
    return unique;
}



