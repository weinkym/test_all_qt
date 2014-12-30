#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    playList=new QMediaPlaylist;
     playList->setPlaybackMode(QMediaPlaylist::Loop);
//     playList->addMedia();
//     QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
//                                                     "/home",
//                                                     tr("Images (*.png *.xpm *.mp3)"));
//     qDebug
//     QString fileName = "D:\\workroot\\src_all\\qt\\src_test\\test_all_qt\\music\\qq.mp3";

//     QMediaContent media(QUrl::fromLocalFile(fileName));
     QMediaContent media(QUrl("qrc:/music/qq.mp3"));
//     playList->addMedia(media);

     player=new QMediaPlayer;
//     player->setPlaylist(playList);
     player->setMedia(media);
//     player->setVolume(80);
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
