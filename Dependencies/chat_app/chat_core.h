#ifndef CHAT_CORE_H
#define CHAT_CORE_H

#include <QObject>
#include "common.h"
#include <QThread>


class Chat : public QThread
{
    Q_OBJECT
public:
    //explicit chat_core(QObject *parent = nullptr);
    explicit Chat
    (QObject *parent,const string& screenName, const string& chatRoom,
     const Name& hubPrefix, Face* face, KeyChain keyChain,
     const Name& certificateName)
    : QThread(parent),screenName_(screenName), chatRoom_(chatRoom), maxMessageCacheLength_(100),
      isRecoverySyncState_(true), syncLifetime_(5000.0), face_(face),
      keyChain(keyChain), certificateName_(certificateName)
    {
    // This should only be called once, so get the random string here.
    isRunning = false;
    chatPrefix_ = Name(hubPrefix).append(chatRoom_).append(Chat::getRandomString());
    }
    void
    initialize();
    // Send a chat message.
    void
    sendMessage(const string& chatmsg);

    // Send leave message and leave.
    void
    leave();  /**
     * Use gettimeofday to return the current time in milliseconds.
     * @return The current time in milliseconds since 1/1/1970, including fractions
     * of a millisecond according to timeval.tv_usec.
     */
    static MillisecondsSince1970
    getNowMilliseconds();
protected:
    void run();
private:
    // Initialization: push the JOIN message in to the messageCache_, update roster and start heartbeat.
    void
    initial();

    // Send a Chat Interest to fetch chat messages after get the user gets the Sync data packet back but will not send interest.
    void
    sendInterest
      (const vector<ChronoSync2013::SyncState>& syncStates, bool isRecovery);

    // Send back Chat Data Packet which contains the user's message.
    void
    onInterest
      (const ptr_lib::shared_ptr<const Name>& prefix,
       const ptr_lib::shared_ptr<const Interest>& interest, Face& face,
       uint64_t interestFilterId,
       const ptr_lib::shared_ptr<const InterestFilter>& filter);

    // Processing the incoming Chat data.
    void
    onData
      (const ptr_lib::shared_ptr<const Interest>& interest,
       const ptr_lib::shared_ptr<Data>& data);

    void
    chatTimeout(const ptr_lib::shared_ptr<const Interest>& interest);

    /**
     * This repeatedly calls itself after a timeout to send a heartbeat message
     * (chat message type HELLO).
     * This method has an "interest" argument because we use it as the onTimeout
     * for Face.expressInterest.
     */
    void
    heartbeat(const ptr_lib::shared_ptr<const Interest> &interest);

    /**
     * This is called after a timeout to check if the user with prefix has a newer
     * sequence number than the given tempSequenceNo. If not, assume the user is idle and
     * remove from the roster and print a leave message.
     * This method has an "interest" argument because we use it as the onTimeout
     * for Face.expressInterest.
     */
    void
    alive
      (const ptr_lib::shared_ptr<const Interest> &interest, int tempSequenceNo,
       const string& name, int sessionNo, const string& prefix);

    /**
     * Append a new CachedMessage to messageCache_, using given messageType and message,
     * the sequence number from sync_->getSequenceNo() and the current time. Also
     * remove elements from the front of the cache as needed to keep
     * the size to maxMessageCacheLength_.
     */
    void
    messageCacheAppend(int messageType, const string& message);

    /**
     * Search for an entry in the roster_.
     * @param nameAndSession The entry to search for.
     * @return The index on roster_, or -1 if not found.
     */
    int
    rosterFind(const string& nameAndSession);

    // Generate a random name for ChronoSync.
    static string
    getRandomString();

    static void
    onRegisterFailed(const ptr_lib::shared_ptr<const Name>& prefix);

    /**
     * This is a do-nothing onData for using expressInterest for timeouts.
     * This should never be called.
     */
    static void
    dummyOnData
      (const ptr_lib::shared_ptr<const Interest>& interest,
       const ptr_lib::shared_ptr<Data>& data);



    class CachedMessage {
    public:
      CachedMessage
        (int sequenceNo, int messageType, const string& message, MillisecondsSince1970 time)
      : sequenceNo_(sequenceNo), messageType_(messageType), message_(message), time_(time)
      {}

      int
      getSequenceNo() const { return sequenceNo_; }

      int
      getMessageType() const { return messageType_; }

      const string&
      getMessage() const { return message_; }

      MillisecondsSince1970
      getTime() const { return time_; }

    private:
      int sequenceNo_;
      // This is really enum SyncDemo::ChatMessage_ChatMessageType, but make it
      //   in int so that the head doesn't need to include the protobuf header.
      int messageType_;
      string message_;
      MillisecondsSince1970 time_;
    };


  vector<ptr_lib::shared_ptr<CachedMessage> > messageCache_;
  vector<string> roster_;
  size_t maxMessageCacheLength_;
  bool isRecoverySyncState_;
  string screenName_;
  string chatRoom_;
  string userName_;
  Name chatPrefix_;
  Milliseconds syncLifetime_;
  ptr_lib::shared_ptr<ChronoSync2013> sync_;
  Face *face_;
  //ptr_lib::shared_ptr<Face> face_;
  KeyChain keyChain;
  Name certificateName_;
  bool isRunning;
signals:
    void chatDataReceived(const QString& from,const QString& content);
    //New session
    void addUser(const QString& from);
    void removeUser(const QString& from);
    void leftDataReceived(const QString& from,const QString& content);
    void leaveNow();
public slots:
};




#endif // CHAT_CORE_H
