#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QMediaPlaylist>
#include <QMediaPlayer>
#include "ztestpublic.h"
#include "ztextedit.h"

#ifndef _DEBUG
#include "ztest_global.h"
#define DEBUG_MAINWINDOW_H(X) LOG_DEBUG(X)
//#define DEBUG_MAINWINDOW_H(X)
#else
#define DEBUG_MAINWINDOW_H(X)
#endif


//TEST_DEBUG(DDDD)

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

    void on_btn02_clicked();

    void on_btn03_clicked();

private:
    Ui::MainWindow *ui;
    QMediaPlaylist* playList;
    QMediaPlayer* player;
    ZTextEdit m_textEidt;

};

#endif // MAINWINDOW_H
