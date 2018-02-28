//
// Created by brunon on 18-2-28.
//

#ifndef KSHINTERPRETER_PWD_H
#define KSHINTERPRETER_PWD_H

#include <unistd.h>
#include <stdio.h>

#define MAX_SIZE_PATH 255        //最大路径长度

void ksh_pwd(){
    char path[MAX_SIZE_PATH];
    getcwd(path, MAX_SIZE_PATH);
    printf("%s\n", path);
}

#endif //KSHINTERPRETER_PWD_H
