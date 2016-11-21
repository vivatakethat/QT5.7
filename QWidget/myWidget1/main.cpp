//#include <QtGui>

#include <QtWidgets>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //新建QWidget类对象，默认parent参数是0，所以它是一个窗口
    QWidget * widget=new QWidget();
     //设置标题
    widget->setWindowTitle(QObject::tr("I'm a  label"));
    // label2指定了父窗口为widget，所以不是窗口.
      QLabel *label2 = new QLabel(widget);
   label2->setText(QObject::tr("label2:i'm not depart windows,i'm just widget part"));
   label2->resize(250,100);//改变窗口大小；void resize(int w, int h)
/******************************************************************************************/
   // 新建QLabel对象，默认parent参数是0，所以它是个窗口
   QLabel *label = new QLabel();
  // 设置窗口标题
   label->setWindowTitle(QObject::tr("I'm a Windows!"));
   // 设置要显示的信息
    label->setText(QObject::tr("show what your want!"));
    label->resize(250,100);
/******************************************************************************************/

    // 在屏幕上显示出来
    widget->show();  //代码中有多少个widget就要show多少个
    label->show();
/******************************************************************************************/
    int ret = a.exec();
 /*
   * 这里使用new操作符为label2分配了空间,但是并没有使用delete进行释放，
   * 这是因为QT在销毁父对象的时候也会自动销毁自独享
 */
    delete label;
    delete widget;
    return ret;
}

