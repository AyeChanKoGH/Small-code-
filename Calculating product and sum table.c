/*calculating product and sum table for four digits*/
//Enter row and column,then calculate the table
//C compiler used
#include <stdio.h>
#include<conio.h>
#define MaxV 20 //limit array size
void productf();//declare product function
void sumf(); //declaring sum function
	int var; //declaring variable
	int a=0;
	int row[MaxV];
	int column[MaxV];
	int product[MaxV];
	int sum[MaxV];
int main()
{
	char dec,deca;
	do{
	printf("Product table or sum table\npress 's' to sum and press 'p' to product or press 'c' to cancel\t");
	scanf("%c",&dec);
	if(dec=='p')
	printf("ProductorTable\n");
	if(dec=='s')
	printf("Sum Table\n");
	printf("Enter the row\t");
		if(dec=='s'||dec=='p')
		{
			
		
	for(int i=0;i<4;i++)
	{
		int var=0;
		scanf("%d",&var);
		row[i]=var;
	}
	printf("Enter column\t");
		for(int i=0;i<4;i++)
	{
		int var=0;
		scanf("%d",&var);
		column[i]=var;
	}}
	if(dec=='p')
	{	
	productf();
	printf("       *");
	}
	if(dec=='s')
	{
		sumf();
		printf("       +");
	}
	for(int j=0;j<4;j++)
	printf("%8d",row[j]);
	
	printf("\n\n%8d%8d%8d%8d%8d\n",column[0],product[0],product[1],product[2],product[3]);
	printf("\n%8d%8d%8d%8d%8d\n",column[1],product[4],product[5],product[6],product[7]);
	printf("\n%8d%8d%8d%8d%8d\n",column[2],product[8],product[9],product[10],product[11]);
	printf("\n%8d%8d%8d%8d%8d\n",column[3],product[12],product[13],product[14],product[15]);
	printf("\nDo you want play more 'y' or 'n' press\n");
	scanf("%c",&deca);
	}while(deca=='y');
	getch();
	return 0;
}
void productf()
{
	
	for(int k=0;k<4;k++)
	{
		var=row[k] * column[0];
		product[k]=var;
	}
		for(int k=4;k<8;k++)
	{
		var=row[a] * column[1];
		product[k]=var;
		a++;
		if(a>3)a=0;
	}
		for(int k=8;k<12;k++)
	{
		var=row[a] * column[2];
		product[k]=var;
		a++;
		if(a>3)a=0;
	}
		for(int k=12;k<16;k++)
	{
		var=row[a] * column[3];
		product[k]=var;
		a++;
		if(a>3)a=0;
	}	
}
void sumf()
{
	for(int k=0;k<4;k++)
	{
		product[k]=row[k]+column[0];	
	}
	for(int k=4;k<8;k++)
	{
		product[k]=row[a]+column[1];	
		a++;
		if(a>3)a=0;
	}
	for(int k=8;k<12;k++)
	{
		product[k]=row[a]+column[2];	
		a++;
		if(a>3)a=0;
	}
	for(int k=12;k<16;k++)
	{
		product[k]=row[a]+column[3];	
		a++;
		if(a>3)a=0;
	}
}
