#include "chat_demo.h"
#include "ui_chat_demo.h"
#include "chat_setter.h"
Chat_demo::Chat_demo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Chat_demo),
    m_setter(new chat_setter(this)),
    ItemModel(new QStandardItemModel(this))
{
    //connect(this,SIGNAL(newMsg(QString)),
    //        &m_backend, SLOT(sendChatMessage(QString, time_t)));
    m_name = "";
    m_prefix = "";
    m_chatroom =  "";
    connect(m_setter, SIGNAL(chatInfoUpdate(const QString&,const QString&,const QString&)),
             this, SLOT(onChatStart(const QString&,const QString&,const QString&)));
    ui->setupUi(this);
}
Chat_demo::~Chat_demo()
{
    delete ui;
}
//////Detect close Event and send leave message
void Chat_demo::closeEvent(QCloseEvent *event){
    QMessageBox::StandardButton button;
    button = QMessageBox::question(this, tr("Exit Chat Room"),
        QString(tr("Are you sure to exit chat room?")),
        QMessageBox::Yes | QMessageBox::No);

    if (button == QMessageBox::No) {
        event->ignore();  //ignore singal
    }
    else if (button == QMessageBox::Yes) {
        m_chat->leave();
        //usleep(1000);
        //event->accept();  //exit program
    }
}


// Show Setter and get information needed
bool Chat_demo::Initiate(){
    try{
    m_setter->show();
    }
    catch (std::exception& e) {
      std::cerr << "Exception thrown while initializing chat:" << e.what() << std::endl;
      return false;
    }
}
void
Chat_demo::on_Send_clicked()
{
    QString text = ui->Input_field->text();
    if (text.toStdString().empty())
      return;
    ui->Input_field->clear();
    m_chat->sendMessage(text.toStdString());
    m_face->processEvents();
    appendChatMessage(m_name,text);
    //emit newMsg(text, timestamp);
}

void
Chat_demo::onChatStart(const QString& name,const QString& prefix,const QString& chatroom){
        m_name = name;
        m_prefix = prefix;
        m_chatroom = chatroom;
        const char* host = "localhost";
        std::cout << "Connecting to " << host << ", Chatroom: " << chatroom.toStdString() <<
          ", Username: " << name.toStdString() << std::endl;
      try{
        KeyChain keyChain("pib-memory:", "tpm-memory:");
        keyChain.importSafeBag(SafeBag
          (Name("/testname/KEY/123"),
           Blob(DEFAULT_RSA_PRIVATE_KEY_DER, sizeof(DEFAULT_RSA_PRIVATE_KEY_DER)),
           Blob(DEFAULT_RSA_PUBLIC_KEY_DER, sizeof(DEFAULT_RSA_PUBLIC_KEY_DER))));
        m_face = new Face(host);
        m_face->setCommandSigningInfo(keyChain, keyChain.getDefaultCertificateName());
        m_chat = new Chat
                (this,name.toStdString(), chatroom.toStdString(), Name(prefix.toStdString()), m_face, keyChain,
                keyChain.getDefaultCertificateName());
        m_chat->initialize();
        connect(m_chat, SIGNAL(chatDataReceived(QString,QString)),
                this, SLOT(onChatDataReceived(QString,QString)));
        connect(m_chat, SIGNAL(addUser(QString)),
                this, SLOT(onNewUser(QString)));
        connect(m_chat, SIGNAL(removeUser(QString)),
                this, SLOT(onUserLeave(QString)));
        connect(m_chat,SIGNAL(leaveNow()),
                this, SLOT(close()));
        this->setWindowTitle(chatroom);
        updateMessage(m_name, true);
        this->show();

        appendControlMessage(m_name,QString("is entring chatroom"));
        //updateMessage(m_name,true);
        usleep(100000);
            m_face->processEvents();
        m_chat->start();
        }
        catch (std::exception& e) {
            QMessageBox errorBox;
            QString errormsg = "Error occurs when initiazing Chat with message ";
            errormsg=errormsg+QString::fromStdString(e.what());
            errorBox.setWindowTitle("Error");
            errorBox.setText(errormsg);
             cout << "Exception Thrown while Starting Chat Dialog: " << e.what() << endl;
           }
}
void
Chat_demo::onControlMessageReceived(const QString& name,const QString& content){
    appendControlMessage(name, content);
}
void
Chat_demo::onChatDataReceived(const QString& name,const QString& content){
    appendReceivedMessage(name, content);
}
void
Chat_demo::onNewUser(const QString& name){
    appendControlMessage(name,QString("is entering chatroom"));
    updateMessage(name,true);
}
void
Chat_demo::onUserLeave(const QString& name){
    appendControlMessage(name,QString("is leaving chatroom"));
    updateMessage(name,false);
}
//TODO

void Chat_demo::updateMessage(const QString& name, bool add){
    ItemModel->clear();
    QFont font;
    //设置文字字体
    font.setFamily("SimSum");
    font.setPixelSize(50);
    font.setBold(true);             //封装的setWeight函数
    font.setPointSize(15);
    font.setOverline(true);
    font.setUnderline(true);
    QStandardItem *item = new QStandardItem(m_name);
    item->setForeground(Qt::darkBlue);
    item->setFont(font);
    if (add){
        users.append(name);
        ItemModel->appendRow(item);
        int nCount = users.size();
         for(int i = 0; i < nCount; i++)
         {
             if(users.at(i) == m_name){
                 continue;
             }
             QString string = static_cast<QString>(users.at(i));
             QStandardItem *item = new QStandardItem(string);
             //item->setFontWeight(QFont::Bold);
             switch (i%3){
             case 0:
                 item->setForeground(Qt::darkCyan);
             case 1:
                 item->setForeground(Qt::darkYellow);
             case 2:
                 item->setForeground(Qt::darkGreen);
             }
             ItemModel->appendRow(item);
         }
        ui->listView->setModel(ItemModel);
        ui->listView->setFixedSize(171,451);
        return;
    }
    else{
        ItemModel->appendRow(item);
            users.removeOne(name);}
        int nCount = users.size();
         for(int i = 0; i < nCount; i++)
         {
             if(users.at(i) == m_name){
                 continue;
             }
             QString string = static_cast<QString>(users.at(i));
             QStandardItem *item = new QStandardItem(string);
             //item->setFontWeight(QFont::Bold);
             switch (i%3){
             case 0:
                 item->setForeground(Qt::darkCyan);
             case 1:
                 item->setForeground(Qt::darkBlue);
             case 2:
                 item->setForeground(Qt::darkGreen);
             }
             ItemModel->appendRow(item);
         }
        ui->listView->setModel(ItemModel);
        ui->listView->setFixedSize(171,451);
        return;
}

//Messages from others
void Chat_demo::appendReceivedMessage(const QString& name, const QString& message)
{
      QTextCharFormat nickFormat;
      nickFormat.setForeground(Qt::darkBlue);
      nickFormat.setFontWeight(QFont::Bold);
      nickFormat.setFontUnderline(true);
      nickFormat.setUnderlineColor(Qt::gray);

      // Print who & when
      QTextCursor cursor(ui->textEdit->textCursor());
      cursor.movePosition(QTextCursor::End);
      QTextTableFormat tableFormat;
      tableFormat.setBorder(0);
      QTextTable *table = cursor.insertTable(1, 2, tableFormat);
      QString from = QString("%1 ").arg(name);
      QTextTableCell fromCell = table->cellAt(0, 0);
      fromCell.setFormat(nickFormat);
      fromCell.firstCursorPosition().insertText(from);

      // Print what
      QTextCursor nextCursor(ui->textEdit->textCursor());
      nextCursor.movePosition(QTextCursor::End);
      table = nextCursor.insertTable(1, 1, tableFormat);
      table->cellAt(0, 0).firstCursorPosition().insertText(message);

      // Popup notification
      //showMessage(from, message);

      QScrollBar *bar = ui->textEdit->verticalScrollBar();
      bar->setValue(bar->maximum());
}
// Messages I sent
void Chat_demo::appendChatMessage(const QString& name, const QString& message)
{
      QTextCharFormat nickFormat;
      nickFormat.setForeground(Qt::darkGreen);
      nickFormat.setFontWeight(QFont::Bold);
      nickFormat.setFontUnderline(true);
      nickFormat.setUnderlineColor(Qt::gray);

      // Print who & when
      QTextCursor cursor(ui->textEdit->textCursor());
      cursor.movePosition(QTextCursor::End);
      QTextTableFormat tableFormat;
      tableFormat.setBorder(0);
      QTextTable *table = cursor.insertTable(1, 2, tableFormat);
      QString from = QString("%1 ").arg(name);
      QTextTableCell fromCell = table->cellAt(0, 0);
      fromCell.setFormat(nickFormat);
      fromCell.firstCursorPosition().insertText(from);

      // Print what
      QTextCursor nextCursor(ui->textEdit->textCursor());
      nextCursor.movePosition(QTextCursor::End);
      table = nextCursor.insertTable(1, 1, tableFormat);
      table->cellAt(0, 0).firstCursorPosition().insertText(message);

      // Popup notification
      //showMessage(from, message);

      QScrollBar *bar = ui->textEdit->verticalScrollBar();
      bar->setValue(bar->maximum());
}
void
Chat_demo::appendControlMessage(const QString& name,
                                 const QString& message)
{
  QTextCharFormat nickFormat;
  nickFormat.setForeground(Qt::gray);
  nickFormat.setFontWeight(QFont::Bold);
  nickFormat.setFontUnderline(true);
  nickFormat.setUnderlineColor(Qt::gray);

  QTextCursor cursor(ui->textEdit->textCursor());
  cursor.movePosition(QTextCursor::End);
  QTextTableFormat tableFormat;
  tableFormat.setBorder(0);
  QTextTable *table = cursor.insertTable(1, 2, tableFormat);

  QString controlMsg = QString("%1 %2  ").arg(name).arg(message);
  QTextTableCell fromCell = table->cellAt(0, 0);
  fromCell.setFormat(nickFormat);
  fromCell.firstCursorPosition().insertText(controlMsg);
  //printTimeInCell(table, timestamp);
}
/*
int
Chat_demo::chatDebug()
{
  try {
    // Silence the warning from Interest wire encode.
    Interest::setDefaultCanBePrefix(true);

    cout << "Enter your chat username:" << endl;
    string screenName = stdinReadLine();

    string defaultHubPrefix = "ndn/edu/ucla/remap";
    cout << "Enter your hub prefix [" << defaultHubPrefix << "]" << endl;
    string hubPrefix = stdinReadLine();
    if (hubPrefix == "")
      hubPrefix = defaultHubPrefix;

    string defaultChatRoom = "ndnchat";
    cout << "Enter the chatroom name [" << defaultChatRoom << "]:" << endl;
    string chatRoom = stdinReadLine();
    if (chatRoom == "")
      chatRoom = defaultChatRoom;

    const char* host = "localhost";
    cout << "Connecting to " << host << ", Chatroom: " << chatRoom <<
      ", Username: " << screenName << endl << endl;

    Face face(host);

    // Set up the key chain.
    KeyChain keyChain("pib-memory:", "tpm-memory:");
    keyChain.importSafeBag(SafeBag
      (Name("/testname/KEY/123"),
       Blob(DEFAULT_RSA_PRIVATE_KEY_DER, sizeof(DEFAULT_RSA_PRIVATE_KEY_DER)),
       Blob(DEFAULT_RSA_PUBLIC_KEY_DER, sizeof(DEFAULT_RSA_PUBLIC_KEY_DER))));
    face.setCommandSigningInfo(keyChain, keyChain.getDefaultCertificateName());

    m_chat = new Chat
            (this,screenName, chatRoom, Name(hubPrefix), &face, keyChain,
             keyChain.getDefaultCertificateName());
    m_chat->start();
    /*ptr_lib::shared_ptr<Chat> chat(new Chat
      (screenName, chatRoom, Name(hubPrefix), face, keyChain,
       keyChain.getDefaultCertificateName()));
    chat->initialize();

    // The main loop to process Chat while checking stdin to send a message.
    cout << "Enter your chat message. To quit, enter \"\" or \"exit\"." << endl;
    while (true) {
      if (isStdinReady()) {
        string input = stdinReadLine();
        if (input == "leave" || input == "exit")
          // We will send the leave message below.
          break;
        m_chat->sendMessage(input);
        ui->Input_field->setText(QString::fromStdString(input));
        this->on_Send_clicked();
      }
        m_chat->sendMessage("test");
      face.processEvents();
      // We need to sleep for a few milliseconds so we don't use 100% of the CPU.
      usleep(10000);
    }

    // The user entered the command to leave.
    m_chat->leave();
    // Wait a little bit to allow other applications to fetch the leave message.
    ndn_MillisecondsSince1970 startTime = Chat::getNowMilliseconds();
    while (true)
    {
      if (Chat::getNowMilliseconds() - startTime >= 1000.0)
        break;

      face.processEvents();
      usleep(10000);
    }
  } catch (std::exception& e) {
    cout << "exception: " << e.what() << endl;
  }
  return 0;
}


*/
