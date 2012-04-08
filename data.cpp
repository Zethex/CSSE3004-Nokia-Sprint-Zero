#include "data.h"

Data::Data(FILE *file, vector<FileTag> tags)
{
    this->file = file;
    this->tags = tags;
}
FILE* Data::get_file()
{
    return this->file;
}
void Data::set_file(FILE* f)
{
    this->file = f;
}
vector<FileTag> Data::get_tags()
{
    return this->tags;
}

