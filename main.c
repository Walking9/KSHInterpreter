#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "ls.h"

//----------宏定义----------------//
#define MAX_SIZE_PATH 255        //最大路径长度
#define MAX_SIZE_COMMAND 255     //最大命令长度

//----------函数申明--------------//
void initCommand();             //每个命令执行前初始化
int getCommand(char *word);     //获得命令。返回值-1 == 退出； 0 == 命令格式错误； 1 == 正确

int main(int argc, char *argv[]) {
    int flag;
    char command[MAX_SIZE_COMMAND];
    for(;;) {
        initCommand();
        flag = getCommand(command);
        if(flag == -1)
            break;
        else if(flag == 0)
            printf("command is error!\n");
        else {
            ksh_ls(".");
        }
    }
}

void initCommand() {
    char path[MAX_SIZE_PATH];
    getcwd(path, MAX_SIZE_PATH);
    printf("[OSProject-ksh@ %s:]#", path);
}

int getCommand(char *word) {
    int i;
    for(i=0; (word[i] = getchar()) != '\n' && i < MAX_SIZE_COMMAND; i++); //读取命令到word
    if(strcmp(word, "exit") == 0)
        return -1;
    if(i == MAX_SIZE_COMMAND)
        return 0;
    return 1;
}
