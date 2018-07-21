#include "WebView.hpp"
#include "WebPage.hpp"
#include "UrlInput.hpp"
#include "TabWidget.hpp"

namespace Bn
{
    WebView::WebView(MainWidget* parent = nullptr):
    QWebEngineView(parent)
    {
        this->parent = parent;
        auto page = new WebPage(this);
        this->setPage(page);
        this->load(QUrl("http://pastagames.fr.nf/browthon"));
    }

    void WebView::createConnection()
    {
        connect(this, &WebView::urlChanged, this->parent->urlInput, &UrlInput::setUrl);
        connect(this, &WebView::titleChanged, this->parent->tabWidget, &TabWidget::setTitle);
    }
}
