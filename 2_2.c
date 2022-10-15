#include<stdio.h>
#include <stdlib.h>
#include<ctype.h>
int lencnt(char* str) {
    int len = 0;
    while(str[len]!='\0'){
        len++;
    }
    return len;
}
char* reverse(char*str, int len){
    for (int i = 0; i < len/2; i++) {   
        char temp = str[i];  
        str[i] = str[len - i - 1];  
        str[len - i - 1] = temp;  
    }  
    return(str);
}
char* regU(char* str) { 
    for(int i = 1; str[i] != '\0'; i+=2){
        if(str[i] <= 'z' && str[i] >= 'a') {
            str[i] += 'A' - 'a';
        }
    }
    return str;
}
char* concat(char* str, char*cont, int len, int cnt) { 
    char* concatstr = malloc(len+cnt+1);
    for(int i = 0; i < len; i++) {
        concatstr[i] = str[i];
    } 
    for(int  i = 0; i < cnt; i++) {
        concatstr[len + i] = cont[i];
    } 
    return concatstr;
}
char* sortN(char* str, int len, char* sorted) {
    int k = 0;
    for(int i = 0; i < len; ++i) {
        if (isdigit(str[i])) {
            sorted[k] = str[i];
            k++;
        }
    }
    for(int i = 0; i < len; ++i) {
        if (isalpha(str[i])) {
            sorted[k] = str[i];
            k++;
        }
    }
    for(int i = 0; i < len; ++i) {
        if (!isdigit(str[i]) && !isalpha(str[i])) {
            sorted[k] = str[i];
            k++;
        }
    }
    return sorted;
}

int main(int argc, char* argv[]) {
    char flag = argv[2][1];
    if (argv[2][0] != '-') {
        printf("Неверные флаги\n");
        return 0;
    }
    if (lencnt(argv[2]) != 2) {
        printf("Неверные флаги\n");
        return 0;
    }
    if (argc < 3) {
        printf("Недостаточно элементов\n");
        return 0;
    }
    else {
        if(argc == 3 && flag == 'c'){
            printf("Не хватает аргумента\n");
            return 0;
        }
        
        if(argc > 4){
            printf("Слишком много аргументов\n");
            return 0;
        }
    }
    char* str = argv[1];
    
    int len = lencnt(str);

    if(flag == 'l') {
        printf("%d", len);
    }
    else if(flag == 'r') {
        printf("%s", reverse(str, len));
    }
    else if(flag == 'u') {
        printf("%s", regU(str));
    }
    else if(flag == 'n') {
        char sorted[len];
        printf("%s", sortN(str, len, sorted));
    }
    else if(flag == 'c') {
        char* cont = argv[3];
        int contlen = lencnt(cont);
        printf("%s", concat(str, cont, len, contlen));
    }
    else {
        printf("такого флага нет\n");
    }
    return 0;
}
