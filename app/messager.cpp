#include "messager.h"
#include "ui_messager.h"

Messager::Messager(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Messager)
{
    ui->setupUi(this);
}

Messager::~Messager()
{
    delete ui;
}
void Messager::setMessage(QString text){
      this->ui->textBrowser->setText(text);
<<<<<<< HEAD
      this->ui->textBrowser->update();
      this->update();
}
void Messager::addMessage(QString text){
      this->ui->textBrowser->append(text);
    this->ui->textBrowser->update();
    this->update();
=======
}
void Messager::addMessage(QString text){
      this->ui->textBrowser->append(text);
>>>>>>> 73f85cd88c469ec05166c7729fca0f5d72976c7b
}
