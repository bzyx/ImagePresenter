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
    QList<QPixmap> m_imageList;
    QString m_currentDir;


public:
    explicit FileManager(QObject *parent = 0);
    int setDirectory(QString dir);
    void loadImages();
    int getCount();
    void clear();
    QPixmap at(int i);

signals:
    
public slots:
    
};

#endif // FILEMANAGER_H
