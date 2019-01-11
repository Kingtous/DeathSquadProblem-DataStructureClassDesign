#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "MethodList.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::OpenFile(OutputOrganizer & organizer)
{
    if(ui->ShowProcess->isChecked())
    {
        organizer.openFile();
        return true;
    }
    else
        return false;
}


void MainWindow::on_pushButton_clicked()
{
    int num=ui->NumberChoice->text().toInt();
    if(ui->Method_1->isChecked())
    {
        OutputOrganizer organizer("CircularLinkList.txt");
        //被选中，循环链表
        CircularLinkListMethod(num,organizer);
        ui->OutputResult->setText(organizer.getWidgetOutput());
        //打开窗口
        OpenFile(organizer);
    }
    else if(ui->Method_2->isChecked())
    {
        //被选中，队列
        OutputOrganizer organizer("QueueMethod.txt");
        QueueMethod(num,organizer);
        ui->OutputResult->setText(organizer.getWidgetOutput());
        //打开窗口
        OpenFile(organizer);
    }
    else if(ui->Method_3->isChecked())
    {
        //被选中，递归
        OutputOrganizer organizer("RecursiveMethod.txt");
        RecursiveMethod(num,organizer);
        ui->OutputResult->setText(organizer.getWidgetOutput());
        //打开窗口
        OpenFile(organizer);
    }
    else if(ui->Method_4->isChecked())
    {
        //被选中，顺序表
        OutputOrganizer organizer("ArrayMethod.txt");
        ArrayMethod(num,organizer);
        ui->OutputResult->setText(organizer.getWidgetOutput());
        //打开窗口
        OpenFile(organizer);
    }

}

void MainWindow::on_pushButton_2_clicked()
{
    ui->OutputResult->clear();
}

void MainWindow::on_pushButton_3_clicked()
{
    exit(0);
}

