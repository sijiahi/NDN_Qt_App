#include "ndn_app.h"
#include <QApplication>
#include "chat_core.cpp"
#include "chat_demo.h"
#include "chat_setter.h"
class NDNApp : public QApplication
{
public:
  NDNApp(int& argc, char** argv)
    : QApplication(argc, argv)
  {
  }

  bool
  notify(QObject* receiver, QEvent* event)
  {
    try {
        return QApplication::notify(receiver, event);
    }
    catch (std::exception& e) {
      std::cerr << "Exception thrown:" << e.what() << std::endl;
      return false;
    }

  }
};
int main(int argc, char *argv[])
{

    //NDNApp app(argc, argv);
    QApplication app(argc, argv);
    //chatDebug(argc,argv);

    //init_chat setter;
    //setter.show();
    Chat_demo chat;
    chat.Initiate();
    return app.exec();
}


