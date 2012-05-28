#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QtCore>
#include <QObject>
#include <QPixmap>

QString const fileTypes[] = {"*.jpg", "*.jpeg", "*.gif", "*.tif"};

class FileManager : public QObject
{
    Q_OBJECT
private:
    //QList<QPixmap> mImageList;
    QMap <int, QString> fileListMap;
    QString m_currentDir;
    int mLastImageNumber;


public:
    explicit FileManager(QObject *parent = 0);
    int setDirectory(QString dir);
    void loadImages();
    int count();
    void clear();
    QPixmap nextImage();
    QPixmap prevImage();
    QPixmap currentImage();
    QString imageNum(int id);
    int currentNumber();

signals:
    
public slots:
    
};

#endif // FILEMANAGER_H
