#include "showpic.h"
#include <QDir>
#include <QTimer>
#include "frame.h"

ShowPic::ShowPic(QWidget *parent) :
    QLabel(parent)
{
    QString strPath = Frame::strRoot +"/adm/PicFile";
    QDir dir(strPath);
    dir.setFilter(QDir::Files);
    m_fileInfoList = dir.entryInfoList();

    onChangePic();

    QTimer* timer = new QTimer();
    timer->start(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(onChangePic()));
}

void ShowPic::onChangePic()
{
    if(m_fileInfoList.size() == 0)
        return;
    QFileInfo fileInfo = m_fileInfoList.at(0);

    QPixmap map(fileInfo.filePath());
    setPixmap(map);

    m_fileInfoList.removeFirst();
    m_fileInfoList.append(fileInfo);
}
