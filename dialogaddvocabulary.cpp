#include "dialogaddvocabulary.h"
#include "ui_dialogaddvocabulary.h"
#include "xmlhandler.h"
#include <QFileDialog>
#include <QDesktopServices>

DialogAddVocabulary::DialogAddVocabulary(QWidget *parent) :
    QDialog(parent),    
    path(QStandardPaths::writableLocation(QStandardPaths::DesktopLocation)),
    ui(new Ui::DialogAddVocabulary)
{
    ui->setupUi(this);
    QString defFileName = "Vocabulary";
    ui->lineEditFileName->setText("Vocabulary");
    ui->lineEditPath->setText(path + "/" + defFileName + ".xml");
}

DialogAddVocabulary::~DialogAddVocabulary()
{
    delete ui;
}

void DialogAddVocabulary::on_pushButton_clicked()
{
    QString knownWord = ui->textEditKnownWord->toPlainText();
    QString unknownWord = ui->textEditUnkownWord->toPlainText();  
    QTableWidgetItem *tableKnownWord = new QTableWidgetItem(knownWord);
    QTableWidgetItem *tableUnknownWord = new QTableWidgetItem(unknownWord);

    int row  =  ui->tableWidgetAddedVoc->rowCount(); 
    ui->tableWidgetAddedVoc->insertRow(row);
    ui->tableWidgetAddedVoc->setItem(row, 0, tableKnownWord);
    ui->tableWidgetAddedVoc->setItem(row, 1, tableUnknownWord);

    ui->textEditKnownWord->clear();
    ui->textEditUnkownWord->clear();
}

void DialogAddVocabulary::on_pushBtnDeleteAddedVoc_clicked()
{
    //Delete the row of the selected items
    QList<QTableWidgetItem*> itemList = ui->tableWidgetAddedVoc->selectedItems();
    for (int i { 0 }; i < itemList.size(); i++)
        ui->tableWidgetAddedVoc->removeRow(itemList.at(i)->row());
}

void DialogAddVocabulary::on_pushBtnSaveVocList_clicked()
{
    //Store all vocabulary and save it
    QVector<QVector<QString>> vocabularyList { QVector<QVector<QString>>() };
    int rows { ui->tableWidgetAddedVoc->rowCount() };
    for (int i { 0 }; i != rows; i++)
    {
        QString knownWord { ui->tableWidgetAddedVoc->item(i, 0)->text() };
        QString unknownWord { ui->tableWidgetAddedVoc->item(i, 1)->text() };
        QVector<QString> vocable { QVector<QString>() };
        vocable.append(knownWord);
        vocable.append(unknownWord);
        vocabularyList.append(vocable);       
    }
    QString learningListName { ui->lineEditFileName->text() };
    QString path = ui->lineEditPath->text();
    XmlHandler xmlHandler;
    if (!xmlHandler.saveToVsXml(learningListName, vocabularyList, path))
        QMessageBox::warning(this, "Error", "Cannot save file.");
    else
        QMessageBox::information(this, "Saved", "Saved file");
}

void DialogAddVocabulary::on_pushBtnChoosePath_clicked()
{
    path = QFileDialog::getExistingDirectory
            (this, "Choose Directory", QStandardPaths::writableLocation(QStandardPaths::DesktopLocation),
             QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    QString fileName = ui->lineEditFileName->text();
    ui->lineEditPath->setText(path + "/" + fileName + ".xml");
}

//Change the preview of the save directory and filename
void DialogAddVocabulary::on_lineEditFileName_textChanged(const QString &arg1)
{
    ui->lineEditPath->setText(path + "/" + arg1 + ".xml");
}
