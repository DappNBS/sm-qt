#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    this->initLabels();

    this->leftInfoWidget        = new QListWidget(this);
    this->msgLogWidget          = new QListWidget(this);


    //<RIGHT>
    this->logChat               = new QTextEdit(this);
    this->msgSend               = new QLineEdit();

    this->sendButton            = new QPushButton(QObject::tr("Send"),this);
    this->initButton            = new QPushButton(QObject::tr("init"),this);
    this->logChat->setFocusPolicy(Qt::NoFocus);
    this->msgSend->setFocusPolicy(Qt::StrongFocus);

    this->initLayout();
    this->setWindowTitle(APP_NAME);
    this->resize(QSize(WIN_WIDTH,WIN_HEIGHT));
}

MainWindow::~MainWindow()
{

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

    //flow
    QVBoxLayout     * infoLayout    = new QVBoxLayout;
    infoLayout->addWidget(this->leftTitleLabel);
    infoLayout->addWidget(this->accLabel);
    infoLayout->addStretch();
    //infoLayout->setSpacing(2);


    QHBoxLayout     * initBtnLayout = new QHBoxLayout;
    initBtnLayout->addStretch();
    initBtnLayout->addWidget(this->initButton);
    initBtnLayout->setSpacing(10);

    QVBoxLayout     * leftVBLayout  = new QVBoxLayout;
    leftVBLayout->addLayout(logoLayout);
    leftVBLayout->addWidget(this->sidLabel,0,Qt::AlignHCenter);

    leftVBLayout->addLayout(infoLayout);
    //leftVBLayout->addWidget(this->accLabel);
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
    rightVBLayout->addWidget(this->msgLogWidget);
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

    this->leftTitleLabel        = new QLabel(QObject::tr("<b>本机NBS网络服务信息:</b>"),this);

    this->rightTitleLabel       = new QLabel(QObject::tr("<b>群聊:</b>"),this);
    this->statLabel             = new QLabel(QObject::tr("状态：服务未初始化..."),this);

    this->sidLabel              = new QLabel(QObject::tr("unknow"),this);
    this->sidLabel->setWordWrap(true);

    this->accLabel              = new QLabel(QObject::tr("Account Name:"),this);
    this->accLabelVal           = new QLineEdit(QObject::tr("unknow"),this);
    this->accLabelVal->setReadOnly(true);
    this->accLabel->setBuddy(this->accLabelVal);
}
