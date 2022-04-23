#include<stdio.h>
#include<stdlib.h>

int daysofmonth[2][12]={{31,28,31,30,31,30,31,31,30,31,30,31},
                        {31,29,31,30,31,30,31,31,30,31,30,31}};
int pyear(int n);
int xingqi(int year,int month,int day);
void xq();


int pyear(int n)
{	
	if(n%4==0&&n%100!=0||n%400==0)
		return 1;
	else 
		return 0;
}

int xingqi(int year,int month,int day)
{
	int d=0,i,j;
	i=pyear(year);
	for(j=0;j<month-1;j++)
	d+=daysofmonth[i][j];
	d+=day;
	int weekday=((year-1)+(year-1)/4-(year-1)/100+(year-1)/400+d)%7 ;
	return weekday;
}

int main()
{
	int year,month,day,weekday,a,i;
	scanf("%d-%d-%d",&year,&month,&day);
	pyear(year);
	a=xingqi(year,month,day);
	int shuchu[7];
	switch(a)
	{
	case 1:
		for(i=0;i<7;i++)
		{
			shuchu[i]=day;
			day++;
		}
		break;
	case 2:
		for(i=0;i<7;i++)
		{
			shuchu[i]=day-1;
			day++;
		}
		break;
	case 3:
		for(i=0;i<7;i++)
		{
			shuchu[i]=day-2;
			day++;
		}
		break;
	case 4:
		for(i=0;i<7;i++)
		{
			shuchu[i]=day-3;
			day++;
		}
		break;
	case 5:
		for(i=0;i<7;i++)
		{
			shuchu[i]=day-4;
			day++;
		}
		break;
	case 6:
		for(i=0;i<7;i++)
		{
			shuchu[i]=day-5;
			day++;
		}
		break;
	case 7:
		for(i=0;i<7;i++)
		{
			shuchu[i]=day-6;
			day++;
		}
		break;
	}

	for(i=0;i<7;i++)
	{
		if(shuchu[i]<1)
		{
			if(month=1)
				shuchu[i]=daysofmonth[pyear(year)][11]+shuchu[i];
			else
			shuchu[i]=daysofmonth[pyear(year)][month-2]+shuchu[i];
		}
	}
	for(i=0;i<7;i++)
	{
		if(shuchu[i]>daysofmonth[pyear(year)][month-1])
			shuchu[i]=shuchu[i]-daysofmonth[pyear(year)][month-1];
	}
	printf("%d年%d月\n",year,month);
	printf("一  二  三  四  五  六  日\n");
	printf("%d   %d   %d   %d   %d   %d   %d",shuchu[0],shuchu[1],shuchu[2],shuchu[3],shuchu[4],shuchu[5],shuchu[6]);
	system("pause");
	return 0;
}