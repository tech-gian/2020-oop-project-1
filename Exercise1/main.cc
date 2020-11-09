//////////////////////////////////////////////
// File with main function, to run the program
//////////////////////////////////////////////


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
    int st_size;
    cin >> st_size;
    student** students = new student*[st_size];
    for (int i=0 ; i<st_size ; i++) {
        string name;
        int flo_no, cls_no;
        cin >> name >> flo_no >> cls_no;

        students[i] = new student(name, flo_no, cls_no);
    }

    int tcr_size;
    cin >> tcr_size;
    teacher** teachers = new teacher*[tcr_size];
    for (int i=0 ; i<tcr_size ; i++) {
        string name;
        int flo_no, cls_no;
        cin >> name >> flo_no >> cls_no;

        teachers[i] = new teacher(name, flo_no, cls_no);
    }


    // Srand
    srand(time(NULL));


    int left = tcr_size;
    while (left > 0) {
        if (rand() % 2 == 0) {
            int pos = rand() % st_size;
            student* s = students[pos];

            if (s->get_pos() == 'o') {
                scl.enter(*s);
            }
            else if (s->get_pos() == 'y') {
                if (scl.get_stairs().enter(*s)) {
                    scl.get_yard().exit(*s);
                }
            }
            else if (s->get_pos() == 's') {
                if (scl.get_flo(s->get_flo()).enter(*s)) {
                    scl.get_stairs().exit(*s);
                }
            }
            else if (s->get_pos() == 'f') {
                flo temp = scl.get_flo(s->get_flo());
                if (temp.get_class(s->get_cls()).enter(*s)) {
                    scl.get_flo(s->get_flo()).get_cor().exit(*s);
                }
            }
        }
        else {
            int pos = rand() % tcr_size;
            teacher* t = teachers[pos];
            
            if (!t->get_in()) {
                scl.get_flo(t->get_flo()).get_class(t->get_cls()).place(*t);
                left--;
            }
        }

        // flag = false;
        // for (int i=0 ; i<tcr_size ; i++) {
        //     if (!teachers[i]->get_in()) {
        //         flag = true;
        //         break;
        //     }
        // }
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
