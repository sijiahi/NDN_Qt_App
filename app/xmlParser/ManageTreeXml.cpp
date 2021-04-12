#include "ManageTreeXml.h"
#include <QStack>
#include <QFile>
#include <QDebug>

#define TREE_LINK_TYPE          "LINKPORT_TYPE"
#define TREE_PACKAGE_TYPE       "PACKAGE_TYPE"

ManageTreeXml::ManageTreeXml()
{
}

bool ManageTreeXml::SaveTreeXml(QTreeWidget *pTree, QString xmlPath)
{
    QDomDocument doc;
    QDomProcessingInstruction head = doc.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"UTF-8\"");
    doc.appendChild(head);
    //invisibleRootItem()函数并不是得到我们想要的这个顶层节点，它得到的是所有节点的最终根节点，因此，得到顶层节点需要自己写操作，下面是根据任意一个节点获取其可见顶层节点的代码
    QTreeWidgetItem *rootItem = pTree->invisibleRootItem(); //树的根节点
    QTreeWidgetItem* childItem = rootItem->child(0);

    QString strRoot;
    strRoot = childItem->text(0);
    QDomElement root = doc.createElement(strRoot);
    doc.appendChild(root);

    SaveItem(root, childItem, doc);

    QFile file(xmlPath);
    if (!file.open(QIODevice::WriteOnly)){
        return false;
    }
    QString xml = doc.toString();
    QTextStream txtOutput(&file);
    txtOutput.setCodec("UTF-8");
    txtOutput<<xml;
    file.close();

    return true;
}

bool ManageTreeXml::LoadTreeXml(QTreeWidget *pTree, QString xmlPath)
{
    pTree->clear();

    if(xmlPath.isEmpty())   return false;

    QDomDocument* doc = new QDomDocument;
    QFile fl(xmlPath);
    if(!doc->setContent(&fl)){
        fl.close();
        return false;
    }
    fl.close();

    showXml(pTree, doc,false);

    return false;
}

bool ManageTreeXml::showXml(QTreeWidget* pTree, QDomDocument* pDoc, bool bEditable)
{
    if(pDoc == NULL)    return false;

//    QDomNodeList RootLst =  pDoc->elementsByTagName(XML_ROOT);
//    QDomNode root = RootLst.item(0);

    QDomElement docElem = pDoc->documentElement();

    QTreeWidgetItem* it = new QTreeWidgetItem;
    if(bEditable){
        it->setFlags(Qt::ItemIsEditable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    }
//    qDebug() << root.toElement().tagName();
    it->setText(0 ,docElem.tagName());
    pTree->addTopLevelItem(it);

    showXmlTreeNode(pTree, docElem.firstChild() ,it, bEditable);

    pTree->expandAll();
    return true;
}

bool ManageTreeXml::showXmlTreeNode(QTreeWidget* pTree, QDomNode domParent ,QTreeWidgetItem* treeParent, bool bEditable)
{
    while(!domParent.isNull()){
        QTreeWidgetItem* it = new QTreeWidgetItem;
        if(bEditable){
            it->setFlags(Qt::ItemIsEditable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
        }
        setTreeNodeText(domParent ,it);
        treeParent->addChild(it);
        if(domParent.hasChildNodes()){
            showXmlTreeNode(pTree, domParent.firstChild() ,it, bEditable);
        }
        domParent = domParent.nextSibling();
    }
    return true;
}

void ManageTreeXml::setTreeNodeText(QDomNode Node ,QTreeWidgetItem* treeNode)
{
    if(treeNode == NULL)    return;

    treeNode->setText(0 ,Node.toElement().tagName());
//    qDebug() << "ItemText:" << Node.toElement().tagName();

    QString treeType = TREE_PACKAGE_TYPE;
    if(treeType == TREE_LINK_TYPE)
    {
//        treeNode->setText(1 ,Node.toElement().attribute("portName"));
//        treeNode->setText(2 ,Node.toElement().attribute("portDesc"));
//        treeNode->setText(3 ,Node.toElement().attribute("portType"));
//        treeNode->setText(4 ,Node.toElement().attribute("portIP"));
//        treeNode->setText(5 ,Node.toElement().attribute("portOrBaudRate"));
    }
    else if(treeType == TREE_PACKAGE_TYPE)
    {
//        treeNode->setText(1 ,Node.toElement().attribute("Value"));
//        treeNode->setText(2 ,Node.toElement().attribute("Name"));
//        treeNode->setText(3 ,Node.toElement().attribute("Index"));
//        treeNode->setText(4 ,Node.toElement().attribute("Type"));
//        treeNode->setText(5 ,Node.toElement().attribute("Len"));
//        treeNode->setText(6 ,Node.toElement().attribute("Desc"));
    }
}


void ManageTreeXml::SaveItem(QDomElement& root, QTreeWidgetItem *item, QDomDocument& doc)
{
    int countChild = item->childCount();
    for (int i = 0; i < countChild; i++)
    {
        QTreeWidgetItem *childItem = item->child(i);
        QString itemTxt = childItem->text(0);
        QDomElement ele = doc.createElement(itemTxt);
        root.appendChild(ele);

        SaveItem(ele,childItem,doc);
    }
}
