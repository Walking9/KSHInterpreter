#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "ls.h"
#include "cd.h"
#include "ifconfig.h"
#include "date.h"
#include "sort.h"
#include "find.h"
#include "ps.h"
#include "clear.h"
#include "cmp.h"
#include "pwd.h"

//----------宏定义----------------//

#define MAX_SIZE_COMMAND 100     //最大命令长度

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
            ksh_ls();
            if(ksh_cd("cd ..\n") != 0)
                printf("error!\n");
            ksh_ifconfig();
            ksh_sort("test.txt");
            ksh_cmp("1.txt", "2.txt");
            ksh_find("tet.txt");
            ksh_date();
            ksh_ps();
            //ksh_clear();
            //ksh_mkdir();
            ksh_pwd();
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
