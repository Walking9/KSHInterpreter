//
// Created by brunon on 18-2-27.
//

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
//#include <ctype.h>
#include <string.h>
#include <regex.h>
#include "../include/line.h"

void ksh_mkdir(char* name){
    if(access(name,R_OK)){
        //printf("\n!\n");
        char cm[255]="./";
        strcat(cm, name);
        mkdir(cm, S_IRWXU|S_IRGRP|S_IROTH);
    }
    else{
        printf("mkdir cannot create directory: %s :", name);
        printf("File exists or Permission denied!\n");
    }
}

int main(int argc, char*argv[]){
    char lines[argc+1][255];
    predealLine(argc, argv, lines);
	ksh_mkdir(lines[1]);

    return 0;
}
