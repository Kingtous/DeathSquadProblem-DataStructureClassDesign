#ifndef SHOWRESULT_H
#define SHOWRESULT_H

#include <QDialog>

namespace Ui {
class ShowResult;
}

class ShowResult : public QDialog
{
    Q_OBJECT

public:
    explicit ShowResult(QWidget *parent = nullptr);
    ~ShowResult();

    Ui::ShowResult *ui;
private slots:
    void on_pushButton_clicked();
};

#endif // SHOWRESULT_H
