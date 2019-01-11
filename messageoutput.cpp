#include "messageoutput.h"

OutputOrganizer::OutputOrganizer(string FileName)
{
    this->FileName=FileName;
    this->WidgetOutput.clear();
    this->FileOutput=new ofstream(this->FileName,ofstream::out);
    this->isSuccess=false;
}

void OutputOrganizer::AddWidgetOutput(QString appendText)
{
    this->WidgetOutput+=appendText;
}
void OutputOrganizer::AddWidgetOutput(QString appendText,bool Enter)
{
    if(Enter)
        this->WidgetOutput+=appendText+"\n";
    else {
        this->WidgetOutput+=appendText;
    }
}

void OutputOrganizer::AddFileOutput(string appendText)
{
    *(this->FileOutput) <<appendText<<"\n";
}


QString OutputOrganizer::getWidgetOutput()
{
    return this->WidgetOutput;
}


void OutputOrganizer::storeFileOutput()
{
    this->FileOutput->close();
}
void OutputOrganizer::resetFileOutput()
{
    this->FileOutput->close();
    this->FileOutput=new ofstream(this->FileName,ofstream::out);
}


void OutputOrganizer::openFile()
{
    if(this->isSuccess){
        //检查checkbox，查看是否勾选显示过程

        //ShowResult * resultWidget = new ShowResult();可考虑从内部读取文件调用
        //resultWidget->show();

        QProcess::startDetached("open "+QString::fromStdString(this->FileName));
    }
    else{
        return;
    }
}

