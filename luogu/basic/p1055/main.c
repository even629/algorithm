#include <stdio.h>
#include <string.h>


int main(){
  // 9位数字，1位识别码，3个分隔符
  char input[14];
  char ISBN[14];
  char array[11] = "";
  char *token;
  int index = 0, num = 0;
  
  scanf("%s",input);
  strcpy(ISBN,input);

  token = strtok(ISBN, "-");
  while(token!=NULL){
    strcat(array,token);
    token = strtok(NULL, "-");
  }
  // 9是识别码,10是\0
  for(int i=0;i<9;i++){
    num += (array[i]-'0')*(i+1);
  }
  num %= 11;
  
  if((array[9]-'0')==num || (num ==10 && array[9]=='X')){
    printf("Right");
  }else{
    if(num==10){
      input[12] = 'X';
    }else{
      input[12] = '0'+num;
    }
    printf("%s",input);
  }
  

}