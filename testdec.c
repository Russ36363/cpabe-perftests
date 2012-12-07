/*Testdec.c 
Creates a shell script that runs 100 iterations of the cpabe-dec
In both horizontal and vertical attribute trees
Note: Requires the script from testenc.c to be run first.

Russ Martin
12/6/12
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

int main(int argc, char** argv)
{
  FILE* file;
  int i;
  
  file=fopen("testdec.sh","w");
  for(i=1; i<=100; i++)
  {
    //Horizontal
    fprintf(file,"%s%d%s","echo i=",i,"\n");
    fprintf(file,"%s%d%s%d%s%d%s","cpabe-dec -k -o file",i,".dec pub_key priv",i," file",i,"\n");

    
    //Vertical
    fprintf(file,"%s%d%s%d%s%d%s","cpabe-dec -k -o file",i,"n.dec pub_key priv",i,"n file",i,"n\n");
  }
  fclose(file);
  return 0;
}