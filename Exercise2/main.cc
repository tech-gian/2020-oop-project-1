//////////////////////////////////////////////
// File with main function, to run the program
//////////////////////////////////////////////


// Header file include
#include "classes.h"


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
    for (int i=0 ; i<size ; i++) {
        string str;
        cin >> str;
        int no = rand() % K;

        children[i] = new child(str, no, (i%2==0) ? 'b' : 'g');
    }







    // Delete data
    for (int i=0 ; i<size ; i++) {
        delete children[i];
    }
    delete[] children;


    return 0;
}