//
// Created by brunon on 18-2-27.
//

#ifndef KSHINTERPRETER_FIND_H
#define KSHINTERPRETER_FIND_H

#include <dirent.h>
#include <stddef.h>
#include <stdio.h>
#include <memory.h>

void ksh_find(char* find) {
    DIR* dir_ptr = opendir(".");    //当前目录下
    struct dirent* direntp;
    while((direntp = readdir(dir_ptr)) != NULL) {  //逐个对比目录里的文件
        if(strcmp(direntp->d_name, find) == 0) {
            printf("%s\n", find);
            return;
        }
    }
    printf("find: '%s': 没有那个文件或目录", find);
    printf("\n");
    closedir(dir_ptr);
}
#endif //KSHINTERPRETER_FIND_H
