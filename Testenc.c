/*Testenc.c 
Creates a shell script that runs 100 iterations of the cpabe-enc
In both horizontal and vertical attribute trees

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
  int i,j;
  
  file=fopen("testenc.sh","w");
  for(i=1; i<=100; i++)
  {
    //Horizontal
    fprintf(file,"%s%d%s","echo i=",i,"\n");
    fprintf(file,"%s%d%s","cpabe-enc -o file",i," -k pub_key testout \"");
    j=1;
    while(j<=i)
    {
      fprintf(file,"%s%d","prop",j);
      if(j<i)
      {
        fprintf(file,"%s"," and ");
      }
      j++;
    }
    fprintf(file,"%s","\"\n");
    
    //Vertical
    
    fprintf(file,"%s%d%s","cpabe-enc -o file",i,"n -k pub_key testout \"");
    if(i<64)
    {
      fprintf(file,"%s%llu%s%d%s","prop <= ",((unsigned long long)1<<(i-1)),"#",i,"\"\n");
    }
    else
    {
      fprintf(file,"%s%llu%s%d%s%llu%s%d%s","prop <=",((unsigned long long)1<<63),"#",63," and prop2 <=",((unsigned long long)1<<(i-64)),"#",(i-63),"\"\n");
    }
  }
  fclose(file);
  return 0;
}