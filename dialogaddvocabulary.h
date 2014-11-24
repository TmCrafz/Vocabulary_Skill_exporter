#ifndef DIALOGADDVOCABULARY_H
#define DIALOGADDVOCABULARY_H

#include <QDialog>

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

private:
    Ui::DialogAddVocabulary *ui;
};

#endif // DIALOGADDVOCABULARY_H
