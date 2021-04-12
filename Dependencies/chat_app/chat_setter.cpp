#include "chat_setter.h"
#include "ui_chat_setter.h"

chat_setter::chat_setter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chat_setter)

{
    this->setWindowTitle("NDN_Chat");
    m_name= QString("user");
    m_prefix = QString("chat/edu/buaa/cn");
    m_chatroom = QString("ChatRoom_0");
    ui->setupUi(this);
}

chat_setter::~chat_setter()
{
    delete ui;
}
QString
chat_setter::getName(){
   return m_name;
}
QString
chat_setter::getPrefix(){
    return m_prefix;
}
QString
chat_setter::getChatroom(){
    return m_chatroom;
}

void chat_setter::on_Enter_clicked()
{
    QString name = ui->name->text();
    QString prefix = ui->prefix->text();
    QString chatroom = ui->chatroom->text();
    if (!name.isEmpty())
        m_name = name;
    if (!prefix.isEmpty())
        m_prefix = prefix;
    if (!chatroom.isEmpty())
        m_chatroom = chatroom;
    this->close();
    emit chatInfoUpdate(m_name, m_prefix, m_chatroom);

}
