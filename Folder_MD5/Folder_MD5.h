#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Folder_MD5.h"

class Folder_MD5 : public QMainWindow
{
	Q_OBJECT

public:
	Folder_MD5(QWidget *parent = Q_NULLPTR);


private slots :
	void on_pushButton_save_clicked();
	void on_pushButton_check_clicked();
	void on_pushButton_login_clicked();

private:
	Ui::Folder_MD5Class ui;
	void get_Setting();
	bool path_Check(QString scan_path);

};
