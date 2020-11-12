/////////////////////////////////////////////
// Implementation of functions of the classes
/////////////////////////////////////////////


// Header file included
#include "classes.h"


// Child Functions

child::child(string name, int class_no, char gender) {
    this->name = name;
    this->class_no = class_no;
    this->gender = gender;

    cout << "A New Child has been created" << endl;
    cout << this->name << " " << this->class_no << endl;
}

child::~child() {
    cout << "A Child to be destroyed" << endl;
    cout << this->name << " " << endl;
}

void child::print(void) const {
    cout << this->name << endl;
}



// Couple Functions

couple::couple(child* boy, child* girl) {
    this->boy = boy;
    this->girl = girl;

    cout << "A New Couple has been created" << endl;
}

couple::~couple() {
    cout << "A Couple to be destroyed" << endl;
}


// Seq_chi Functions

seq_chi::seq_chi(child** children, int size, int no) {

    int i=0, j=0;
    child** boys = new child*[size];
    child** girls = new child*[size];
    for (int k=0 ; k<size ; k++) {
        if (children[k]->get_gen() == 'b') {
            boys[i] = children[k];
            i++;
        }
        else {
            girls[j] = children[k];
            j++;
        }
    }

    int couples_size;
    if (i > j) couples_size = i;
    else couples_size = j;
    this->couples = new couple*[couples_size];

    for (int k=0 ; k<couples_size-1 ; k++) {
        couple* temp = new couple(boys[k], girls[k]);
        this->couples[k] = temp;
    }

    couple* temp;
    if (i == j) {
        temp = new couple(boys[i-1], girls[j-1]);
    }
    else if (i > j) {
        temp = new couple(boys[i-1], NULL);
    }
    else {
        temp = new couple(NULL, girls[j-1]);
    }

    this->couples[couples_size-1] = temp;

    // Delete temp boys, girls
    delete[] boys;
    delete[] girls;

    // Define size of couples
    this->size = couples_size;
    this->no = no;
}


seq_chi::~seq_chi() {
    for (int i=0 ; i<this->size ; i++) {
        delete this->couples[i];
    }

    delete[] this->couples;

    cout << "A Seq_chi to be destroyed" << endl;
}


// Seq_seq Functions

seq_seq::seq_seq(seq_chi** seqs, int size) {

}

