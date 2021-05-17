
#include <stdio.h>
#include <string.h>

#define len_max 10000
int main()
{
    char s[len_max],t[len_max];
	printf("Enter string 1:");
	scanf("%s",&s);	
	printf("Enter string 2:");
	scanf("%s",&t);	
	int m=strlen(s),n=strlen(t);
	int dp[m+1][n+1];
	memset(dp,0,sizeof(dp));
	int i,j;
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(s[i-1]==t[j-1])
			{
				dp[i][j]=1+dp[i-1][j-1];
			}
			else
			{
				dp[i][j]=dp[i-1][j]>dp[i][j-1]?dp[i-1][j]:dp[i][j-1];
			}
		}
	}
	printf("The length of longest subsequence:%d",dp[m][n]);
	int index=dp[m][n];
	char l[index+1]; 
   l[index] = '\0'; // Set the terminating character 
  
   i = m, j = n; 
   while (i > 0 && j > 0) 
   { 
   
      if (s[i-1] == t[j-1]) 
      { 
          l[index-1] = s[i-1];  
          i--; j--; index--;      
      } 
  
      else if (dp[i-1][j] > dp[i][j-1]) 
         i--; 
      else
         j--; 
   } 
  
   // Print the lcs 
   printf("\nLCS of string-1 and string-2 is : ");
   i=0;
   while(l[i]!='\0')
   printf("%c",l[i++]);
}    
