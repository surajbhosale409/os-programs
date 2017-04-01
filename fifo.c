#include<stdio.h>

 



int in(int p,int *f,int nf)
{
 int i;
  for(i=0;i<nf;i++)
   if(f[i]==p)
     return 1;

 return 0; 
 
}



int fifo(int *p,int np,int nf)
{
 int frame[nf];
 int i,j,pf=0;
 for(i=0;i<nf;i++)
  frame[i]=-1;


 for(j=0,i=0;i<np;i++)
 { 
  if(!in(p[i],&frame,nf))
  {
   frame[j]=p[i];
   if(j==2)
     j=0;
   else
     j++;

   pf++;
  }
  
  
 }

 return pf;
}


void display(int pf)
{
 int i;

 FILE *fp;
 fp=fopen("demo2.txt","a");

 fprintf(fp,"\nNo of Page Faults : %d",pf);

 
}


main()
{
 FILE *fp;
 int np,nf;
 int pf;
 fp=fopen("demo2.txt","r");
 fscanf(fp,"%d",&np);
 
 int p[np];
 int i;
 
 for(i=0;i<np;i++)
  fscanf(fp,"%d",&p[i]);
 
 fscanf(fp,"%d",&nf);
 
 
 pf=fifo(&p,np,nf);
 display(pf);
 
return 0;
}
