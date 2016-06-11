#include <iostream>
#include <vector>
#include "DBHelper.h"

using namespace std;

class StudentDao
{
public:
	int openDB(const char *path);
	int closeDB();
	bool checkUidExits(string uid);              // ���ѧ��ѧ���Ƿ����
	void addStudent(Student student);            // ���ѧ��
	void removeStudent();                        // ɾ��ѧ��
	vector<string> getStudentByUid(string uid);  // ��ȡָ��ѧ�ŵ�ѧ������
	vector<string> getStudentByName(string name);// ��ȡָ��ѧ�ŵ�ѧ������
	StudentDao(){ openDB(DB_NAME); }
	~StudentDao(){ closeDB(); }

private:
	sqlite3 *sqliteDb;	    // ���ݿ��ָ��
	char* errorMsg;			// ������Ϣ
	bool isClose;			// �ر����ݵı�ʶ

	static int callBackGetStudentByUid(void *, int elementCount, char **element, char **colName);
	static int callBackGetStudentByName(void *, int elementCount, char **element, char **colName);
};