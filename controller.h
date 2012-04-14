#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "tagfactory.h"
#include <QObject>

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = 0); //upon controller being initiated it needs to:
                    //1.     display splash screen
                    //prompt user for music folder
                    //start by just choosing some tag
                    //tell the view to display the sphere currently selected which will be a member variable
                    //tell the view to display the 5 spheres around it which are stored as member variables
                    //listen for clicks
                    //upon getting a click on an outer sphere update its 2 member variables and redraw its stuff
                    //upon getting a click on its centre/song clicked sphere changes the view to some view that will include
                        //all of its tags/mockup buttons saying play music ect. and a back button that will take you back to where were when you clicked the song
                    //upon getting click on exit button end application
    void display_splash_screen();
    void request_filepath();//populates the Tagfactory with input string
    vector<string> get_related_tags(string s); // passes call to tagfactory
    void setFirstTag(void);
public slots:
    void onLabelClick(int label_index);
signals:
    void setNewCentreTag(vector<string> related_tag_names);
private:
    vector<string> spheres_in_view; // holds the 5 instances of names of spheres around current sphere
    string current_sphere;//sphere currently selected
    string filename, current_tag_name;


};

#endif // CONTROLLER_H
