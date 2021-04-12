/********************************************************************************
** Form generated from reading UI file 'chat_demo.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAT_DEMO_H
#define UI_CHAT_DEMO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Chat_demo
{
public:
    QLineEdit *Input_field;
    QPushButton *More;
    QPushButton *Send;
    QTextEdit *textEdit;
    QListView *listView;

    void setupUi(QDialog *Chat_demo)
    {
        if (Chat_demo->objectName().isEmpty())
            Chat_demo->setObjectName(QStringLiteral("Chat_demo"));
        Chat_demo->resize(827, 580);
        Input_field = new QLineEdit(Chat_demo);
        Input_field->setObjectName(QStringLiteral("Input_field"));
        Input_field->setGeometry(QRect(0, 450, 651, 141));
        More = new QPushButton(Chat_demo);
        More->setObjectName(QStringLiteral("More"));
        More->setGeometry(QRect(650, 450, 161, 131));
        Send = new QPushButton(Chat_demo);
        Send->setObjectName(QStringLiteral("Send"));
        Send->setGeometry(QRect(650, 450, 181, 131));
        textEdit = new QTextEdit(Chat_demo);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(170, 0, 651, 451));
        listView = new QListView(Chat_demo);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(0, 0, 171, 451));

        retranslateUi(Chat_demo);

        QMetaObject::connectSlotsByName(Chat_demo);
    } // setupUi

    void retranslateUi(QDialog *Chat_demo)
    {
        Chat_demo->setWindowTitle(QApplication::translate("Chat_demo", "Chat", Q_NULLPTR));
        More->setText(QApplication::translate("Chat_demo", "More", Q_NULLPTR));
        Send->setText(QApplication::translate("Chat_demo", "Send", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Chat_demo: public Ui_Chat_demo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_DEMO_H
