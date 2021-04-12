#include "chat_setter.h"
#include "ui_chat_setter.h"

chat_setter::chat_setter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chat_setter)

{
<<<<<<< HEAD
    m_name= QString("user");
    m_prefix = QString("chat/edu/buaa/cn");
    m_chatroom = QString("ChatRoom_0");
    ui->setupUi(this);
    this->setWindowTitle("NDN_Chat v003");
=======
    this->setWindowTitle("NDN_Chat");
    m_name= QString("user");
    m_prefix = QString("ndn/edu/buaa/chat");
    m_chatroom = QString("ChatRoom1");
    ui->setupUi(this);
>>>>>>> 73f85cd88c469ec05166c7729fca0f5d72976c7b
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
