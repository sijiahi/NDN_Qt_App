#include "DlgTreeXml.hpp"
#include "ManageTreeXml.hpp"

DlgTreeXml::DlgTreeXml(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgTreeXml)
{
    ui->setupUi(this);

    QStringList qv;
    qv.push_back("标签");//qv.push_back("值");qv.push_back("名称");qv.push_back("索引");qv.push_back("类型");qv.push_back("长度");qv.push_back("描述");
    ui->treeWidget->setHeaderLabels(qv);
}

DlgTreeXml::~DlgTreeXml()
{
    delete ui;
}

void DlgTreeXml::on_btnLoadXml_clicked()
{
    LoadXml();
}

void DlgTreeXml::on_btnSaveXml_clicked()
{
    SaveXml();
}

bool DlgTreeXml::LoadXml()
{
    ManageTreeXml xml;
    xml.LoadTreeXml(ui->treeWidget, "D:/_work/scenePro/1.xml");
    return false;
}

bool DlgTreeXml::SaveXml()
{
    ManageTreeXml xml;
    xml.SaveTreeXml(ui->treeWidget, "D:/_work/scenePro/2.xml");
    return false;
}
