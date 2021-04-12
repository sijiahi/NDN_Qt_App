/********************************************************************************
** Form generated from reading UI file 'ndn_app.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NDN_APP_H
#define UI_NDN_APP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ndn_app
{
public:
    QWidget *centralWidget;
    QPushButton *nfd_report;
    QPushButton *consumer_app;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ndn_app)
    {
        if (ndn_app->objectName().isEmpty())
            ndn_app->setObjectName(QStringLiteral("ndn_app"));
        ndn_app->resize(525, 405);
        centralWidget = new QWidget(ndn_app);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        nfd_report = new QPushButton(centralWidget);
        nfd_report->setObjectName(QStringLiteral("nfd_report"));
        nfd_report->setGeometry(QRect(0, 0, 261, 171));
        consumer_app = new QPushButton(centralWidget);
        consumer_app->setObjectName(QStringLiteral("consumer_app"));
        consumer_app->setGeometry(QRect(0, 170, 261, 171));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(260, 170, 261, 171));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(260, 0, 261, 171));
        ndn_app->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ndn_app);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 525, 22));
        ndn_app->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ndn_app);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ndn_app->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ndn_app);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ndn_app->setStatusBar(statusBar);

        retranslateUi(ndn_app);

        QMetaObject::connectSlotsByName(ndn_app);
    } // setupUi

    void retranslateUi(QMainWindow *ndn_app)
    {
        ndn_app->setWindowTitle(QApplication::translate("ndn_app", "ndn_app", Q_NULLPTR));
        nfd_report->setText(QApplication::translate("ndn_app", "NFD Report", Q_NULLPTR));
        consumer_app->setText(QApplication::translate("ndn_app", "Consumer", Q_NULLPTR));
        pushButton->setText(QApplication::translate("ndn_app", "Producer", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("ndn_app", "Chat", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ndn_app: public Ui_ndn_app {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NDN_APP_H
