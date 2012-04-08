#include "filereader.h"
#include <dirent.h>
#include <sys/types.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>



using namespace std;

FileReader::FileReader(string filepath)
{
    //s is the filepath which will analyze every mp3 in folder
    DIR *dp;
    struct dirent *ep;

    dp = opendir (filepath.c_str());
    if (dp != NULL)
    {
        while (ep = readdir (dp)){
            int len = strlen(ep->d_name);
            if(strcmp(".mp3", ep->d_name+len -4)==0){

                read_file(filepath+"\\"+ep->d_name);
            }
        }
        (void) closedir (dp);
    }
        else
            perror ("Couldn't open the directory");
}
void FileReader::read_file(string filepath)
{
    //helper function for filereader class to break down file iteration and file reading
    //this class will read all data from mp3 then iterate through each tag found adding it to multimap

    for(unsigned int i=0; i<filepath.length(); i++){
        if (filepath.at(i)=='\\'){
            filepath.insert(i, "\\");
            i++;
        }
    }
    cout<<filepath;
    id3tag ID3;
    if(ReadID3(filepath.c_str(),&ID3)){
        cout<<endl;
        cout<<ID3.comment<<endl;
        cout<<ID3.album<<endl;
        cout<<ID3.artist<<endl;
        cout<<ID3.title<<endl;
        cout<<ID3.track<<endl;
        cout<<ID3.year<<endl;
    } else{
        cout<<" doesnt have ID3v1(end of file tagging) tag"<<endl;
        if(!ReadID3v2(filepath.c_str(),&ID3)){
            cout<<" doesnt have ID3v2(start of file tagging) tag"<<endl;
        } else{
            cout<<" no current implementation of id3v2 tags"<<endl;
        }
    }


}
multimap<string , FILE*> FileReader::get_multimap()
{
    return this->tagsToBeCreated;
}


int FileReader::ReadID3(const char* Filename, id3tag *ID3Tag)
{
    FILE *fp=fopen(Filename,"rb");
    char buffer[128];
    int x;

    fseek(fp,-128,SEEK_END);
    fread(buffer,sizeof(char),sizeof(buffer),fp);

    if(!(buffer[0]=='T' && buffer[1] == 'A' && buffer[2] == 'G'))
    {

        return 0;
    }

    //Found id3 tag, let's fill out our id3tag struct
    for(x=0;x<30;x++)
        ID3Tag->title[x] = buffer[x+3]; //take 3 off cause of TAG
        ID3Tag->title[30] = '\0';

    for(x=0;x<30;x++)
        ID3Tag->artist[x] = buffer[x+33]; //33 = TAG + title
        ID3Tag->artist[30] = '\0';

    for(x=0;x<30;x++)
        ID3Tag->album[x] = buffer[x+63]; //TAG + title + artist
        ID3Tag->album[30] = '\0';

    for(x=0;x<4;x++)
        ID3Tag->year[x] = buffer[x+93]; //TAG + title + artist + album
        ID3Tag->year[4] = '\0';

    for(x=0;x<30;x++)
        ID3Tag->comment[x] = buffer[x+97]; //TAG + title + artist + album + year
        ID3Tag->comment[30] = '\0';

    if(buffer[127] > 0 && buffer[127] < 256)
        ID3Tag->genre = buffer[127]; //If its between 1-255, put it
    else
        ID3Tag->genre = 255; //255 means unused

    //ID3 1.1 compatibility (Track field)
    if(ID3Tag->comment[28] == '\0')
        ID3Tag->track = ID3Tag->comment[29]; //If comment ends at 28.. then 29 is the track
    else
        ID3Tag->track = 0; //0 mean's unknown track
    return 1;
}

int FileReader::ReadID3v2(const char* Filename, id3tag *ID3Tag)
{
    FILE *fp=fopen(Filename,"rb");
    char buffer[128];

    fseek(fp,10,SEEK_SET);
    fread(buffer,sizeof(char),sizeof(buffer),fp);

    if((buffer[0]=='I' && buffer[1] == 'D' && buffer[2] == '3'))
        return 1;
    return 0;
}
