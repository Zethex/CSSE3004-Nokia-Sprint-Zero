#ifndef TAG_H
#define TAG_H

#include <string>
#include <data.h>
#include <vector>

using namespace std;

class Tag
{
private:
    string name;
    vector<Data> files;
public:
    Tag(string name, vector<Data> d);
    void add_file(Data d);
    int remove_file(Data d);
    vector<Tag> get_related_tags();
    string get_name();
    void set_name(string s);
    vector<Data> get_files();
    void set_files(vector<Data> d);
};

#endif // TAG_H
