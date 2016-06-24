#ifndef _STUDENT_DAO_H
#define _STUDENT_DAO_H
#include <iostream>
#include <vector>
#include "DBHelper.h"
#include "Student.h"

class StudentDao : public DBHelper
{
public:
	bool checkUidExits(string uid);              // 检查学生学号是否存在
	void addStudent(Student student);            // 添加学生
	void removeStudent();                        // 删除学生
	vector<string> getStudentByUid(string uid);  // 获取指定学号的学生对象
	vector<string> getStudentByName(string name);// 获取指定学号的学生对象
	vector<Student> getAllStudents();            // 获取全部学生
	StudentDao(){ openDB(DB_NAME); }
	~StudentDao(){ }

private:
	static int callBackGetStudent(void *, int elementCount, char **element, char **colName);
	static int callBackGetAllStudents(void *, int elementCount, char **element, char **colName);
};

#endif