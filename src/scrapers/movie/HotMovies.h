#pragma once

#include "scrapers/movie/MovieScraperInterface.h"

#include <QComboBox>
#include <QNetworkAccessManager>
#include <QObject>
#include <QWidget>

class HotMovies : public MovieScraperInterface
{
    Q_OBJECT
public:
    explicit HotMovies(QObject* parent = nullptr);
    static constexpr const char* scraperIdentifier = "hotmovies";

    QString name() const override;
    QString identifier() const override;
    void search(QString searchStr) override;
    void loadData(QHash<MovieScraperInterface*, QString> ids, Movie* movie, QSet<MovieScraperInfo> infos) override;
    bool hasSettings() const override;
    void loadSettings(ScraperSettings& settings) override;
    void saveSettings(ScraperSettings& settings) override;
    QSet<MovieScraperInfo> scraperSupports() override;
    QSet<MovieScraperInfo> scraperNativelySupports() override;
    QVector<mediaelch::Locale> supportedLanguages() override;
    void changeLanguage(mediaelch::Locale locale) override;
    mediaelch::Locale defaultLanguage() override;
    QWidget* settingsWidget() override;
    bool isAdult() const override;

private slots:
    void onSearchFinished();
    void onLoadFinished();

private:
    QNetworkAccessManager m_qnam;
    QSet<MovieScraperInfo> m_scraperSupports;

    QNetworkAccessManager* qnam();
    QVector<ScraperSearchResult> parseSearch(QString html);
    void parseAndAssignInfos(QString html, Movie* movie, QSet<MovieScraperInfo> infos);
};
