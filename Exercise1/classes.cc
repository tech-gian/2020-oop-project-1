/////////////////////////////////////////////
// Implementation of functions of the classes
/////////////////////////////////////////////


// Header file included
#include "classes.h"




// Students Functions

void student::print(void) const {
    cout << name << endl;
}




// Teacher Functions

void teacher::print(void) const {
    cout << "The teacher is: " << name << endl;
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



// Student Functions

void yard::print(void) const {
    cout << "People in schoolyard are: " << endl;

    for (int i=0 ; i<st_no ; i++) {
        students[i].print();
    }
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
