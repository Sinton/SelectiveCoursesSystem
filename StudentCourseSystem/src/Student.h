#include <iostream>
using namespace std;
class Student
{
	string uid;       // ѧ��ѧ��
	string name;      // ѧ������
	string sex;       // ѧ���Ա�
	double credit;    // ����
	string grade;     // �꼶
	string major;     // רҵ
	string department;// Ժϵ
public:
	static vector<Student>::iterator itCurr; //��ǰѧ�����
	static vector<Student> vStu;             //��¼ѧ����Ϣ

	int login();                             // ��¼
	void createStudent();                    // ���ѧ����Ϣ
	void updateStudent();                    // ����ѧ����Ϣ
	void deleteStudent();                    // ɾ��ѧ����Ϣ
	void showStudent();                      // ��ʾѧ����Ϣ
	Student();
	~Student();
};