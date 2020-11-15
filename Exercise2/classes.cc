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

void couple::add_child(child* extra) {
    if (extra->get_gen() == 'b') this->boy = extra;
    else this->girl = extra;
}

void couple::print(void) const {
    cout << "Below children are a couple:" << endl;
    if (this->boy != NULL) this->boy->print();
    if (this->girl != NULL) this->girl->print();
}

child* couple::change(child* chi) {

    child* temp;
    if (chi->get_gen() == 'b') {
        temp = this->boy;
        this->boy = chi;
    }
    else {
        temp = this->girl;
        this->girl = chi;
    }

    return temp;
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
        this->gender = 'e';
    }
    else if (i > j) {
        temp = new couple(boys[i-1], NULL);
        this->gender = 'b';
    }
    else {
        temp = new couple(NULL, girls[j-1]);
        this->gender = 'g';
    }

    this->couples[couples_size-1] = temp;

    // Delete temp boys, girls
    delete[] boys;
    delete[] girls;

    // Define size of couples
    this->size = couples_size;
    this->no = no;
    this->disorder = 0;

    cout << "A New Sequence_of_couples created" << endl;
}


seq_chi::~seq_chi() {
    for (int i=0 ; i<this->size ; i++) {
        delete this->couples[i];
    }

    delete[] this->couples;

    cout << "A Sequence_of_couples to be destroyed" << endl;
}

child* seq_chi::move_extra_child(void) {
    child* temp = this->couples[this->size-1]->get_child();

    delete this->couples[this->size-1];
    couple** new_couples = new couple*[this->size-1];
    this->size--;
    for (int i=0 ; i<this->size ; i++) {
        new_couples[i] = this->couples[i];
    }
    delete[] this->couples;
    this->couples = new_couples;

    return temp;
}

void seq_chi::print(void) const {
    cout << "Below couples are in sequence " << this->no << endl;
    for (int i=0 ; i<this->size ; i++) {
        this->couples[i]->print();
    }
}



// Seq_seq Functions

seq_seq::seq_seq(seq_chi** seqs, int size, int Tquiet, int Tmessy) {

    this->seqs = new seq_chi*[size];

    seq_chi** boy = new seq_chi*[size];
    seq_chi** girl = new seq_chi*[size];

    int j = 0;
    int boys=0, girls=0;
    for (int i=0 ; i<size ; i++) {
        if (seqs[i]->get_gen() == 'e') {
            this->seqs[j] = seqs[i];
            j++;
        }
        else if (seqs[i]->get_gen() == 'b') {
            boy[boys] = seqs[i];
            boys++;
        }
        else {
            girl[girls] = seqs[i];
            girls++;
        }
    }

    int max_size = (boys>girls) ? boys : girls;
    int min_size = (girls>boys) ? boys : girls;
    for (int i=0 ; i<max_size ; i++) {
        if (i < min_size) {
            child* temp = girl[i]->move_extra_child();
            boy[i]->merge_2_children(temp);
            this->seqs[j] = boy[i];
            j++;
            this->seqs[j] = girl[i];
            j++;
        }
        else {
            if (boys > girls) {
                this->seqs[j] = boy[i];
                j++;
            }
            else {
                this->seqs[j] = girl[i];
                j++;
            }
        }
    }

    // Define building blocks
    this->size = size;
    this->Tquiet = Tquiet;
    this->Tmessy = Tmessy;

    // Delete extra arrays, used for the algorithm
    delete[] boy;
    delete[] girl;

    cout << "A New Sequence_of_sequences has been created" << endl;
}

seq_seq::~seq_seq() {
    delete[] this->seqs;

    cout << "A Sequence_of_sequences to be destroyed" << endl;
}

void seq_seq::print(void) const {
    cout << "Below sequences are in a sequence of classrooms:" << endl;
    cout << this->size << endl;
    for (int i=0 ; i<this->size ; i++) {
        this->seqs[i]->print();

        // Print Message for disorder
        if (this->seqs[i]->get_dis() < Tquiet) {
            cout << "What a quiet class!" << endl;
        }
        else if (this->seqs[i]->get_dis() > Tmessy) {
            cout << "What a mess!" << endl;
        }
        else {
            cout << "Please, be quiet!" << endl;
        }
    }
}

void seq_seq::change(child** children, int len) {

    int counter = 0;
    if (len <= 2) {
        // Loop for every child in children
        // (max of 2 children)
        for (int k=0 ; k<len ; k++) {
            int no = children[k]->get_no();
            couple** temp = this->seqs[no]->get_couples();

            for (int i=0 ; i<this->seqs[no]->get_size() ; i++) {
                if (temp[i]->check(children[k])) {
                    if (i == 0) {
                        child* chi = temp[i+1]->change(children[k]);
                        temp[i]->change(chi);
                    }
                    else {
                        child* chi = temp[i-1]->change(children[k]);
                        temp[i]->change(chi);
                    }
                    this->seqs[no]->set_dis(1);
                    break;
                }
            }

            // Print sequence that changed
            this->seqs[no]->print();
        }

    }
    else {
        // Check if there are consecutive or not
        bool con = true;
        int no = children[0]->get_no();
        couple** temp = this->seqs[no]->get_couples();
        for (int i=0 ; i<this->seqs[no]->get_size() ; i++) {
            if (temp[i]->check(children[0])) {
                for (int j=i+1 ; j<this->seqs[no]->get_size() ; j++) {
                    if (!temp[j]->check(children[j-i])) {
                        con = false;
                        break;
                    }
                }
                break;
            }
        }

        // Initialize srand
        srand(time(NULL));

        if (con) {
            // Loop for every child in children
            // if consecutive
            for (int k=0 ; k<len ; k++) {
                no = children[k]->get_no();
                temp = this->seqs[no]->get_couples();
                int new_no = rand() % this->size;

                for (int i=0 ; i<this->seqs[no]->get_size() ; i++) {
                    if (temp[i]->check(children[k])) {
                        int ran = rand() % (this->seqs[new_no]->get_size() - 1);
                        child* chi = this->seqs[new_no]->get_couples()[ran]->change(children[k]);
                        temp[i]->change(chi);

                        this->seqs[no]->set_dis(2);
                        break;
                    }
                }

                // Print sequence that changed
                this->seqs[no]->print();
            }

        }
        else {
            // Loop for every child in children
            // if not consecutive
            for (int k=0 ; k<len ; k++) {
                no = children[k]->get_no();
                temp = this->seqs[no]->get_couples();

                for (int i=0 ; i<this->seqs[no]->get_size() ; i++) {
                    if (temp[i]->check(children[k])) {
                        if (no < this->size-1) {
                            int ran = rand() % (this->seqs[no+1]->get_size() - 1);
                            child* chi = this->seqs[no+1]->get_couples()[ran]->change(children[k]);
                            temp[i]->change(chi);
                        }
                        else {
                            int ran = rand() % (this->seqs[no-1]->get_size() - 1);
                            child* chi = this->seqs[no-1]->get_couples()[ran]->change(children[k]);
                            temp[i]->change(chi);
                        }
                        this->seqs[no]->set_dis(2);
                        break;
                    }
                }

                // Print sequence that changed
                this->seqs[no]->print();
            }
        }


    }
}


