#include<stdio.h>
#include<unistd.h>

int main(){
    char name[50];
    int univ_rn;
    int class_rn;
    printf("Enter yor name : ");
    scanf("%s",name);
    fflush(stdin);
    printf("Enter univ_rn : ");
    scanf("%d",&univ_rn);
    printf("Enter class_rn : ");
    scanf("%d",&class_rn);
    pid_t pid = fork();
    
    if(pid>0) { //parent
        FILE* fp = fopen("input.txt","w");
        if(fp==NULL) {
            printf("Error");
            return 1;
        }
        fprintf(fp,"Your name is : %s\n",name);
        fprintf(fp,"Your university name is : %d\n",univ_rn);
        fprintf(fp,"Your class name is : %d\n",class_rn);
        fclose(fp);
    }

    else if(pid==0) { //child
        FILE* fp;
        fp = fopen("input.txt","r");
        if(fp==NULL)
        return 1;
        char ch;
        while((ch=getc(fp))!=EOF){
            printf("%c",ch);
        }
        fclose(fp);
    }
    else {
        printf("fork error!!!!\n");
    }
    return 0;
}