int strlen(char *str);
char *stradd(char *origin, char *addition);
int strfind(char *origin, char *substr);

int main(int argc, char **argv){

  printf("Initial Lenght      : %d\n", strlen(argv[1]));
  printf("New String          : %s\n", stradd(argv[1],argv[2]));

  if(strfind(stradd(argv[1],argv[2]), argv[3]) == 1){
    printf("SubString was found : yes" );
  }
  else{
    printf("SubString was found : no" );
  }

  /*
  printf("Initial Lenght      : %d\n", strlen("Hello there"));
  printf("New String          : %s\n", stradd("general","Kenobi"));
  if(strfind("HelloThereGeneralKenobi", "ThereGen") == 0){
    printf("SubString was found : no" );
  }
  if(strfind("HelloThereGeneralKenobi", "ThereGen") == 1){
    printf("SubString was found : yes" );
  }
  printf("SubString was found : %d\n", strfind("HelloThereGeneralKenobi", "ThereGen"));*/
}
