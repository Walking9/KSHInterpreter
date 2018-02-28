#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>  
#include "../include/preprocess.h"

int main(int argc, char** argv) {
    char lines[argc+1][255];
    predealLine(argc, argv, lines);
    printf("ksh-shell:\n");
    char* srcname = lines[1];
    // 从路径中获取到文件名
    char* filename = strrchr(srcname, '/') + 1;
    char* dirname = lines[2];
    // 链接被替换文件的路径和文件名
    char dstname[256];
    strcat(dstname, dirname);
    strcat(dstname, "/");
    strcat(dstname, filename);
    // 替换文件内容
    FILE *src, *dst;
    src = fopen(srcname, "rb");
    if((dst = fopen(dstname, "wb")) == NULL) {
        printf("can not open file: %s\n", dstname);
    }
    int bufferLen = 1024;
    int readCount = 0;
    char *buffer = (char*)malloc(bufferLen);
    while((readCount=fread(buffer, 1, bufferLen, src)) > 0) {
        fwrite(buffer, readCount, 1, dst);
    }
    fclose(src);
    fclose(dst);
}
