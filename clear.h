//
// Created by brunon on 18-2-27.
//

#ifndef KSHINTERPRETER_CLEAR_H
#define KSHINTERPRETER_CLEAR_H

#include<stdio.h>

void ksh_clear() {
    printf("\033[2J");
}

#endif //KSHINTERPRETER_CLEAR_H
