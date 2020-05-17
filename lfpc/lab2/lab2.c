/*1. States will be represented as:
q0 = 2^0 = 1
q1 = 2^1 = 2
q2 = 2^2 = 4
2. Union of states will be represented as -
q0,q1 = 2^0 + 2^1 = 3
q1, q2 = 2^1 + 2^2 = 6
q0,q1,q2 = 2^0 + 2^1 + 2^2 = 7
*/
#include<stdio.h>
#include<string.h>
#include<math.h>

int ninputs;
int dfa[100][2][100] = {0};
int state[10000] = {0};
char ch[10], str[1000];
int go[10000][2] = {0};
int arr[10000] = {0};

int main()
{
     int start, finp, in;
     int f[10];
     int i,j=3,s=0,final=0,flag=0,curr1,curr2,k,l;
     int c;

     printf("\nNr of states:");
     scanf("%d",&start);

     printf("\nNr of states from 0 to %d",start-1);

     for(i=0;i<start;i++)
     		state[(int)(pow(2,i))] = 1;

     printf("\nNr of final states\t");
     scanf("%d",&finp);

     printf("\nFinal states:");
     for(i=0;i<finp;i++)
     {
          scanf("%d",&f[i]);
     }

     int p,q,r,rel;

     printf("\nNr of rules according to NFA:");
     scanf("%d",&rel);

     printf("\n\nDefine transition rule as \"initial state input symbol final state\"\n");



     for(i=0; i<rel; i++)
     {
          scanf("%d%d%d",&p,&q,&r);
		  if (q==0)
		  	dfa[p][0][r] = 1;
		  else
		  	dfa[p][1][r] = 1;
     }

     printf("\nInitial state:");
     scanf("%d",&in);

     in = pow(2,in);

     i=0;

     printf("\nDFA sollution");

     int x=0;
     for(i=0;i<start;i++)
     {
     		for(j=0;j<2;j++)
     		{
     				int stf=0;
     				for(k=0;k<start;k++)
     				{
     						if(dfa[i][j][k]==1)
     							stf = stf + pow(2,k);
     				}


     				go[(int)(pow(2,i))][j] = stf;
     				printf("%d-%d-->%d\n",(int)(pow(2,i)),j,stf);
     				if(state[stf]==0)
     					arr[x++] = stf;
     				state[stf] = 1;
          }

     }


     //for new states
     for(i=0;i<x;i++)
     {
     		printf("for %d ---- ",arr[x]);
     		for(j=0;j<2;j++)
     		{
     				int new=0;
     				for(k=0;k<start;k++)
     				{
     						if(arr[i] & (1<<k))
     						{
     								int h = pow(2,k);

     								if(new==0)
     									new = go[h][j];
     								new = new | (go[h][j]);


     						}
     				}

     				if(state[new]==0)
     				{
     					arr[x++] = new;
     					state[new] = 1;
     				}
     		}
     }

     j=3;
     while(j--)
     {
     		printf("\nEnter string");
			scanf("%s",str);
			l = strlen(str);
			curr1 = in;
			flag = 0;
			printf("\nString takes the following path-->\n");
			printf("%d-",curr1);

			for(i=0;i<l;i++)
			{
				curr1 = go[curr1][str[i]-'0'];
				printf("%d-",curr1);
			}

			printf("\nFinal state : %d\n",curr1);

			for(i=0;i<finp;i++)
			{
					if(curr1 & (1<<f[i]))
					{
							flag = 1;
							break;
					}
			}

			if(flag)
				printf("\nString Accepted");
			else
				printf("\nString Rejected");

	 }


	return 0;
}
