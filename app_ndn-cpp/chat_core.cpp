#include "chat_core.h"



void
Chat::initialize()
  {
    int sessionNo = (int)::round(getNowMilliseconds()  / 1000.0);
    ostringstream tempStream;
    tempStream << screenName_ << sessionNo;
    userName_ = tempStream.str();
<<<<<<< HEAD
    //Using ChronoSync to ensure syncing processs
=======

>>>>>>> 73f85cd88c469ec05166c7729fca0f5d72976c7b
    sync_.reset(new ChronoSync2013
      (bind(&Chat::sendInterest, this, _1, _2),
       bind(&Chat::initial, this), chatPrefix_,
       Name("/ndn/broadcast/ChronoChat-0.3").append(chatRoom_), sessionNo,
       *face_, keyChain, certificateName_, syncLifetime_, &Chat::onRegisterFailed));

    // TODO: After we remove the registerPrefix with the deprecated OnInterest,
    // we can remove the explicit cast to OnInterestCallback (needed for boost).
    //face_.registerPrefix
    face_->registerPrefix
      (chatPrefix_, (const OnInterestCallback&)bind(&Chat::onInterest, this, _1, _2, _3, _4, _5),
       onRegisterFailed);
  }
void
Chat::run(){
    isRunning = true;
    //this->initialize();
<<<<<<< HEAD
//TODO:Register chat prefix
    ostringstream uri;
    uri << "/local/advertise"<<chatPrefix_;
    Interest interest(uri.str());
    interest.setInterestLifetimeMilliseconds(syncLifetime_);
    std::cout<<"sending interest"<<uri.str()<<std::endl;
    face_->expressInterest
      (interest, dummyOnData,
       nullptr);
    do{
    try{
    //std::cout<<"Initializing"<<std::endl;
=======
    do{
    try{
    //std::cout<<"Initializing"<<std::endl;

>>>>>>> 73f85cd88c469ec05166c7729fca0f5d72976c7b
    face_->processEvents();
    //std::cout<<"sleep"<<std::endl;
    usleep(100000);
    }
    catch (std::exception& e) {
      isRunning = false;
      std::cerr << "Exception thrown:" << e.what() << std::endl;
      //return false;
    }
    }while(isRunning = true);
}
void
Chat::initial()
{
  // Set the heartbeat timeout using the Interest timeout mechanism. The
  // heartbeat() function will call itself again after a timeout.
  // TODO: Are we sure using a "/local/timeout" interest is the best future call approach?
  Interest timeout("/local/timeout");
  timeout.setInterestLifetimeMilliseconds(60000);
  //face_.expressInterest(timeout, dummyOnData, bind(&Chat::heartbeat, this, _1));
face_->expressInterest(timeout, dummyOnData, bind(&Chat::heartbeat, this, _1));
  if (rosterFind(userName_) < 0) {
    roster_.push_back(userName_);
    cout << "Member: " << screenName_ << endl;
    cout << screenName_ << ": Join" << endl;
    messageCacheAppend(SyncDemo::ChatMessage_ChatMessageType_JOIN, "xxx");
  }
}

void
Chat::sendInterest
  (const vector<ChronoSync2013::SyncState>& syncStates, bool isRecovery)
{
  // This is used by onData to decide whether to display the chat messages.
  isRecoverySyncState_ = isRecovery;

  vector<string> sendList;
  vector<int> sessionNoList;
  vector<int> sequenceNoList;
  for (size_t j = 0; j < syncStates.size(); ++j) {
    Name nameComponents(syncStates[j].getDataPrefix());
    string tempName = nameComponents.get(-1).toEscapedString();
    int sessionNo = syncStates[j].getSessionNo();
    if (tempName != screenName_) {
      int index = -1;
      for (size_t k = 0; k < sendList.size(); ++k) {
        if (sendList[k] == syncStates[j].getDataPrefix()) {
          index = k;
          break;
        }
      }
      if (index != -1) {
        sessionNoList[index] = sessionNo;
        sequenceNoList[index] = syncStates[j].getSequenceNo();
      }
      else{
        sendList.push_back(syncStates[j].getDataPrefix());
        sessionNoList.push_back(sessionNo);
        sequenceNoList.push_back(syncStates[j].getSequenceNo());
      }
    }
  }

  for (size_t i = 0; i < sendList.size(); ++i) {
    ostringstream uri;
    uri << sendList[i] << "/" << sessionNoList[i] << "/" << sequenceNoList[i];
    Interest interest(uri.str());
    interest.setInterestLifetimeMilliseconds(syncLifetime_);
    face_->expressInterest
      (interest, bind(&Chat::onData, this, _1, _2),
       bind(&Chat::chatTimeout, this, _1));
  }
}

void
Chat::onInterest
  (const ptr_lib::shared_ptr<const Name>& prefix,
   const ptr_lib::shared_ptr<const Interest>& interest, Face& face,
   uint64_t interestFilterId,
   const ptr_lib::shared_ptr<const InterestFilter>& filter)
{
  SyncDemo::ChatMessage content;
  int sequenceNo = ::atoi(interest->getName().get(chatPrefix_.size() + 1).toEscapedString().c_str());
  for (int i = messageCache_.size() - 1; i >= 0; --i) {
    if (messageCache_[i]->getSequenceNo() == sequenceNo) {
      if (messageCache_[i]->getMessageType() != SyncDemo::ChatMessage_ChatMessageType_CHAT) {
        content.set_from(screenName_);
        content.set_to(chatRoom_);
        content.set_type((SyncDemo::ChatMessage_ChatMessageType)messageCache_[i]->getMessageType());
        content.set_timestamp(::round(messageCache_[i]->getTime() / 1000.0));
      }
      else {
        content.set_from(screenName_);
        content.set_to(chatRoom_);
        content.set_type((SyncDemo::ChatMessage_ChatMessageType)messageCache_[i]->getMessageType());
        content.set_data(messageCache_[i]->getMessage());
        content.set_timestamp(::round(messageCache_[i]->getTime() / 1000.0));
      }
      break;
    }
  }

  if (content.from().size() != 0) {
    ptr_lib::shared_ptr<vector<uint8_t> > array(new vector<uint8_t>(content.ByteSize()));
    content.SerializeToArray(&array->front(), array->size());
    Data data(interest->getName());
    data.setContent(Blob(array, false));
    keyChain.sign(data, certificateName_);
    try {
      face.putData(data);
    }
    catch (std::exception& e) {
      cout << "Error sending the chat data " << e.what() << endl;
    }
  }
}

void
Chat::onData
  (const ptr_lib::shared_ptr<const Interest>& interest,
   const ptr_lib::shared_ptr<Data>& data)
{
  SyncDemo::ChatMessage content;
  content.ParseFromArray(data->getContent().buf(), data->getContent().size());
  if (getNowMilliseconds() - content.timestamp() * 1000.0 < 120000.0) {
    string name = content.from();
    string prefix = data->getName().getPrefix(-2).toUri();
    int sessionNo = ::atoi(data->getName().get(-2).toEscapedString().c_str());
    int sequenceNo = ::atoi(data->getName().get(-1).toEscapedString().c_str());
    ostringstream tempStream;
    tempStream << name << sessionNo;
    string nameAndSession = tempStream.str();

    size_t l = 0;
    //update roster
    while (l < roster_.size()) {
      string tempName2 = roster_[l].substr(0, roster_[l].size() - 10);
      int tempSessionNo = ::atoi(roster_[l].substr(roster_[l].size() - 10, 10).c_str());
      if (name != tempName2 && content.type() != SyncDemo::ChatMessage_ChatMessageType_LEAVE)
        ++l;
      else {
        if (name == tempName2 && sessionNo > tempSessionNo)
          roster_[l] = nameAndSession;
        break;
      }
    }

    if (l == roster_.size()) {
      roster_.push_back(nameAndSession);
<<<<<<< HEAD
//Emitting intro signal
      emit addUser(QString::fromStdString(name));
    }

    // Set the alive timeout using the Interest timeout mechanism.
    // O: Are we sure using a "/local/timeout" interest is the best future call approach?
=======
      cout << name << ": Join" << endl;
    }

    // Set the alive timeout using the Interest timeout mechanism.
    // TODO: Are we sure using a "/local/timeout" interest is the best future call approach?
>>>>>>> 73f85cd88c469ec05166c7729fca0f5d72976c7b
    Interest timeout("/local/timeout");
    timeout.setInterestLifetimeMilliseconds(120000);
    face_->expressInterest
      (timeout, dummyOnData,
       bind(&Chat::alive, this, _1, sequenceNo, name, sessionNo, prefix));

    // isRecoverySyncState_ was set by sendInterest.
    // TODO: If isRecoverySyncState_ changed, this assumes that we won't get
    //   data from an interest sent before it changed.
    if (content.type() == SyncDemo::ChatMessage_ChatMessageType_CHAT &&
            !isRecoverySyncState_ && content.from() != screenName_){
<<<<<<< HEAD
=======
      cout << content.from() << ": " << content.data() << endl;
>>>>>>> 73f85cd88c469ec05166c7729fca0f5d72976c7b
       emit chatDataReceived(QString::fromStdString(content.from()),QString::fromStdString(content.data()));
    }
    else if (content.type() == SyncDemo::ChatMessage_ChatMessageType_LEAVE) {
      // leave message
      int n = rosterFind(nameAndSession);
      if (n >= 0 && name != screenName_) {
        roster_.erase(roster_.begin() + n);
<<<<<<< HEAD
        //# Emitting leave data
        emit removeUser(QString::fromStdString(name));
=======
        cout << name << ": Leave" << endl;
>>>>>>> 73f85cd88c469ec05166c7729fca0f5d72976c7b
      }
    }
  }
}

void
Chat::chatTimeout(const ptr_lib::shared_ptr<const Interest>& interest)
{
  cout << "Timeout waiting for chat data" << endl;
}

void
Chat::heartbeat(const ptr_lib::shared_ptr<const Interest> &interest)
{
  if (messageCache_.size() == 0)
    messageCacheAppend(SyncDemo::ChatMessage_ChatMessageType_JOIN, "xxx");

  sync_->publishNextSequenceNo();
  messageCacheAppend(SyncDemo::ChatMessage_ChatMessageType_HELLO, "xxx");

  // Call again.
  // TODO: Are we sure using a "/local/timeout" interest is the best future call approach?
  Interest timeout("/local/timeout");
  timeout.setInterestLifetimeMilliseconds(60000);
  face_->expressInterest(timeout, dummyOnData, bind(&Chat::heartbeat, this, _1));
}

void
Chat::sendMessage(const string& chatMessage)
{
  if (messageCache_.size() == 0)
    messageCacheAppend(SyncDemo::ChatMessage_ChatMessageType_JOIN, "xxx");

  // Ignore an empty message.
  // forming Sync Data Packet.
  if (chatMessage != "") {
    sync_->publishNextSequenceNo();
    messageCacheAppend(SyncDemo::ChatMessage_ChatMessageType_CHAT, chatMessage);
    cout << screenName_ << ": " << chatMessage << endl;
  }
}

void
Chat::leave()
{
<<<<<<< HEAD
    ostringstream uri;
    uri << "/local/advertise/leave"<<chatPrefix_;
    Interest interest(uri.str());
    interest.setInterestLifetimeMilliseconds(syncLifetime_);
    std::cout<<"sending interest"<<uri.str()<<std::endl;
    face_->expressInterest
      (interest, dummyOnData,
       nullptr);
  sync_->publishNextSequenceNo();
  messageCacheAppend(SyncDemo::ChatMessage_ChatMessageType_LEAVE, "xxx");
  usleep(1000000);
  emit leaveNow();
=======
  sync_->publishNextSequenceNo();
  messageCacheAppend(SyncDemo::ChatMessage_ChatMessageType_LEAVE, "xxx");
>>>>>>> 73f85cd88c469ec05166c7729fca0f5d72976c7b
}

void
Chat::alive
  (const ptr_lib::shared_ptr<const Interest> &interest, int tempSequenceNo,
   const string& name, int sessionNo, const string& prefix)
{
  int sequenceNo = sync_->getProducerSequenceNo(prefix, sessionNo);
  ostringstream tempStream;
  tempStream << name << sessionNo;
  string nameAndSession = tempStream.str();
  int n = rosterFind(nameAndSession);
  if (sequenceNo != -1 && n >= 0) {
    if (tempSequenceNo == sequenceNo){
      roster_.erase(roster_.begin() + n);
      cout << name << ": Leave" << endl;
    }
  }
}
<<<<<<< HEAD
=======
#include <QDebug>
>>>>>>> 73f85cd88c469ec05166c7729fca0f5d72976c7b
void
Chat::messageCacheAppend(int messageType, const string& message)
{
  messageCache_.push_back(ptr_lib::make_shared<CachedMessage>
    (sync_->getSequenceNo(), messageType, message, getNowMilliseconds()));

auto temp=messageCache_.size();

while (messageCache_.size() > maxMessageCacheLength_)
    messageCache_.erase(messageCache_.begin());
}

int
Chat::rosterFind(const string& nameAndSession)
{
  for (size_t i = 0; i < roster_.size(); ++i) {
    if (roster_[i] == nameAndSession)
      return i;
  }

  return -1;
}

string
Chat::getRandomString()
{
<<<<<<< HEAD
  string seed("buaaklbnt2021sijiapresent");
=======
  string seed("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM0123456789");
>>>>>>> 73f85cd88c469ec05166c7729fca0f5d72976c7b
  string result;
  uint8_t random[10];
  CryptoLite::generateRandomBytes(random, sizeof(random));
  for (int i = 0; i < 10; ++i) {
      // Using % means the distribution isn't uniform, but that's OK.
    size_t pos = (size_t)random[i] % seed.size();
    result += seed[pos];
  }

  return result;
}

void
Chat::onRegisterFailed(const ptr_lib::shared_ptr<const Name>& prefix)
{
  cout << "Register failed for prefix " << prefix->toUri() << endl;
}

MillisecondsSince1970
Chat::getNowMilliseconds()
{
  struct timeval t;
  // Note: configure.ac requires gettimeofday.
  gettimeofday(&t, 0);
  return t.tv_sec * 1000.0 + t.tv_usec / 1000.0;
}

void
Chat::dummyOnData
  (const ptr_lib::shared_ptr<const Interest>& interest,
   const ptr_lib::shared_ptr<Data>& data)
{
<<<<<<< HEAD

=======
}



int chatDebug(int argc, char** argv)
{
  try {
    // Silence the warning from Interest wire encode.
    Interest::setDefaultCanBePrefix(true);

    cout << "Enter your chat username:" << endl;
    //string screenName = stdinReadLine();
    string screenName ="";
    string defaultHubPrefix = "ndn/edu/ucla/remap";
    cout << "Enter your hub prefix [" << defaultHubPrefix << "]" << endl;
    //string hubPrefix = stdinReadLine();
    string hubPrefix = "";
    if (hubPrefix == "")
      hubPrefix = defaultHubPrefix;

    string defaultChatRoom = "ndnchat";
    cout << "Enter the chatroom name [" << defaultChatRoom << "]:" << endl;
    //string chatRoom = stdinReadLine();
    string chatRoom = "";
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

    Chat* m_chat = new Chat
            (nullptr,screenName, chatRoom, Name(hubPrefix), &face, keyChain,
             keyChain.getDefaultCertificateName());
    m_chat->initialize();
m_chat->sendMessage("input");
face.processEvents();
    // The main loop to process Chat while checking stdin to send a message.
    cout << "Enter your chat message. To quit, enter \"leave\" or \"exit\"." << endl;
    while (true) {
      if (isStdinReady()) {
        string input = stdinReadLine();
        if (input == "leave" || input == "exit")
          // We will send the leave message below.
          break;

        m_chat->sendMessage(input);

      }

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
>>>>>>> 73f85cd88c469ec05166c7729fca0f5d72976c7b
}

