//
// Created by brunon on 18-2-27.
//
//
// Created by brunon on 18-2-27.
//
#include    <unistd.h>
#include    <sys/stat.h>
#include    <stdio.h>
#include    <errno.h>
#include    <string.h>
#include    <stdlib.h>
int main(int argc, char *argv[]){
    struct stat st;
    char* tty;
    tty = ttyname(STDERR_FILENO);
    if(tty == NULL){
        exit(1);
    }
    if(stat(tty, &st) == -1){
        exit(1);
    }
    if(argc == 1){
        if(st.st_mode & S_IWGRP)
            printf("is y\n");
        else
            printf("is n\n");
        return 0;
    }
    switch(argv[1][0]){
        case 'y':
            if(chmod(tty, st.st_mode | S_IWGRP) == -1)
                fprintf(stderr, "cannot set '%s': %s\n",tty, strerror(errno));
            break;
        case 'n':
            if(chmod(tty, st.st_mode & ~S_IWGRP) == -1)
                fprintf(stderr, "cannot set '%s': %s\n", tty, strerror(errno));
            break;
        default: ;
    }
    return 0;
}
