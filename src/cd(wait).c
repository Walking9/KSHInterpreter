//
// Created by brunon on 18-2-27.
//
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <unistd.h>
#include "../include/line.h"

#define MAX_SIZE_PATH 255        //最大路径长度

int ksh_cd(char *path) {
    int res;
	char cd[MAX_SIZE_PATH];

	memset(cd,'\0',MAX_SIZE_PATH);
	printf("%s\n", path);
	strcat(cd, path);
    res = chdir(cd); //change dir
    if(res != 0)
        printf("%s is nod a path,please check again \n",path);

    return res;
}

int main(int argc, char*argv[]){
    char lines[argc+1][255];
    predealLine(argc, argv, lines);
	ksh_cd(lines[1]);

    return 0;
}
