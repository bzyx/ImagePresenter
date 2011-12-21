#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include "filemanager.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    FileManager fileManager;
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    
private slots:
    void on_btn_prev_clicked();

    void on_btn_next_clicked();

    void on_btn_help_clicked();

    void on_btn_changeImage_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
