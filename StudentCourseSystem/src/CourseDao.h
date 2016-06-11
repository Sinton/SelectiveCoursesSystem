#include <iostream>
#include <vector>
#include "DBHelper.h"

using namespace std;

class CourseDao
{
public:
	int openDB(const char *path);
	int closeDB();
	vector<Course> getAllCourses();
	void addCourse(Course course);
	void removeCourse();
	CourseDao(){ openDB(DB_NAME); }
	~CourseDao(){ closeDB(); }

private:
	sqlite3 *sqliteDb;	    // ���ݿ��ָ��
	char* errorMsg;			// ������Ϣ
	bool isClose;			// �ر����ݵı�ʶ

	static int callBackAllCourses(void *, int argc, char **argv, char **colName);
	static int callBackAddCourse(void *, int argc, char **argv, char **colName);
	static int callBackRemoveCourse(void *, int argc, char **argv, char **colName);
};