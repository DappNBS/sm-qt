#ifndef ACCOUNTDIALOG_H
#define ACCOUNTDIALOG_H
#define ACC_WIN_WIDTH 460
#define ACC_WIN_HIGHT 260

#include "commheader.h"
#include <QWidget>
#include <QDialog>

class AccountDialog : public QDialog
{
    Q_OBJECT
public:
    explicit AccountDialog(QWidget *parent = nullptr);
    ~AccountDialog();

    QString         getAccountName();
    QString         getServerIP();
    int             getServerPort();
    QString         getSID();

signals:

public slots:
    void            on_createdButton_clicked();
    void            on_cancelButton_clicked();

private:
    void            initElements();
    void            initLayout();

    //<PAGEEL>
    QLineEdit       *editAccName;

    QLineEdit       *editAccPW;
    QLineEdit       *editRepAccPW;
    QLineEdit       *editNbsIp;
    QSpinBox        *editNbsPort;

    QPushButton     *creatButton;
    QPushButton     *cancelButton;

    QString         sid;
};

#endif // ACCOUNTDIALOG_H
