#include "filereader.h"

FileReader::FileReader(string filepath)
{
    //s is the filepath which will analyze every mp3 in folder
}
void FileReader::read_file()
{
    //helper function for filereader class to break down file iteration and file reading
    //this class will read all data from mp3 then iterate through each tag found adding it to multimap

}
multimap<string , FILE*> FileReader::get_multimap()
{
    return this->tagsToBeCreated;
}
