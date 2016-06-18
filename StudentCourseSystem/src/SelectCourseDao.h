#ifndef _SELECT_COURSE_DAO_H
#define _SELECT_COURSE_DAO_H
#include <vector>
#include "Course.h"
#include "DBHelper.h"

class SelectCourseDao
{
public:
	int openDB(const char *path);
	int closeDB();
	vector<Course> getsOptionalCourses();
	vector<Course> getRecordsByUid(string uid);
	vector<Course> getCourseByCredit(string credit);
	void addRecord(Course course);
	void removeRecord();
	SelectCourseDao(){ openDB(DB_NAME); }
	~SelectCourseDao(){ closeDB(); }

private:
	sqlite3 *sqliteDb;	    // ���ݿ��ָ��
	char* errorMsg;			// ������Ϣ
	bool isClose;			// �ر����ݵı�ʶ
};

#endif