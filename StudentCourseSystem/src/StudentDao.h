#ifndef _STUDENT_DAO_H
#define _STUDENT_DAO_H
#include <iostream>
#include <vector>
#include "DBHelper.h"
#include "Student.h"

class StudentDao : public DBHelper
{
public:
	bool checkUidExits(string uid);              // ���ѧ��ѧ���Ƿ����
	void addStudent(Student student);            // ���ѧ��
	void removeStudent();                        // ɾ��ѧ��
	vector<string> getStudentByUid(string uid);  // ��ȡָ��ѧ�ŵ�ѧ������
	vector<string> getStudentByName(string name);// ��ȡָ��ѧ�ŵ�ѧ������
	vector<Student> getAllStudents();            // ��ȡȫ��ѧ��
	StudentDao(){ openDB(DB_NAME); }
	~StudentDao(){ }

private:
	static int callBackGetStudent(void *, int elementCount, char **element, char **colName);
	static int callBackGetAllStudents(void *, int elementCount, char **element, char **colName);
};

#endif