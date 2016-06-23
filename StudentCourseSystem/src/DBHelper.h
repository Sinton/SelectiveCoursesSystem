#ifndef  __DBHELPER_H__
#define  __DBHELPER_H__

#ifdef _DEBUG
#pragma comment(lib, "lib/sqlite3.lib")
#else
#pragma comment(lib, "lib/sqlite3.lib")
#endif

#include "sqlite3.h"

const char DB_NAME[] = "db/StudentCourse.db";

class DBHelper
{
public:
	DBHelper() { openDB(DB_NAME); }
	virtual ~DBHelper() { closeDB(); }
	int openDB(const char *path);							// �����ݿ�
	int closeDB();											// �ر����ݿ�
	sqlite3 *sqliteDb;	    // ���ݿ��ָ��
	char* errorMsg;			// ������Ϣ
	bool isClose;			// �ر����ݵı�ʶ
private:
	
};

#endif