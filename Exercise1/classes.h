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
    student(string name, int floor_no, int class_no);
    // Destructor
    ~student();

    // Printing function
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
    // Printing function
    void print(void) const;
};





class classroom {
    int no;
    int st_no;
    student** students;
    teacher* tchr;

    int capacity;

    public:

    // Constructor
    classroom(int cap, int no);
    // Destructor
    ~classroom();

    // Entering function
    bool enter(student& s);
    // Printing function
    void print(void) const;
};

class corridor {
    int st_no;
    student** students;

    int capacity;

    public:

    // Constructor
    corridor(int cap);
    // Destructor
    ~corridor();

    // Entering function
    bool enter(student& s);
    void exit();
    // Printing function
    void print(void) const;
};


class yard {
    int st_no;
    student** students;

    int capacity;

    public:

    // Constructor
    yard(int cap);
    // Destructor
    ~yard();

    // Entering function
    bool enter(student& s);
    void exit();
    // Printing function
    void print(void) const;
};

class stairs {
    int st_no;
    student** students;

    int capacity;

    public:

    // Constructor
    stairs(int cap);
    // Destructor
    ~stairs();

    // Entering function
    bool enter(student& s);
    void exit();
    // Printing function
    void print(void) const;
};

class flo {
    int no;
    classroom* clsrm[6];
    // classroom c0;
    // classroom c1;
    // classroom c2;
    // classroom c3;
    // classroom c4;
    // classroom c5;

    corridor* cor;

    public:

    // Constructor
    flo(int cls_cap, int cor_cap, int no);
    // Destructor
    ~flo();

    void enter();
    // Printing function
    void print(void) const;
};



class school {
    yard* syard;
    stairs* sstairs;
    flo* sflo[3];

    public:

    // Constructor
    school(int yard_cap, int st_cap, int cls_cap, int cor_cap);
    // Destructor
    ~school();

    void enter();
    // Printing Function
    void print(void) const;
};
