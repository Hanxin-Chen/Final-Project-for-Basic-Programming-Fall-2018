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
	程序设计基础大作业——ATM
	陈汉鑫  计1704  1110170107
*/
class ATM {
public:
	ATM(){};
	ATM(string, string);    //构造函数1，用户名+密码
	ATM(string, string, double);    //构造函数2 用户名+密码+余额
	void Start_show();       //初始界面
	
private:
	string username; 
	string password;
	double balance;
	void page2();
	bool LogOn(string,string);   //登陆
	void query();       //查询余额
	void withdraw();    //取钱
	void transfer();    //转账
	void deposit();     //存钱
	void ChangePassword();//修改密码
	void LogOut();    //退出
	//void gettrans(double);
};

vector<ATM*> users;

ATM::ATM(string un, string pw):balance(0) {
	username = un;
	password = pw;
}
ATM::ATM(string un, string pw, double bal) {
	username = un;
	password = pw;
	balance = bal;
}
bool ATM::LogOn(string un,string pw) {
	if (un == username && pw == password)
		return true;
	return false;
}

void ATM::LogOut() {
	system("cls");
	cout << "------------------------------------------------" << endl;   //48个字符
	cout << "*" << right << setw(47) << "*" << endl;
	cout << "*" << setw(35) << "请离开时带好随身物品!" << setw(12) << "*" << endl;
	cout << "*" << right << setw(47) << "*" << endl;
	cout << "------------------------------------------------" << endl;
	Sleep(3 * 1000);
	return;
}

void ATM::query() {
	int tmp;
	system("cls");
	cout << "------------------------------------------------" << endl;
	cout << "*" << right << setw(47) << "*" << endl;
	cout << "*" << setw(10) << username <<left << setw(20) << "，您的余额为："<<left<<setw(5)
		<<fixed<<setprecision(2)<<showpoint<<balance<< left<<setw(8)<<right<<setw(12) << "*" << endl;
	cout << "*" << right << setw(47) << "*" << endl;
	cout << "*" << left << setw(20) << "    [1]返回" << left << setw(26) << "[2]退出" << "*" << endl;
	cout << "*" << right << setw(47) << "*" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "通过输入序号，选择需要办理的业务：";
	cin >> tmp;
	switch (tmp)
	{
	case 1:
		page2();
		break;
	case 2:
		LogOut();
		break;
	default:
		cout << "不存在该业务！" << endl;
		Sleep(3 * 1000);
		LogOut();
		break;
	}
}

void ATM::withdraw() {
	int tmp;
	system("cls");
	cout << "------------------------------------------------" << endl;   
	cout << "*" << right << setw(47) << "*" << endl;
	cout << "*" << setw(35) << "正在办理取款业务！" << setw(12) << "*" << endl;
	cout << "*" << right << setw(47) << "*" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "请输入取款数目：";
	double money;
	cin >> money;
	if (balance > money) {
		balance -= money;
		cout << "------------------------------------------------" << endl;
		cout << "*" << right << setw(47) << "*" << endl;
		cout << "*" << setw(25) << "取款成功!" << setw(22) << "*" << endl;
		cout << "*" << right << setw(47) << "*" << endl;
		cout << "*" << setw(10) << username << left << setw(20) << "，您的余额为：" << left << setw(5)
			<< fixed << setprecision(2) << showpoint << balance <<right<< setw(11) << "*" << endl;
	}
	else {
		cout << "------------------------------------------------" << endl;
		cout << "*" << right << setw(47) << "*" << endl;
		cout << "*" << setw(35) << "余额不足，取款失败！" << setw(12) << "*" << endl;	
		cout << "*" << right << setw(47) << "*" << endl;
	}
	cout << "*" << right << setw(47) << "*" << endl;
	cout << "*" << left << setw(20) << "      [1]返回" << left << setw(26) << "[2]退出" << "*" << endl;
	cout << "*" << right << setw(47) << "*" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "通过输入序号，选择需要办理的业务：";
	cin >> tmp;
	switch (tmp)
	{
	case 1:
		page2();
		break;
	case 2:
		LogOut();
		break;
	default:
		cout << "不存在该业务！" << endl;
		Sleep(3 * 1000);
		LogOut();
		break;
	}

}

void ATM::deposit() {
	int tmp;
	system("cls");
	cout << "------------------------------------------------" << endl;
	cout << "*" << right << setw(47) << "*" << endl;
	cout << "*" << setw(35) << "正在办理存款业务！" << setw(12) << "*" << endl;
	cout << "*" << right << setw(47) << "*" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "请输入存款数目：";
	double money;
	cin >> money;
	balance += money;
	cout << "------------------------------------------------" << endl;
	cout << "*" << right << setw(47) << "*" << endl;
	cout << "*" << setw(25) << "存款成功!" << setw(22) << "*" << endl;
	cout << "*" << right << setw(47) << "*" << endl;
	cout << "*" <<right<< setw(10) << username << left << setw(20) << "，您的余额为：" << left << setw(5)
			<< fixed << setprecision(2) << showpoint << balance <<right<< setw(11) << "*" << endl;
	cout << "*" << right << setw(47) << "*" << endl;
	cout << "*" << left << setw(20) << "    [1]返回" << left << setw(26) << "[2]退出" << "*" << endl;
	cout << "*" << right << setw(47) << "*" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "通过输入序号，选择需要办理的业务：";
	cin >> tmp;
	switch (tmp)
	{
	case 1:
		page2();
		break;
	case 2:
		LogOut();
		break;
	default:
		cout << "不存在该业务！" << endl;
		Sleep(3 * 1000);
		LogOut();
		break;
	}
}

void ATM::transfer() {
	cout << "------------------------------------------------" << endl;
	cout << "*" << right << setw(47) << "*" << endl;
	cout << "*" << setw(35) << "正在进行转账交易！" << setw(12) << "*" << endl;
	cout << "*" << right << setw(47) << "*" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "请输入汇款对象：";
	string to_user;
	cin >> to_user;
	double money;
	cout << "请输入汇款金额：";
	cin >> money;
	int flag = 0;
	int i;
	for (i = 0; i < users.size();i++) {
		if (users[i]->username == to_user) {
			flag = 1;
			break;
		}
	}
	if (flag == 0 || money > balance) {
		cout << "------------------------------------------------" << endl;
		cout << "*" << right << setw(47) << "*" << endl;
		cout << "*" << setw(35) << "交易失败，请重试！" << setw(12) << "*" << endl;
		cout << "*" << right << setw(47) << "*" << endl;
		cout << "------------------------------------------------" << endl;
		Sleep(3 * 1000);
		page2();
		return;
	}
	else
	{
		balance -= money;
		users[i]->balance += money;
		cout << "------------------------------------------------" << endl;
		cout << "*" << right << setw(47) << "*" << endl;
		cout << "*" << setw(35) << "交易成功，返回初始菜单！" << setw(12) << "*" << endl;
		cout << "*" << right << setw(47) << "*" << endl;
		cout << "------------------------------------------------" << endl;
		Sleep(3 * 1000);
		page2();
		return;
	}
}

void ATM::ChangePassword() {
	string pw, tmp1, tmp2;
	char tmp;
	cout << "------------------------------------------------" << endl;
	cout << "*" << right << setw(47) << "*" << endl;
	cout << "*" << setw(35) << "正在修改用户密码！" << setw(12) << "*" << endl;
	cout << "*" << right << setw(47) << "*" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "请输入原始密码：";
	while ((tmp = _getch()) != '\r')
	{
		if (tmp == 0)
			continue;
		if (tmp == 8 && pw.empty()) {
			continue;
		}
		if (tmp != 8) {
			pw += tmp;
			putchar('*');
		}
		else {
			pw.erase(pw.size() - 1);
			putchar('\b');
			putchar(' ');
			putchar('\b');
		}
		_getch();
	}
	cout << endl;
	if (pw != password) {
		cout << "------------------------------------------------" << endl;
		cout << "*" << right << setw(47) << "*" << endl;
		cout << "*" << setw(35) << "密码错误，请重试！" << setw(12) << "*" << endl;
		cout << "*" << right << setw(47) << "*" << endl;
		cout << "------------------------------------------------" << endl;
		Sleep(3 * 1000);
		page2();
		return;
	}
	cout << endl;
	cout << "请输入新密码：";
	while ((tmp = _getch()) != '\r')
	{
		if (tmp == 0)
			continue;
		if (tmp == 8 && tmp1.empty()) {
			continue;
		}
		if (tmp != 8) {
			tmp1 += tmp;
			putchar('*');
		}
		else {
			tmp1.erase(tmp1.size() - 1);
			putchar('\b');
			putchar(' ');
			putchar('\b');
		}
		_getch();
	}
	cout << endl;
	cout << "\n请确认密码：";
	while ((tmp = _getch()) != '\r')
	{
		if (tmp == 0)
			continue;
		if (tmp == 8 && tmp2.empty()) {
			continue;
		}
		if (tmp != 8) {
			tmp2 += tmp;
			putchar('*');
		}
		else {
			tmp2.erase(tmp2.size() - 1);
			putchar('\b');
			putchar(' ');
			putchar('\b');
		}
		_getch();
	}
	cout << endl;
	if (tmp1 != tmp2) {
		cout << "------------------------------------------------" << endl;
		cout << "*" << right << setw(47) << "*" << endl;
		cout << "*" << setw(35) << "两次输入的密码不相同，请重试！" << setw(12) << "*" << endl;
		cout << "*" << right << setw(47) << "*" << endl;
		cout << "------------------------------------------------" << endl;
	}
	else
	{
		this->password = tmp1;
		cout << "------------------------------------------------" << endl;
		cout << "*" << right << setw(47) << "*" << endl;
		cout << "*" << setw(25) << "密码修改成功！" << setw(22) << "*" << endl;
		cout << "*" << right << setw(47) << "*" << endl;
		cout << "------------------------------------------------" << endl;
	}
	Sleep(3 * 1000);
	page2();
	return;
}

void ATM::page2() {
	system("cls");
	int tmp;
	cout << "------------------------------------------------" << endl;   
	cout << "*" <<right<< setw(47) << "*" << endl;
	cout << "*" << setw(10)<<username<<setw(25) << "您好，请选择需要办理的业务！" << setw(9) << "*" << endl;
	cout << "*" <<right<< setw(47) << "*" << endl;
	cout << "*" << left << setw(20) << "  [1]查询余额" << left << setw(26) << "[2]修改密码" << "*" << endl;
	cout << "*" << left << setw(20) << "  [3]存款" << left << setw(26) << "[4]取款" << "*" << endl;
	cout << "*" << left << setw(20) << "  [5]转账" << left << setw(26) << "[6]退出" << "*" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "通过输入序号，选择需要办理的业务：";
	cin >> tmp;
	switch (tmp)
	{
	case 1:
		query();
		break;
	case 2:
		ChangePassword();
		break;
	case 3:
		deposit();
		break;
	case 4:
		withdraw();
		break;
	case 5:
		transfer();
		break;
	case 6:
		LogOut();
		break;
	default:
		cout << "不存在该业务！" << endl;
		Sleep(3 * 1000);
		LogOut();
		break;
	}
	return;
}

void ATM::Start_show() {
	system("cls");
	char tmp;
	int cnt = 3;
	cout << "------------------------------------------------" << endl;   //48个字符
	cout << "*" << setw(47) << "*" << endl;
	cout << "*" << setw(35) << "欢迎使用C++银行自助存取款机" << setw(12) << "*" << endl;
	cout << "*" << setw(35) << "默认用户：张三，密码：123456" << setw(12) << "*" << endl;
	cout << "*" << setw(35) << "转账用户：李四，密码：123456" << setw(12) << "*" << endl;
	cout << "*" << setw(47) << "*" << endl;
	cout << "------------------------------------------------" << endl;
	while (cnt)
	{
		string username, password;
		cout << "请输入用户名：";
		cin >> username;
		cout << "请输入密码：";
		getchar();
		while ((tmp = _getch()) != '\r')
		{
			if (tmp == 0)
				continue;
			if (tmp == 8 && password.empty()) {
				continue;
			}
			if (tmp != 8) {
				password += tmp;
				putchar('*');
			}
			else {
				password.erase(password.size() - 1);
				putchar('\b');
				putchar(' ');
				putchar('\b');
			}
			_getch();
		}
		if (LogOn(username, password) == true) {
			page2();
			break;
		}
		else {
			cnt--;
			system("cls");
			cout << "------------------------------------------------" << endl;   
			cout << "*" << setw(47) << "*" << endl;
			cout << "*" << setw(26) << "密码错误，您还有"<<cnt<<"次机会！" << setw(12) << "*" << endl;
			cout << "*" << setw(47) << "*" << endl;
			cout << "------------------------------------------------" << endl;
		}
	}
	if (cnt == 0) {
		system("cls");
		cout << "------------------------------------------------" << endl;
		cout << "*" << setw(47) << "*" << endl;
		cout << "*" << setw(37) << "密码错误超过3次，该账户已被冻结！" << setw(10) << "*" << endl;
		cout << "*" << setw(47) << "*" << endl;
		cout << "------------------------------------------------" << endl;
		//Sleep(5 * 1000);
	}
	return;
}

int main(){
	ATM zhangsan("张三", "123456"), lisi("李四", "123456");
	users.push_back( &zhangsan);
	users.push_back( &lisi);
	zhangsan.Start_show();
	lisi.Start_show();
	return 0;
}
