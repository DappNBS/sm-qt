#include "accountdialog.h"

AccountDialog::AccountDialog(QWidget *parent) : QDialog(parent)
{
    this->initElements();

    this->initLayout();

    this->resize(QSize(ACC_WIN_WIDTH,ACC_WIN_HIGHT));
    this->setMinimumSize(QSize(ACC_WIN_WIDTH,ACC_WIN_HIGHT));
    this->setMaximumSize(QSize(ACC_WIN_WIDTH,ACC_WIN_HIGHT));
    this->setWindowTitle(QObject::tr("初始化NBS服务"));
}

AccountDialog::~AccountDialog(){}

void AccountDialog::initElements(){
    this->editAccName       = new QLineEdit(this);

    this->editAccPW         = new QLineEdit(this);
    this->editRepAccPW      = new QLineEdit(this);

    this->editAccPW->setEchoMode(QLineEdit::PasswordEchoOnEdit);
    this->editRepAccPW->setEchoMode(QLineEdit::PasswordEchoOnEdit);

    this->editNbsIp         = new QLineEdit(this);
    this->editNbsIp->setText("127.0.0.0.1");

    this->editNbsPort       = new QSpinBox(this);
    this->editNbsPort->setRange(1024,65535);
    this->editNbsPort->setValue(59527);

    this->creatButton       = new QPushButton(QObject::tr("创建"),this);
    this->cancelButton      = new QPushButton(QObject::tr("取消"),this);
    this->creatButton->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    this->cancelButton->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
}

void AccountDialog::initLayout(){
    QFormLayout         *fLayout        = new QFormLayout();
    fLayout->setRowWrapPolicy(QFormLayout::DontWrapRows);
    fLayout->addRow(QStringLiteral("Account:"),this->editAccName);
    fLayout->addRow(QStringLiteral("密码:"),this->editAccPW);
    fLayout->addRow(QStringLiteral("确认密码:"),this->editRepAccPW);
    fLayout->addRow(QStringLiteral("NBS地址:"),this->editNbsIp);
    fLayout->addRow(QStringLiteral("NBS端口:"),this->editNbsPort);

    QHBoxLayout         *btnLayout      = new QHBoxLayout;
    btnLayout->addStretch();
    btnLayout->addWidget(this->creatButton);
    btnLayout->addWidget(this->cancelButton);
    btnLayout->setSpacing(2);


    QVBoxLayout         *mainBoxLayout  = new QVBoxLayout;
    mainBoxLayout->addLayout(fLayout);
    mainBoxLayout->addStretch();
    mainBoxLayout->addLayout(btnLayout);
}

QString AccountDialog::getAccountName(){
    QString account = this->editAccName->text();
    if(account.isEmpty())
        account = "unknow";
    return account;
}

QString AccountDialog::getServerIP(){
    QString ipStr = this->editNbsIp->text();
       if(ipStr.isEmpty())
           ipStr = "127.0.0.1";
       return ipStr;
}

int AccountDialog::getServerPort(){
    return this->editNbsPort->value();
}
