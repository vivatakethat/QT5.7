#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    bool isSaved; //为true时标志文件已经保存，为false时标志文件尚未保存
    QString curFile; //保存当前文件的文件名
    void do_file_New(); //新建文件
    void do_file_SaveOrNot(); //修改过的文件是否保存
    void do_file_Save(); //保存文件
    void do_file_SaveAs(); //文件另存为
    bool saveFile(const QString& fileName); //存储文件
    void do_file_Open(); //打开文件
    bool do_file_Load(const QString& fileName); //读取文件
private slots:
    void on_action_Past_triggered();
    void on_action_Copy_triggered();
    void on_action_Cut_triggered();
    void on_action_Undo_triggered();
    void on_action_Quit_triggered();
    void on_action_Close_triggered();
    void on_action_Open_triggered();
    void on_action_SaveAs_triggered();
    void on_action_Save_triggered();
    void on_action_New_triggered();
};

#endif // MAINWINDOW_H
