#ifndef MYTEXTEDITOR_H
#define MYTEXTEDITOR_H

#include <QMainWindow>

namespace Ui {
class MyTextEditor;
}

class MyTextEditor : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyTextEditor(QWidget *parent = 0);
    ~MyTextEditor();

private slots:
    void on_actionBold_triggered(bool checked);

    void on_actionItalic_triggered(bool checked);

    void on_actionUnderline_triggered(bool checked);

    void on_actionSuperscript_triggered(bool checked);

    void on_actionSubscript_triggered(bool checked);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MyTextEditor *ui;
};

#endif // MYTEXTEDITOR_H
