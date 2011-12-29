#ifndef ABOUTBOX_H
#define ABOUTBOX_H

#include <QDialog>

namespace Ui {
class AboutBox;
}

class AboutBox : public QDialog
{
    Q_OBJECT
    
public:
    explicit AboutBox(QWidget *parent = 0);
    ~AboutBox();
    
private slots:
    void on_pushButton_2_clicked();

private:
    Ui::AboutBox *ui;
};

#endif // ABOUTBOX_H
