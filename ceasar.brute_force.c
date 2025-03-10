#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define MAXN 1000
#define ALPHA_LENGTH 26

char* ceasar_decipher(char* cipher, int key)
{
    int length = strlen(cipher);
    char* plaintext = (char*) malloc(sizeof(char) * (length + 1));
    for(int i = 0; i < length; i++)
    {
        if(cipher[i] >= 'a' && cipher[i] <= 'z')
        {
            plaintext[i] = (cipher[i] - 'a' - key + 26) % 26 + 'a';
        }
        else if(cipher[i] >= 'A' && cipher[i] <= 'Z')
        {
            plaintext[i] = (cipher[i] - 'A' - key + 26) % 26 + 'A';
        }
        else if(cipher[i] >= '0' && cipher[i] <= '9')
        {
            plaintext[i] = (cipher[i] - '0' - key + 10) % 10 + '9';
        }
        else
        {
            plaintext[i] = cipher[i];
        }
    }
    plaintext[length] = '\0';

    return plaintext;
}
    int main(){
        char cipher[MAXN];
        fgets(cipher,MAXN,stdin);

        for(int key=0; key<ALPHA_LENGTH; key++){
            char * plaintext = ceasar_decipher(cipher, key);
            printf("%s key = %d -> %s\n", cipher, key, plaintext);
            free (plaintext) ;
        }
        return EXIT_SUCCESS;
    }
