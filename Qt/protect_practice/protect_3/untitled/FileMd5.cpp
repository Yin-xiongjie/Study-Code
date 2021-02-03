#include "FileMd5.h"
#include<QApplication>
#include<QDir>
#include<QFileInfo>
#include<QFile>
#include<QDebug>
#include<QMessageBox>
#include<QCryptographicHash>

FileMd5::FileMd5(QObject *parent) : QObject(parent)
{

}

void FileMd5::checDumplate(const QString &path)
{
   //检测文件重复
    QHash<QByteArray, QStringList> ret;
    QStringList files = getFiles(path);

    for (int i = 0; i < files.count(); i++)
    {
        QString  fileName = files.at(i);
        QByteArray md5 = getFileMd5(fileName);
        qDebug() << "fileName:" << fileName << endl<<"md5:"<<md5;

        ret[md5].append(fileName);
        emit progress(i+1, files.count());
    }

    emit getDrumplate(ret);
}

QStringList FileMd5::getFiles(const QString &path)
{
    QStringList ret;

    QDir dir(path);
    //.表示当前目录， ..表示上一级目录
    QFileInfoList infolist=  dir.entryInfoList(QDir::Files | QDir::Dirs |  QDir::NoDotAndDotDot);
    for(int i = 0; i < infolist.count(); ++i)
    {
        QFileInfo info = infolist.at(i);
        if (info.isDir()) //判断是不是目录
        {
            QString subDir = info.absoluteFilePath();
            //如果是目录,就启用getfile递归,传入目录参数
            QStringList files = getFiles(subDir);

            ret.append(files);
        }
        else{
            QString fileName=info.absoluteFilePath();
            ret.append(fileName);

        }
    }
    return ret;
}

QByteArray FileMd5::getFileMd5(const QString &filename)
{
    QFile file(filename);
    if(file.open(QIODevice::ReadOnly)){

        QCryptographicHash hash(QCryptographicHash::Md5);
        while(!file.atEnd())
        {
            QByteArray content = file.read(100 * 1024 * 1024);
            hash.addData(content);
            qApp->processEvents();
        }

        QByteArray md5 = hash.result();
        file.close();
        return md5;
    }
    return QByteArray();


}

