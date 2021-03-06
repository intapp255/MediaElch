#pragma once

#include "tv_shows/TvShowEpisode.h"

#include <QJsonObject>
#include <QString>
#include <QVector>

namespace thetvdb {

class EpisodeParser
{
public:
    EpisodeParser(TvShowEpisode& episode, QSet<ShowScraperInfo> infosToLoad) :
        m_episode{episode}, m_infosToLoad{infosToLoad}
    {
    }

    void parseInfos(const QString& json);
    void parseInfos(const QJsonObject& episodeObj);
    void parseIdFromSeason(const QString& json);

private:
    TvShowEpisode& m_episode;
    QSet<ShowScraperInfo> m_infosToLoad;
};

} // namespace thetvdb
