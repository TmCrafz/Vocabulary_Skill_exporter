#ifndef DIALOGADDVOCABULARY_H
#define DIALOGADDVOCABULARY_H

#include <QDialog>
#include <QtXml>
#include <QMessageBox>

namespace Ui {
class DialogAddVocabulary;
}

class DialogAddVocabulary : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAddVocabulary(QWidget *parent = 0);
    ~DialogAddVocabulary();



private slots:
    void on_pushButton_clicked();

    void on_pushBtnDeleteAddedVoc_clicked();

    void on_pushBtnSaveVocList_clicked();

    void on_pushBtnChoosePath_clicked();



    void on_lineEditFileName_textChanged(const QString &arg1);

private:
    Ui::DialogAddVocabulary *ui;
    QString path;
};

#endif // DIALOGADDVOCABULARY_H
