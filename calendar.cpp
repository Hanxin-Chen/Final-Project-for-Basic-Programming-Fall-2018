#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <cctype>
#include <Windows.h>
#include <map>
#include <ctime>
#include <sstream>
#include <conio.h>
using namespace std;
/*
	程序设计基础大作业——万年历
	陈汉鑫  计1704  1110170107
*/
#define N 100005
int LeapYear[N];
int Days_LeapYear[15] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
int Days_NormalYear[15] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
string title[8] = { "日","一","二","三","四","五","六" };

bool isLeapYear(int year) {
	if (year % 4 == 0 && year % 100 != 0)
		return true;
	if (year % 400 == 0)
		return true;
	return false;
}

void ini_year() {
	for (int i = 1; i <= N; i++)
	{
		if (isLeapYear(i))
			LeapYear[i] = 1;
	}
}

void ini_days() {
	for (int i = 1; i <= 12; i++)
	{
		Days_LeapYear[i] += Days_LeapYear[i - 1];
		Days_NormalYear[i] += Days_NormalYear[i - 1];
	}
}

int WeekJudge(int year, int month) {
	//2019年1月1日是星期二,将其设为对比基准
	int days = 0;
	if (year < 2019) {
		for (int i = year; i < 2019; i++)
		{
			days += 365 + LeapYear[i];
		}
		if (LeapYear[year]) {
			days -= Days_LeapYear[month - 1];
		}
		else {
			days -= Days_NormalYear[month - 1];
		}
		return (7 - ((days-2) % 7))%7;
	}
	else
	{
		for (int i = 2019; i < year; i++)
		{
			days += 365 + LeapYear[i];
		}
		if (LeapYear[year]) {
			days += Days_LeapYear[month - 1];
		}
		else
		{
			days += Days_NormalYear[month - 1];
		}
		return (days + 2) % 7;
	}
	
}

void display(int year, int month) {
	int first_day = WeekJudge(year, month);
	//cout << first_day << endl;
	int days = Days_NormalYear[month]-Days_NormalYear[month-1];
	if (month == 2)
		days += LeapYear[year];
	int row = ceil((days + first_day) / 7);
	int k = 1;
	for (int i = 0; i < 7; i++)
	{
		cout << setw(3) << title[i];
	}
	cout << endl;
	for (int i = 0; i < row+1; i++)
	{
		if (i == 0) {
			for (int j = 0; j < first_day; j++)
			{
				cout << setw(3) << " ";
			}
			for (int j = first_day; j < 7; j++)
			{
				cout << setw(3) << k++;
			}
			cout << endl;
			continue;
		}
		for (int j = 0; j < 7; j++)
		{
			cout << setw(3) << k++;
			if (k > days)
				break;
		}
		cout << endl;
		if (k > days)
			break;
	}
}

int main(){
	int year, month;
	ini_year();   //闰年打表
	ini_days();   //初始化天数
	while (cout<<"请输入年份与月份：",cin>>year>>month,year!=-1&&month!=-1)
	{
		cout << endl;
		cout << year << "年  " << month << "月\n" << endl;
		cout << "----------------------" << endl;
		display(year, month);
		cout << "----------------------" << endl;
		cout << endl;
	}
	return 0;
}
