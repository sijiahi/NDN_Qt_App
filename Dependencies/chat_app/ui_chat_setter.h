/********************************************************************************
** Form generated from reading UI file 'chat_setter.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAT_SETTER_H
#define UI_CHAT_SETTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_chat_setter
{
public:
    QLabel *name_label;
    QLineEdit *name;
    QLineEdit *prefix;
    QLineEdit *chatroom;
    QLabel *hubPrefix_label;
    QLabel *chatRoom_label;
    QPushButton *Enter;

    void setupUi(QDialog *chat_setter)
    {
        if (chat_setter->objectName().isEmpty())
            chat_setter->setObjectName(QStringLiteral("chat_setter"));
        chat_setter->resize(541, 300);
        name_label = new QLabel(chat_setter);
        name_label->setObjectName(QStringLiteral("name_label"));
        name_label->setGeometry(QRect(60, 60, 67, 17));
        name = new QLineEdit(chat_setter);
        name->setObjectName(QStringLiteral("name"));
        name->setGeometry(QRect(260, 50, 113, 25));
        prefix = new QLineEdit(chat_setter);
        prefix->setObjectName(QStringLiteral("prefix"));
        prefix->setGeometry(QRect(260, 110, 113, 25));
        chatroom = new QLineEdit(chat_setter);
        chatroom->setObjectName(QStringLiteral("chatroom"));
        chatroom->setGeometry(QRect(260, 180, 113, 25));
        hubPrefix_label = new QLabel(chat_setter);
        hubPrefix_label->setObjectName(QStringLiteral("hubPrefix_label"));
        hubPrefix_label->setGeometry(QRect(60, 120, 81, 21));
        chatRoom_label = new QLabel(chat_setter);
        chatRoom_label->setObjectName(QStringLiteral("chatRoom_label"));
        chatRoom_label->setGeometry(QRect(50, 180, 81, 17));
        Enter = new QPushButton(chat_setter);
        Enter->setObjectName(QStringLiteral("Enter"));
        Enter->setGeometry(QRect(330, 250, 161, 31));

        retranslateUi(chat_setter);

        QMetaObject::connectSlotsByName(chat_setter);
    } // setupUi

    void retranslateUi(QDialog *chat_setter)
    {
        chat_setter->setWindowTitle(QApplication::translate("chat_setter", "Dialog", Q_NULLPTR));
        name_label->setText(QApplication::translate("chat_setter", "Name", Q_NULLPTR));
        hubPrefix_label->setText(QApplication::translate("chat_setter", "Hub Prefix", Q_NULLPTR));
        chatRoom_label->setText(QApplication::translate("chat_setter", "Chatroom", Q_NULLPTR));
        Enter->setText(QApplication::translate("chat_setter", "Enter Chatroom", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class chat_setter: public Ui_chat_setter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_SETTER_H
