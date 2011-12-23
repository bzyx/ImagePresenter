#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QObject>
#include <QPixmap>
#include <QString>

QString const fileTypes[] = {"*.jpg", "*.gif", "*.tif"};

class FileManager : public QObject
{
    Q_OBJECT
private:
    QList<QPixmap> mImageList;
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
    QPixmap imageNum(int id);
    int currentNumber();

signals:
    
public slots:
    
};

#endif // FILEMANAGER_H
