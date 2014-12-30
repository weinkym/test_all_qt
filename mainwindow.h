#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QMediaPlaylist>
#include <QMediaPlayer>
#include "ztestpublic.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btn01_clicked();

private:
    Ui::MainWindow *ui;
    QMediaPlaylist* playList;
    QMediaPlayer* player;

};

#endif // MAINWINDOW_H