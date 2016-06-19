#ifndef _SELECT_COURSE_DAO_H
#define _SELECT_COURSE_DAO_H
#include <vector>
#include "Course.h"
#include "SelectCourse.h"
#include "DBHelper.h"

class SelectCourseDao
{
public:
	int openDB(const char *path);
	int closeDB();
	vector<Course> getOptionalCourses(string uid);      // ��ȡ��ѡ�γ�
	vector<Course> getRecords(string uid);    // ��ȡѡ�μ�¼
	void addRecord(SelectCourse selectCourse);// ���ѡ�μ�¼
	void removeRecord();					  // ɾ��ѡ�μ�¼
	SelectCourseDao(){ openDB(DB_NAME); }
	~SelectCourseDao(){ closeDB(); }

private:
	sqlite3 *sqliteDb;	    // ���ݿ��ָ��
	char* errorMsg;			// ������Ϣ
	bool isClose;			// �ر����ݵı�ʶ

	static int callBackGetRecords(void *, int elementCount, char **element, char **colName);
	static int callBackGetOptionalCourses(void *, int elementCount, char **element, char **colName);
};

#endif