//////////////////////////////////////////////
// File with main function, to run the program
//////////////////////////////////////////////


#include "classes.h"


int main(void) {

    student s("John", 0, 1);

    teacher t("Nick", 3, 4);

    student* s1 = new student("j", 5, 6);
    delete s1;


    cout << "Everything works fine" << endl;

    return 0;
}