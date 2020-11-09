/////////////////////////////////////////////
// Implementation of functions of the classes
/////////////////////////////////////////////


// Header file included
#include "classes.h"




// Student Functions

void student::print(void) const {
    cout << name << endl;
}

student::student(string name, int floor_no, int class_no) {
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
        students[i]->print();
    }

    tchr->print();
}

classroom::classroom(int cap, int no) {
    this->capacity = cap;
    this->no = no;
    this->st_no = 0;
    this->students = new student*[cap];
    this->tchr = NULL;

    cout << "A New Classroom has been created!" << endl;
}

classroom::~classroom() {
    delete[] this->students;

    cout << "A Classroom to be destroyed!" << endl;
}


bool classroom::enter(student& s) {
    if (this->tchr != NULL) return false;
    if (st_no >= capacity) return false;

    this->students[st_no] = &s;
    st_no++;

    s.print();
    cout << "...enters classroom!" << endl;
    return true;
}

void classroom::place(teacher& t) {
    this->tchr = &t;
}




// Corridor Functions

void corridor::print(void) const {
    cout << "People in corridor are: " << endl;

    for (int i=0 ; i<st_no ; i++) {
        students[i]->print();
    }
}

corridor::corridor(int cap) {
    this->capacity = cap;
    this->st_no = 0;
    this->students = new student*[cap];
    
    cout << "A New Corridor has been created!" << endl;
}

corridor::~corridor() {
    delete[] this->students;

    cout << "A Corridor to be destroyed!" << endl;
}

bool corridor::enter(student& s) {
    if (st_no >= capacity) return false;

    this->students[st_no] = &s;
    st_no++;

    s.print();
    cout << "...enters corridor!" << endl;
    return true;
}

student* corridor::exit(void) {
    if (st_no == 0) return NULL;

    this->students[st_no-1]->print();
    cout << "...exits corridor!" << endl;
    this->st_no--;

    return this->students[st_no];
}




// Floor Functions

void flo::print(void) const {
    cout << "Floor number " << no << " contains: " << endl;

    for (int i=0 ; i<6 ; i++) {
        clsrm[i]->print();
    }

    cor->print();
}


flo::flo(int cls_cap, int cor_cap, int no) {
    this->no = no;
    this->cor = new corridor(cor_cap);

    for (int i=0 ; i<6 ; i++) {
        this->clsrm[i] = new classroom(cls_cap, i);
    }

    cout << "A New Floor has been created!" << endl;
}

flo::~flo() {
    delete this->cor;

    for (int i=0 ; i<6 ; i++) {
        delete this->clsrm[i];
    }
    delete[] this->clsrm;

    cout << "A Floor to be destroyed!" << endl;
}

bool flo::enter(student& s) {
    if (this->cor->enter(s) == true) {
        s.print();
        cout << "...enters floor!" << endl;
        return true;
    }

    return false;
}



// Stairs Functions

void stairs::print(void) const {
    cout << "People in stairs are: " << endl;

    for (int i=0 ; i<st_no ; i++) {
        students[i]->print();
    }
}

stairs::stairs(int cap) {
    this->capacity = cap;
    this->st_no = 0;
    this->students = new student*[cap];

    cout << "A New Stairs has been created!" << endl;
}

stairs::~stairs() {
    delete[] this->students;

    cout << "A Stairs to be destroyed!" << endl;
}

bool stairs::enter(student& s) {
    if (st_no >= capacity) return false;

    this->students[st_no] = &s;
    st_no++;

    s.print();
    cout << "...enters stairs!" << endl;
    return true;
}

student* stairs::exit(void) {
    if (st_no == 0) return NULL;

    this->students[st_no-1]->print();
    cout << "...exits stairs!" << endl;
    this->st_no--;

    return this->students[st_no];
}




// Yard Functions

void yard::print(void) const {
    cout << "People in schoolyard are: " << endl;

    for (int i=0 ; i<st_no ; i++) {
        students[i]->print();
    }
}

yard::yard(int cap) {
    this->capacity = cap;
    this->st_no = 0;
    this->students = new student*[cap];

    cout << "A New Yard has been created!" << endl;
}

yard::~yard() {
    delete[] this->students;

    cout << "A Yard to be destroyed!" << endl;
}

bool yard::enter(student& s) {
    if (st_no >= capacity) return false;

    this->students[st_no] = &s;
    st_no++;

    s.print();
    cout << "...enters schoolyard!" << endl;
    return true;
}

student* yard::exit(void) {
    if (st_no == 0) return NULL;

    this->students[st_no-1]->print();
    cout << "...exits schoolyard!" << endl;
    this->st_no--;

    return this->students[st_no];
}




// School Functions

void school::print(void) const {
    cout << "School life consists of: " << endl;

    syard->print();
    sstairs->print();

    for (int i=0 ; i<3 ; i++) {
        sflo[i]->print();
    }
}

school::school(int yard_cap, int st_cap, int cls_cap, int cor_cap) {
    this->syard = new yard(yard_cap);
    this->sstairs = new stairs(st_cap);

    for (int i=0 ; i<3 ; i++) {
        this->sflo[i] = new flo(cls_cap, cor_cap, i);
    }

    cout << "A New School has been created!" << endl;
}

school::~school() {
    delete this->syard;
    delete this->sstairs;

    for (int i=0 ; i<3 ; i++) {
        delete this->sflo[i];
    }
    delete[] sflo;

    cout << "A School to be destroyed!" << endl;
}

bool school::enter(student& s) {
    if (this->syard->enter(s) == true) {
        s.print();
        cout << "...enters school!" << endl;
        return true;
    }

    return false;
}


