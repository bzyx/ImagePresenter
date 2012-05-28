#include <QMessageBox>

#include "startandhelpscreen.h"
#include "ui_startandhelpscreen.h"
#include "aboutbox.h"

StartAndHelpScreen::StartAndHelpScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::startAndHelpScreen)
{
    ui->setupUi(this);
}

StartAndHelpScreen::~StartAndHelpScreen()
{
    delete ui;
}

void StartAndHelpScreen::on_startButton_clicked()
{
    emit startButtonClicked();
}

void StartAndHelpScreen::setButtonText(QString newText){
    ui->startButton->setText(newText);
}


void StartAndHelpScreen::on_pushButton_clicked()
{
    AboutBox box;
    box.exec();
}

void StartAndHelpScreen::lockShowButton(){
    ui->startButton->setEnabled(false);
}
