#include "CustomCommand.h"

CustomCommand::CustomCommand(QObject *parent) : QObject(parent)
{
    QSysInfo info;

    app = "bash";
    endl = "\n";

#ifdef Q_OS_WIN
    //Windows
    app = "powershell";
    endl = "\r\n";
#elif Q_OS_MACOS
    //Mac
    app = "zsh";
    endl = "\n";
#endif

    proc.setProgram(app);
    proc.start();
    qInfo() << "Start command" << proc.waitForStarted(1000);
    connect(&proc,&QProcess::readyRead, this, &CustomCommand::readyRead);
    connect(&proc,&QProcess::readyReadStandardOutput, this, &CustomCommand::readyRead);
    connect(&proc,&QProcess::readyReadStandardError, this, &CustomCommand::readyRead);
}

CustomCommand::~CustomCommand()
{
    if(proc.isOpen())
        proc.close();
}

void CustomCommand::readyRead()
{
    qint64 value = 0;
    do
    {
        QByteArray line = proc.readAll();
        qInfo() << line.trimmed();
        value = line.length();
    } while(value > 0);
}

void CustomCommand::action(QByteArray data)
{
    if(!data.endsWith(endl.toLatin1()))
        data.append(endl.toUtf8());

    proc.write(data);
    proc.waitForReadyRead(1000);
}
