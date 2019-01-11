#include "showresult.h"
#include "ui_showresult.h"

ShowResult::ShowResult(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowResult)
{
    ui->setupUi(this);
}

ShowResult::~ShowResult()
{
    delete ui;
}

void ShowResult::on_pushButton_clicked()
{
    exit(0);
}
