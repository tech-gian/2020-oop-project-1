//////////////////////////////////////////////
// Header file with definitions of all classes
//////////////////////////////////////////////


// Library included
#include <string>
#include <iostream>


using namespace std;


class student {
    string name;    // Student's name

    // Classroom data
    int floor_no;
    int class_no;

    // Current position in school
    // o -> out
    // y -> yard
    // s -> stairs
    // f -> corridor
    // c -> classroom
    char position;


    public:

    // Constructor
    // Dummy default values
    student(string name="no", int floor_no=0, int class_no=0);
    // Destructor
    ~student();

    void print(void) const;
};


class teacher {
    string name;    // Teacher's name

    // Classroom data
    int floor_no;
    int class_no;

    // Inside classroom or not
    bool in_class;


    public:

    // Constructor
    teacher(string name, int floor_no, int class_no);
    // Destructor
    ~teacher();
    void print(void) const;
};





class classroom {
    int no;
    int st_no;
    student* students;
    teacher tchr;

    public:

    classroom();
    ~classroom();

    void enter();
    void print(void) const;
};

class corridor {
    int st_no;
    student* students;

    int capacity;

    public:

    // Constructor
    corridor(int cap);
    // Destructor
    ~corridor();

    void enter();
    void exit();
    void print(void) const;
};


class yard {
    int st_no;
    student* students;

    int capacity;

    public:

    // Constructor
    yard(int cap);
    // Destructor
    ~yard();

    void enter();
    void exit();
    void print(void) const;
};

class stairs {
    int st_no;
    student* students;

    int capacity;

    public:

    // Constructor
    stairs(int cap);
    // Destructor
    ~stairs();

    void enter();
    void exit();
    void print(void) const;
};

class flo {
    int no;
    int cl_no;
    classroom clsrm[6];
    // classroom c0;
    // classroom c1;
    // classroom c2;
    // classroom c3;
    // classroom c4;
    // classroom c5;

    corridor cor;

    public:

    flo();
    ~flo();

    void enter();
    void print(void) const;
};



class school {
    yard syard;
    stairs sstairs;
    flo sflo0;
    flo sflo1;
    flo sflo2;

    public:

    school();
    ~school();

    void enter();
    void print(void) const;
};
