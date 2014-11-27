#include "dialogaddvocabulary.h"
#include "ui_dialogaddvocabulary.h"
#include <QFileDialog>
#include <QDebug>
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
    qDebug() << "Rows" << row;
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
        qDebug() << "i: " << i << " Word: " << knownWord << " - " << unknownWord;
    }
    QString learningListName { ui->lineEditFileName->text() };
    saveToXml(learningListName, vocabularyList);
}

void DialogAddVocabulary::saveToXml(QString learningListName, QVector<QVector<QString> > vocabularyList )
{
    QDomDocument document;
    QDomProcessingInstruction declaration = document.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"UTF-8\"");
    document.insertBefore(declaration, QDomNode());
    QDomElement rootElement = document.createElement("vocabularyskill");
    document.appendChild(rootElement);
    QDomElement learningListElement = document.createElement("learning_list");
    learningListElement.setAttribute("name", learningListName);
    rootElement.appendChild(learningListElement);
    for (auto vocable : vocabularyList)
    {
        QDomElement vocableElement = document.createElement("vocable");
        vocableElement.setAttribute("known_word", vocable[0]);
        vocableElement.setAttribute("unknown_word", vocable[1]);
        rootElement.appendChild(vocableElement);
    }
   // QString fileName { learningListName + ".xml" };
    QString fileName = ui->lineEditPath->text();
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        QMessageBox::warning(this, "Error", "Cannot save file.");
    else
    {
        QTextStream stream(&file);
        stream.setCodec("UTF-8");
        stream << document.toString();
        file.flush();
        file.close();
        QMessageBox::information(this, "Saved", "Saved file");
    }
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
