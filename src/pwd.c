//
// Created by brunon on 18-2-27.
//

#include <unistd.h>
#include <stdio.h>

#define MAX_SIZE_PATH 255        //最大路径长度

void ksh_pwd(){
    char path[MAX_SIZE_PATH];
    getcwd(path, MAX_SIZE_PATH);
    printf("%s\n", path);
}

int main(int argc, char*argv[]){
    printf("ksh-shell:\n");
	ksh_pwd();
    return 0;
}
