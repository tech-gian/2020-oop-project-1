/////////////////////////////////////////////
// Implementation of functions of the classes
/////////////////////////////////////////////


// Header file included
#include "classes.h"




// Student Functions

void student::print(void) const {
    cout << name << endl;
}

student::student(string name="no", int floor_no=0, int class_no=0) {
    this->name = name;
    this->floor_no = floor_no;
    this->class_no = class_no;
    this->position = 'o';

    cout << "A New Student has been created!" << endl;
    cout << this->name << " " << this->class_no << endl;
}

student::~student() {
    cout << "A Student to be destroyed!" << endl;
    cout << this->name << " " << this->position << endl;
}




// Teacher Functions

void teacher::print(void) const {
    cout << "The teacher is: " << name << endl;
}

teacher::teacher(string name, int floor_no, int class_no) {
    this->name = name;
    this->floor_no = floor_no;
    this->class_no = class_no;
    this->in_class = false;

    cout << "A New Teacher has been created!" << endl;
    cout << this->name << " " << this->class_no << endl;
}

teacher::~teacher() {
    cout << "A Teacher to be destroyed!" << endl;
    cout << this->name << endl;
}



// Classroom Functions

void classroom::print(void) const {
    cout << "People in class " << no << " are: " << endl;

    for (int i=0 ; i<st_no ; i++) {
        students[i].print();
    }

    tchr.print();
}




// Corridor Functions

void corridor::print(void) const {
    cout << "People in corridor are: " << endl;

    for (int i=0 ; i<st_no ; i++) {
        students[i].print();
    }
}

corridor::corridor(int cap) {
    this->capacity = cap;
    this->st_no = 0;
    this->students = new student[cap];
    
    cout << "A New Corridor has been created!" << endl;
}

corridor::~corridor() {
    delete[] this->students;

    cout << "A Corridor to be destroyed!" << endl;
}




// Floor Functions

void flo::print(void) const {
    cout << "Floor number " << no << " contains: " << endl;

    for (int i=0 ; i<cl_no ; i++) {
        clsrm[i].print();
    }

    cor.print();
}




// Stairs Functions

void stairs::print(void) const {
    cout << "People in stairs are: " << endl;

    for (int i=0 ; i<st_no ; i++) {
        students[i].print();
    }
}

stairs::stairs(int cap) {
    this->capacity = cap;
    this->st_no = 0;
    this->students = new student[cap];

    cout << "A New Stairs has been created!" << endl;
}

stairs::~stairs() {
    delete[] this->students;

    cout << "A Stairs to be destroyed!" << endl;
}




// Yard Functions

void yard::print(void) const {
    cout << "People in schoolyard are: " << endl;

    for (int i=0 ; i<st_no ; i++) {
        students[i].print();
    }
}

yard::yard(int cap) {
    this->capacity = cap;
    this->st_no = 0;
    this->students = new student[cap];

    cout << "A New Yard has been created!" << endl;
}

yard::~yard() {
    delete[] this->students;

    cout << "A Yard to be destroyed!" << endl;
}



// School Functions

void school::print(void) const {
    cout << "School life consists of: " << endl;

    syard.print();
    sstairs.print();
    sflo0.print();
    sflo1.print();
    sflo2.print();
}
