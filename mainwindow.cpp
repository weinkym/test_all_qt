#include "mainwindow.h"
#include "ui_mainwindow.h"

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
