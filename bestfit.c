#include<stdio.h>

int bc=0,pc=0;
 

typedef struct block
{
 int blocksize;
 int allocated;
}block;

typedef struct process
{
 int psize;
 int bindex;
}process;


int minfrag(int *f)
{
 int i,min=100000,index=0;
 for(i=0;i<bc;i++)
 {
  if(min>f[i]&&f[i]>0)
   {
   min=f[i]; 
   index=i;
   }
 }
 return index;
}

int maxblock(block *b)
{
 int i,max=0;
  for(i=0;i<bc;i++)
   if(max<b[i].blocksize)
    max=b[i].blocksize;
 
 return max;
}

void bestfit(block *b,process *p)
{
 int fragment[bc];
 int i,j;
 for(i=0;i<pc;i++)
 {
  for(j=0;j<bc;j++)
   {
    if(b[j].allocated!=1)
    fragment[j]=b[j].blocksize-p[i].psize;
    else 
    fragment[j]=maxblock(b);
   }

   p[i].bindex=minfrag(&fragment);
   b[p[i].bindex].allocated=1;
 }   

}

void display(block *b,process *p)
{
 int i;

 FILE *fp;
 fp=fopen("demo1.txt","a");
 
 for(i=0;i<pc;i++)
  fprintf(fp,"\n%d \t %d ",p[i].psize,b[p[i].bindex].blocksize);

 
}

void sort(process p[])
{
 process temp;
 int i,j;
 for(j=0;j<pc;j++)
 for(i=0;i<pc-1;i++)
  {
   if(p[i].psize>p[i+1].psize)
    {
     temp=p[i];
     p[i]=p[i+1];
     p[i+1]=temp;
    }
  }
}

main()
{
 FILE *fp;
 fp=fopen("demo1.txt","r");
 char ch='a';
 while(ch!='\n')
 {
  ch=fgetc(fp);
  if(ch==' ')
   bc++;
 }
 ch='a';
 while(ch!='\n')
 {
  ch=fgetc(fp);
  if(ch==' ')
   pc++;
 } 
 bc++;
 pc++;
 
fclose(fp);


 fp=fopen("demo1.txt","r");
  
 
 block b[bc];
 process p[pc],*p1;
 int i;
 
 for(i=0;i<bc;i++)
  fscanf(fp,"%d",&b[i].blocksize);
 
 for(i=0;i<pc;i++)
  fscanf(fp,"%d",&p[i].psize);
 
 
 for(i=0;i<bc;i++)
 {
  b[i].allocated=0;
 }
 //sort(&p);
 bestfit(&b,p);
 display(&b,p);
return 0;
}
