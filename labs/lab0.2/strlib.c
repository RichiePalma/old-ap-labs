#include <stdio.h>


int strlen(char *str){ //strlib.c:3:5: aviso: tipos en conflicto para la función interna ‘strlen’

  int i = 0;
  int count = 0;
  while(str[i] != '\0'){
    count++;
    i++;
  }
  return count;
}

char* stradd(char *origin, char *addition)
{
  int totalLength = strlen(origin) + strlen(addition);
  char *newString = (char *)malloc(totalLength+1);

  int i = 0;
  int j = 0;
  while(origin[i] != '\0'){
    newString[j] = origin[i];
    i++;
    j++;
  }

  i = 0;

  while(addition[i] != '\0'){
    newString[j] = addition[i];
    i++;
    j++;
  }

  newString[j] = '\0';

  return newString;

}

int strfind(char *origin, char *substr){
  if(strlen(substr) > strlen(origin)){
    return 0;   //substr is longer than origin; hence, it cannot be a substring
  }
  int i = 0;
  while(origin[i] != '\0'){
    int j = 0;
    if(origin[i] == substr[j]){
      while(substr[j] != '\0' && origin[i+j] != '\0'){
        if(origin[i+j] == substr[j]){
          if(j == strlen(substr) -1){
            return 1;
          }
          j++;
        }
        else{
          break;
        }
      }
    }
    i++;
  }
  return 0;
}

/*int main(){
  printf("%d\n", strlen("Hello there"));
  printf("New String: %s\n", stradd("general","Kenobi"));
  printf("%d\n", strfind("HelloThereGeneralKenobi", "ThereGen"));
}*/
