#include "addvocabularywindow.h"
#include "ui_addvocabularywindow.h"

AddVocabularyWindow::AddVocabularyWindow(QWidget *parent, QString fileName) :
    QMainWindow(parent),
    ui(new Ui::AddVocabularyWindow)
{
    ui->setupUi(this);
    setWindowTitle("Create File: " + fileName + ".xml");
}

AddVocabularyWindow::~AddVocabularyWindow()
{
    delete ui;
}

void AddVocabularyWindow::on_pushButton_clicked()
{

}
