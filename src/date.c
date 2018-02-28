//
// Created by brunon on 18-2-27.
//

#include <time.h>
#include <stdio.h>

void ksh_date() {
    time_t rawtime;
    time(&rawtime);
    printf("%s", asctime(localtime(&rawtime)));
}

int main(int argc, char **argv)
{
    printf("ksh-shell:\n");
	ksh_date();
	return 0;
}
