#ifndef FILEREADER_H
#define FILEREADER_H

#include <map>
#include <string>

using namespace std;

typedef struct _id3tag
{
    char title[30];
    char artist[30];
    char album[30];
    char year[4];
    char comment[30];
    unsigned char track;
    unsigned char genre;
} id3tag;

class FileReader
{
private:
    multimap<string , FILE*> tagsToBeCreated;
public:
    FileReader(string filepath);
    void read_file(string filepath);
    multimap<string , FILE*> get_multimap();
    int ReadID3(const char* Filename, id3tag *ID3Tag);
    int ReadID3v2(const char* Filename, id3tag *ID3Tag);

};

#endif // FILEREADER_H
