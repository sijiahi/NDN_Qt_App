#ifndef DLGTREEXML_H
#define DLGTREEXML_H

#include <QDialog>

namespace Ui {
class DlgTreeXml;
}

class DlgTreeXml : public QDialog
{
    Q_OBJECT

public:
    explicit DlgTreeXml(QWidget *parent = 0);
    ~DlgTreeXml();

private slots:
    void on_btnLoadXml_clicked();

    void on_btnSaveXml_clicked();

private:
    Ui::DlgTreeXml *ui;

    bool LoadXml();
    bool SaveXml();
};

#endif // DLGTREEXML_H
