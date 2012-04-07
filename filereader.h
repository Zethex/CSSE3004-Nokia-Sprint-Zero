#ifndef FILEREADER_H
#define FILEREADER_H

#include <map>
#include <string>

using namespace std;

class FileReader
{
private:
    multimap<string , FILE*> tagsToBeCreated;
public:
    FileReader(string filepath);
    void read_file();
    multimap<string , FILE*> get_multimap();

};

#endif // FILEREADER_H
