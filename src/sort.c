//
// Created by brunon on 18-2-27.
//

#include <stdio.h>
#include <memory.h>
#include "../lib/preprocess.h"

#define MAX_CHARNUM 1024

void ksh_sort(char* filename){
    int lineNum = 0;
    char fileLine[MAX_CHARNUM];      //存储一行内容
    FILE* file = fopen(filename, "r");
    if(file == NULL){
        printf("error, it isn't a file\n");
        return;
    }
    while(!feof(file)){             //获得文件总行数
        fgets(fileLine, MAX_CHARNUM, file);
        lineNum++;
    }
    rewind(file);
    char fileContent[lineNum][MAX_CHARNUM];   //将文件内容放到fileContent
    for(int i = 0; i < lineNum; i++) {
        fgets(fileLine, 1024, file);
        strcpy(fileContent[i], fileLine);
    }

    for(int i = 0; i < lineNum-1; ++i) {     //sort, 选择排序
        for(int j = i+1; j < lineNum; ++j) {
            if(strcmp(fileContent[i], fileContent[j])>0) {
                strcpy(fileLine, fileContent[i]);
                strcpy(fileContent[i], fileContent[j]);
                strcpy(fileContent[j], fileLine);
            }
        }
    }

    for(int i = 0; i < lineNum; i++) {     //输出结果
        int len = strlen(fileContent[i]);
        if(fileContent[i][len-1] == '\n')
            printf("%s", fileContent[i]);
        else
            printf("%s\n", fileContent[i]);
    }
}

int main(int argc, char*argv[]){
    char lines[argc+1][255];
    predealLine(argc, argv, lines);
    printf("ksh-shell:\n");
	ksh_sort(lines[1]);
    return 0;
}
