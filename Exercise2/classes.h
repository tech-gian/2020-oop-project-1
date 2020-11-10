//////////////////////////////////////////////
// Header file with definitions of all classes
//////////////////////////////////////////////


// Libraries included
#include <string>
#include <iostream>

using namespace std;



// Child
class child {
    string name;    // Child's name
    int class_no;   // Child's classroom
    char gender;    // Child's gender


    public:

    // Constructor
    child(string name, int class_no, char gender);
    // Destructor
    ~child();
    // Print child info
    void print(void) const;

};


// Classroom
class classroom {
    int no;             // Classroom's number
    child** children;   // Sequence of students
    int disorder;       // Degree of disorder


    public:

    classroom();
    ~classroom();

    void change();
    void print();

};

