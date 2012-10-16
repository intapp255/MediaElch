#ifndef THETVDBIMAGES_H
#define THETVDBIMAGES_H

#include <QObject>
#include "data/ImageProviderInterface.h"
#include "data/TvShow.h"
#include "data/TvShowEpisode.h"
#include "globals/Globals.h"
#include "scrapers/TheTvDb.h"

/**
 * @brief The TheTvDbImages class
 */
class TheTvDbImages : public ImageProviderInterface
{
    Q_OBJECT
public:
    explicit TheTvDbImages(QObject *parent = 0);
    QString name();
    void moviePosters(QString tmdbId);
    void movieBackdrops(QString tmdbId);
    void movieLogos(QString tmdbId);
    void movieClearArts(QString tmdbId);
    void movieCdArts(QString tmdbId);
    void concertPosters(QString tmdbId);
    void concertBackdrops(QString tmdbId);
    void concertLogos(QString tmdbId);
    void concertClearArts(QString tmdbId);
    void concertCdArts(QString tmdbId);
    void tvShowPosters(QString tvdbId);
    void tvShowBackdrops(QString tvdbId);
    void tvShowLogos(QString tvdbId);
    void tvShowClearArts(QString tvdbId);
    void tvShowCharacterArts(QString tvdbId);
    void tvShowBanners(QString tvdbId);
    void tvShowThumb(QString tvdbId, int season, int episode);
    void tvShowSeason(QString tvdbId, int season);
    QList<int> provides();

public slots:
    void searchMovie(QString searchStr, int limit = 0);
    void searchConcert(QString searchStr, int limit = 0);
    void searchTvShow(QString searchStr, int limit = 0);

signals:
    void sigSearchDone(QList<ScraperSearchResult>);
    void sigImagesLoaded(QList<Poster>);

private slots:
    void onSearchTvShowFinished(QList<ScraperSearchResult> results);
    void onLoadTvShowDataFinished();

private:
    QList<int> m_provides;
    int m_currentType;
    int m_searchResultLimit;
    TheTvDb *m_tvdb;
    TvShow *m_dummyShow;
    TvShowEpisode *m_dummyEpisode;
    int m_season;

    QList<Poster> parseTvShowData(QString json, int type);
    void loadTvShowData(QString tvdbId, int type);
};

#endif // THETVDBIMAGES_H
