#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->initStatusBar();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initStatusBar()
{
    mStatusBarTimeLabel = new QLabel("加载中");
    QFont font("Microsoft YaHei UI",15);
    mStatusBarTimeLabel->setFont(font);
    ui->statusbar->addPermanentWidget(mStatusBarTimeLabel);
    mStatusBarTimer = new QTimer(this);
    mStatusBarTimer->setInterval(1000);
    connect(mStatusBarTimer,&QTimer::timeout,this,&MainWindow::updateStatusBarTimeLabel);
    mStatusBarTimer->start();
}

void MainWindow::updateStatusBarTimeLabel()
{
    QDateTime current_time = QDateTime::currentDateTime();
    QString timestr = current_time.toString("yyyy年MM月dd日 hh:mm:ss");
    mStatusBarTimeLabel->setText(timestr);
}

