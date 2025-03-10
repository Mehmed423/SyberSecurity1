#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

#define MAXN 1000
#define ALPHA_LENGTH 26
#define COMMON_COUNT 10

char * ceasar_decipher(char* cipher, int key){
    int length = strlen(cipher);
    char * plaintext = (char*)malloc(sizeof(char)*(length+1));
    for(int i =0; i<length; i++){
        if(cipher[i]>='a' && cipher[i]<='z'){
            plaintext[i]=((cipher[i]-'a')-key+26) %26 + 'a';
        }
        else  if(cipher[i]>='A' && cipher[i]<='Z'){
            plaintext[i]=((cipher[i]-'A')-key+26) %26 + 'A';
        }
        else  if(cipher[i]>='0' && cipher[i]<='9'){
            plaintext[i]=((cipher[i]-'0')-key+10) %10 + '0';
        }
        else{
            plaintext[i]=cipher[i];
        }
    }
    return plaintext;
}

int* count_frequencies(char* cipher){
    int* frequency = (int*)malloc(sizeof(int)*ALPHA_LENGTH);
    memset(frequency,0,sizeof(int)*ALPHA_LENGTH);
    int length = strlen(cipher);
    for(int i = 0; i<length; i++){
        char letter = tolower(cipher[i]);
        if(letter>='a' && length<='z'){
            int position = letter-'a';
            frequency[position]++;
        }
    }
    return frequency;
}
int get_max_index(int* frequency){
    int max_index=0;
    for(int i = 0; i<ALPHA_LENGTH; i++){
        if(frequency[i]>frequency[max_index]){
            max_index = i;
        }
    }
    return max_index;
}
int main(){
    char cipher[MAXN];
    fgets(cipher, MAXN, stdin);

    char letters[COMMON_COUNT] = {'e', 't', 'a', 'o', 'i', 'n', 's', 'h', 'r', 'd'};

    int most_common_letter = get_max_index(count_frequencies(cipher)) + 'a';
    for(int i = 0; i<COMMON_COUNT; i++){
        int key = abs(most_common_letter - letters[i]);
        char * plaintext = ceasar_decipher(cipher, key);
        printf("%s key = %d -> %s\n", cipher, key, plaintext);
        free(plaintext);
    }
}
