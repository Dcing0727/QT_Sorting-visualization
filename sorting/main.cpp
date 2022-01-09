#include "widget.h"
#include <QApplication>
#include "mywidget.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWidget mw;
    mw.setAutoFillBackground(true);// 充满
    QPalette palette;  //调色板
    QPixmap pixmap("://image/ui.jpg");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    mw.setPalette(palette);
    mw.show();

    return a.exec();
}
