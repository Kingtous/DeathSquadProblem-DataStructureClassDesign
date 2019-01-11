#ifndef MESSAGEOUTPUT_H
#define MESSAGEOUTPUT_H

#include "showresult.h"

//此文件负责将执行中产生的信息输出到窗口或者文件中
#include <QString>
#include <QProcess>
#include <fstream>
#include <ostream>
#include <cstring>
using namespace std;
class OutputOrganizer
{
public:
    OutputOrganizer(string FileName);
    void AddWidgetOutput(QString appendText);
    void AddWidgetOutput(QString appendText,bool Enter);
    void AddFileOutput(string appendText);
    QString getWidgetOutput();
    void storeFileOutput();
    void resetFileOutput();
    void openFile();


    bool isSuccess;//判断是否有解决方案，用于判断是否打开文件

private:
    QString WidgetOutput;//窗口输出，只输出结果，不输出过程
    ofstream *FileOutput;//文件输出，输出过程
    string FileName;//文件名

};

#endif // MESSAGEOUTPUT_H
