#include <QtGui/QApplication>
#include <QTextCodec>
#include <QTranslator>
#include <QMessageBox>

#include "startandhelpscreen.h"
#include "widget.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("CP1250"));

    QTranslator translator;
    if (translator.load("qt_pl", ":tra/"))
        a.installTranslator(&translator);

    QFont appFont = QApplication::font();
    appFont.setPointSize(11);
    QApplication::setFont(appFont);

    a.addLibraryPath(QCoreApplication::applicationDirPath());
    StartAndHelpScreen startScreen;
    Widget w;

    if (w.haveNoFiles()){
        QMessageBox::warning(NULL, "Image presenter - b��d", "Uwaga: \n Brak odpowiednich plik�w w katalogu programu.", QMessageBox::Ok);
        startScreen.lockShowButton();
    }

    QObject::connect(&startScreen,SIGNAL(startButtonClicked()),
                     &w, SLOT(showFullScreen()));


    /*
    QObject::connect(&startScreen,SIGNAL(startButtonClicked()),
                     &w, SLOT(show()));
    */
    QObject::connect(&startScreen,SIGNAL(startButtonClicked()),
                     &startScreen, SLOT(hide()));

    startScreen.show();
    return a.exec();
}
