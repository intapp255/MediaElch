#include "globals/ScraperInfos.h"

namespace mediaelch {

QString scraperInfoToTranslatedString(ShowScraperInfo info)
{
    ScraperInfoTranslation tr;
    return tr.toString(info);
}

QString scraperInfoToTranslatedString(EpisodeScraperInfo info)
{
    ScraperInfoTranslation tr;
    return tr.toString(info);
}

} // namespace mediaelch

ScraperInfoTranslation::ScraperInfoTranslation(QObject* parent) : QObject(parent)
{
}

ScraperInfoTranslation::~ScraperInfoTranslation()
{
}

QString ScraperInfoTranslation::toString(ShowScraperInfo info)
{
    switch (info) {
    case ShowScraperInfo::Invalid: return tr("Invalid");
    case ShowScraperInfo::Actors: return tr("Actors");
    case ShowScraperInfo::Banner: return tr("Banner");
    case ShowScraperInfo::Certification: return tr("Certification");
    case ShowScraperInfo::Fanart: return tr("Fanart");
    case ShowScraperInfo::FirstAired: return tr("First Aired");
    case ShowScraperInfo::Genres: return tr("Genres");
    case ShowScraperInfo::Network: return tr("Network");
    case ShowScraperInfo::Overview: return tr("Overview");
    case ShowScraperInfo::Poster: return tr("Poster");
    case ShowScraperInfo::Rating: return tr("Rating");
    case ShowScraperInfo::SeasonPoster: return tr("Season Poster");
    case ShowScraperInfo::Title: return tr("Title");
    case ShowScraperInfo::Tags: return tr("Tags");
    case ShowScraperInfo::ExtraArts: return tr("Extra Art");
    case ShowScraperInfo::SeasonBackdrop: return tr("Season Backdrop");
    case ShowScraperInfo::SeasonBanner: return tr("Season Banner");
    case ShowScraperInfo::ExtraFanarts: return tr("Extra Fanart");
    case ShowScraperInfo::Thumb: return tr("Show Thumbnail");
    case ShowScraperInfo::SeasonThumb: return tr("Season Thumbnail");
    case ShowScraperInfo::Runtime: return tr("Runtime");
    case ShowScraperInfo::Status: return tr("Status");

    // To be removed:
    case ShowScraperInfo::Thumbnail: return tr("Thumbnail");
    case ShowScraperInfo::Director: return tr("Director");
    case ShowScraperInfo::Writer: return tr("Writer");
    }
}

QString ScraperInfoTranslation::toString(EpisodeScraperInfo info)
{
    switch (info) {
    case EpisodeScraperInfo::Invalid: return tr("Invalid");
    case EpisodeScraperInfo::Actors: return tr("Actors");
    case EpisodeScraperInfo::Certification: return tr("Certification");
    case EpisodeScraperInfo::Director: return tr("Director");
    case EpisodeScraperInfo::FirstAired: return tr("First Aired");
    case EpisodeScraperInfo::Network: return tr("Network");
    case EpisodeScraperInfo::Overview: return tr("Overview");
    case EpisodeScraperInfo::Rating: return tr("Rating");
    case EpisodeScraperInfo::Thumbnail: return tr("Thumbnail");
    case EpisodeScraperInfo::Title: return tr("Title");
    case EpisodeScraperInfo::Writer: return tr("Writer");
    }
}
