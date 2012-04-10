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
    id3tag ID3;
    if(ReadID3(filepath.c_str(),&ID3)){
        string artist = ID3.artist;
        int genre = ID3.genre;

        if(artist.length()>2){
            if(this->tagsToBeCreated.find(artist)==this->tagsToBeCreated.end()){
                //no tag yet
                vector<string> temp = *new vector<string>();
                temp.push_back(filepath);
                this->tagsToBeCreated[artist] = temp;
            } else {
                //tag found add to tags vector
                this->tagsToBeCreated[artist].push_back(filepath);
            }
        }
        if(genre){
            string genre_string = genreTosString( genre);
            if(this->tagsToBeCreated.find(genre_string)==this->tagsToBeCreated.end()){
                //no tag yet
                vector<string> temp = *new vector<string>();
                temp.push_back(filepath);
                this->tagsToBeCreated[genre_string] = temp;
            } else {
                //tag found add to tags vector
                this->tagsToBeCreated[genre_string].push_back(filepath);
            }
        }
    } else{
        cout<<"doesnt have ID3v1(end of file tagging) tag"<<endl;
    }


}
map<string, std::vector<string> > FileReader::get_multimap()
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

string genreTosString(int genre){
    if(genre<=10){
        return "first 10 genres";
    } else if(genre<=20 &&genre>10){
        return "second 10 genres";
    } else if(genre<=30 &&genre>20){
        return "third 10 genres";
    } else if(genre<=40 &&genre>30){
        return "forth 10 genres";
    } else if(genre<=50 &&genre>40){
        return "fifth 10 genres";
    } else if(genre<=60 &&genre>50){
        return "sixth 10 genres";
    } else if(genre<=70 &&genre>60){
        return "seventh 10 genres";
    } else if(genre<=80 &&genre>70){
        return "eighth 10 genres";
    } else if(genre<=90 &&genre>80){
        return "ninth 10 genres";
    } else if(genre<=100 &&genre>90){
        return "tenth 10 genres";
    } else {
        return "more then tenth genre";
    }

}
