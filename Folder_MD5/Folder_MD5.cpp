#include "Folder_MD5.h"

#include "md5.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <direct.h>
#include <io.h>
#include <afx.h>
#include <fstream>
#include <windows.h>
#include <qdatetime.h>

using namespace std;

string skip_Words[32] = { "" };
string base_path[8192] = { "" };
string file_hash[8192] = { "" };
string root_path[1024] = { "" };

string pw = "";
int use_Data[8192] = { 0 };

int database_cnt = 0;
bool ok = true;

void PrintMD5(const string &str, MD5 &md5) {
	cout << "MD5(\"" << str << "\") = " << md5.toString() << endl;
}


string FileDigest(const string &file) {

	ifstream in(file.c_str(), ios::binary);
	if (!in)
		return "";

	MD5 md5;
	std::streamsize length;
	char buffer[1024];
	while (!in.eof()) {
		in.read(buffer, 1024);
		length = in.gcount();
		if (length > 0)
			md5.update(buffer, length);
	}
	in.close();
	return md5.toString();
}


Folder_MD5::Folder_MD5(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	get_Setting();
}


vector<string> getFiles(string cate_dir)
{
	vector<string> files;//存放文件名
	_finddata_t file;
	long lf = 0;
	//输入文件夹路径
	if ((lf = _findfirst(cate_dir.c_str(), &file)) == -1) {
		cout << cate_dir << " not found!!!" << endl;
	}
	else {
		while (_findnext(lf, &file) == 0) {
			//输出文件名
			//cout<<file.name<<endl;
			if (strcmp(file.name, ".") == 0 || strcmp(file.name, "..") == 0)
				continue;
			files.push_back(file.name);
		}
	}
	_findclose(lf);

	//排序，按从小到大排序
	sort(files.begin(), files.end());
	return files;
}


bool File_Name_Compare(string file) {

	int x = file.length();
	if (x > 4){
		if (file[x - 3] == 't'&&file[x - 2] == 'x'&&file[x - 1] == 't')
			return true;

		if (file[x - 3] == 'r'&&file[x - 2] == 'a'&&file[x - 1] == 'w')
			return true;

		if (file[x - 3] == 'R'&&file[x - 2] == 'A'&&file[x - 1] == 'W')
			return true;

		if (file[x - 3] == 'b'&&file[x - 2] == 'm'&&file[x - 1] == 'p')
			return true;

		if (file[x - 3] == 'c'&&file[x - 2] == 's'&&file[x - 1] == 'v')
			return true;
	}
	for (int k = 0; k < 32; k++) {
		if (skip_Words[k].length()>2) {
			for (int i = 0; i < file.length(); i++) {
				if (file[i] == skip_Words[k][0]) {
					int e = 0;
					while (e < skip_Words[k].length() && file[i + e] == skip_Words[k][e]) {
						e++;
					}
					if (e == skip_Words[k].length())
						return true;
				}
			}
		}
	}
	return false;
}
//
//bool is_File(string s) {
//
//	int i = 0;
//	while (i < s.length()) {
//		if (s[i] == '.')
//			return true;
//		i++;
//	}
//	return false;
//}

int checkPath(const std::string strPath)
{
	struct stat         infos;

	if (stat(strPath.c_str(), &infos) != 0)
	{
		return -1;    //无效
	}
	else if (infos.st_mode & S_IFDIR)
	{
		return 0;    //目录
	}
	else if (infos.st_mode & S_IFREG)
	{
		//这里多写一个if 是为了记录一下判断条件
		return 1;    //文件
	}
	else
	{
		return -1;
	}
}


void path_Sacn(string scan_path,int path_level) {

	vector<string> files1 = getFiles(scan_path+"*");
	vector<string> ::iterator iVector = files1.begin();
	bool ok = false; int path_cnt = 0;
	while (iVector != files1.end())
	{
		if (!File_Name_Compare(*iVector)) {

			if (checkPath(scan_path + *iVector) == 1) {
				string s = "base_path" + to_string(database_cnt);
				WritePrivateProfileString(TEXT("Database_Path"), CA2CT(s.c_str()), CA2CT((scan_path + *iVector).c_str()), TEXT(".\\MD5_Setting.ini"));
				s = "file_hash" + to_string(database_cnt);
				string m = FileDigest(scan_path + *iVector);
				WritePrivateProfileString(TEXT("Database_MD5"), CA2CT(s.c_str()), CA2CT(m.c_str()), TEXT(".\\MD5_Setting.ini"));
				database_cnt++;;
			}
			else {
				path_Sacn(scan_path + (*iVector) + "\\", path_level + 1);
			}
			if (path_level == 0) {
				string s = "folder_path" + to_string(path_cnt);
				WritePrivateProfileString(TEXT("Root_Path"), CA2CT(s.c_str()), CA2CT((*iVector).c_str()), TEXT(".\\MD5_Setting.ini"));
			}
			path_cnt++;

		}
		++iVector;
	}

	if (path_level == 0) {
		WritePrivateProfileString(TEXT("Root_Path"), TEXT("Datebase_Size"), CA2CT(to_string(path_cnt).c_str()), TEXT(".\\MD5_Setting.ini"));
	}
}

void Folder_MD5::on_pushButton_save_clicked() {

	database_cnt = 0;
	path_Sacn("..\\",0);
	WritePrivateProfileString(TEXT("Scan_Setting"), TEXT("Datebase_Size"), CA2CT(to_string(database_cnt).c_str()), TEXT(".\\MD5_Setting.ini"));
	get_Setting();

}

bool Folder_MD5::path_Check(QString scan_path) {

	string s = scan_path.toStdString();
	vector<string> files1 = getFiles(s + "*");
	vector<string> ::iterator iVector = files1.begin();

	while (iVector != files1.end())
	{
		if (!File_Name_Compare(*iVector)) {

			if (checkPath(s+*iVector)==1) {

				string m = FileDigest(s + *iVector);
				for (int i = 0; i < database_cnt; i++) {
					if (strcmp(base_path[i].c_str(), (s+*iVector).c_str()) == 0) {
						if (strcmp(file_hash[i].c_str(), m.c_str()) != 0) {

							ui.current_Data->setTextColor(QColor(255, 0, 0, 255));
							ui.current_Data->insertPlainText(base_path[i].c_str());
							ui.current_Data->insertPlainText(":	");
							ui.current_Data->insertPlainText(m.c_str());
							ui.current_Data->insertPlainText("\n");
							ok = false;				
						}
						use_Data[i] = 1;
						break;
					}
				}	
			}
			else {
				string a = s + (*iVector) + "\\";
				path_Check(a.c_str());
			}
		}
		++iVector;
	}

	return ok;
}


void Folder_MD5::on_pushButton_check_clicked() {

	ok = true;
	memset(use_Data, 0, sizeof(use_Data));
	ui.current_Data->setText("");
	ui.Result->setFontPointSize(14);
	
	ok = path_Check("..\\");
	for (int i = 0; i < database_cnt; i++) {
		if (use_Data[i] != 1) {
			ui.current_Data->setTextColor(QColor(255, 0, 0, 255));
			ui.current_Data->insertPlainText("Lost File:	");
			ui.current_Data->insertPlainText(base_path[i].c_str());
			ui.current_Data->insertPlainText("\n");
			ok = false;;
		}
	}

	ofstream fout;
	fout.open("history_log.txt", ios::app);
	string str = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss").toStdString();
	fout << str << "	";


	if (ok) {
		ui.Result->setTextColor(QColor(0, 255, 0, 255));
		ui.Result->setText("OK");
		fout << "OK" << endl;
	}
	else {		
		ui.Result->setTextColor(QColor(255, 0, 0, 255));
		ui.Result->setText("NG");
		fout << "NG" << endl;
	}
	string s = ui.current_Data->document()->toPlainText().toLocal8Bit().toStdString();
	fout << s << endl;

}


void Folder_MD5::on_pushButton_login_clicked() {

	string s = string((const char *)ui.pw->text().toLocal8Bit());

	if (strcmp(s.c_str(), pw.c_str()) == 0) {
		ui.pushButton_save->setEnabled(true); 
	}

}

void Folder_MD5::get_Setting() {

	TCHAR lpTexts[1024];
	for (int i = 0; i < 32; i++) {
		string t_str = "skip_filename_Words_" + to_string(i+1);
		GetPrivateProfileString(TEXT("Scan_Setting"), CA2CT(t_str.c_str()), TEXT(""), lpTexts, 1024, TEXT(".\\MD5_Setting.ini"));
		skip_Words[i] = CT2A(lpTexts);
	}
	GetPrivateProfileString(TEXT("Scan_Setting"), TEXT("pw"), TEXT(""), lpTexts, 16, TEXT(".\\MD5_Setting.ini"));
	pw = CT2A(lpTexts);

	database_cnt = GetPrivateProfileInt(_T("Scan_Setting"), TEXT("Datebase_Size"), 0, TEXT(".\\MD5_Setting.ini"));

	for (int i = 0; i < database_cnt; i++) {

		string a = "base_path" + to_string(i);
		GetPrivateProfileString(TEXT("Database_Path"), CA2CT(a.c_str()), TEXT(""), lpTexts, 1024, TEXT(".\\MD5_Setting.ini"));
		base_path[i] = CT2A(lpTexts);

		a = "file_hash" + to_string(i);
		GetPrivateProfileString(TEXT("Database_MD5"), CA2CT(a.c_str()), TEXT(""), lpTexts, 1024, TEXT(".\\MD5_Setting.ini"));
		file_hash[i] = CT2A(lpTexts);

		ui.data_Base->insertPlainText(base_path[i].c_str());
		ui.data_Base->insertPlainText(":	");
		ui.data_Base->insertPlainText(file_hash[i].c_str());
		ui.data_Base->insertPlainText("\n");

	}

}

