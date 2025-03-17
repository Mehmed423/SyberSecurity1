#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAXN 1024
#define FILENAME_MAXN 1024

char * vigenere_encrypt(char* plaintext, char * key){
    int text_length = strlen(plaintext);
    int key_length = strlen(key);

    char * cipher = (char*)malloc(sizeof(char) * (text_length+1));
    memset(cipher, '\0', sizeof(char) * (text_length+1));
    int shift = 0;
    char * key_ptr = key;
    for(int i = 0; i<text_length; i++){
        if(isalpha(plaintext[i])){
            //shift = tolower(key[i%key_length]) - 'a';
            shift = tolower(*key_ptr) - 'a';
            if(islower(plaintext[i])){
                cipher[i] = 'a' + (plaintext[i] - 'a' + shift) %26;
            }
            else{
                cipher[i] = 'A' + (plaintext[i] - 'A' + shift) %26;
            }
            key_ptr++;
            if(*key_ptr == '\0')
                key_ptr=key;
        }
        else{
            cipher[i] = plaintext[i];
        }
    }
    cipher[text_length] = '\0';
    return cipher;
}


int read_input_file(char* filename, char* text)
{
    FILE *fp = fopen(filename, "r");
    if(fp == NULL)
    {
        printf("Error opening file.");
        return EXIT_FAILURE;
    }

    if(fgets(text, MAXN, fp) == NULL)
    {
        printf("Error reading from file.");
        return EXIT_FAILURE;
    }
    fclose(fp);
    return EXIT_SUCCESS;
}

void write_text(char* filename, char* text)
{
    FILE *fp = fopen(filename, "wb");
    fprintf(fp, "%s", text);
    fclose(fp);
}

char * read_filename_stdin(){
    char * filename = malloc(sizeof(char) * (FILENAME_MAXN+1));
    memset(filename, '\0', sizeof(char) * (FILENAME_MAXN+1));
    //fgets(filename, FILENAME_MAXN, stdin);
    scanf("%s", filename);
    return filename;
}

int main(){
    
    char text[MAXN];
    char key[MAXN];

    //scanf("%s",text);
    read_input_file(read_filename_stdin(), text);
    read_input_file(read_filename_stdin(), key);

    //scanf("%s",key);

    char * cipher = vigenere_encrypt(text ,key);
    puts(cipher);
    write_text("vigenere_cypher.txt", cipher);

    free(cipher);

    return EXIT_SUCCESS;

}
