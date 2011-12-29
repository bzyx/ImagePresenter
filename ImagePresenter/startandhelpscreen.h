#ifndef STARTANDHELPSCREEN_H
#define STARTANDHELPSCREEN_H

#include <QDialog>

namespace Ui {
class startAndHelpScreen;
}

class StartAndHelpScreen : public QDialog
{
    Q_OBJECT
    
public:
    explicit StartAndHelpScreen(QWidget *parent = 0);
    ~StartAndHelpScreen();
    void setButtonText(QString newText);

signals:
    void startButtonClicked();
    
private slots:
    void on_startButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::startAndHelpScreen *ui;
};

#endif // STARTANDHELPSCREEN_H
