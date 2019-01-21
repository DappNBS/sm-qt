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

    bool        getState();

signals:

public slots:
    void        handleInitAccount();
    void        handleSendMessage();

protected:
    bool        eventFilter(QObject *target,QEvent *event);

private:
    void        initLabels();
    void        initLayout();

    void        networkInterfaceList(QListWidget *);
    void        appendMessage(QString msg,QString from);




    //UI 成员变量
    QLabel              * logoLabel;

    QLabel              * leftTitleLabel;
    QLabel              * rightTitleLabel;


    //left
    QLabel              * sidLabel;
    QLineEdit           * accLabelVal;
    //
    QLabel              * nbsAddress;


    QListWidget         * ipList;

    //Buttons
    QPushButton         * initButton;//init nbs account button

    //<RIGHT>
    QTextEdit           * logChat;  //聊天记录
    QLineEdit           * msgSend;  //待发送内容

    QPushButton         * sendButton;//send msg
    //</RIGHT>
    QLabel              * statLabel;//状态


    //<VARIABLES>
    QString             accoutName;
    QString             nbsServerIP;
    int                 nbsServerPort = 59527;

    bool                nsbState = false;

    QString             scrollStyle;
};

#endif // MAINWINDOW_H
