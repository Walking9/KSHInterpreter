//
// Created by brunon on 18-2-27.
//

#ifndef KSHINTERPRETER_CMP_H
#define KSHINTERPRETER_CMP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ksh_cmp(char* filename1, char* filename2){
    FILE* file1;
    FILE* file2;
    char ch1, ch2;
    int lineNum = 1, columnNum = 1;
    if((file1=fopen(filename1, "r"))==NULL) {   //文件打开失败
        printf("%s isn't a file\n", filename1);
        return;
    }
    if((file2=fopen(filename2, "r"))==NULL){
        printf("%s isn't a file\n", filename2);
        return;
    }

    printf("%s  %s ", filename1, filename2);
    while((ch1 = fgetc(file1)) != EOF && (ch2 = fgetc(file2)) != EOF) {
        if(ch1 != ch2){
            printf("不同: 第 %d 字节, 第 %d 行\n", columnNum, lineNum);
            return;
        }
        else {
            columnNum++;
            if(ch1 == '\n') {
                lineNum++;
            }
        }
    }
    if(ch1 == EOF && ch2 == EOF){
        printf("相同\n");
    }
    else
        printf("不同: 第 %d 字节, 第 %d 行\n", columnNum+1, lineNum);
}

#endif //KSHINTERPRETER_CMP_H
