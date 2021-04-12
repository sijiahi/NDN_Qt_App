#ifndef CHAT_DEMO_H
#define CHAT_DEMO_H

#include <QDialog>
#include <QTextTableCell>
#include "chat_core.h"
#include "chat_setter.h"
#include "common.h"
#include <QScrollBar>
#include <QMessageBox>
#include <data_sender.h>
#include <QStringListModel>
#include <QStandardItemModel>
#include <QModelIndex>
#include <QCloseEvent>

namespace Ui {
class Chat_demo;
}

class Chat_demo : public QDialog
{
    Q_OBJECT

public:
    explicit Chat_demo(QWidget *parent = 0);
    ~Chat_demo();
    bool Initiate();
    void closeEvent(QCloseEvent *event);
    //int chatDebug();
private slots:
    void on_Send_clicked();
    void onChatStart(const QString& name,const QString& prefix,const QString& chatroom);
    void onChatDataReceived(const QString& name,const QString& content);
    void onNewUser(const QString& name);
    void onUserLeave(const QString& name);
    void onControlMessageReceived(const QString& name,const QString& content);
private:
    Ui::Chat_demo *ui;
    //vector<string> users;
    QStandardItemModel *ItemModel;
    QStringList users;
    void appendControlMessage(const QString& name,const QString& message);
    void appendChatMessage(const QString& name, const QString& message);
    void appendReceivedMessage(const QString& name, const QString& message);
    void updateMessage(const QString& name, bool add);
    QString m_name;
    QString m_prefix;
    QString m_chatroom;
    chat_setter* m_setter;
    Chat* m_chat;
     //ptr_lib::shared_ptr<chat_core> m_chat;
    ndn::Face* m_face;
};

#endif // CHAT_DEMO_H
