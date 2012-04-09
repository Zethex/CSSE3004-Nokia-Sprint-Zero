#ifndef DATA_H
#define DATA_H

using namespace std;
#include <string>
#include <vector>
#include <filetag.h>

class FileTag;

class Data
{
private:
    string filepath;
    vector<FileTag> tags;
public:
    Data(string filepath, vector<FileTag> tags);
    string get_filepath();
    void set_file(string filepath);
    void add_tag(FileTag f);
    vector<FileTag> get_tags();
};

#endif // DATA_H
