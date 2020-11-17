//////////////////////////////////////////////
// File with main function, to run the program
//////////////////////////////////////////////


// Header file included
#include "classes.h"


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
            if (scl.enter(s)) {
                s = scl.get_yard().exit();

                // Check if student fits in stairs
                if (scl.get_stairs().enter(s)) {
                    s = scl.get_stairs().exit();

                    // Check if student fits in floor (corridor)
                    if (scl.get_flo(s->get_flo()).enter(s)) {
                        flo* temp = &(scl.get_flo(s->get_flo()));
                        s = temp->get_cor().exit();

                        // Check if student fits in classroom
                        if (!temp->get_class(s->get_cls()).enter(s)) {
                            temp->enter(s);
                        }
                    }
                    // If doesn't fit in floor, get him in stairs
                    else {
                        scl.get_stairs().enter(s);
                    }
                }
                // If doesn't fit in stairs, get him in schoolyard
                else {
                    scl.enter(s);
                }
            }
            else {
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

            // If teacher isn't in the classroom
            if (!t->get_in()) {
                scl.get_flo(t->get_flo()).get_class(t->get_cls()).place(t);
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
