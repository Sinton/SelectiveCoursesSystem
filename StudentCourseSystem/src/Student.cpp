#include "Student.h"
#include "StudentDao.h"
#include "Menu.h"

string Student::loginUid = "";
string Student::profile[] = { "ѧ�ţ�", "������", "�Ա�", "���㣺", "�꼶��", "רҵ��", "Ժϵ��" };

void Student::login()
{
	
	cout << "������ѧ��: ";
	loginUid = inputString();
	StudentDao studentDao;
	vector<string> studentInfo = studentDao.getStudentByUid(loginUid);
	if (studentDao.checkUidExits(loginUid))
		Menu::studentMenu();
	else
	{
		cout << "ѧ�Ŵ���!" << endl;
		this->login();
	}
}

void Student::createStudent()
{
	Student student;
	cout << "������ѧ�ţ�";
	student.setUid(inputString());
	cout << "������������";
	student.setName(inputString());
	cout << "�������Ա�";
	student.setSex(inputString());
	cout << "�����뼨�㣺";
	student.setCredit(inputString());
	cout << "�������꼶��";
	student.setGrade(inputString());
	cout << "������רҵ��";
	student.setMajor(inputString());
	cout << "������Ժϵ��";
	student.setDepartment(inputString());
	StudentDao studentDao;
	studentDao.addStudent(student);
}

void Student::updateStudent()
{
}

void Student::deleteStudent()
{
}

void Student::showStudentByUid(string uid)
{
	StudentDao studentDao;
	vector<string> studentInfo = studentDao.getStudentByUid(uid);
	vector<string>::iterator iterator;
	if (studentInfo.empty())
		cout << endl << "û�ҵ���ѧ��";
	// ��ӡ��ȡ����ѧ����Ϣ
	cout << endl;
	int index = 0;
	for (iterator = studentInfo.begin(); iterator != studentInfo.end(); iterator++)
		cout << profile[index++] << iterator->data() << endl;
	cout << endl;
	system("pause");
}

void Student::showStudentByName(string name)
{
	StudentDao studentDao;
	vector<string> studentInfo = studentDao.getStudentByName(name);
	vector<string>::iterator iterator;
	if (studentInfo.empty())
		cout << endl << "û�ҵ���ѧ��";
	// ��ӡ��ȡ����ѧ����Ϣ
	cout << endl;
	int index = 0;
	for (iterator = studentInfo.begin(); iterator != studentInfo.end(); iterator++)
		cout << profile[index++] << iterator->data() << endl;
	cout << endl;
	system("pause");
}

void Student::showAllStudents()
{
	StudentDao studentDao;
	vector<Student> students = studentDao.getAllStudents();
	if (students.empty())
	{
		cout << "û�м�¼ѧ����Ϣ!\n";
		system("pause");
		return;
	}
	cout << "\nѧ����Ϣ���£�\n" << endl;
	for (vector<Student>::iterator iter = students.begin(); iter != students.end(); iter++)
	{
		cout << "=========================================================\n"
			<< "ѧ�ţ�" << iter->getUid() << endl
			<< "������" << iter->getName() << endl
			<< "�Ա�" << iter->getSex() << endl
			<< "���㣺" << iter->getCredit() << endl
			<< "�꼶��" << iter->getGrade() << endl
			<< "רҵ��" << iter->getMajor() << endl
			<< "Ժϵ��" << iter->getDepartment() << endl << endl;
	}
	system("pause");
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