//////////////////////////////////////////////
// File with main function, to run the program
//////////////////////////////////////////////


// Header file include
#include "classes.h"


int main(int argc, char* argv[]) {
    
    // Arguments from command line
    int K = atoi(argv[1]);
    int L = atoi(argv[2]);
    int Tquiet = atoi(argv[3]);
    int Tmessy = atoi(argv[4]);


    // Initialize srand
    srand(time(NULL));


    // Get data
    int size;
    cin >> size;
    child** children = new child*[size];
    for (int i=0 ; i<size ; i++) {
        string str;
        cin >> str;
        int no = rand() % K;

        children[i] = new child(str, no, (i%2==0) ? 'b' : 'g');
    }

    // Get children in K classrooms
    child*** chi_seq = new child**[K];
    for (int i=0 ; i<K ; i++) {
        chi_seq[i] = new child*[size];
    }
    int* pos = new int[K];
    for (int i=0 ; i<K ; i++) pos[i] = 0;

    for (int i=0 ; i<size ; i++) {
        int temp = rand() % K;
        chi_seq[temp][pos[temp]] = children[i];
        pos[temp]++;
    }

    // Get children in sequences (classrooms)
    seq_chi** seqs = new seq_chi*[K];
    for (int i=0 ; i<K ; i++) {
        seq_chi* temp = new seq_chi(chi_seq[i], pos[i], i);
        seqs[i] = temp;
    }

    // Get sequences_of_classrooms in a sequence
    seq_seq* seq = new seq_seq(seqs, K, Tquiet, Tmessy);

    // Print seq
    seq->print();





    // Delete data
    for (int i=0 ; i<K ; i++) {
        delete chi_seq[i];
    }
    delete[] chi_seq;
    delete[] pos;

    for (int i=0 ; i<K ; i++) {
        delete seqs[i];
    }
    delete[] seqs;

    delete[] seq;

    for (int i=0 ; i<size ; i++) {
        delete children[i];
    }
    delete[] children;


    return 0;
}