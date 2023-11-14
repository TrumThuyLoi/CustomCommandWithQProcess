#include <QCoreApplication>

#include "CustomCommand.h"

void CustomCmdEx()
{
    CustomCommand cmd;
    cmd.action(QByteArray("ls"));
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CustomCommand cmd;
    cmd.action(QByteArray("ls"));

//    CustomCmdEx();

    return a.exec();
}
