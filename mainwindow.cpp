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
/*
void MainWindow::on_lineEditFileName_textChanged(const QString &arg1)
{
    ui->pushButtonAddVoc->setEnabled(arg1 > 0);
}
*/
/*
void MainWindow::on_pushButtonAddVoc_clicked()
{
  // mAddVocabularyWindow = new AddVocabularyWindow(0, ui->lineEditFileName->text());
  // mAddVocabularyWindow->show();
}
*/

void MainWindow::on_pushBtnNewVocFile_clicked()
{
    mDialogAddVocabulary = new DialogAddVocabulary(0);
    mDialogAddVocabulary->show();
}