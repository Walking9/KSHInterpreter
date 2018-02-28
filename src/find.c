//
// Created by brunon on 18-2-27.
//

#include <dirent.h>
#include <stddef.h>
#include <stdio.h>
#include <memory.h>
#include "../lib/preprocess.h"

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

int main(int argc, char*argv[]){
    char lines[argc+1][255];
    predealLine(argc, argv, lines);
    printf("ksh-shell:\n");
	ksh_find(lines[1]);

    return 0;
}
