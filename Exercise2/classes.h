//////////////////////////////////////////////
// Header file with definitions of all classes
//////////////////////////////////////////////


// Libraries included
#include <string>
#include <iostream>

using namespace std;



// Child
class child {
    string name;    // Child's name
    int class_no;   // Child's classroom

    // 'b' -> boy
    // 'g' -> girl
    char gender;    // Child's gender


    public:

    // Constructor
    child(string name, int class_no, char gender);
    // Destructor
    ~child();
    // Getting child's gender
    char get_gen(void) const { return this->gender; }
    // Print child info
    void print(void) const;

};



// Couple
class couple {
    child* boy;
    child* girl;

    public:
    // Constructor
    couple(child* boy, child* girl);
    // Destructor
    ~couple();

};



// Sequence of couples
class seq_chi {
    couple** couples;   // Array of couple*
    int size;           // Size of array
    int no;             // Sequence's number

    public:
    // Constructor
    seq_chi(child** children, int size, int no);
    // Destructor
    ~seq_chi();

};



// Sequence of sequences of couples
class seq_seq {
    seq_chi** seqs;     // Array of seq_chi
    int size;           // Size of array


    public:
    seq_seq(seq_chi** seqs, int size);
    ~seq_seq();

};




// TO BE deleted
// Classroom
class classroom {
    int no;             // Classroom's number
    child** children;   // Sequence of students
    int disorder;       // Degree of disorder


    public:

    classroom();
    ~classroom();

    void change();
    void print();

};

