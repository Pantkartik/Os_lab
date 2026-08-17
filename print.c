#include <stdio.h>
#include <unistd.h> //#include unistd
int main(){
    printf("before fork \n");
    fork();
    printf(".\n");
    return 0;
}