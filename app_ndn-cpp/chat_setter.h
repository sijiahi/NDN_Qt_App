#ifndef chat_setter_H
#define chat_setter_H

#include <QDialog>
#include <QString>

namespace Ui {
class chat_setter;
}

class chat_setter : public QDialog
{
    Q_OBJECT

public:
    explicit chat_setter(QWidget *parent = 0);
    ~chat_setter();
    QString getName();
    QString getPrefix();
    QString getChatroom();
private slots:
    void on_Enter_clicked();

signals:
    void chatInfoUpdate(const QString& name, const QString& prefix,const QString& chatroom);
private:
    Ui::chat_setter *ui;
    QString m_name;
    QString m_prefix;
    QString m_chatroom;

};

#endif // chat_setter_H
