#ifndef DATA_H
#define DATA_H

class Data
{
private:
    FILE *file;
    Vector<Tag> tags;
public:
    Data();
    Data(FILE *file, Vector<Tag> tags);
    Data(Data *d);
    FILE* get_file();
    int set_file(FILE* f);
    Vector<Tag> get_tags();
    int set_tags( Vector<Tags> t);
};

#endif // DATA_H
