//
// Created by brunon on 18-2-27.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/preprocess.h"

void ksh_cmp(char* filename1, char* filename2);

int main(int argc, char **argv) {
    char lines[argc+1][255];
    predealLine(argc, argv, lines);
    ksh_cmp(lines[1], lines[2]);
    return 0;
}

void ksh_cmp(char* filename1, char* filename2){
    FILE* file1;
    FILE* file2;
    char ch1, ch2;
    int lineNum = 1, columnNum = 1;
    printf("ksh-shell:\n");
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
                columnNum = 1;
            }
        }
    }
    if(ch1 == EOF && ch2 == EOF){
        printf("相同\n");
    }
    else
        printf("不同: 第 %d 字节, 第 %d 行\n", columnNum+1, lineNum);
}
