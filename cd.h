//
// Created by brunon on 18-2-27.
//

#ifndef KSHINTERPRETER_CD_H
#define KSHINTERPRETER_CD_H

#include <stdio.h>
#include <memory.h>
#include <printf.h>
#include <unistd.h>

#define MAX_SIZE_PATH 255        //最大路径长度

int ksh_cd(char *p) {
    char path[MAX_SIZE_PATH];
    char *start;
    char *end;
    int res;

    memset(path,'\0',MAX_SIZE_PATH); // must init ,ohtrway there is a wrong result with @

    start = strchr(p,' ');
    end = strchr(p,'\n');
    if(!start || !end){   //检查命令是否符合格式
        printf("can't support this format \n");
        return 1;
    }

    strncpy(path,p+3,end-start-1); // get the path in inputting command
    res = chdir(path); //change dir
    if(res != 0)
        printf("%s is nod a path,please check again \n",path);

    return res;
}

#endif //KSHINTERPRETER_CD_H
