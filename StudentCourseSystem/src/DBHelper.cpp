#include <iostream>
#include "DBHelper.h"

using namespace std;

/**
 *  ����������
 *  @return
 */
int DBHelper::openDB(const char *path)
{
	int res = sqlite3_open(path, &sqliteDb);
	if (res)
	{
		cout << "�޷������ݿ�: " << sqlite3_errmsg(sqliteDb);
		sqlite3_close(sqliteDb);
		return -1;
	}
	isClose = false;
	return 0;
}

/**
 *  �ر����ݿ�����
 *  @return
 */
int DBHelper::closeDB()
{
	if (!isClose)
	{
		int res = sqlite3_close(sqliteDb);
		if (res)
		{
			cout << "�޷��ر����ݿ�: " << sqlite3_errmsg(sqliteDb);
			return -1;
		}
	}

	return 0;
}

/**
 *  �������ݿ��
 *  @return
 */
int DBHelper::createTable(const char *table_name_and_field)
{
	string create_table_state = "create table ";
	create_table_state += table_name_and_field;
	create_table_state += ";";
	int res = sqlExecute(create_table_state.c_str());
	if (res != SQLITE_OK)
	{
		cout << "create table failed." << errorMsg << endl;
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
int DBHelper::dropTable(const char *table_name)
{
	string sql_state = "drop table ";
	sql_state += table_name;
	sql_state += ";";
	int res = sqlExecute(sql_state.c_str());
	if (res != SQLITE_OK)
	{
		cout << "drop table failed." << errorMsg << endl;
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
int DBHelper::select(const char *select_state)
{
	int res = sqlExecute(select_state);

	if (res != SQLITE_OK)
	{
		cout << "select operate failed." << errorMsg << endl;
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
int DBHelper::insert(const char *insert_state)
{
	int res = sqlite3_exec(sqliteDb, "begin transaction;", callBackFun, 0, &errorMsg);
	res = sqlExecute(insert_state);
	if (res != SQLITE_OK)
	{
		cout << "insert operate failed." << errorMsg << endl;
		return -1;
	}

	res = sqlite3_exec(sqliteDb, "commit transaction;", 0, 0, &errorMsg);

	cout << "insert operate successed." << endl;

	return 0;
}


int DBHelper::remove(const char *delete_state)
{
	int res = sqlExecute(delete_state);
	if (res != SQLITE_OK)
	{
		cout << "delete operate failed." << errorMsg << endl;
		return -1;
	}
	else
	{
		cout << "delete operate successed." << endl;
	}

	return 0;
}


int DBHelper::update(const char *update_state)
{
	int res = sqlExecute(update_state);
	if (res != SQLITE_OK)
	{
		cout << "update operate failed." << errorMsg << endl;
		return -1;
	}
	else
	{
		cout << "update operate successed." << endl;
	}

	return 0;
}


int DBHelper::callBackFun(void *not_used, int element_count, char **element, char **col_name)
{
	for (int index = 0; index < element_count; index++)
	{
		cout << col_name[index] << " = " << (element[index] ? element[index] : "NULL") << ", ";
	}

	cout << "\n";

	return 0;
}

int DBHelper::get(const char *select_state)
{
	char **dbResult;
	int nRow = 0, nColumn = 0; int number;
	int res = sqlite3_get_table(
		sqliteDb,          /* An open database */
		select_state,     /* SQL to be evaluated */
		&dbResult,    /* Results of the query */
		&nRow,           /* Number of result rows written here */
		&nColumn,        /* Number of result columns written here */
		&errorMsg      /* Error msg written here */
		);
	if (dbResult[nColumn] == NULL)
		return -1;
	number = atoi(dbResult[nColumn]);
	sqlite3_free_table(dbResult);
	return number;

	if (res != SQLITE_OK)
	{
		cout << "select operate failed." << errorMsg << endl;
		return -1;
	}
	else
	{
		cout << "select operate successed." << endl;
	}

	return 0;
}

int DBHelper::sqlExecute(const char *sql_state)
{
	return sqlite3_exec(sqliteDb, sql_state, callBackFun, 0, &errorMsg);
}