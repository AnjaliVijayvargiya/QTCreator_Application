#include "mytexteditor.h"
#include "ui_mytexteditor.h"
#include <QTextStream>
#include <QFile>
#include <QMessageBox>
#include <QDesktopServices>
#include<QUrl>
#include<QPixmap>

MyTextEditor::MyTextEditor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyTextEditor)
{
    ui->setupUi(this);
    QMessageBox::about(this, tr("About MDI"),
                 tr("Loading my Notepad\n\n Basic Operations: \n 1. Bold \n 2. Italic \n 3. Underline \n 4. Superscript \n 5. Subscript \n 6. Show Text File \n 7. Show PDF "
                    "\n 8. Show Image \n 9. Load Image \n Enabling with some stylesheet"));
}

MyTextEditor::~MyTextEditor()
{
    delete ui;
}

void MyTextEditor::on_actionBold_triggered(bool checked)
{
    checked ? ui->textEdit->setFontWeight(QFont::Bold) :
              ui->textEdit->setFontWeight(QFont::Normal);
}

void MyTextEditor::on_actionItalic_triggered(bool italic)
{
    ui->textEdit->setFontItalic(italic);
}

void MyTextEditor::on_actionUnderline_triggered(bool underline)
{
    ui->textEdit->setFontUnderline(underline);
}

void MyTextEditor::on_actionSuperscript_triggered(bool super)
{
    const QTextCharFormat::VerticalAlignment align = super ?
                QTextCharFormat::AlignSuperScript : QTextCharFormat::AlignNormal;
    QTextCharFormat charFormat = ui->textEdit->currentCharFormat();
    charFormat.setVerticalAlignment(align);
    ui->textEdit->setCurrentCharFormat(charFormat);
}

void MyTextEditor::on_actionSubscript_triggered(bool sub)
{
    const QTextCharFormat::VerticalAlignment align = sub ?
                QTextCharFormat::AlignSubScript : QTextCharFormat::AlignNormal;
    QTextCharFormat charFormat = ui->textEdit->currentCharFormat();
    charFormat.setVerticalAlignment(align);
    ui->textEdit->setCurrentCharFormat(charFormat);
}

void MyTextEditor::on_pushButton_clicked()
{
    QString title = "About Me";
    QFile file(":/Images/data/aboutMe.html");
    QString description = "" ;
    if(file.open(QFile::ReadOnly | QFile::Text))
    {
        QTextStream in(&file);
        description = in.readAll();
        file.close();
    }
    QMessageBox msgBox;
    msgBox.information(this, title, description);
}

void MyTextEditor::on_pushButton_2_clicked()
{
    QString pdfFile="/home/anjali/Downloads/Text-Editor-Qt-master/data/page-1-converted.pdf";
    QDesktopServices::openUrl(QUrl::fromLocalFile(pdfFile));
}

void MyTextEditor::on_pushButton_3_clicked()
{
    QString imageFile="/home/anjali/Downloads/Text-Editor-Qt-master/data/page-1.jpeg";
    QDesktopServices::openUrl(QUrl::fromLocalFile(imageFile));
}

void MyTextEditor::on_pushButton_4_clicked()
{
    QPixmap m_logo_pic;
    m_logo_pic.load(":/Images/data/page-1.jpeg");;
    int w = ui->label->width ();
    int h = ui->label->height ();
    ui->label->setPixmap(m_logo_pic.scaled(w,h,Qt::KeepAspectRatio));
}

