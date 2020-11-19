//////////////////////////////////////////////
// File with main function, to run the program
//////////////////////////////////////////////


// Header file included
#include "School.h"


int main(int argc, char* argv[]) {

    // Arguments from command line
    int cclass = atoi(argv[1]);
    int cyard = atoi(argv[2]);
    int cstairs = atoi(argv[3]);
    int ccor = atoi(argv[4]);


    // Creating school
    school scl(cyard, cstairs, cclass, ccor);

    ///////////////
    // Reading data

    // Students size
    int st_size;
    cin >> st_size;
    student** students = new student*[st_size];
    for (int i=0 ; i<st_size ; i++) {
        string name;
        int flo_no, cls_no;
        cin >> name >> flo_no >> cls_no;

        students[i] = new student(name, flo_no, cls_no);
    }

    // Teacher size
    int tcr_size;
    cin >> tcr_size;
    teacher** teachers = new teacher*[tcr_size];
    for (int i=0 ; i<tcr_size ; i++) {
        string name;
        int flo_no, cls_no;
        cin >> name >> flo_no >> cls_no;

        teachers[i] = new teacher(name, flo_no, cls_no);
    }


    // Initialize srand
    srand(time(NULL));


    int i = 0;
    // Finish the simulation
    // All students got in school
    while (i < st_size) {
        // Random pick for student
        if (rand() % 2 == 0) {
            student* s = students[i];

            // Check if student fits in school
            if (!scl.enter(s)) {
                // Finish the simulation
                // No more fit in school
                cout << "The school is full!" << endl;
                break;
            }

            // Going to the next student
            i++;
        }
        // Random pick for teacher
        else {
            int pos = rand() % tcr_size;
            teacher* t = teachers[pos];

            // If teacher is already in the classroom
            // print that statement
            if (!scl.place(t)) {
                t->print();
                cout << "Already in classroom" << endl;
            }
        }
    }


    // Printing school
    scl.print();



    // Deleting data
    for (int i=0 ; i<st_size ; i++) {
        delete students[i];
    }
    delete[] students;

    for (int i=0 ; i<tcr_size ; i++) {
        delete teachers[i];
    }
    delete[] teachers;

    return 0;
}
