#ifndef CUSTOMCOMMAND_H
#define CUSTOMCOMMAND_H

#include <QObject>
#include <QDebug>
#include <QProcess>
#include <QSysInfo>

class CustomCommand : public QObject
{
    Q_OBJECT
public:
    explicit CustomCommand(QObject *parent = nullptr);
    ~CustomCommand();

signals:

public slots:
    void readyRead();
    void action(QByteArray data);

private:
    QProcess proc;
    QString app;
    QString endl;

};

#endif // CUSTOMCOMMAND_H
