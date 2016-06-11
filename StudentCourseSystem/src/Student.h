#include "header.h"

class Student
{
public:
	//static vector<Student>::iterator itCurr; //��ǰѧ�����
	//static vector<Student> vStu;             //��¼ѧ����Ϣ

	// set����
	void setUid(string uid){ this->uid = uid; }
	void setName(string name){ this->name = name; }
	void setSex(string sex){ this->sex = sex; }
	void setCredit(string credit){ this->credit = credit; }
	void setGrade(string grade){ this->grade = grade; }
	void setMajor(string major){ this->major = major; }
	void setDepartment(string department){ this->department = department; }

	// get����
	string getUid(){ return uid; }
	string getName(){ return name; }
	string getSex(){ return sex; }
	string getCredit(){ return credit; }
	string getGrade(){ return grade; }
	string getMajor(){ return major; }
	string getDepartment(){ return department; }

	int login();                             // ��¼
	void createStudent();                    // ���ѧ����Ϣ
	void updateStudent();                    // ����ѧ����Ϣ
	void deleteStudent();                    // ɾ��ѧ����Ϣ
	void showStudent(string uid);            // ��ʾѧ����Ϣ
	Student();
	~Student();

private:
	string uid;       // ѧ��
	string name;      // ����
	string sex;       // �Ա�
	string credit;    // ����
	string grade;     // �꼶
	string major;     // רҵ
	string department;// Ժϵ
};