//
// Created by brunon on 18-2-27.
//

#ifndef KSHINTERPRETER_DATE_H
#define KSHINTERPRETER_DATE_H

#include <time.h>
#include <stdio.h>

void ksh_date() {
    time_t rawtime;
    time(&rawtime);
    printf("%s", asctime(localtime(&rawtime)));
}

#endif //KSHINTERPRETER_DATE_H
