#include "NetworkReplyWatcher.h"

#include <QDebug>

NetworkReplyWatcher::NetworkReplyWatcher(QObject *parent, QNetworkReply *reply) : QObject(parent), m_reply{nullptr}
{
    connect(&m_timer, &QTimer::timeout, this, &NetworkReplyWatcher::onTimeout);
    setReply(reply);
}

void NetworkReplyWatcher::setReply(QNetworkReply *reply)
{
    m_reply = reply;
    if (!m_reply) {
        return;
    }
    connect(m_reply, &QNetworkReply::finished, &m_timer, &QTimer::stop);
    connect(m_reply, &QObject::destroyed, this, &QObject::deleteLater);
    connect(m_reply, &QNetworkReply::downloadProgress, this, &NetworkReplyWatcher::onProgress);
    m_timer.start(3000);
}

void NetworkReplyWatcher::onTimeout()
{
    if (m_reply) {
        m_reply->abort();
    }
}

void NetworkReplyWatcher::onProgress()
{
    m_timer.start(3000);
}
