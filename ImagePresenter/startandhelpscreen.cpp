#include "startandhelpscreen.h"
#include "ui_startandhelpscreen.h"

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

