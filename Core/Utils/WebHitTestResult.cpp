#include "WebHitTestResult.hpp"
#include "../Widgets/WebPage.hpp"

#include <QWebEngineScript>
#include <QWebEngineContextMenuData>

namespace Bn
{
    WebHitTestResult::WebHitTestResult(const WebPage *page, const QPoint &pos)
    {
        auto m_isNull = true;
        auto m_isContentEditable = false;
        auto m_isContentSelected = false;
        auto m_mediaPaused = false;
        auto m_mediaMuted = false;
        auto m_pos = pos;
        QString source = QLatin1String("(function() {"
                                       "let e = document.elementFromPoint(%1, %2);"
                                       "if (!e)"
                                       "    return;"
                                       "function isMediaElement(e) {"
                                       "    return e.tagName == 'AUDIO' || e.tagName == 'VIDEO';"
                                       "};"
                                       "function isEditableElement(e) {"
                                       "    if (e.isContentEditable)"
                                       "        return true;"
                                       "    if (e.tagName === 'INPUT' || e.tagName === 'TEXTAREA')"
                                       "        return e.getAttribute('readonly') != 'readonly';"
                                       "    return false;"
                                       "};"
                                       "function isSelected(e) {"
                                       "    let selection = window.getSelection();"
                                       "    if (selection.type !== 'Range')"
                                       "        return false;"
                                       "    return window.getSelection().containsNode(e, true);"
                                       "};"
                                       "let res = {"
                                       "        baseUrl: document.baseURI,"
                                       "        alternateText: e.getAttribute('alt'),"
                                       "        boundingRect: '',"
                                       "        imageUrl: '',"
                                       "        contentEditable: isEditableElement(e),"
                                       "        contentSelected: isSelected(e),"
                                       "        linkTitle: '',"
                                       "        linkUrl: '',"
                                       "        mediaUrl: '',"
                                       "        tagName: e.tagName.toLowerCase()"
                                       "};"
                                       "let r = e.getBoundingClientRect();"
                                       "res.boundingRect = [r.top, r.left, r.width, r.height];"
                                       "if (e.tagName == 'IMG')"
                                       "    res.imageUrl = e.getAttribute('src');"
                                       "if (e.tagName == 'A') {"
                                       "    res.linkTitle = e.text;"
                                       "    res.linkUrl = e.getAttribute('href');"
                                       "}"
                                       "while (e) {"
                                       "    if (res.linkTitle === '' && e.tagName === 'A') {"
                                       "        res.linkTitle = e.text;"
                                       "        if(res.linkUrl === '') {"
                                       "            res.linkUrl = e.getAttribute('href');"
                                       "        }"
                                       "    }"
                                       "    if (res.mediaUrl === '' && isMediaElement(e)) {"
                                       "        res.mediaUrl = e.currentSrc;"
                                       "        res.mediaPaused = e.paused;"
                                       "        res.mediaMuted = e.muted;"
                                       "    }"
                                       "    e = e.parentElement;"
                                       "}"
                                       "return res;"
                                       "})()");

        WebPage* p = const_cast<WebPage*>(page);
        m_viewportPos = p->mapToViewport(m_pos);

        const QString& js = source.arg(m_viewportPos.x()).arg(m_viewportPos.y());
        const QUrl& url{p->url()};
        const QVariantMap& map{p->executeJavaScript(js, QWebEngineScript::ApplicationWorld).toMap()};

        if (map.isEmpty())
            return;

        m_isNull = false;
        m_baseUrl = map.value(QStringLiteral("baseUrl")).toUrl();
        m_alternateText = map.value(QStringLiteral("alternateText")).toString();
        m_imageUrl = map.value(QStringLiteral("imageUrl")).toUrl();
        m_isContentEditable = map.value(QStringLiteral("contentEditable")).toBool();
        m_isContentSelected = map.value(QStringLiteral("contentSelected")).toBool();
        m_linkTitle = map.value(QStringLiteral("linkTitle")).toString();
        m_linkUrl = map.value(QStringLiteral("linkUrl")).toUrl();
        m_mediaUrl = map.value(QStringLiteral("mediaUrl")).toUrl();
        m_mediaPaused = map.value(QStringLiteral("mediaPaused")).toBool();
        m_mediaMuted = map.value(QStringLiteral("mediaMuted")).toBool();
        m_tagName = map.value(QStringLiteral("tagName")).toString();

        const QVariantList& rect = map.value(QStringLiteral("boundingRect")).toList();
        if (rect.size() == 4)
            m_boundingRect = QRect(rect.at(0).toInt(), rect.at(1).toInt(), rect.at(2).toInt(), rect.at(3).toInt());

        if (!m_imageUrl.isEmpty())
            m_imageUrl = url.resolved(m_imageUrl);
        if (!m_linkUrl.isEmpty())
            m_linkUrl = m_baseUrl.resolved(m_linkUrl);
        if (!m_mediaUrl.isEmpty())
            m_mediaUrl = url.resolved(m_mediaUrl);
    }

    QUrl WebHitTestResult::baseUrl() const
    {
        return m_baseUrl;
    }

    QString WebHitTestResult::alternateText() const
    {
        return m_alternateText;
    }

    QRect WebHitTestResult::boundingRect() const
    {
        return m_boundingRect;
    }

    QUrl WebHitTestResult::imageUrl() const
    {
        return m_imageUrl;
    }

    bool WebHitTestResult::isContentEditable() const
    {
        return m_isContentEditable;
    }

    bool WebHitTestResult::isContentSelected() const
    {
        return m_isContentSelected;
    }

    bool WebHitTestResult::isNull() const
    {
        return m_isNull;
    }

    QString WebHitTestResult::linkTitle() const
    {
        return m_linkTitle;
    }

    QUrl WebHitTestResult::linkUrl() const
    {
        return m_linkUrl;
    }

    QUrl WebHitTestResult::mediaUrl() const
    {
        return m_mediaUrl;
    }

    bool WebHitTestResult::mediaPaused() const
    {
        return m_mediaPaused;
    }

    bool WebHitTestResult::mediaMuted() const
    {
        return m_mediaMuted;
    }

    QPoint WebHitTestResult::pos() const
    {
        return m_pos;
    }

    QPointF WebHitTestResult::viewportPos() const
    {
        return m_viewportPos;
    }

    QString WebHitTestResult::tagName() const
    {

        return m_tagName;
    }

}
