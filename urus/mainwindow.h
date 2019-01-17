#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "commheader.h"
#include <QMainWindow>
#include <QListWidget>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:

public slots:
    //void        handleInitAccount(QString name,QString pw);

private:
    void        initLabels();
    void        initLayout();

    void        networkInterfaceList(QListWidget *);


    //UI 成员变量
    QLabel              * logoLabel;

    QLabel              * leftTitleLabel;
    QLabel              * rightTitleLabel;


    //left
    QLabel              * sidLabel;
    QLineEdit           * accLabelVal;

    QListWidget         * ipList;

    //Buttons
    QPushButton         * initButton;//init nbs account button

    //<RIGHT>
    QTextEdit           * logChat;  //聊天记录
    QLineEdit           * msgSend;  //待发送内容

    QPushButton         * sendButton;//send msg
    //</RIGHT>
    QLabel              * statLabel;//状态
};

#endif // MAINWINDOW_H
