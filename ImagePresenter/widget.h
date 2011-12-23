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
   // void keyPressEvent(QKeyEvent* event);
    
private slots:
    void on_btn_prev_clicked();
    void on_btn_next_clicked();
    void helpDialog();
    void selectImageDialog();

private:
    Ui::Widget *ui;
    bool showImage(QPixmap image);
};

#endif // WIDGET_H
