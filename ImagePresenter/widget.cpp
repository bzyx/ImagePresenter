#include <QDebug>

#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    if (fileManager.setDirectory("/")){
        //FIXME: No file in directory should show a dialog with error
        qWarning() << "There was no file";
    } else {
        fileManager.loadImages();
        qDebug() << fileManager.getCount();

    }
}

Widget::~Widget()
{
    delete ui;
    fileManager.clear();
}

void Widget::on_btn_prev_clicked()
{
    //Poprzedni obraz
    QGraphicsScene *scn = new QGraphicsScene(this );
    scn->setSceneRect(ui->gView->rect());
    ui->gView->setScene(scn);
    //QPixmap pix( "c:\\gotowe-1.jpg" );
    QPixmap pix;
    pix = fileManager.at(1);
    QPixmap betterPix = pix.scaled(ui->gView->width(),ui->gView->height(),Qt::KeepAspectRatio);
    scn->addPixmap(betterPix);
}

void Widget::on_btn_next_clicked()
{
    //Nastêpny obraz
}

void Widget::on_btn_help_clicked()
{
    //Pomoc
}

void Widget::on_btn_changeImage_clicked()
{
    //Wybór obrazka
}
