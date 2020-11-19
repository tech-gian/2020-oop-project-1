//////////////////////////////////////////////
// File with main function, to run the program
//////////////////////////////////////////////


// Header file include
#include "Sequence.h"


int main(int argc, char* argv[]) {
    
    // Arguments from command line
    int K = atoi(argv[1]);
    int L = atoi(argv[2]);
    double Tquiet = atof(argv[3]);
    double Tmessy = atof(argv[4]);


    // Initialize srand
    srand(time(NULL));


    // Get data
    int size;
    cin >> size;
    child** children = new child*[size];
    int no = 0;
    int counter = 0;
    bool flag = true;
    for (int i=0 ; i<size ; i++) {
        string str;
        cin >> str;        

        children[i] = new child(str, no, (i%2==0) ? 'b' : 'g');

        // Calculate number of classroom for this example input
        if (counter < size/K-1) {
            counter++;
        }
        else if (no < size%K && flag) {
            flag = false;
        }
        else {
            no++;
            counter = 0;
            flag = true;
        }
    }


    // Get children in K classrooms
    child*** chi_seq = new child**[K];
    for (int i=0 ; i<K ; i++) {
        chi_seq[i] = new child*[size];
    }
    int* pos = new int[K];
    for (int i=0 ; i<K ; i++) pos[i] = 0;

    for (int i=0 ; i<size ; i++) {
        int temp = children[i]->get_no();
        chi_seq[temp][pos[temp]] = children[i];
        pos[temp]++;
    }


    // Get children in sequences (classrooms)
    seq_chi** seqs = new seq_chi*[K];
    for (int i=0 ; i<K ; i++) {
        seqs[i] = new seq_chi(chi_seq[i], pos[i], i);
    }

    // Get sequences_of_classrooms in a sequence
    seq_seq* seq = new seq_seq(seqs, K, Tquiet, Tmessy);

    // Print seq
    seq->print();


    // Random children disorder
    for (int k=0 ; k<L ; k++) {
        int start = rand() % size;
        int end = rand() % size;

        if (end < start) {
            int temp = start;
            start = end;
            end = temp;
        }

        // Change the children, chosen in random
        for (int i=start ; i<end ; i++) children[i]->print();
        seq->change(children+start, end-start);
    }


    // Print how seq is now
    seq->print();


    // Delete data
    for (int i=0 ; i<size ; i++) {
        if (children[i] != NULL) delete children[i];
    }
    delete[] children;

    for (int i=0 ; i<K ; i++) {
        delete chi_seq[i];
    }
    delete[] chi_seq;

    delete[] pos;

    for (int i=0 ; i<K ; i++) {
        delete seqs[i];
    }
    delete[] seqs;

    delete seq;

    return 0;
}
