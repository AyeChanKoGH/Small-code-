/*new form to fix old error */
/*using C++ code*/

#include <iostream>
#include<conio.h>
#include<iomanip>
#include<stdlib.h>
using namespace std;
#define MaxV 20                     //for array length
//variable declaring
int rowN=0;
int columnN=0;
int row[MaxV];
int column[MaxV];
int product[MaxV][MaxV];
int sum[MaxV][MaxV];
//function declaring
void displayP();
void displayS();
void userInput();
char tryagain();

int main()
{
    char dec, deca;
    do {
        cout<<"Product Table or Sum Table \n"
            <<"Press 's' for Sum Table\tor \t"
            <<"Press 'p' for Product Table\tor\t"
            <<"Press 'c' for cancel\n"<<endl;
        cin>>dec;
        //if user choice p to calculate product table
        if (dec=='p'||dec=='P')
        {
            userInput();                //to known user want table form
            for(int j=0;j<rowN;j++)
            {
                for(int k=0;k<columnN;k++){
                product[j][k]=row[j]*column[k];
                }
            }
            displayP();                 //after calculating, show results as table
            deca=tryagain();            //ask user want calculate more or not!
        }else
        if (dec=='s'||dec=='S')     //if user choice s to calculate sum table
        {
            userInput();
            for(int m=0;m<rowN;m++)
            {
                for(int n=0;n<columnN;n++){
                sum[m][n]=row[m]+column[n];
                }
            }
            displayS();
            deca=tryagain();
        }else
        if(dec=='c'||dec=='C')           //if user choice c to exit the program
        {
            deca='n';
            cout <<"cancel program\n";
            exit(EXIT_SUCCESS);
        }else{
            cout<< "Input INVAILD\n";
            deca=tryagain();
        }
    }while(deca=='y'||deca=='Y');
    //
    getch();
    return 0;
}
void displayP()
{
    cout<<"Product Table:\n";
    cout<<setw(8)<<"*";
    for(int r=0;r<columnN;r++)
        cout<<setw(8)<<column[r];
    for(int p=0;p<rowN;p++)
    {
        cout<<"\n"<<setw(8)<<row[p];
        for(int q=0;q<columnN;q++)
        {
            cout<<setw(8)<<product[p][q];
        }
    }cout<<endl;
}
void displayS()
{
    cout<<"Sum Table:\n";
    cout<<setw(8)<<"+";
    for(int r=0;r<columnN;r++)
        cout<<setw(8)<<column[r];
    for(int p=0;p<rowN;p++)
    {
        cout<<"\n"<<setw(8)<<row[p];
        for(int q=0;q<columnN;q++)
        {
            cout<<setw(8)<<sum[p][q];
        }
    }cout<<endl;
}
void userInput()
{
    cout<<"Enter the number of Row     ";
    cin>>rowN;
    cout<<"Enter the number of Column  ";
    cin>>columnN;
    cout<<"Number in the Row are:   \t";
    for(int i=0;i<rowN;i++)
    {
        cin>>row[i];
    }
    cout<<"Number in the Column are:\t";
    for(int l=0;l<columnN;l++)
    {
        cin>>column[l];
    }
}
char tryagain()
{
    char a;
    cout<<"Do you want to calculate again:\n"
        <<"Press 'y' to continue calculate:\t ";
    cin>>a;
    return a;
}
