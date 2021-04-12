#ifndef NDN_APP_H
#define NDN_APP_H

#include <QMainWindow>
#include <QMessageBox>
#include "consumer_manager.h"
#include "repo_putfile.h"
#include "repo_deletefile.h"
#include <QProcess>
<<<<<<< HEAD
#include <dirent.h>

=======
//#include <QtWebEngineWidgets/QWebEngineView>
>>>>>>> 73f85cd88c469ec05166c7729fca0f5d72976c7b
namespace Ui {
class ndn_app;
}

class ndn_app : public QMainWindow
{
    Q_OBJECT

public:
    explicit ndn_app(QWidget *parent = 0);
    ~ndn_app();

private slots:

    void on_nfd_Manager_clicked();

    void on_consumer_app_clicked();

    void on_to_DB_clicked();

    void on_delete_DB_clicked();

    void on_chat_app_clicked();
<<<<<<< HEAD

    void on_getFiles_clicked();
=======
>>>>>>> 73f85cd88c469ec05166c7729fca0f5d72976c7b

private:
    Ui::ndn_app *ui;
    Consumer_manager *manager;
    QProcess *chatList;
};

#endif // NDN_APP_H
