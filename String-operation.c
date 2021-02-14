 #include<stdio.h>
 #define n 20

  int length(char s1[])
  {
      int i=0;
      while(s1[i]!='\0')
         {
           i++;
         }

      return(i);
  }
  reverse(char s1[])
  {
  	int i;
  	for(i=length(s1)-1;i>=0;i--)
  	    printf("%c",s1[i]);
  }

 concatenate(char s1[],char s2[])
  {
  	int j=length(s1)+length(s2);
  	int i1=length(s1),i2=0;
  	if(j>=n)
  	   {
		 printf("string is full");
         return(i1);
	}
  	else
	  {
	  while(s2[i2]!='\0')
	    s1[i1++]=s2[i2++];
  }
}

  int main()
  {
      char s1[n],s2[10];
      int i,j;
      printf("Enter a string 1");
      gets(s1);
      printf("\nEnter a string 2");
      gets(s2);
      i=length(s1);
      printf("\nlength of string 1 is a %d",i);
       i=length(s2);
      printf("\nlength of string 1 is a %d",i);
      printf("\nReverse string 1 is a  ");
      reverse(s1);
      printf("\ns1+s2= ");
      i=concatenate(s1,s2);
      puts(s1);

       }
