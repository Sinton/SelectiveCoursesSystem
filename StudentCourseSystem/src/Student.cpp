#include <iostream>
#include "header.h"
#include "Student.h"
#include "Menu.h"
#include "StudentDao.h"

using namespace std;

Student::Student()
{
	uid = "";
	name = "";
	sex = "";
	credit = 0;
	grade = "";
	major = "";
	department = "";
}

Student::~Student()
{

}

int Student::login()
{
	system("cls");	
	while (true)
	{
		system("cls");
		cout << "\n\t\t\t       ѧ����¼" << endl;
		for (int i = 0; i < 80; i++)
			cout << "*";
		cout << "������ѧ�ţ�";
		string uid = inputString();
		StudentDao studentDao;
		vector<string> studentInfo = studentDao.getStudentByUid(uid);
		vector<string>::iterator iterator;
		for (iterator = studentInfo.begin(); iterator != studentInfo.end(); iterator++)
			cout << iterator->data() << "=" << endl;
		system("pause");
		if (!studentInfo.empty())
		{
			cout << "\t\t\t\t��¼�ɹ�!\n\n";
			system("pause");
		}
		else
		{
			system("cls");
			cout << "\t\t\tѧ�Ŵ���!����������!" << endl;
			cout << "\t\t\t��ϵͳ��δ��¼ѧ����Ϣ" << endl;
			system("pause");
		}
	}
}