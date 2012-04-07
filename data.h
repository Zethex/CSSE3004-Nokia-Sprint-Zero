#ifndef DATA_H
#define DATA_H

using namespace std;
#include <string>
#include <vector>
//#include <tag.h>

class Tag;
class Data
{
private:
    FILE *file;
    vector<Tag> tags;
public:
    Data(FILE *file, vector<Tag> tags);
    FILE* get_file();
    int set_file(FILE* f);
    vector<Tag> get_tags();
    int set_tags( vector<Tag> t);
};

#endif // DATA_H
