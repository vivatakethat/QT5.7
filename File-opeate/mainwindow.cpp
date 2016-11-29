#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    isSaved = false; //初始化文件为未保存过状态
    curFile = tr("Without name.txt"); //初始化文件名为“未命名.txt”
    setWindowTitle(curFile); //初始化主窗口的标题
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::do_file_New() //实现新建文件的功能
{
    do_file_SaveOrNot();
    isSaved = false;
    curFile = tr("withouname.txt");
    setWindowTitle(curFile);
    ui->textEdit->clear();//清空文本编辑器
    ui->textEdit->setVisible(true); //文本编辑器可见
}

void MainWindow::do_file_SaveOrNot()//弹出是否保存文件对话框
{
    if(ui->textEdit->document()->isModified())//如果文件被更改过，弹出保存对话框
    {
        QMessageBox box;
        box.setWindowTitle(tr("Waring"));
        box.setIcon(QMessageBox::Warning);
        box.setText(curFile+tr("Doesn't save,need save?"));
        box.setStandardButtons(QMessageBox::Yes|QMessageBox::No);
        if(box.exec()==QMessageBox::Yes)
            do_file_Save();
    }
}

void MainWindow::do_file_Save()  //保存文件
{
    if(isSaved){          //如果文件已经被保存过，直接保存文件
        saveFile(curFile);
    }
    else{
        do_file_SaveAs();   //如果文件是第一次保存，那么调用另存为
    }
}

void MainWindow::do_file_SaveAs()
{
    QString fileName=QFileDialog::getSaveFileName(this,tr("另存为"),curFile);
    if(!fileName.isEmpty())
    {
        saveFile(fileName);
    }
}

bool MainWindow::saveFile(const QString &fileName)
{
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly|QFile::Text))//以只写方式打开文件，如果打开失败则弹出提示框并返回
    {
        QMessageBox::warning(this,tr("Save file"),tr("Cannot save file %1:\n %2").arg(fileName).arg(file.errorString()));
        //%1,%2表示后面的两个arg参数的值
        return false;
    }
    QTextStream out(&file);
    out<<ui->textEdit->toPlainText();//将文本编辑器里的内容以纯文本的形式输出到流对象中
    isSaved = true;
    curFile = QFileInfo(fileName).canonicalFilePath(); //获得文件的标准路径
    setWindowTitle(curFile);
    return true;
}


void MainWindow::on_action_New_triggered()
{
    do_file_New();
}

void MainWindow::on_action_Save_triggered()
{
    do_file_Save();
}

void MainWindow::on_action_SaveAs_triggered()
{
    do_file_SaveAs();
}

void MainWindow::do_file_Open()
{
    do_file_SaveOrNot();
    QString fileName = QFileDialog::getOpenFileName(this);
    if(!fileName.isEmpty())
    {
        do_file_Load(fileName);
    }
    ui->textEdit->setVisible(true);
}

bool MainWindow::do_file_Load(const QString &fileName)
{
    QFile file(fileName);
    if(!file.open(QFile::ReadOnly|QFile::Text))
    {
        QMessageBox::warning(this,tr("Read file"),tr("Cannot read file' %1:\n%2.").arg(fileName).arg(file.errorString()));
        return false;
    }
    QTextStream in(&file);
    ui->textEdit->setText(in.readAll()); //将文件中的所有内容都写到文本编辑器中
    curFile = QFileInfo(fileName).canonicalFilePath();
    setWindowTitle(curFile);
    return true;
}

void MainWindow::on_action_Open_triggered()
{
    do_file_Open();
}

void MainWindow::on_action_Close_triggered()
{
    do_file_SaveOrNot();
    ui->textEdit->setVisible(false);
}

void MainWindow::on_action_Quit_triggered()
{
    on_action_Close_triggered(); //先执行关闭操作
    qApp->quit(); //再退出系统，qApp是指向应用程序的全局指针
}

void MainWindow::on_action_Undo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_action_Cut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_action_Copy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_action_Past_triggered()
{
    ui->textEdit->paste();
}
