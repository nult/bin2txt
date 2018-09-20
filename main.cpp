#include <iostream>
#include <fstream>
#include <stdio.h>
#include <io.h>
#include <sys\stat.h>
//#include <afx.h>
using namespace std;

int main(int argc, char** argv)
{
    FILE *fp;
    FILE *fp1;
    fp = fopen("proc000001_z.bin", "rb");
    fp1 = fopen("p1z.txt","w");
    int fz= filelength(fileno(fp));
    //printf("%d\n",fz);
    fz=fz/4;
    float rfea[fz]={0};
    if (fp != NULL){
        fread(rfea, fz*sizeof(float), 1, fp);
        fclose(fp);
    }
    int i=0;
  for (i=0;i<fz ;i++ )
  {
    fprintf(fp1,"%f\n",rfea[i]);
  }
  return 0;
}
