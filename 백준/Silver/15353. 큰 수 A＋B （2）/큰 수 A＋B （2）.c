#include <stdio.h>
#include <string.h>
#define su 1000000
void changenum(char number[su],int);
int main(void){
    char number1[su]={0};
    char number2[su]={0};
    char result[su]={0};
    int number1_len,number2_len,result_len;
    scanf("%s",number1);
    scanf("%s",number2);
    number1_len=strlen(number1);
    number2_len=strlen(number2);
    changenum(number1,number1_len);
    changenum(number2,number2_len);
    for(int i=0;i<number1_len;i++){
        number1[i]-='0';
    }
    for(int i=0;i<number2_len;i++){
        number2[i]-='0';
    }
    result_len=(number1_len>=number2_len)?number1_len:number2_len;
        for(int i=0;i<result_len;i++){
            // result[i+1]+=(number1[i]+number2[i])/10;
            result[i]+=number1[i]+number2[i];
            if(result[i]/10!=0){
                result[i+1]+=result[i]/10;
                result[i]=result[i]%10;
                if(i==result_len-1){
                    result_len++;
                    break;
                }
            }
        }
    changenum(result,result_len);
    for(int i=0;i<result_len;i++){
        result[i]+='0';
    }
    printf("%s\n",result);
    return 0;
}
void changenum(char number[su],int number_len){
    char tmp[su]={0};
    for(int i=0;i<number_len;i++){
        tmp[i]=number[number_len-i-1];
    }
    for(int i=0;i<number_len;i++){
        number[i]=tmp[i];
    }
}
