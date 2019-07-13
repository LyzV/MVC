#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->listView->setModel(&model);
    ui->listView->setItemDelegate(&slider_delegate);
}

MainWindow::~MainWindow()
{
    delete ui;
}
