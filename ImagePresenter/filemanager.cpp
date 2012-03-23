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
    mLastImageNumber = 0;
}

int FileManager::setDirectory(QString dir){
    if (dir == "/"){
        //Current path is where the program begins
        //_mStartDir_ = QDir::current();
        //_mStartDir_ == dir.absolutePath();
        _mStartDir_.setCurrent(QCoreApplication::applicationDirPath());
        //_mStartDir_.
        qDebug() << _mStartDir_;
        //QMessageBox box;
        //box.setText(_mStartDir_.currentPath());
        //box.exec();
       //// box.setText(_mStartDir_.path());
       // box.exec();
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
        //How many files we have
        qDebug() << "How many files" << _mStartDir_.count();
        */


        //Information about files
        QFileInfoList list = _mStartDir_.entryInfoList(QDir::NoFilter, QDir::Name | QDir::IgnoreCase);
        for (int i = 0; i < list.size(); ++i)  {
            QFileInfo fileInfo = list.at(i);
            qDebug() << qPrintable(QString("%1 %2").arg(fileInfo.size(), 10)
                                   .arg(fileInfo.fileName()));
        }


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
    int i = 0;
    QStringList fileNameList = _mStartDir_.entryList(QDir::NoFilter, QDir::Name | QDir::IgnoreCase);
    fileNameList.sort();
    qDebug() << fileNameList;
    QList<QPixmap> theOtherImages10;
    QList<QPixmap> theOtherImages100;
    QList<QPixmap> theOtherImages1000;
    QList<QPixmap> theOtherImages10000;
    foreach(QString fileName, _mStartDir_.entryList(QDir::NoFilter, QDir::Name) ){
        //QPixmap pix = QPixmap(_mStartDir_.absoluteFilePath(fileName));
        //QPixmap pix = QPixmap("c:\\gotowe-1.jpg");
        bool canBeConverted;
        int numInFileName = fileName.left(fileName.lastIndexOf(".")).toInt(&canBeConverted);
        qDebug() << numInFileName;
        if (canBeConverted ){
            //if (i > 10)
            //    break;
            if (numInFileName < 10){
                mImageList.append( QPixmap(_mStartDir_.absoluteFilePath(fileName)) );
            } else if (numInFileName < 99 ){
                theOtherImages10.append( QPixmap(_mStartDir_.absoluteFilePath(fileName)) );
            } else if (numInFileName < 999 ){
                theOtherImages100.append( QPixmap(_mStartDir_.absoluteFilePath(fileName)) );
            } else if (numInFileName < 9999 ){
                theOtherImages1000.append( QPixmap(_mStartDir_.absoluteFilePath(fileName)) );
            } else if (numInFileName < 99999 ){
                theOtherImages10000.append( QPixmap(_mStartDir_.absoluteFilePath(fileName)) );
            }
            i++;
        }
        //qDebug() <<"Loading file: " << _mStartDir_.absoluteFilePath(fileName);
    }
    mImageList+=theOtherImages10;
    mImageList+=theOtherImages100;
    mImageList+=theOtherImages1000;
    mImageList+=theOtherImages10000;
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
