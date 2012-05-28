#include "filemanager.h"
#include <QFile>
#include <QDir>
#include <QCoreApplication>
#include <QMessageBox>

#include <QDebug>

//This is a file only member. No need to be a class member.
QDir _mStartDir_;

FileManager::FileManager(QObject *parent) :
    QObject(parent)
{
    //A static variable
    mLastImageNumber = 1;
}

int FileManager::setDirectory(QString dir){
    if (dir == "/"){
        //Current path is where the program begins
        //_mStartDir_ = QDir::current();
        //_mStartDir_ == dir.absolutePath();
        _mStartDir_.setCurrent(QCoreApplication::applicationDirPath());
        //Don't show any special files and only readable ones
        _mStartDir_.setFilter(QDir::NoDotAndDotDot | QDir::Files | QDir::Readable);
        //We sort all by name igonring the case
        _mStartDir_.setSorting(QDir::Name | QDir::IgnoreCase);

        //creating a list of masks of interesting filetypes
        QStringList fileTypeList;
        for (unsigned int i=0; i < (sizeof(fileTypes)/sizeof(QString)); i++){
            fileTypeList.append(fileTypes[i]);
        }
        //Seting the mask
        _mStartDir_.setNameFilters(fileTypeList);

        /*
        //Information about files
        QFileInfoList list = _mStartDir_.entryInfoList(QDir::NoFilter, QDir::Name | QDir::IgnoreCase);
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
    QStringList fileNameList = _mStartDir_.entryList(QDir::NoFilter, QDir::Name | QDir::IgnoreCase);

    foreach(QString fileName, fileNameList){
        bool canBeConverted;
        int numInFileName = fileName.left(fileName.lastIndexOf(".")).toInt(&canBeConverted);
        fileListMap.insert(numInFileName,_mStartDir_.absoluteFilePath(fileName) );
    }

    /*
    QMap<int, QString>::const_iterator i = fileListMap.constBegin();
    while (i != fileListMap.constEnd()) {
        qDebug() <<  i.key() << ": " << i.value();
        ++i;
    }
    */

}

    int FileManager::count(){
        return fileListMap.size();
    }
    void FileManager::clear(){
        fileListMap.clear();
    }


    QPixmap FileManager::nextImage(){
        return QPixmap(this->imageNum(this->mLastImageNumber+1));
    }
    QPixmap FileManager::prevImage(){
        return QPixmap(this->imageNum(this->mLastImageNumber-1));
    }

    QPixmap FileManager::currentImage(){
        return QPixmap(this->imageNum(this->mLastImageNumber));
    }

    QString FileManager::imageNum(int id){
        if ( (id > 0) && (id < fileListMap.size()+1) ){
            QString theImagePath = fileListMap.value(id);
            if (!theImagePath.isNull()){
                //We should not change the image number when it is wrong
                mLastImageNumber = id;
                return theImagePath;
            }
        }
        //The number was wrong
        return QString();
    }

    int FileManager::currentNumber(){
        return mLastImageNumber;
    }
