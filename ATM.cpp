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
	������ƻ�������ҵ����ATM
	�º���  ��1704  1110170107
*/
class ATM {
public:
	ATM(){};
	ATM(string, string);    //���캯��1���û���+����
	ATM(string, string, double);    //���캯��2 �û���+����+���
	void Start_show();       //��ʼ����
	
private:
	string username; 
	string password;
	double balance;
	void page2();
	bool LogOn(string,string);   //��½
	void query();       //��ѯ���
	void withdraw();    //ȡǮ
	void transfer();    //ת��
	void deposit();     //��Ǯ
	void ChangePassword();//�޸�����
	void LogOut();    //�˳�
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
	cout << "------------------------------------------------" << endl;   //48���ַ�
	cout << "*" << right << setw(47) << "*" << endl;
	cout << "*" << setw(35) << "���뿪ʱ����������Ʒ!" << setw(12) << "*" << endl;
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
	cout << "*" << setw(10) << username <<left << setw(20) << "���������Ϊ��"<<left<<setw(5)
		<<fixed<<setprecision(2)<<showpoint<<balance<< left<<setw(8)<<right<<setw(12) << "*" << endl;
	cout << "*" << right << setw(47) << "*" << endl;
	cout << "*" << left << setw(20) << "    [1]����" << left << setw(26) << "[2]�˳�" << "*" << endl;
	cout << "*" << right << setw(47) << "*" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "ͨ��������ţ�ѡ����Ҫ�����ҵ��";
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
		cout << "�����ڸ�ҵ��" << endl;
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
	cout << "*" << setw(35) << "���ڰ���ȡ��ҵ��" << setw(12) << "*" << endl;
	cout << "*" << right << setw(47) << "*" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "������ȡ����Ŀ��";
	double money;
	cin >> money;
	if (balance > money) {
		balance -= money;
		cout << "------------------------------------------------" << endl;
		cout << "*" << right << setw(47) << "*" << endl;
		cout << "*" << setw(25) << "ȡ��ɹ�!" << setw(22) << "*" << endl;
		cout << "*" << right << setw(47) << "*" << endl;
		cout << "*" << setw(10) << username << left << setw(20) << "���������Ϊ��" << left << setw(5)
			<< fixed << setprecision(2) << showpoint << balance <<right<< setw(11) << "*" << endl;
	}
	else {
		cout << "------------------------------------------------" << endl;
		cout << "*" << right << setw(47) << "*" << endl;
		cout << "*" << setw(35) << "���㣬ȡ��ʧ�ܣ�" << setw(12) << "*" << endl;	
		cout << "*" << right << setw(47) << "*" << endl;
	}
	cout << "*" << right << setw(47) << "*" << endl;
	cout << "*" << left << setw(20) << "      [1]����" << left << setw(26) << "[2]�˳�" << "*" << endl;
	cout << "*" << right << setw(47) << "*" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "ͨ��������ţ�ѡ����Ҫ�����ҵ��";
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
		cout << "�����ڸ�ҵ��" << endl;
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
	cout << "*" << setw(35) << "���ڰ�����ҵ��" << setw(12) << "*" << endl;
	cout << "*" << right << setw(47) << "*" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "����������Ŀ��";
	double money;
	cin >> money;
	balance += money;
	cout << "------------------------------------------------" << endl;
	cout << "*" << right << setw(47) << "*" << endl;
	cout << "*" << setw(25) << "���ɹ�!" << setw(22) << "*" << endl;
	cout << "*" << right << setw(47) << "*" << endl;
	cout << "*" <<right<< setw(10) << username << left << setw(20) << "���������Ϊ��" << left << setw(5)
			<< fixed << setprecision(2) << showpoint << balance <<right<< setw(11) << "*" << endl;
	cout << "*" << right << setw(47) << "*" << endl;
	cout << "*" << left << setw(20) << "    [1]����" << left << setw(26) << "[2]�˳�" << "*" << endl;
	cout << "*" << right << setw(47) << "*" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "ͨ��������ţ�ѡ����Ҫ�����ҵ��";
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
		cout << "�����ڸ�ҵ��" << endl;
		Sleep(3 * 1000);
		LogOut();
		break;
	}
}

void ATM::transfer() {
	cout << "------------------------------------------------" << endl;
	cout << "*" << right << setw(47) << "*" << endl;
	cout << "*" << setw(35) << "���ڽ���ת�˽��ף�" << setw(12) << "*" << endl;
	cout << "*" << right << setw(47) << "*" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "�����������";
	string to_user;
	cin >> to_user;
	double money;
	cout << "���������";
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
		cout << "*" << setw(35) << "����ʧ�ܣ������ԣ�" << setw(12) << "*" << endl;
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
		cout << "*" << setw(35) << "���׳ɹ������س�ʼ�˵���" << setw(12) << "*" << endl;
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
	cout << "*" << setw(35) << "�����޸��û����룡" << setw(12) << "*" << endl;
	cout << "*" << right << setw(47) << "*" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "������ԭʼ���룺";
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
		cout << "*" << setw(35) << "������������ԣ�" << setw(12) << "*" << endl;
		cout << "*" << right << setw(47) << "*" << endl;
		cout << "------------------------------------------------" << endl;
		Sleep(3 * 1000);
		page2();
		return;
	}
	cout << endl;
	cout << "�����������룺";
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
	cout << "\n��ȷ�����룺";
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
		cout << "*" << setw(35) << "������������벻��ͬ�������ԣ�" << setw(12) << "*" << endl;
		cout << "*" << right << setw(47) << "*" << endl;
		cout << "------------------------------------------------" << endl;
	}
	else
	{
		this->password = tmp1;
		cout << "------------------------------------------------" << endl;
		cout << "*" << right << setw(47) << "*" << endl;
		cout << "*" << setw(25) << "�����޸ĳɹ���" << setw(22) << "*" << endl;
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
	cout << "*" << setw(10)<<username<<setw(25) << "���ã���ѡ����Ҫ�����ҵ��" << setw(9) << "*" << endl;
	cout << "*" <<right<< setw(47) << "*" << endl;
	cout << "*" << left << setw(20) << "  [1]��ѯ���" << left << setw(26) << "[2]�޸�����" << "*" << endl;
	cout << "*" << left << setw(20) << "  [3]���" << left << setw(26) << "[4]ȡ��" << "*" << endl;
	cout << "*" << left << setw(20) << "  [5]ת��" << left << setw(26) << "[6]�˳�" << "*" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "ͨ��������ţ�ѡ����Ҫ�����ҵ��";
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
		cout << "�����ڸ�ҵ��" << endl;
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
	cout << "------------------------------------------------" << endl;   //48���ַ�
	cout << "*" << setw(47) << "*" << endl;
	cout << "*" << setw(35) << "��ӭʹ��C++����������ȡ���" << setw(12) << "*" << endl;
	cout << "*" << setw(35) << "Ĭ���û������������룺123456" << setw(12) << "*" << endl;
	cout << "*" << setw(35) << "ת���û������ģ����룺123456" << setw(12) << "*" << endl;
	cout << "*" << setw(47) << "*" << endl;
	cout << "------------------------------------------------" << endl;
	while (cnt)
	{
		string username, password;
		cout << "�������û�����";
		cin >> username;
		cout << "���������룺";
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
			cout << "*" << setw(26) << "�������������"<<cnt<<"�λ��ᣡ" << setw(12) << "*" << endl;
			cout << "*" << setw(47) << "*" << endl;
			cout << "------------------------------------------------" << endl;
		}
	}
	if (cnt == 0) {
		system("cls");
		cout << "------------------------------------------------" << endl;
		cout << "*" << setw(47) << "*" << endl;
		cout << "*" << setw(37) << "������󳬹�3�Σ����˻��ѱ����ᣡ" << setw(10) << "*" << endl;
		cout << "*" << setw(47) << "*" << endl;
		cout << "------------------------------------------------" << endl;
		//Sleep(5 * 1000);
	}
	return;
}

int main(){
	ATM zhangsan("����", "123456"), lisi("����", "123456");
	users.push_back( &zhangsan);
	users.push_back( &lisi);
	zhangsan.Start_show();
	lisi.Start_show();
	return 0;
}
