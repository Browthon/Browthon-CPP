#include "WebHitTestResult.hpp"
#include "../Widgets/WebPage.hpp"

#include <QWebEngineScript>

namespace Bn
{
    WebHitTestResult::WebHitTestResult(WebPage *page, QPoint pos)
    {
        this->page = page;
        this->pos = pos;
        auto viewportPos = this->page->mapToViewport(this->pos);
        QString source = QLatin1String("(function() {"
                                       "var e = document.elementFromPoint(%1, %2);"
                                       "if (!e)"
                                       "    return;"
                                       "function isMediaElement(e) {"
                                       "    return e.tagName == 'AUDIO' || e.tagName == 'VIDEO';"
                                       "}"
                                       "function isEditableElement(e) {"
                                       "    if (e.isContentEditable)"
                                       "        return true;"
                                       "    if (e.tagName == 'INPUT' || e.tagName == 'TEXTAREA')"
                                       "        return e.getAttribute('readonly') != 'readonly';"
                                       "    return false;"
                                       "}"
                                       "function isSelected(e) {"
                                       "    var selection = window.getSelection();"
                                       "    if (selection.type != 'Range')"
                                       "        return false;"
                                       "    return window.getSelection().containsNode(e, true);"
                                       "}"
                                       "var res = {"
                                       "    baseUrl: document.baseURI,"
                                       "    alternateText: e.getAttribute('alt'),"
                                       "    boundingRect: '',"
                                       "    imageUrl: '',"
                                       "    contentEditable: isEditableElement(e),"
                                       "    contentSelected: isSelected(e),"
                                       "    linkTitle: '',"
                                       "    linkUrl: '',"
                                       "    mediaUrl: '',"
                                       "    tagName: e.tagName.toLowerCase()"
                                       "};"
                                       "var r = e.getBoundingClientRect();"
                                       "res.boundingRect = [r.top, r.left, r.width, r.height];"
                                       "if (e.tagName == 'IMG')"
                                       "    res.imageUrl = e.getAttribute('src');"
                                       "if (e.tagName == 'A') {"
                                       "    res.linkTitle = e.text;"
                                       "    res.linkUrl = e.getAttribute('href');"
                                       "}"
                                       "while (e) {"
                                       "    if (res.linkTitle == ''& & e.tagName == 'A')"
                                       "        res.linkTitle = e.text;"
                                       "    if (res.linkUrl == ''& & e.tagName == 'A')"
                                       "        res.linkUrl = e.getAttribute('href');"
                                       "    if (res.mediaUrl == ''& & isMediaElement(e)) {"
                                       "        res.mediaUrl = e.currentSrc;"
                                       "        res.mediaPaused = e.paused;"
                                       "        res.mediaMuted = e.muted;"
                                       "    }"
                                       "    e = e.parentElement;"
                                       "}"
                                       "return res;"
                                       "})()");
        const QString& js = source.arg(viewportPos.x()).arg(viewportPos.y());
        const QVariantMap& map{this->page->executeJavaScript(js, QWebEngineScript::ApplicationWorld).toMap()};

        if (map.isEmpty())
            return;

        this->baseUrl = map.value(QStringLiteral("baseUrl")).toUrl();
        this->linkUrl = map.value(QStringLiteral("linkUrl")).toUrl();

        if (!this->linkUrl.isEmpty())
        {
            this->linkUrl = this->baseUrl.resolved(this->linkUrl);
        }
    }

    QString WebHitTestResult::getBaseUrl()
    {
        return this->baseUrl.toString();
    }

    QString WebHitTestResult::getLinkUrl()
    {
        return this->linkUrl.toString();
    }
}