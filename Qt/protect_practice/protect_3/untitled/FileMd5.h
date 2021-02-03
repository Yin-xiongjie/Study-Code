#ifndef FILEMD5_H
#define FILEMD5_H

#include <QObject>
#include <QHash>
#include <QStringList>

class FileMd5 : public QObject
{
    Q_OBJECT
public:
    explicit FileMd5(QObject *parent = nullptr);

signals:
    //获取文件重复
    void getDrumplate(const QHash<QByteArray, QStringList> &dumplates);
    void progress(int current, int total);

public slots:
    //检测文件重复
    void checDumplate(const QString &path);

private:
    QStringList getFiles(const QString &path);
    QByteArray getFileMd5(const QString &filename);

};

#endif // FILEMD5_H
