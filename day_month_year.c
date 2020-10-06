/*
That program is trying to write "Guessing Tomorrow"
    tomorrow be next month or next year or normal inner month day.
Try to write clean and readable program with no special format
    use with    -while
                -scanf
                -printf
                -if else
*/
#include<stdio.h>
#include<conio.h>
int main(){
    int day,month,year=0;
    char ask='Y';
    while(ask=='Y'|| ask=='y')          //checking to exit or not
        {
        printf("Please enter current date or guess want date before\n");
        printf("\tPlease put with DD/MM/YY method\n\t*");
        scanf("%d %d %d",&day,&month,&year);
        //test input is valid
        if ((0<day && day<=31)&&(0<month && month<=12)&&(0<=year) )
            {
                //checking is 31 days month
                if (month== 1 || month==3 || month==5 || month==7 || month==8 || month==10 )
                {
                    if(day<31){day++;goto print;}      //under 30 day may
                    else if (day==31){day=1;month++;goto print;}
                }
                else if (month==2)          //check month is February or Not?
                {
                    if (day<28){day++;goto print;}
                    else if(day==28)
                    {
                        if(month%4==0){day++;goto print;}
                            else{day=1;month++;goto print;}
                    }
                    else if(day==29)
                    {
                        if (month%4==0){day=1;month++;goto print;}
                            else{goto error1;}
                    }else{goto error1;}
                }
                else if(month==12){
                    if(day<31){day++;goto print;}
                    else{day=1;month=1;year++;goto print;}
                }
                //mean 30 day month
                else{
                    if(day<30){day++;goto print;}
                    else if(day==30){day=1;month++;goto print;}
                    else {goto error1;}}
                }
    error1:
        printf("Error! You Put Invalid Date\n");
        goto check;
    print:
        printf("Tomorrow is %d/%d/%d ",day,month,year);
        goto check;
    check:
        printf("\n\nDo You want to play more?\nType 'Y' for recalculate or\nType 'N' for exit (~_~)\t");
        scanf(" %c",&ask);
        printf("\n\n");
    }
    getch();
    return 0;
}
