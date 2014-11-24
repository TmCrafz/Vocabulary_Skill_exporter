#include "dialogaddvocabulary.h"
#include "ui_dialogaddvocabulary.h"

DialogAddVocabulary::DialogAddVocabulary(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAddVocabulary)
{
    ui->setupUi(this);
}

DialogAddVocabulary::~DialogAddVocabulary()
{
    delete ui;
}

void DialogAddVocabulary::on_pushButton_clicked()
{
    QString knownWord = ui->textEditKnownWord->toPlainText();
    QString unknownWord = ui->textEditUnkownWord->toPlainText();
    QString listString = knownWord + " - " + unknownWord;
    ui->listWidgetAddedVoc->addItem(listString);
    ui->textEditKnownWord->clear();
    ui->textEditUnkownWord->clear();
}

void DialogAddVocabulary::on_pushBtnDeleteAddedVoc_clicked()
{
    qDeleteAll(ui->listWidgetAddedVoc->selectedItems());

}
