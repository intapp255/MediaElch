#include "NameFormatter.h"
#include "settings/Settings.h"

#include <QRegExp>
#include <QStringList>

NameFormatter *NameFormatter::m_instance = 0;

NameFormatter::NameFormatter(QObject *parent) :
    QObject(parent)
{
    exWords = Settings::instance(this)->excludeWords().split(",", QString::SkipEmptyParts);
}

/**
 * @brief Returns an instance of the name formatter
 * @param parent Parent widget
 * @return Instance of name formatter
 */
NameFormatter *NameFormatter::instance(QObject *parent)
{
    if (m_instance == 0) {
        m_instance = new NameFormatter(parent);
    }
    return m_instance;
}

/**
 * @brief removes the exclude words, given from settings
 * @param name name to remove ex. words from
 * @return cleaned name
 */
QString NameFormatter::excludeWords(QString name)
{
    int pos;
    QRegExp rx;
    rx.setCaseSensitivity(Qt::CaseInsensitive);
    foreach (QString word, exWords) {
        rx.setPattern(word);
        pos = rx.indexIn(name);
        while (rx.indexIn(name) >= 0) {
            name = name.remove(pos, word.length());
            pos = rx.indexIn(name);
        }
    }

    // remove " - _" at the end of a name
    rx.setPattern("[\\-\\s_]");
    while (rx.lastIndexIn(name) == name.length() -1)
        name.chop(1);

    return name;
}

/**
 * @brief Removes the exclude words,
 * changes "." and "_" to " "
 * and removes all " - " at the end of the name
 * @param name Not yet formatted name.
 * @return Formatted name
 */
QString NameFormatter::formatName(QString name)
{
    name =  name.replace(".", " ").replace("_", " ");

    // remove exclude words
    name = excludeWords(name);

    // remove " - " at the end of a name
    QRegExp rx("[\\-\\s]");
    while (rx.lastIndexIn(name) == name.length() -1)
        name.chop(1);
    return name;
}

/**
 * @brief Removes the last part of a name,
 * looking like " - cd1" or "_a"
 * @param name name
 * @return cleaned name
 */
QString NameFormatter::formatParts(QString name)
{
    QRegExp rx("([\\-\\s\\(\\)\\._]+((a|b|c|d|e|f)|((part|cd|xvid)" \
               "[\\-\\s\\._]*\\d+))[\\-_\\s\\.\\(\\)]*)",
               Qt::CaseInsensitive);
    int pos = rx.lastIndexIn(name);
    name = name.left(pos);
    return name;
}