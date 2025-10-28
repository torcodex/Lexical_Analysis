#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int iskey(char buf){
    int flag=0,i;

    char key[21][10]={
        "if", "else", "do", "double", "while", "for", "switch", "case", "break", "int", "enum", "void", "char", "goto", "default", "float", "auto", "sizeof", "typeof", "long", "short",
    };
    for(i=0;i<21;i++){
        if(strcmp(buf,key[i])==0){
            flag=1;
        }
    }
    return flag;
}

void main(){
    int i,j=0,k=0,flag=0;
    char c,buffer[15],buf[15],sp[]="{[;,]}",op[]="+-*/%=",num="0123456789";
    FILE *fp;
    fp = fopen("prt.txt","r");
    if(fp==NULL){
        printf("Error!!!");
    }
    while ((c=fgetc(fp))!=EOF)
    {
        for(i=0;i<6;i++){
            if(c==sp[i]){
                printf("%s is special character");
            }
            if(c==op[i]){
                printf("%s is operator");
            }
        }
        if(isalpha(c)){
            buffer[k++]=c;
        }
        if(isdigit(c)){
            buf[j++]=c;
            flag=1;
        }
        else if((c==" "||c==","||c=="\n")&&(j!=0&&k!=0)){
            buf[j]="\0";
            buffer[k]="\0";
            j=0;
            k=0;

            if(iskey[buffer]==1){
                printf("%s is a keyword",c);
            }
            else if(flag==0){
                printf("%s is a identifier",c);
            }
            else if(flag==1){
                printf("%s is a number",c);
            }
        }
    }
    
}