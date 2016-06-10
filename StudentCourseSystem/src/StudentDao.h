#include <iostream>
#include <vector>
#include "DBHelper.h"

using namespace std;

class StudentDao
{
public:
	int openDB(const char *path);
	int closeDB();
	vector<string> getStudentByUid(string uid);// ��ȡָ��ѧ�ŵ�ѧ������
	StudentDao(){ openDB(DB_NAME); }
	~StudentDao(){ closeDB(); }

private:
	sqlite3 *sqliteDb;	    // ���ݿ��ָ��
	char* errorMsg;			// ������Ϣ
	bool isClose;			// �ر����ݵı�ʶ

	// sql�ص�����
	static int callBackSaveStudentInfo(void *, int argc, char **argv, char **colName);
};
