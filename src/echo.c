//
// Created by brunon on 18-2-27.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int beg = 1;
    
    while(beg < argc){
        fprintf(stdout, argv[beg++]);
        if(argc != beg)     //仅在中间才打印空格
            fprintf(stdout, " ");
    }
    fprintf(stdout, "\n");
    exit(0);
}
