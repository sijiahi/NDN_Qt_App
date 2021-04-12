#ifndef NDN_APP_H
#define NDN_APP_H

#include <QMainWindow>

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

    void on_nfd_report_clicked();

private:
    Ui::ndn_app *ui;
};

#endif // NDN_APP_H
