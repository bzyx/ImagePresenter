#include<QMessageBox>

#include "aboutbox.h"
#include "ui_aboutbox.h"

AboutBox::AboutBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutBox)
{
    ui->setupUi(this);
}

AboutBox::~AboutBox()
{
    delete ui;
}

void AboutBox::on_pushButton_2_clicked()
{
    QMessageBox::aboutQt(0,"O Qt..");
}
