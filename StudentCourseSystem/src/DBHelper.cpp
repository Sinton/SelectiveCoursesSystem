#include <iostream>
#include "DBHelper.h"

/**
 *  ����������
 *  @return
 */
int DBHelper::openDB(const char *path)
{
	int res = sqlite3_open(path, &sqliteDb);
	if (res)
	{
		std::cout << "�޷������ݿ�: " << sqlite3_errmsg(sqliteDb);
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
			std::cout << "�޷��ر����ݿ�: " << sqlite3_errmsg(sqliteDb);
			return -1;
		}
	}
	return 0;
}