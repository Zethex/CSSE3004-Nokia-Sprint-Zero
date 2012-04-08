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
    FILE *file;
    vector<FileTag> tags;
public:
    Data(FILE *file, vector<FileTag> tags);
    FILE* get_file();
    void set_file(FILE* f);
    vector<FileTag> get_tags();
};

#endif // DATA_H
