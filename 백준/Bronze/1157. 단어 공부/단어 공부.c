#include <stdio.h>
#include <string.h>

int main(void){
    char word[1000000]={0};
    int word_len;
    int alpha[26]={0};
    int biggest=0;
    int same=0;
    scanf("%s",word);
    word_len=strlen(word);
    for(int i=0;i<word_len;i++){
        if('a'<=word[i]&&'z'>=word[i]){
            alpha[word[i]-'a']++;
        }
        else if('A'<=word[i]&&'Z'>=word[i]){
            alpha[word[i]-'A']++;
        }
    }
    for(int i=1;i<26;i++){
        if(alpha[biggest]<alpha[i]){
            biggest=i;
            same=0;
        }
        else if(alpha[biggest]==alpha[i]){
            same=1;
        }
    }
    if(same!=1){
        printf("%c\n",biggest+'A');
    }
    else{
        printf("?\n");
    }
    return 0;
}