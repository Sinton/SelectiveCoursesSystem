#ifndef  __INCLUDE_DB_HELPER_H__
#define  __INCLUDE_DB_HELPER_H__

#ifdef _DEBUG
#pragma comment(lib, "lib/sqlite3.lib")
#else
#pragma comment(lib, "lib/sqlite3.lib")
#endif

#include "sqlite3.h"

class DBHelper
{
public:
	DBHelper() { }
	virtual ~DBHelper() { CloseDB(); }
	int OpenDB(const char *path);							// �����ݿ�
	int CloseDB();											// �ر����ݿ�
	int CreateTable(const char *create_table_state);        // ����һ�ű�
	int DropTable(const char *table_name);                  // ɾ��һ�ű�
	int Select(const char *select_state);                   // ��ѯ����
	int Insert(const char *insert_state);                   // �������
	int Delete(const char *delete_state);                   // ɾ������
	int Update(const char *update_state);                   // ���²���
	int Get(const char *select_state);

private:
	sqlite3 *sqlite_db_;	// ���ݿ��ָ��
	char* err_msg_;			// ������Ϣ
	bool is_close_;			// �ر����ݵı�ʶ

	// ��Ҫ����selece�����е���ʾ����Ԫ��
	static int CallBackFunc(void *NotUsed, int argc, char **argv, char **azColName);
	// ִ��sql���
	int SqlStateExec(const char *sql_state);
};


#endif