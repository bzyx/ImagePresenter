#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>

#include "filemanager.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    FileManager fileManager;
    QGraphicsScene* scene;
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    bool eventFilter(QObject *obj, QEvent *evt);
    bool haveNoFiles(){return fileManager.count()==0; }
    
private slots:
    void helpDialog();
    void selectImageDialog();

private:
    Ui::Widget *ui;
    bool showImage(QPixmap image);
};

#endif // WIDGET_H
