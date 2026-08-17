#include <stdio.h>
#include <unistd.h> 
int main(){
    printf("before fork \n");
    fork();
    printf(".\n");
    return 0;
}