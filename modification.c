#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXN 1000

char * ceasar_cipher(char* str, int key){
    int length = strlen(str);
    char * cipher = (char*)malloc(sizeof(char)*(length+1));

    for(int i = 0; i < length; i++){
        if(str[i] >= 'a' && str[i] <= 'z'){ 
            cipher[i] = ((str[i] - 'a' + key) % 26 + 26) % 26 + 'a';
        }
        else if(str[i] >= 'A' && str[i] <= 'Z'){ 
            cipher[i] = ((str[i] - 'A' + key) % 26 + 26) % 26 + 'A';
        }
        else if(str[i] >= '0' && str[i] <= '9'){
            cipher[i] = ((str[i] - '0' + key) % 10 + 10) % 10 + '0';
        }
        else{ 
            cipher[i] = str[i];
        }
    }

    cipher[length] = '\0';
    return cipher;
}

int main(){
    char str[MAXN];
    
    printf("Enter the string to encrypt:\n");
    fgets(str, MAXN, stdin);
    
    str[strcspn(str, "\n")] = '\0';
    
    int key;
    
    printf("Enter the shift key:\n");
    scanf("%d", &key);

    char* cipher = ceasar_cipher(str, key);
    printf("Encrypted text: %s\n", cipher); 

    free(cipher);
    
    return EXIT_SUCCESS;
}
