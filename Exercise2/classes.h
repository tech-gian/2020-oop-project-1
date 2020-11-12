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
    // Get child's gender
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
    
    // Add extra child
    void add_child(child* extra);
    void print(void) const;

};



// Sequence of couples
class seq_chi {
    couple** couples;   // Array of couple*
    int size;           // Size of array
    int no;             // Sequence's number

    // 'e' -> equal boys-girls
    // 'b' -> last_couple boy
    // 'g' -> last_couple girl
    char gender;

    public:
    // Constructor
    seq_chi(child** children, int size, int no);
    // Destructor
    ~seq_chi();

    // Get last_couple gender
    char get_gen(void) const { return this->gender; }

    child* move_extra_child(void);
    // Merge extra with the last child
    void merge_2_children(child* extra) { this->couples[this->size-1]->add_child(extra); };
    void print(void) const;

};



// Sequence of sequences of couples
class seq_seq {
    seq_chi** seqs;     // Array of seq_chi
    int size;           // Size of array


    public:
    // Constructor
    seq_seq(seq_chi** seqs, int size);
    // Destructor
    ~seq_seq();
    void print(void) const;

};


