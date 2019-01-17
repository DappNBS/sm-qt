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


    //UI 成员变量
    QLabel              * logoLabel;
    //Label
    QLabel              * leftTitleLabel;//
    QLabel              * rightTitleLabel;//

    QLabel              * statLabel;//状态

    QListWidget         * leftInfoWidget;

    QListWidget         * msgLogWidget;//聊天历史

    //left
    QLabel              * sidLabel;
    QLabel              * accLabel;
    QLineEdit           * accLabelVal;

    //Buttons
    QPushButton         * initButton;//init nbs account button

    //<RIGHT>
    QTextEdit           * logChat;  //聊天记录
    QLineEdit           * msgSend;  //待发送内容

    QPushButton         * sendButton;//send msg
    //</RIGHT>

};

#endif // MAINWINDOW_H
