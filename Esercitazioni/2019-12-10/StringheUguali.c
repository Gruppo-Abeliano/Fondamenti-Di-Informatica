#include <stdio.h>

#define INPUT_FILE1 "./Input1.txt"
#define INPUT_FILE2 "./Input2.txt"

int fileIdentici(char *File1,char *File2);

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}

int fileIdentici(char *File1,char *File2)
{
  FILE *stream1,*stream2;
  int byte1,byte2,daRestituire;

  stream1 = fopen(File1,"r");
  stream2 = fopen(File2,"r");

  byte1 = fgetc(stream1);
  byte2 = fgetc(stream2);
  daRestituire = 0;

  while(((byte1 != EOF) || (byte2 != EOF)) && (daRestituire == 0))
  {
    if(byte1 != byte2) daRestituire++;

    byte1 = fgetc(stream1);
    byte2 = fgetc(stream2);
  }

  fclose(stream1);
  fclose(stream2);

  return daRestituire;
}
