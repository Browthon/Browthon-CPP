#include <QChildEvent>
#include <QEvent>
#include <QMouseEvent>

#include "WebView.hpp"
#include "WebPage.hpp"
#include "UrlInput.hpp"
#include "TabWidget.hpp"
#include "../Utils/WebHitTestResult.hpp"

namespace Bn
{
    WebView::WebView(MainWidget* parent = nullptr):
    QWebEngineView(parent)
    {
        this->parent = parent;
        page = new WebPage(this);
        this->setPage(page);
        this->load(QUrl("http://pastagames.fr.nf/browthon"));

		installEventFilter(this);

		if (parentWidget())
			parentWidget()->installEventFilter(this);
    }

    void WebView::createConnection()
    {
        connect(this, &WebView::urlChanged, this->parent->urlInput, &UrlInput::setUrl);
        connect(this, &WebView::titleChanged, this->parent->tabWidget, &TabWidget::setTitle);
    }

    bool WebView::event(QEvent *event)
    {
        if(event->type() == QEvent::ChildAdded)
        {
            auto childev = static_cast<QChildEvent*>(event);
            auto widget = childev->child();

            if(widget)
            {
                widget->installEventFilter(this);
            }
        }
        if (event->type() == QEvent::ParentChange && parentWidget())
        {
            parentWidget()->installEventFilter(this);
        }
        return QWebEngineView::event(event);
    }

    bool WebView::eventFilter(QObject *watched, QEvent *event)
    {
        if(event->type() == QEvent::MouseButtonRelease)
        {
            auto eventClick = dynamic_cast<QMouseEvent*>(event);
            if(eventClick->button() == Qt::MiddleButton)
            {
                auto hit = this->page->hitTestContent(eventClick->pos());
                auto clickedUrl = hit->linkUrl().toString();
                auto baseUrl = hit->baseUrl().toString();
                if(clickedUrl != baseUrl && !(clickedUrl.isEmpty()))
                {
                    QString result;
                    if(clickedUrl.contains("http://") || clickedUrl.contains("https://"))
                    {
                        result = clickedUrl;
                    }
                    else if (clickedUrl == "#")
                    {
                        result = baseUrl + clickedUrl;
                    }
                    else
                    {
                        result = QString("http://").append(baseUrl.split("/")[2]).append(clickedUrl);
                    }
                    this->parent->createTabWithUrl(result);
                }
                event->accept();
                return true;
            }
        }
        return QObject::eventFilter(watched, event);
    }
}
