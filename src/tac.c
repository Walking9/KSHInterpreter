#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#define SIZE  1000001
#define NLINE '\n'


int main(int argc , char *argv[]){
    char buf[SIZE];
    char *p1,*p2,*p3,*p4;
    struct stat  *fp;
    int fd;
    printf("ksh-shell:\n");
    fp=(struct stat *)malloc(sizeof(struct stat));

    if(argc != 2){
        fprintf(stderr,"input error %s \n", strerror(errno));
        exit(1);
    }

    if( (fd=open(argv[1],O_RDONLY)) == -1 ){
        fprintf(stderr,"open error %s \n",strerror(errno));
        exit(1);
    }

    if(fstat(fd,fp)== -1){
        fprintf(stderr,"fstat error %s \n",strerror(errno));
        exit(2);
    }

    if(fp->st_size > (SIZE-1)){
        fprintf(stderr,"buffer size is not big enough \n");
        exit(3);
    }

    if(read(fd,buf,fp->st_size) == -1){
        fprintf(stderr,"read error.\n");
        exit(4);
    }

    p1=strchr(buf,NLINE);
    p2=strrchr(buf,NLINE);
    *p2='\0';

    do{
        p2=strrchr(buf,NLINE);
        p4=p2;
        p3=p2+sizeof(char);
        printf("%s\n",p3);
        *p4='\0';
    }while(p2 != p1);

    if(p2 == p1){
        *p2 = '\0';
        printf("%s\n",buf);
    }

    return 0;
}   
