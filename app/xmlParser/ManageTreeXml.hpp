#ifndef MANAGETREEXML_H
#define MANAGETREEXML_H
#include <QTreeWidget>
#include <QDomDocument>

class ManageTreeXml
{
public:
    ManageTreeXml();
struct PackageItem : public QObjectUserData {
    QString head;
    QString name;
    QString desc;
    QString id;
};
Q_DECLARE_METATYPE(PackageItem)

struct FieldItem : public QObjectUserData {
    QString desc;
    QString name;
    QString value;
    QString type;
};
Q_DECLARE_METATYPE(FieldItem)

    bool SaveTreeXml(QTreeWidget* pTree, QString xmlPath);
    bool LoadTreeXml(QTreeWidget* pTree, QString xmlPath);
private:
    bool showXml(QTreeWidget* pTree, QDomDocument *pDoc, bool bEditable);
    bool showXmlTreeNode(QTreeWidget* pTree, QDomNode domParent, QTreeWidgetItem *treeParent, bool bEditable);
    void setTreeNodeText(QDomNode Node, QTreeWidgetItem *treeNode);

    void SaveItem(QDomElement& root,QTreeWidgetItem* item,QDomDocument& doc);
};

#endif // MANAGETREEXML_H
