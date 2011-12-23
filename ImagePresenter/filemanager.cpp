#include "filemanager.h"
#include <QFile>
#include <QDir>

#include <QDebug>

//This is a file only member. No need to be a class member.
QDir _mStartDir_;

FileManager::FileManager(QObject *parent) :
    QObject(parent)
{
    mLastImageNumber = 0;
}

int FileManager::setDirectory(QString dir){
    if (dir == "/"){
        //Current path is where the program begins
        _mStartDir_ = QDir::currentPath();
        //Don't show any special files and only readable ones
        _mStartDir_.setFilter(QDir::NoDotAndDotDot | QDir::Files | QDir::Readable);
        //We sort all by name igonring the case
        _mStartDir_.setSorting(QDir::Name | QDir::IgnoreCase);

        //reating a list of masks of interesting filetypes
        QStringList fileTypeList;
        for (unsigned int i=0; i < (sizeof(fileTypes)/sizeof(QString)); i++){
            fileTypeList.append(fileTypes[i]);
        }
        //Seting the mask
        _mStartDir_.setNameFilters(fileTypeList);

        /*
        //How many files we have
        qDebug() << "How many files" << _mStartDir_.count();
        */

        /*
        //Information about files
        QFileInfoList list = _mStartDir_.entryInfoList();
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
    foreach(QString fileName, _mStartDir_.entryList()){
        //QPixmap pix = QPixmap(_mStartDir_.absoluteFilePath(fileName));
        //QPixmap pix = QPixmap("c:\\gotowe-1.jpg");
        bool canBeConverted;
        fileName.left(fileName.lastIndexOf(".")).toInt(&canBeConverted);
        if (canBeConverted)
            mImageList.append(QPixmap(_mStartDir_.absoluteFilePath(fileName)));
        //qDebug() <<"Loading file: " << _mStartDir_.absoluteFilePath(fileName);
    }
}
int FileManager::count(){
    return mImageList.size()-1;
}
void FileManager::clear(){
    mImageList.clear();
}


QPixmap FileManager::nextImage(){
    QPixmap retunValue = this->imageNum(this->mLastImageNumber+1);
    qDebug() << "Next" << mLastImageNumber;
    return retunValue;
}
QPixmap FileManager::prevImage(){
    QPixmap retunValue = this->imageNum(this->mLastImageNumber-1);
    return retunValue;
}

QPixmap FileManager::currentImage(){
    QPixmap retunValue = this->imageNum(this->mLastImageNumber);
    return retunValue;
}

QPixmap FileManager::imageNum(int id){
    if ( (id > -1) && (id < mImageList.size()) ){
        QPixmap theImage = mImageList.at(id);
        if (!theImage.isNull()){
            //We should not change the image number when it is wrong
            mLastImageNumber = id;
            return theImage;
        }
    }
    //The number was wrongo or the image was null
    return QPixmap();
}

int FileManager::currentNumber(){
    return mLastImageNumber;
}
