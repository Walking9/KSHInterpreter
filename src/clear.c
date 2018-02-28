//
// Created by brunon on 18-2-27.
//

#include <stdio.h>
#include "../include/line.h"

int main(int argc, char*argv[]){
    char lines[argc+1][255];
    predealLine(argc, argv, lines);

    if(strcmp(lines[0], "clear")==0){
        printf("\033[2J");
    }
    else{
        printf("sytax error!");
    }

    return 0;
}
