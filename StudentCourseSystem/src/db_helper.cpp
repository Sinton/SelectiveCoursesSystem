#include <iostream>
#include "db_helper.h"
using namespace std;

/**
 *  ����������
 *  @return
 */
int DBHelper::OpenDB(const char *path)
{
	int res = sqlite3_open(path, &sqlite_db_);
	if (res)
	{
		cout << "�޷������ݿ�: " << sqlite3_errmsg(sqlite_db_);
		sqlite3_close(sqlite_db_);
		return -1;
	}
	is_close_ = false;
	return 0;
}

/**
 *  �ر����ݿ�����
 *  @return
 */
int DBHelper::CloseDB()
{
	if (!is_close_)
	{
		int res = sqlite3_close(sqlite_db_);
		if (res)
		{
			cout << "�޷��ر����ݿ�: " << sqlite3_errmsg(sqlite_db_);
			return -1;
		}
	}

	return 0;
}

/**
 *  �������ݿ��
 *  @return
 */
int DBHelper::CreateTable(const char *table_name_and_field)
{
	string create_table_state = "create table ";
	create_table_state += table_name_and_field;
	create_table_state += ";";
	int res = SqlStateExec(create_table_state.c_str());
	if (res != SQLITE_OK)
	{
		cout << "create table failed." << err_msg_ << endl;
		return -1;
	}
	else
	{
		cout << "create table successed." << endl;
	}
	return 0;
}

/**
 *  ɾ�����ݿ��
 *  @return
 */
int DBHelper::DropTable(const char *table_name)
{
	string sql_state = "drop table ";
	sql_state += table_name;
	sql_state += ";";
	int res = SqlStateExec(sql_state.c_str());
	if (res != SQLITE_OK)
	{
		cout << "drop table failed." << err_msg_ << endl;
		return -1;
	}
	else
	{
		cout << "drop table successed." << endl;
	}
	return 0;
}

/**
 *  ��ѯ���ݿ�
 *  @return
 */
int DBHelper::Select(const char *select_state)
{
	int res = SqlStateExec(select_state);

	if (res != SQLITE_OK)
	{
		cout << "select operate failed." << err_msg_ << endl;
		return -1;
	}
	else
	{
		cout << "select operate successed." << endl;
	}

	return 0;
}

/**
 *  ���������
 *  @return
 */
int DBHelper::Insert(const char *insert_state)
{
	int res = sqlite3_exec(sqlite_db_, "begin transaction;", CallBackFunc, 0, &err_msg_);
	res = SqlStateExec(insert_state);
	if (res != SQLITE_OK)
	{
		cout << "insert operate failed." << err_msg_ << endl;
		return -1;
	}

	res = sqlite3_exec(sqlite_db_, "commit transaction;", 0, 0, &err_msg_);

	cout << "insert operate successed." << endl;

	return 0;
}


int DBHelper::Delete(const char *delete_state)
{
	int res = SqlStateExec(delete_state);
	if (res != SQLITE_OK)
	{
		cout << "delete operate failed." << err_msg_ << endl;
		return -1;
	}
	else
	{
		cout << "delete operate successed." << endl;
	}

	return 0;
}


int DBHelper::Update(const char *update_state)
{
	int res = SqlStateExec(update_state);
	if (res != SQLITE_OK)
	{
		cout << "update operate failed." << err_msg_ << endl;
		return -1;
	}
	else
	{
		cout << "update operate successed." << endl;
	}

	return 0;
}


int DBHelper::CallBackFunc(void *not_used, int element_count, char **element, char **col_name)
{
	for (int index = 0; index < element_count; index++)
	{
		cout << col_name[index] << " = " << (element[index] ? element[index] : "NULL") << ", ";
	}

	cout << "\n";

	return 0;
}

int DBHelper::Get(const char *select_state)
{
	char **dbResult;
	int nRow = 0, nColumn = 0; int number;
	int res = sqlite3_get_table(
		sqlite_db_,          /* An open database */
		select_state,     /* SQL to be evaluated */
		&dbResult,    /* Results of the query */
		&nRow,           /* Number of result rows written here */
		&nColumn,        /* Number of result columns written here */
		&err_msg_      /* Error msg written here */
		);
	if (dbResult[nColumn] == NULL)
		return -1;
	number = atoi(dbResult[nColumn]);
	sqlite3_free_table(dbResult);
	return number;

	if (res != SQLITE_OK)
	{
		cout << "select operate failed." << err_msg_ << endl;
		return -1;
	}
	else
	{
		cout << "select operate successed." << endl;
	}

	return 0;
}

int DBHelper::SqlStateExec(const char *sql_state)
{
	return sqlite3_exec(sqlite_db_, sql_state, CallBackFunc, 0, &err_msg_);
}