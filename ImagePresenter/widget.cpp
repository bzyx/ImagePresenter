#include <QDebug>

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

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
        qDebug() << "I have loaded" << fileManager.getCount();
    }
    scene = new QGraphicsScene(this);

    ui->gView->setScene(scene);
    ui->gView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->gView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    ui->gView->installEventFilter(this);
}

Widget::~Widget()
{
    delete ui;
    fileManager.clear();
}




bool Widget::eventFilter(QObject *obj, QEvent *evt) {
    if(obj == ui->gView && evt->type() == QEvent::Resize) {
        ui->gView->setSceneRect(0,0,ui->gView->width(), ui->gView->height());
        showImage(fileManager.currentImage());
        return QWidget::eventFilter(obj, evt);
    } else{
        // Call the base class implementation
        return QWidget::eventFilter(obj, evt);
    }
}


void Widget::on_btn_prev_clicked()
{
    showImage(fileManager.prevImage());

}

void Widget::on_btn_next_clicked()
{
    showImage(fileManager.nextImage());

}

void Widget::on_btn_help_clicked()
{
    //Pomoc
}

void Widget::on_btn_changeImage_clicked()
{
    //Wyb�r obrazka
}

bool Widget::showImage(QPixmap image){
    if (image.isNull()){
        //No more images (means that this is before first or after last image)
        return false;
    }
    if ( (image.height() < ui->gView->height()) &&
         (image.width() < ui->gView->width()) ){
        scene->clear();
        QGraphicsPixmapItem* pixmapItem = scene->addPixmap(image);
        pixmapItem->setPos((ui->gView->width()-image.width())/2,(ui->gView->height()-image.height())/2);
        return true;
    } else if ( (image.height() > ui->gView->height()) &&
                (image.width() < ui->gView->width()) ){
        scene->clear();
        QPixmap scaledImage = image.scaledToHeight(ui->gView->height());
        QGraphicsPixmapItem* pixmapItem = scene->addPixmap(scaledImage);
        pixmapItem->setPos((ui->gView->width()-scaledImage.width())/2,(ui->gView->height()-scaledImage.height())/2);
        return true;
    } else if (image.width() > ui->gView->width() &&
               (image.height() < ui->gView->height()) ){
        scene->clear();
        QPixmap scaledImage = image.scaledToWidth( ui->gView->width());
        QGraphicsPixmapItem* pixmapItem = scene->addPixmap(scaledImage);
        pixmapItem->setPos((ui->gView->width()-scaledImage.width())/2,(ui->gView->height()-scaledImage.height())/2);
        return true;
    } else {
        scene->clear();
        QPixmap scaledImage = image.scaled(ui->gView->width(),ui->gView->height(),Qt::KeepAspectRatio);
        QGraphicsPixmapItem* pixmapItem = scene->addPixmap(scaledImage);
        pixmapItem->setPos((ui->gView->width()-scaledImage.width())/2,(ui->gView->height()-scaledImage.height())/2);
        return true;
    }
}
