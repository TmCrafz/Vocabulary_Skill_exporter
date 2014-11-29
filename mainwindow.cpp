#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // ui->pushButtonAddVoc->setEnabled(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushBtnNewVocFile_clicked()
{
    mDialogAddVocabulary = new DialogAddVocabulary(0);
    mDialogAddVocabulary->show();
}

void MainWindow::on_pushButton_clicked()
{
    mDialogConvertTxt = new DialogConvertTxt(0);
    mDialogConvertTxt->show();
}
