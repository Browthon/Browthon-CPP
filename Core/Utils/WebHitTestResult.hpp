#ifndef BROWTHON_APP_WEBHITTESTRESULT_HPP
#define BROWTHON_APP_WEBHITTESTRESULT_HPP

#include <QPoint>
#include <QUrl>

namespace Bn
{
    class WebPage;

    class WebHitTestResult
    {
    public:
        WebHitTestResult(WebPage* page, QPoint pos);
        WebPage* page;
        QPoint pos;
        QUrl linkUrl;
        QUrl baseUrl;
        QString getLinkUrl();
        QString getBaseUrl();
    };
}

#endif //BROWTHON_APP_WEBHITTESTRESULT_HPP
