#include "mainwindow.h"
#include "globalconst.h"
#include "accountdialog.h"
#include <QShortcut>
#include <iostream>
#include <QIODevice>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    QFile scrollQssFile(":/qss/scrollbar.qss");
    scrollQssFile.open(QFile::ReadOnly);
    this->scrollStyle = scrollQssFile.readAll();
    scrollQssFile.close();

    //初始化页面标签
    this->initLabels();
    //设值

    //布局
    this->initLayout();
    this->setWindowTitle(APP_NAME);
    this->resize(QSize(WIN_WIDTH,WIN_HEIGHT));

    connect(this->initButton,SIGNAL(clicked()),this,SLOT(handleInitAccount()));
    connect(this->sendButton,SIGNAL(clicked()),this,SLOT(handleSendMessage()));
    //this->msgSend->grabKeyboard();

}

MainWindow::~MainWindow()
{

}



bool MainWindow::getState(){
    return this->nsbState;
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event){
    if(watched == this->msgSend){
        if(event->type() == QEvent::KeyPress){
            QKeyEvent *k = static_cast<QKeyEvent *>(event);
            if(k->key() == Qt::Key_Return){
                handleSendMessage();
                return true;
            }
        }
    }

    return QWidget::eventFilter(watched,event);
}

void MainWindow::handleInitAccount(){
    AccountDialog       *accDialog  = new AccountDialog(this);
    if(accDialog->exec() != QDialog::Accepted)
    {
        this->statLabel->setText("取消初始化操作...");
        return;
    }

    this->accoutName                = accDialog->getAccountName();
    this->nbsServerIP               = accDialog->getServerIP();
    this->nbsServerPort             = accDialog->getServerPort();

    QString svrIP =
            this->nbsServerIP + ":" + QString::number(this->nbsServerPort);
    this->nbsAddress->setText(svrIP);
    this->accLabelVal->setText(this->accoutName);
    this->sidLabel->setText(accDialog->getSID());
    this->statLabel->setText("NBS服务初始化完成...");
    this->nsbState = true;
    this->initButton->setEnabled(false);
    this->sendButton->setEnabled(true);
}

void MainWindow::handleSendMessage(){
    if(!this->getState() || this->msgSend->text().isEmpty())return;
    this->appendMessage(this->msgSend->text(),this->accLabelVal->text());
}

void MainWindow::appendMessage(QString msg, QString from){
    if(msg.isEmpty())return;
    QDateTime   time        = QDateTime::currentDateTime();
    QString     timeStr     = time.toString("hh:mm:ss");
    QColor      color       = this->logChat->textColor();

    if(this->accLabelVal->text().compare(from) == 0){
        this->logChat->setTextColor(Qt::blue);
    }else{
        this->logChat->setTextColor(color);
    }

    QString info = from + " [" + timeStr +"] > \n";
    this->logChat->append(info);
    this->logChat->append("    "+msg + "\n");
    this->logChat->setTextColor(color);
    this->msgSend->clear();

    QScrollBar  *bar        = logChat->verticalScrollBar();
    using std::cout;
    if(!this->scrollStyle.isEmpty()){
        std::cout << this->scrollStyle.data();
        this->logChat->setStyleSheet(this->scrollStyle);
    }

    bar->setValue(bar->maximum());
}

void MainWindow::initLayout(){

    //Layout
    QHBoxLayout     * statLayout    = new QHBoxLayout;
    statLayout->addStretch();
    this->statLabel->setAlignment(Qt::AlignLeft);
    this->statLabel->setStyleSheet("color:blue");
    statLayout->addWidget(this->statLabel);


    // <left>
    QHBoxLayout     * logoLayout    = new QHBoxLayout;
    logoLayout->addStretch();
    logoLayout->addWidget(this->logoLabel);
    logoLayout->addStretch();
    logoLayout->setSpacing(10);

    QVBoxLayout     * leftVBLayout  = new QVBoxLayout;
    leftVBLayout->addLayout(logoLayout);
    leftVBLayout->addWidget(this->sidLabel,0,Qt::AlignHCenter);
    leftVBLayout->addWidget(this->leftTitleLabel,0,Qt::AlignLeft);

    //formLayout
    QFormLayout     * fLayout    = new QFormLayout();
    fLayout->setRowWrapPolicy(QFormLayout::DontWrapRows);
    fLayout->addRow(QStringLiteral("Account Name:"),this->accLabelVal);
    fLayout->addRow(QStringLiteral("NBS SERVER:"),this->nbsAddress);
    fLayout->addRow(QStringLiteral("Local IP:"),this->ipList);

    leftVBLayout->addLayout(fLayout);

    leftVBLayout->addStretch();

    QHBoxLayout     * initBtnLayout = new QHBoxLayout;
    initBtnLayout->addStretch();
    initBtnLayout->addWidget(this->initButton);
    initBtnLayout->setSpacing(10);
    leftVBLayout->addLayout(initBtnLayout);

    //</left>

    //<RIGHT>
    QHBoxLayout     * sendLayout    = new QHBoxLayout;
    sendLayout->addWidget(this->msgSend);
    sendLayout->addWidget(this->sendButton);
    sendLayout->setStretch(0,6);
    sendLayout->setStretch(1,1);

    QVBoxLayout     * rightVBLayout = new QVBoxLayout;
    rightVBLayout->addWidget(this->rightTitleLabel);
    rightVBLayout->addWidget(this->logChat);
    rightVBLayout->addLayout(sendLayout);


    //承载中间布局 控制左右两侧比例
    QHBoxLayout     * midHBLayout   = new QHBoxLayout;
    midHBLayout->addLayout(leftVBLayout);
    midHBLayout->addLayout(rightVBLayout);
    midHBLayout->setStretch(0,2);
    midHBLayout->setStretch(1,3);


    QVBoxLayout     * mainLayout    = new QVBoxLayout;
    mainLayout->addLayout(midHBLayout);
    mainLayout->addLayout(statLayout);
    mainLayout->setStretch(0,15);
    mainLayout->setStretch(1,1);

    QWidget * widget = new QWidget(this);
    widget->setLayout(mainLayout);
    this->setCentralWidget(widget);
}

//
void MainWindow::initLabels(){
    this->logoLabel             = new QLabel(this);
    QPixmap     pixmap(":/images/logo.png");
    this->logoLabel->setPixmap(pixmap);
    this->logoLabel->setFixedSize(100,100);
    this->logoLabel->setScaledContents(true);
    this->logoLabel->setAlignment(Qt::AlignHCenter);

    this->sidLabel              = new QLabel(QObject::tr("unknow"),this);
    this->sidLabel->setWordWrap(true);

    this->leftTitleLabel        = new QLabel(QObject::tr("<b>本机NBS网络服务信息:</b>"),this);

    this->accLabelVal           = new QLineEdit(QObject::tr("NA"),this);
    this->accLabelVal->setReadOnly(true);
    this->accLabelVal->setStyleSheet(BGC_LIGHT_GRAY);

    this->nbsAddress            = new QLabel(QObject::tr("127.0.0.1:59527"),this);
    this->nbsAddress->setStyleSheet(BGC_LIGHT_GRAY);



    this->ipList                = new QListWidget(this);
    this->networkInterfaceList(this->ipList);
    this->ipList->setStyleSheet(BGC_LIGHT_GRAY);


    this->initButton            = new QPushButton(QObject::tr("init"),this);


    //<RIGHT>


    this->rightTitleLabel       = new QLabel(QObject::tr("<b>群聊:</b>"),this);
    this->logChat               = new QTextEdit(this);
    this->logChat->setReadOnly(true);
    this->logChat->setFocusPolicy(Qt::NoFocus);


    this->msgSend               = new QLineEdit();
    this->msgSend->setFocusPolicy(Qt::StrongFocus);
    this->msgSend->setFocus();
    this->msgSend->installEventFilter(this);
    this->sendButton            = new QPushButton(QObject::tr("Send"),this);

    this->sendButton->setEnabled(false);

    this->statLabel             = new QLabel(QObject::tr("状态：服务未初始化..."),this);
}


void MainWindow::networkInterfaceList(QListWidget * listWidget){
    if(listWidget != nullptr){
        QList<QHostAddress> lst = QNetworkInterface::allAddresses();

        foreach(QHostAddress address,lst){
            if(address.protocol()==QAbstractSocket::IPv4Protocol)
                listWidget->addItem(address.toString());
        }

        listWidget->setFocusPolicy(Qt::NoFocus);
    }
}
