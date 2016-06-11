#include "Student.h"
#include "StudentDao.h"
#include "Menu.h"

vector<Student> stu_vec;
//vector<Student> Student::vStu = stu_vec;
//vector<Student>::iterator Student::itCurr = vStu.begin();

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
		if (studentDao.checkUidExits(uid))
		{
			Menu::studentMenu();
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

void Student::createStudent()
{
	Student student;
	cout << "������ѧ�ţ�" << endl;
	student.uid = inputString();
	cout << "������������" << endl;
	student.name = inputString();
	cout << "�������Ա�" << endl;
	student.sex = inputString();
	cout << "�����뼨�㣺" << endl;
	student.credit = inputString();
	cout << "�������꼶��" << endl;
	student.grade = inputString();
	cout << "������רҵ��" << endl;
	student.major = inputString();
	cout << "������Ժϵ��" << endl;
	student.department = inputString();
	StudentDao studentDao;
	studentDao.addStudent(student);
}

void Student::updateStudent()
{

}

void Student::deleteStudent()
{

}

void Student::showStudent(string uid)
{
	StudentDao studentDao;
	vector<string> studentInfo = studentDao.getStudentByUid(uid);
	vector<string>::iterator iterator;
	// ��ӡ��ȡ����ѧ����Ϣ
	for (iterator = studentInfo.begin(); iterator != studentInfo.end(); iterator++)
		cout << iterator->data() << "=" << endl;
}

Student::Student()
{
	uid = "";
	name = "";
	sex = "";
	credit = "";
	grade = "";
	major = "";
	department = "";
}

Student::~Student()
{

}