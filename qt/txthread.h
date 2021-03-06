#ifndef TXTHREAD_H
#define TXTHREAD_H

#include <QThread>
#include <QObject>
#include "msgqueue.h"

class BitMail;

class TxThread : public QThread
{
    Q_OBJECT
public:
    TxThread(BitMail * bm);
    ~TxThread();
public:
    void run();
    void stop();
    void NotifyTxProgress(const QString & info);

signals:
    void messageSent(const QString & to
                     , const QString & msg);

    void done();

    void txProgress(const QString & info);

public slots:
    void onSendMessage(const QString & to
                       , const QString & msg);

    void onGroupMessage(const QStringList & to
                        , const QString & msg);
private:
    BitMail * m_bitmail;
    MsgQueue m_txq;
    bool m_fStopFlag;
};

#endif // TXTHREAD_H
