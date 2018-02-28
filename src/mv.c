//
// Created by brunon on 18-2-27.
//

#include<stdio.h>  
#include<unistd.h>  
#include<sys/stat.h>  
#include<string.h>  
#include<stdlib.h>  
char * getFileName(char * fileName){  
    char tp[100],*nm=(char*)malloc(sizeof(char));  
    int i,j=0;  
    for(i=strlen(fileName)-1;i>=0;i--){  
        if(fileName[i]=='/')break;  
    }  
    for(i++;i<strlen(fileName);i++){  
        tp[j++]=fileName[i];  
    }  
    tp[j]='\0';  
    strcpy(nm,tp);  
    return nm;  
}  
int main(int argc,char** argv){  
    struct stat st;  
    if(argc!=3){  
        fprintf(stderr,"usage: %s source destination not found\n",*argv);  
    }  
      
    if(stat(argv[1],&st)==-1 || S_ISDIR(st.st_mode)){  
        printf("source is not a file");  
        exit(1);  
    }  
    if(stat(argv[2],&st)!=-1){	//判断是不是目录   
        if(S_ISDIR(st.st_mode)){  
            strcpy(argv[2] + strlen(argv[2]),"/");  
            strcpy(argv[2] + strlen(argv[2]),getFileName(argv[1]));  
            strcpy(argv[2] + strlen(argv[2]),"\0");  
        }else{  
            printf("destination file is already exist\n");  
            //exit(1);  
        }  
    }  

    if(rename(argv[1],argv[2])==-1){   //复制包含目录的文件
        printf("error!\n");  
    }  
    return 1;  
}  
