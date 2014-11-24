ifndef ADDVOCABULARYWINDOW_H
#define ADDVOCABULARYWINDOW_H

#include <QMainWindow>

namespace Ui {
class AddVocabularyWindow;
}

class AddVocabularyWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddVocabularyWindow(QWidget *parent = 0, QString fileName = "UnknownFile");
    ~AddVocabularyWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddVocabularyWindow *ui;
};

#endif // ADDVOCABULARYWINDOW_H
