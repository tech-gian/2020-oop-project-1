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


    // How many teachers out of classroom left
    int left = tcr_size;
    while (left > 0) {
        // Random select if teacher or student going in
        if (rand() % 2 == 0) {
            // Random select of student
            int pos = rand() % st_size;
            student* s = students[pos];

            // If student is out
            if (s->get_pos() == 'o') {
                scl.enter(*s);
            }
            // If student in yard
            else if (s->get_pos() == 'y') {
                if (scl.get_stairs().enter(*s)) {
                    scl.get_yard().exit(*s);
                }
            }
            // If student in stairs
            else if (s->get_pos() == 's') {
                if (scl.get_flo(s->get_flo()).enter(*s)) {
                    scl.get_stairs().exit(*s);
                }
            }
            // If student in corridor (floor)
            else if (s->get_pos() == 'f') {
                flo* temp = &(scl.get_flo(s->get_flo()));
                if (temp->get_class(s->get_cls()).enter(*s)) {
                    scl.get_flo(s->get_flo()).get_cor().exit(*s);
                }
            }
        }
        else {
            // Random select of teacher
            int pos = rand() % tcr_size;
            teacher* t = teachers[pos];
            
            // If teacher isn't in the classroom
            if (!t->get_in()) {
                scl.get_flo(t->get_flo()).get_class(t->get_cls()).place(*t);
                left--;
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
