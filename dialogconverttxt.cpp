#include <fstream>
#include <QFileDialog>
#include <QMessageBox>
#include <QDesktopServices>
#include "dialogconverttxt.h"
#include "ui_dialogconverttxt.h"
#include "xmlhandler.h"

DialogConvertTxt::DialogConvertTxt(QWidget *parent) :
    QDialog(parent),
    xmlPath(QStandardPaths::writableLocation(QStandardPaths::DesktopLocation)),
    ui(new Ui::DialogConvertTxt)
{
    ui->setupUi(this);
    QString defFileName = "Vocabulary.xml";
    ui->lineEditListName->setText("Vocabulary");
    ui->lineEditSavePath->setText(xmlPath + "/" + defFileName);
}

DialogConvertTxt::~DialogConvertTxt()
{
    delete ui;
}

void DialogConvertTxt::on_pushBtnChooseTxt_clicked()
{   const QString filter = "Text files (*.txt)";
    txtPath = QFileDialog::getOpenFileName
            (this, "Open file", QStandardPaths::writableLocation(QStandardPaths::DesktopLocation),
             "Text files (*.txt)" );
    QString fileName = ui->lineEditListName->text();
    ui->lineEditTxtPath->setText(txtPath);

}

void DialogConvertTxt::on_pushBtnChooseXmlSave_clicked()
{
    xmlPath = QFileDialog::getExistingDirectory
            (this, "Choose Directory", QStandardPaths::writableLocation(QStandardPaths::DesktopLocation),
             QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    QString fileName = ui->lineEditListName->text();
    ui->lineEditSavePath->setText(xmlPath + "/" + fileName + ".xml");
}

void DialogConvertTxt::on_pushBtnConvert_clicked()
{
    /*
     * If a line contains a '#' the line get Split to two strings, split by the hash.
     * The left is the unknown word and the right the known.
     * */
    std::string filePath = txtPath.toStdString();
    std::ifstream txtFileRead;
    txtFileRead.open(filePath);
    if (!txtFileRead)
        QMessageBox::warning(this, "Error", "Cannot open file.");
    std::string tmp;
    QVector<QVector<QString>> vocabularyList { QVector<QVector<QString>>() };
    while(std::getline(txtFileRead, tmp))
    {
        size_t hashPos = tmp.find('#');
        //Check if the line size is higher then the hash position, to check if there is a known word.
        if (hashPos != std::string::npos && tmp.size() > hashPos)
        {
            std::string unknownWord = tmp.substr(0, hashPos);
            std::string knownWord = tmp.substr(hashPos + 1);
            QVector<QString> vocable { QVector<QString>() };
            vocable.append(QString::fromStdString(knownWord).trimmed());
            vocable.append(QString::fromStdString(unknownWord).trimmed());
            vocabularyList.append(vocable);
        }
    }
    //Save into a Vocabulary Skill compatible .xml file
    QString learningListName = ui->lineEditListName->text();
    QString path = ui->lineEditSavePath->text();
    XmlHandler xmlHandler;
    if (!xmlHandler.saveToVsXml(learningListName, vocabularyList, path))
        QMessageBox::warning(this, "Error", "Cannot save file.");
    else
        QMessageBox::information(this, "Saved", "Saved file");

}



