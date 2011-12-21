#include "filemanager.h"
#include <QFile>
#include <QDir>

#include <QDebug>

QDir mi_startDir;

FileManager::FileManager(QObject *parent) :
    QObject(parent)
{
}

int FileManager::setDirectory(QString dir){
    if (dir == "/"){
        //Current path is where the program begins
        mi_startDir = QDir::currentPath();
        //Don't show any special files and only readable ones
        mi_startDir.setFilter(QDir::NoDotAndDotDot | QDir::Files | QDir::Readable);
        //We sort all by name igonring the case
        mi_startDir.setSorting(QDir::Name | QDir::IgnoreCase);

        //reating a list of masks of interesting filetypes
        QStringList fileTypeList;
        for (int i=0; i < (sizeof(fileTypes)/sizeof(QString)); i++){
            fileTypeList.append(fileTypes[i]);
        }
        //Seting the mask
        mi_startDir.setNameFilters(fileTypeList);

        /*
          //How many files we have
        qDebug() << startDir.count();
        */

        /*
        //Information about files
        QFileInfoList list = startDir.entryInfoList();
        for (int i = 0; i < list.size(); ++i)  {
            QFileInfo fileInfo = list.at(i);
            qDebug() << qPrintable(QString("%1 %2").arg(fileInfo.size(), 10)
                                                    .arg(fileInfo.fileName()));
        }
        */
        //Everything goes fine
        return 0;
    }
    /*
      Error - Not Implemented Yet

      Currently we can only open the main directory where the application starts
    */
    return 1;
}

void FileManager::loadImages(){
    //If the directory is not empty creates a list of images
    foreach(QString fileName, mi_startDir.entryList()){
        QPixmap pix = QPixmap(mi_startDir.absoluteFilePath(fileName));
        //QPixmap pix = QPixmap("c:\\gotowe-1.jpg");
        m_imageList.append(pix);
        qDebug() << mi_startDir.absoluteFilePath(fileName);
    }
}
int FileManager::getCount(){
    return m_imageList.size();
}
void FileManager::clear(){
    m_imageList.clear();
}

QPixmap FileManager::at(int i){
    //TODO: Should check if the image is valid, whathever it means
    if (i <= m_imageList.size()){
        return m_imageList.at(i);
    }
}
