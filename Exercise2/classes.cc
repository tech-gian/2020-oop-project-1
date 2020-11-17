/////////////////////////////////////////////
// Implementation of functions of the classes
/////////////////////////////////////////////


// Header file included
#include "classes.h"



//////////////////
// Child Functions

child::child(string name, int class_no, char gender) {
    this->name = name;
    this->class_no = class_no;
    this->gender = gender;

    // Assign items and print construction
    cout << "A New Child has been created" << endl;
    cout << this->name << " " << this->class_no << endl;
}

child::~child() {
    // Print destruction
    cout << "A Child to be destroyed" << endl;
    cout << this->name << " " << endl;
}

void child::print(void) const {
    // Print name of child
    cout << this->name << endl;
}



///////////////////
// Couple Functions

couple::couple(child* boy, child* girl) {
    this->boy = boy;
    this->girl = girl;

    // Assign items and print construction
    cout << "A New Couple has been created" << endl;
}

couple::~couple() {
    // Print construction
    cout << "A Couple to be destroyed" << endl;
}

void couple::add_child(child* extra, int no) {
    // Add child, depending on its gender
    if (extra->get_gen() == 'b') {
        this->boy = extra;
        this->boy->set_no(no);
    }
    else {
        this->girl = extra;
        this->girl->set_no(no);
    }
}

void couple::print(void) const {
    // Print couple
    cout << "Below children are a couple:" << endl;
    if (this->boy != NULL) this->boy->print();
    if (this->girl != NULL) this->girl->print();
}

child* couple::change(child* chi, char gen) {
    // Change boy or girl of the couple
    // with chi
    child* temp;
    
    // If chi is NULL
    if (chi == NULL) {
        if (gen == 'g') {
            temp = this->girl;
            this->girl = chi;
        }
        else {
            temp = this->boy;
            this->boy = chi;
        }
        return temp;
    }

    // Else check the gender of chi
    // and change with the correspoding one
    if (chi->get_gen() == 'b') {
        if (this->boy != NULL) {
            temp = this->boy;
            this->boy = chi;
        }
        else {
            this->boy = chi;
            temp = NULL;
        }
    }
    else {
        if (this->girl != NULL) {
            temp = this->girl;
            this->girl = chi;
        }
        else {
            this->girl = chi;
            temp = NULL;
        }
    }

    return temp;
}



////////////////////
// Seq_chi Functions

seq_chi::seq_chi(child** children, int size, int no) {
    // Divide children into boys and girls
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

    // Create couple** array
    int couples_size;
    if (i > j) couples_size = i;
    else couples_size = j;
    this->couples = new couple*[couples_size];

    // Get all couples in the array
    for (int k=0 ; k<couples_size-1 ; k++) {
        couple* temp = new couple(boys[k], girls[k]);
        this->couples[k] = temp;
    }

    // Check the last couple
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

    // Assign items and print construction
    this->size = couples_size;
    this->no = no;
    this->disorder = 0;

    cout << "A New Sequence_of_couples created" << endl;
}


seq_chi::~seq_chi() {
    // Delete array
    for (int i=0 ; i<this->size ; i++) {
        delete this->couples[i];
    }
    delete[] this->couples;

    // Print destruction
    cout << "A Sequence_of_couples to be destroyed" << endl;
}

child* seq_chi::move_extra_child(void) {
    // Get the last couple's child
    child* temp = this->couples[this->size-1]->get_child();

    // Delete the last couple and allocate new space for the rest
    delete this->couples[this->size-1];
    couple** new_couples = new couple*[this->size-1];
    this->size--;
    for (int i=0 ; i<this->size ; i++) {
        new_couples[i] = this->couples[i];
    }
    delete[] this->couples;
    this->couples = new_couples;

    // Return the extra_child
    return temp;
}

void seq_chi::print(void) const {
    // Print the sequence of couples
    cout << "Below couples are in sequence " << this->no << endl;
    for (int i=0 ; i<this->size ; i++) {
        this->couples[i]->print();
    }
}



////////////////////
// Seq_seq Functions

seq_seq::seq_seq(seq_chi** seqs, int size, double Tquiet, double Tmessy) {
    // Allocate array seqs
    this->seqs = new seq_chi*[size];

    seq_chi** boy = new seq_chi*[size];
    seq_chi** girl = new seq_chi*[size];

    // Get all 'equal' sequences in the array
    // and the extra_boy or extra_girl int boy or girl array
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

    // Do the algorithm to fit the 'boy' and 'girl' sequence
    // in the main array, with the instructions from the pronunciation
    int max_size = (boys>girls) ? boys : girls;
    int min_size = (girls>boys) ? boys : girls;
    for (int i=0 ; i<max_size ; i++) {
        if (i < min_size) {
            child* temp = girl[i]->move_extra_child();
            boy[i]->merge_2_children(temp, boy[i]->get_no());
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

    // Assing building blocks and print construction
    this->size = size;
    this->Tquiet = Tquiet;
    this->Tmessy = Tmessy;

    // Delete extra arrays, used for the algorithm
    delete[] boy;
    delete[] girl;

    cout << "A New Sequence_of_sequences has been created" << endl;
}

seq_seq::~seq_seq() {
    // Delete array and print destruction
    delete[] this->seqs;

    cout << "A Sequence_of_sequences to be destroyed" << endl;
}

void seq_seq::print(void) const {
    // Print the sequence of sequences
    cout << "Below sequences are in a sequence of classrooms:" << endl;
    for (int i=0 ; i<this->size ; i++) {
        this->seqs[i]->print();

        // Print Message for disorder
        double dis = (double)this->seqs[i]->get_dis() / ((double)this->seqs[i]->get_size() * 2.0);
        if (dis < Tquiet) {
            cout << "What a quiet class!" << endl;
        }
        else if (dis > Tmessy) {
            cout << "What a mess!" << endl;
        }
        else {
            cout << "Please, be quiet!" << endl;
        }
    }
}

void seq_seq::change(child** children, int len) {
    // Change children (array) with other children
    // depending on the pronunciation

    // If are max of 2 children in the array
    if (len <= 2) {
        // Loop for every child in children
        // (max of 2 children)
        for (int k=0 ; k<len ; k++) {
            int no = children[k]->get_no();

            // Get the couple** array that every child belongs
            couple** temp;
            int pos;
            for (int i=0 ; i<this->size ; i++) {
                if (this->seqs[i]->get_no() == no) {
                    temp = this->seqs[i]->get_couples();
                    pos = i;
                    break;
                }
            }

            // Change each child with child from the same sequence
            for (int i=0 ; i<this->seqs[pos]->get_size() ; i++) {
                if (temp[i]->check(children[k])) {
                    if (i == 0) {
                        // Don't care about gen we give, because children[k] != NULL
                        child* chi = temp[i+1]->change(children[k], 'b');
                        temp[i]->change(chi, children[k]->get_gen());
                    }
                    else {
                        // Don't care about gen we give, because children[k] != NULL
                        child* chi = temp[i-1]->change(children[k], 'b');
                        temp[i]->change(chi, children[k]->get_gen());
                    }
                    this->seqs[pos]->set_dis(1);
                    break;
                }
            }

            // Print sequence that changed
            this->seqs[no]->print();
        }

    }
    else {
        // Check if there are consecutive or not
        // (for more than 2 children)
        bool con = true;
        int no = children[0]->get_no();

        // Get couple** array of the 1st child
        couple** temp;
        int pos;
        for (int i=0 ; i<this->size ; i++) {
            if (this->seqs[i]->get_no() == no) {
                temp = seqs[i]->get_couples();
                pos = i;
                break;
            }
        }

        // Check if all children are consecutively
        for (int i=0 ; i<this->seqs[pos]->get_size() ; i++) {
            if (temp[i]->check(children[i])) {
                for (int j=i+1 ; j<this->seqs[pos]->get_size() ; j++) {
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

        // Ιf consecutive
        if (con) {
            // Loop for every child in children
            for (int k=0 ; k<len ; k++) {
                no = children[k]->get_no();

                // Get the couple** array of each child
                for (int i=0 ; i<this->size ; i++) {
                    if (this->seqs[i]->get_no() == no) {
                        temp = seqs[i]->get_couples();
                        pos = i;
                        break;
                    }
                }

                int new_no = rand() % this->size;

                // Change with children of random classrooms
                for (int i=0 ; i<this->seqs[pos]->get_size() ; i++) {
                    if (temp[i]->check(children[k])) {
                        int ran = rand() % (this->seqs[new_no]->get_size());
                        // Don't care about gen we give, because children[k] != NULL
                        child* chi = this->seqs[new_no]->get_couples()[ran]->change(children[k], 'b');
                        temp[i]->change(chi, children[k]->get_gen());

                        this->seqs[pos]->set_dis(2);
                        break;
                    }
                }

                // Print sequence that changed
                this->seqs[pos]->print();
            }

        }
        // if not consecutive
        else {
            // Loop for every child in children
            for (int k=0 ; k<len ; k++) {
                no = children[k]->get_no();

                // Get the couple** array of each child
                for (int i=0 ; i<this->size ; i++) {
                    if (this->seqs[i]->get_no() == no) {
                        temp = seqs[i]->get_couples();
                        pos = i;
                        break;
                    }
                }

                // Change with children of the next classroom
                // (or the 1st if it's the last one)
                for (int i=0 ; i<this->seqs[pos]->get_size() ; i++) {
                    if (temp[i]->check(children[k])) {
                        if (pos < this->size-1) {
                            int ran = rand() % (this->seqs[pos+1]->get_size());
                            // Don't care about gen we give, because children[k] != NULL
                            child* chi = this->seqs[pos+1]->get_couples()[ran]->change(children[k], 'b');
                            temp[i]->change(chi, children[k]->get_gen());
                        }
                        else {
                            int ran = rand() % (this->seqs[0]->get_size());
                            // Don't care about gen we give, because children[k] != NULL
                            child* chi = this->seqs[0]->get_couples()[ran]->change(children[k], 'b');
                            temp[i]->change(chi, children[k]->get_gen());
                        }

                        this->seqs[pos]->set_dis(2);

                        break;
                    }
                }

                // Print sequence that changed
                this->seqs[pos]->print();
            }
        }
    }
}
