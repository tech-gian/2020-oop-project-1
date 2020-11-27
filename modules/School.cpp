/////////////////////////////////////////////
// Implementation of functions of the classes
/////////////////////////////////////////////


// Header file included
#include "School.h"



//////////////////// 
// Student Functions

void student::print(void) const {
    cout << name << endl;
}

student::student(string name, int floor_no, int class_no) {
    this->name = name;
    this->floor_no = floor_no;
    this->class_no = class_no;
    // Initialize position to "out"
    this->position = 'o';

    cout << "A New Student has been created!" << endl;
    cout << this->name << " " << this->class_no << endl;
}

student::~student() {
    cout << "A Student to be destroyed!" << endl;
    cout << this->name << " " << this->position << endl;
}




////////////////////
// Teacher Functions

void teacher::print(void) const {
    cout << "The teacher is: " << name << endl;
}

teacher::teacher(string name, int floor_no, int class_no) {
    this->name = name;
    this->floor_no = floor_no;
    this->class_no = class_no;

    cout << "A New Teacher has been created!" << endl;
    cout << this->name << " " << this->class_no << endl;
}

teacher::~teacher() {
    cout << "A Teacher to be destroyed!" << endl;
    cout << this->name << endl;
}



//////////////////////
// Classroom Functions

void classroom::print(void) const {
    cout << "People in class " << no << " are: " << endl;

    // Print each student
    for (int i=0 ; i<st_no ; i++) {
        students[i]->print();
    }

    // If there is teacher, print it
    if (tchr != NULL) {
        tchr->print();
    }
}

classroom::classroom(int cap, int no) {
    this->capacity = cap;
    this->no = no;
    this->st_no = 0;
    // Allocate array with student*, size of cap
    this->students = new student*[cap];
    // Initialize with NULL the teacher
    this->tchr = NULL;

    cout << "A New Classroom has been created!" << endl;
}

classroom::~classroom() {
    // Deallocate array of students
    delete[] this->students;

    cout << "A Classroom to be destroyed!" << endl;
}

bool classroom::enter(student* s) {
    // Returns false if teacher is inside
    // or classroom is full
    if (this->tchr != NULL) return false;
    if (st_no >= capacity) return false;

    // Add student to array
    this->students[st_no] = s;
    st_no++;
    // Change the position
    s->set_pos('c');

    s->print();
    cout << "...enters classroom!" << endl;
    return true;
}



/////////////////////
// Corridor Functions

void corridor::print(void) const {
    cout << "People in corridor are: " << endl;

    // Print each student
    for (int i=0 ; i<st_no ; i++) {
        students[i]->print();
    }
}

corridor::corridor(int cap) {
    this->capacity = cap;
    this->st_no = 0;
    // Allocate array with student*, size of cap
    this->students = new student*[cap];
    
    cout << "A New Corridor has been created!" << endl;
}

corridor::~corridor() {
    // Deallocate array of students
    delete[] this->students;

    cout << "A Corridor to be destroyed!" << endl;
}

bool corridor::enter(student* s) {
    // If corridor is, return false
    if (st_no >= capacity) return false;

    // Add student to array
    this->students[st_no] = s;
    st_no++;
    s->set_pos('f');

    s->print();
    cout << "...enters corridor!" << endl;
    return true;
}

student* corridor::exit(void) {
    // If corridor is empty, return NULL
    if (st_no == 0) return NULL;

    this->st_no--;
    // Print exiting student
    this->students[st_no]->print();
    cout << "...exits corridor!" << endl;

    // Return the last student and replace it with NULL
    student* temp = this->students[st_no];
    this->students[st_no] = NULL;

    return temp;
}



//////////////////
// Floor Functions

void flo::print(void) const {
    cout << "Floor number " << no << " contains: " << endl;

    // Print each classroom
    for (int i=0 ; i<6 ; i++) {
        clsrm[i]->print();
    }

    // Print corridor
    cor->print();
}

flo::flo(int cls_cap, int cor_cap, int no) {
    this->no = no;
    // Allocate memory for corridor
    this->cor = new corridor(cor_cap);

    // Allocate memory for each classroom
    for (int i=0 ; i<6 ; i++) {
        this->clsrm[i] = new classroom(cls_cap, i);
    }

    cout << "A New Floor has been created!" << endl;
}

flo::~flo() {
    // Deallocate corridor
    delete this->cor;

    // Deallocate each classroom
    for (int i=0 ; i<6 ; i++) {
        delete this->clsrm[i];
    }

    cout << "A Floor to be destroyed!" << endl;
}

bool flo::enter(student* s) {
    // Enter student, if fit in corridor
    if (this->cor->enter(s) == true) {
        s->print();
        cout << "...enters floor!" << endl;

        // Try to get student in classroom
        s = this->cor->exit();
        if (!this->clsrm[s->get_cls()]->enter(s)) {
            this->cor->enter(s);
        }
        return true;
    }

    return false;
}

bool flo::place(teacher* t) {
    // If teacher isn't placed already
    if (this->clsrm[t->get_cls()]->get_tchr() != NULL) {
        this->clsrm[t->get_cls()]->set_tchr(t);

        cout << "A Teacher to be placed!" << endl;
        return true;
    }

    return false;
}



///////////////////
// Stairs Functions

void stairs::print(void) const {
    cout << "People in stairs are: " << endl;

    // Print each student
    for (int i=0 ; i<st_no ; i++) {
        students[i]->print();
    }
}

stairs::stairs(int cap) {
    this->capacity = cap;
    this->st_no = 0;
    // Allocate array of student*, size of cap
    this->students = new student*[cap];

    cout << "A New Stairs has been created!" << endl;
}

stairs::~stairs() {
    // Deallocate array
    delete[] this->students;

    cout << "A Stairs to be destroyed!" << endl;
}

bool stairs::enter(student* s) {
    // If stairs are full, return false
    if (st_no >= capacity) return false;

    // Add student to array
    this->students[st_no] = s;
    st_no++;
    s->set_pos('s');

    s->print();
    cout << "...enters stairs!" << endl;
    return true;
}

student* stairs::exit(void) {
    // If stairs are empty, return NULL
    if (st_no == 0) return NULL;

    this->st_no--;

    // Print exiting student
    this->students[st_no]->print();
    cout << "...exits stairs!" << endl;

    // Return the last student and replace it with NULL
    student* temp = this->students[st_no];
    this->students[st_no] = NULL;

    return temp;
}



/////////////////
// Yard Functions

void yard::print(void) const {
    cout << "People in schoolyard are: " << endl;

    // Print each student
    for (int i=0 ; i<st_no ; i++) {
        students[i]->print();
    }
}

yard::yard(int cap) {
    this->capacity = cap;
    this->st_no = 0;
    // Allocate array of student*, size of cap
    this->students = new student*[cap];

    cout << "A New Yard has been created!" << endl;
}

yard::~yard() {
    // Deallocate array
    delete[] this->students;

    cout << "A Yard to be destroyed!" << endl;
}

bool yard::enter(student* s) {
    // If yard is full, return false
    if (st_no >= capacity) return false;

    // Add student
    this->students[st_no] = s;
    st_no++;
    s->set_pos('y');

    s->print();
    cout << "...enters schoolyard!" << endl;
    return true;
}

student* yard::exit(void) {
    // If yard is empty, return NULL
    if (st_no == 0) return NULL;

    this->st_no--;

    // Print exiting student
    this->students[st_no]->print();
    cout << "...exits schoolyard!" << endl;

    // Return the last student and replace it with NULL
    student* temp = this->students[st_no];
    this->students[st_no] = NULL;

    return temp;
}



///////////////////
// School Functions

void school::print(void) const {
    cout << "School life consists of: " << endl;

    // Print yard and stairs
    syard->print();
    sstairs->print();

    // Print each floor
    for (int i=0 ; i<3 ; i++) {
        sflo[i]->print();
    }
}

school::school(int yard_cap, int st_cap, int cls_cap, int cor_cap) {
    // Allocate memory for yard, stairs
    this->syard = new yard(yard_cap);
    this->sstairs = new stairs(st_cap);

    // Allocate memory for each floor
    for (int i=0 ; i<3 ; i++) {
        this->sflo[i] = new flo(cls_cap, cor_cap, i);
    }

    cout << "A New School has been created!" << endl;
}

school::~school() {
    // Deallocate yard, stairs
    delete this->syard;
    delete this->sstairs;

    // Deallocate each floor
    for (int i=0 ; i<3 ; i++) {
        delete this->sflo[i];
    }

    cout << "A School to be destroyed!" << endl;
}

bool school::enter(student* s) {
    // If student fit in yard, enter it
    if (this->syard->enter(s) == true) {
        s->print();
        cout << "...enters school!" << endl;

        // Try to get student to stairs
        s = this->syard->exit();
        if (this->sstairs->enter(s)) {

            // Try to get student to floor (corridor)
            s = this->sstairs->exit();
            if (!this->sflo[s->get_flo()]->enter(s)) {
                this->sstairs->enter(s);
            }
        }
        else {
            this->syard->enter(s);
        }

        return true;
    }

    return false;
}

int school::enter(student** students, int len) {
    int counter = 0;

    // Insert as many as fit
    for (int i=0 ; i<len ; i++) {
        if (!this->enter(students[i])) {
            break;
        }
        counter++;
    }

    // Return how many got in
    return counter;
}

bool school::place(teacher* t) {
    // Return bool of flo->place
    return this->sflo[t->get_flo()]->place(t);
}
