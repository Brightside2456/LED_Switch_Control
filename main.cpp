#include "dialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();
    w.setMaximumSize(550, 300);
    w.setWindowTitle("Switch Control");
    return a.exec();


}
