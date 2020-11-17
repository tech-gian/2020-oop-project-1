//////////////////////////////////////////////
// Header file with definitions of all classes
//////////////////////////////////////////////


// Libraries included
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

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
    // Get class_no
    int get_no(void) const { return this->class_no; }
    // Set class_no
    int set_no(int no) { this->class_no = no; }
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
    
    // Return extra child
    child* get_child(void) { return (boy==NULL) ? this->girl : this->boy; }
    // Add extra child
    void add_child(child* extra, int no);
    // Print couple
    void print(void) const;
    // Check if child is here
    bool check(child* chi) { return (chi==boy || chi==girl) ? true : false; }

    // Change children
    child* change(child* chi, char gen);
};



// Sequence of couples
class seq_chi {
    couple** couples;   // Array of couple*
    int size;           // Size of array
    int no;             // Sequence's number
    int disorder;       // Disorder in classroom

    // 'e' -> equal boys-girls
    // 'b' -> last_couple boy
    // 'g' -> last_couple girl
    char gender;

    public:
    // Constructor
    seq_chi(child** children, int size, int no);
    // Destructor
    ~seq_chi();

    // Get classroom no
    int get_no(void) const { return this->no; }
    // Get last_couple gender
    char get_gen(void) const { return this->gender; }
    // Get size
    int get_size(void) const { return this->size; }
    // Get disorderd
    int get_dis(void) const { return this->disorder; }
    // Add to disorder
    void set_dis(int num) { this->disorder += num; }

    // Return last-alone child and resize couples
    child* move_extra_child(void);
    // Merge extra with the last child
    void merge_2_children(child* extra, int no) { this->couples[this->size-1]->add_child(extra, no); };
    // Print each couple
    void print(void) const;
    // Return couples
    couple** get_couples(void) const { return this->couples; }
};



// Sequence of sequences of couples
class seq_seq {
    seq_chi** seqs;         // Array of seq_chi
    int size;               // Size of array

    double Tquiet;          // Rate of disorder
    double Tmessy;          // to print each message

    public:
    // Constructor
    seq_seq(seq_chi** seqs, int size, double Tquiet, double Tmessy);
    // Destructor
    ~seq_seq();

    // Change children who create disorder
    void change(child** children, int len);
    // Print sequences
    void print(void) const;
};
