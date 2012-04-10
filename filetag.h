#ifndef FileTag_H
#define FileTag_H

#include <string>
#include <data.h>
#include <vector>
#include <iostream>

using namespace std;

class Data;

class FileTag
{
private:
    string name;
    vector<Data> files;
public:
    FileTag(string name, vector<Data> d);
    void add_file(Data* d);
    int remove_file(Data d);
    vector<FileTag> get_related_FileTags();
    string get_name();
    void set_name(string s);
    vector<Data> get_files();
    void set_files(vector<Data> d);
};

#endif // FileTag_H
