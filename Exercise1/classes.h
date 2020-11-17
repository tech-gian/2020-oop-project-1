//////////////////////////////////////////////
// Header file with definitions of all classes
//////////////////////////////////////////////


// Libraries included
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;


/////////////////
// People classes


// Student
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
    student(string name, int floor_no, int class_no);
    // Destructor
    ~student();

    // Setting position
    void set_pos(char pos) { this->position = pos; }
    // Getting position
    char get_pos(void) const { return this->position; }
    // Getting flo_no
    int get_flo(void) const { return this->floor_no; }
    // Getting class_no
    int get_cls(void) const { return this->class_no; }
    // Printing function
    void print(void) const;
};


// Teacher
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

    // Setting teacher in class
    void set_in(void) { this->in_class = true; }
    // Getting teacher in class
    bool get_in(void) const { return this->in_class; }
    // Getting flo_no
    int get_flo(void) const { return this->floor_no; }
    // Getting cls_no
    int get_cls(void) const { return this->class_no; }
    // Printing function
    void print(void) const;
};


/////////////////
// School classes


// Classroom
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
    bool enter(student* s);
    // Placing teacher function
    void place(teacher* t);
    // Printing function
    void print(void) const;
};


// Corridor
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
    bool enter(student* s);
    // Exiting function
    student* exit(void);
    // Printing function
    void print(void) const;
};


// Yard
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
    bool enter(student* s);
    // Exiting function
    student* exit(void);
    // Printing function
    void print(void) const;
};


// Stairs
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
    bool enter(student* s);
    // Exiting function
    student* exit(void);
    // Printing function
    void print(void) const;
};


// Floor
class flo {
    int no;
    classroom* clsrm[6];
    corridor* cor;

    public:

    // Constructor
    flo(int cls_cap, int cor_cap, int no);
    // Destructor
    ~flo();

    // Entering function
    bool enter(student* s);
    // Getting class
    classroom& get_class(int no) const { return *(this->clsrm[no]); }
    // Getting corridor
    corridor& get_cor(void) const { return *(this->cor); }
    // Printing function
    void print(void) const;
};


// School
class school {
    yard* syard;
    stairs* sstairs;
    flo* sflo[3];

    public:

    // Constructor
    school(int yard_cap, int st_cap, int cls_cap, int cor_cap);
    // Destructor
    ~school();

    // Entering function (for 1 student)
    bool enter(student* s);
    // Entering function (for multiple students)
    // Return how many got in
    int enter(student** students, int len);
    // Getting yard
    yard& get_yard(void) const { return *(this->syard); }
    // Getting stairs
    stairs& get_stairs(void) const { return *(this->sstairs); }
    // Getting floor
    flo& get_flo(int no) const {return *(this->sflo[no]); }
    // Printing Function
    void print(void) const;
};
