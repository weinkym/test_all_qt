#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSound>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    playList=new QMediaPlaylist;
     playList->setPlaybackMode(QMediaPlaylist::Loop);
     QMediaContent media(QUrl("qrc:/music/qq.mp3"));
//     playList->addMedia(media);
     player=new QMediaPlayer;
//     player->setPlaylist(playList);
     player->setMedia(media);
//     player->setVolume(80);
     //=============================
     ui->label->setOpenExternalLinks(true);
//     ui->label->setText(QString("<a href = %1>%1</a>").arg("www@baidu.com"));
     ui->label->setText(QString("<p><a href=\"mailto:example@example.com\">email</a></p>"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn01_clicked()
{
    qDebug()<<"on_btn01_clicked";
//    if(!player->isAvailable())
//    {
//        player->stop();
//        player->play();
//    }
    player->play();
}

void MainWindow::on_btn02_clicked()
{
    qDebug()<<"on_btn02_clicked";
//    QSound::play(":/music/qq.mp3");
    QSound::play(":/music/qq.wav");
}

void MainWindow::on_btn03_clicked()
{
    QString text = ui->textEdit_2->toPlainText();
//    QStringList list = text.split(";");
//    int count = list.count();
//    m_textEidt.clear();
//    for(int i = 0; i < count; ++i)
//    {
//        m_textEidt.append(list.at(i));
//        if(i < count - 1)
//        {
//            m_textEidt.insertImage(":/images/1.png");
//        }
//    }
    m_textEidt.insertAllText(text);
    m_textEidt.show();
}
