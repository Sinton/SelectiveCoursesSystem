#include <iostream>
#include "DBHelper.h"

using namespace std;

class StudentDao
{
public:
	int openDB(const char *path);
	int closeDB();
	int getStudentByUid(string uid);// ��ȡָ��ѧ�ŵ�ѧ������
	StudentDao(){ openDB(DB_NAME); }
	~StudentDao(){ closeDB(); }

private:
	sqlite3 *sqliteDb;	    // ���ݿ��ָ��
	char* errorMsg;			// ������Ϣ
	bool isClose;			// �ر����ݵı�ʶ

	// sql�ص�����
	static int callBackSaveStudent(void *, int argc, char **argv, char **colName);
	// ִ��sql���
	int sqlExecute(const char *sqlStmt);
};
