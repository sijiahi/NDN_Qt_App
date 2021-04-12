#ifndef REPO_GETFILE_H
#define REPO_GETFILE_H


#include <ndn-cxx/data.hpp>
#include <ndn-cxx/face.hpp>
#include <ndn-cxx/interest.hpp>

#include <fstream>
#include <iostream>
#include <unistd.h>


#include <messager.h>

#include <boost/lexical_cast.hpp>

#include <QObject>
#include <QInputDialog>
#include<QLineEdit>

namespace repo {

using ndn::Name;
using ndn::Interest;
using ndn::Data;


static int getfile();

class repo_getfile : public QObject
{
        Q_OBJECT

public:
repo_getfile(std::ostream& os)
        : //m_dataName(dataName)
         m_os(os)
        , m_verbose(true)
        , m_hasVersion(true)
        , m_isSingle(true)
        , m_isFinished(false)
        , m_isFirst(true)
        , m_interestLifetime(4000)
        , m_timeout(0)
        , m_nextSegment(0)
        , m_totalSize(0)
        , m_retryCount(0)
        , m_mustBeFresh(false)
        , m_canBePrefix(true)
        , messager(nullptr)
      {

      }

      void
      initMessager();
      void
      run();
     Messager* messager;

    private:
      void
      fetchData(const ndn::Name& name);

      void
      onVersionedData(const ndn::Interest& interest, const ndn::Data& data);

      void
      onUnversionedData(const ndn::Interest& interest, const ndn::Data& data);

      void
      onTimeout(const ndn::Interest& interest);

      void
      readData(const ndn::Data& data);

      void
      fetchNextData(const ndn::Name& name, const ndn::Data& data);

    private:
      ndn::Face m_face;
      ndn::Name m_dataName;
      std::ostream& m_os;
      bool m_verbose;
      bool m_hasVersion;
      bool m_isSingle;
      bool m_isFinished;
      bool m_isFirst;
      ndn::time::milliseconds m_interestLifetime;
      ndn::time::milliseconds m_timeout;
      uint64_t m_nextSegment;
      int m_totalSize;
      int m_retryCount;
      bool m_mustBeFresh;
      bool m_canBePrefix;

      static constexpr int MAX_RETRY = 3;
    };
static int
getfile()
{

    std::streambuf* buf;
    std::ofstream of;
    const char* outputFile = nullptr;
    std::string filename;
    std::string name;
    Messager messager;
    messager.setWindowTitle("Get file");
    messager.addMessage("Start Getting file");
    messager.show();
    bool nameset = false;
    while(!nameset){
    name = QInputDialog::getText(NULL, "ndnPrefix: dataPrefix",
                                                       "Please Enter dataPrefix",
                                                       QLineEdit::Normal,
                                                       "/sijiahi/hello",
                                                       &nameset).toStdString();
    }
    messager.addMessage(QString::fromStdString("\nSetting data Prefix: "+name));

    nameset = false;
    while(!nameset){
    filename = QInputDialog::getText(NULL, "Saving new file",
                                                       "Please Enter new filename",
                                                       QLineEdit::Normal,
                                                       "",
                                                       &nameset).toStdString();
    }
    messager.addMessage(QString::fromStdString("\nRetrieving file to: "+filename));
    outputFile = filename.c_str();
    if (outputFile != nullptr) {

      of.open(outputFile, std::ios::out | std::ios::binary | std::ios::trunc);
      if (!of || !of.is_open()) {
        std::cerr << "ERROR: cannot open " << outputFile << std::endl;
        return 2;
      }
      buf = of.rdbuf();
    }
    else {
      buf = std::cout.rdbuf();
    }
  std::ostream os(buf);
  repo_getfile repo_getfile(os);
  repo_getfile.messager = &messager;
  try {
    repo_getfile.run();
  }
  catch (const std::exception& e) {
    std::cerr << "ERROR: " << e.what() << std::endl;
    return 1;
  }
  return 0;
}
} //repo

#endif // REPO_PUTFILE_H
