#ifndef  __INCLUDE_DBHELPER_H__
#define  __INCLUDE_DBHELPER_H__

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
	int createTable(const char *createTableStmt);           // ����һ�ű�
	int dropTable(const char *tableName);                   // ɾ��һ�ű�
	int select(const char *selectStmt);                     // ��ѯ����
	int insert(const char *insertStmt);                     // �������
	int remove(const char *deleteStmt);                     // ɾ������
	int update(const char *updateStmt);                     // ���²���
	int get(const char *selectStmt);

private:
	sqlite3 *sqliteDb;	    // ���ݿ��ָ��
	char* errorMsg;			// ������Ϣ
	bool isClose;			// �ر����ݵı�ʶ

	// ��Ҫ����selece�����е���ʾ����Ԫ��
	static int callBackFun(void *NotUsed, int argc, char **argv, char **colName);
	// ִ��sql���
	int sqlExecute(const char *sqlStmt);
};


#endif