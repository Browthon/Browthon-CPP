#include "WebView.hpp"
#include "WebPage.hpp"

namespace Bn
{
    WebView::WebView(QWidget* parent = nullptr):
    QWebEngineView(parent)
    {
        WebPage* page = new WebPage(this);
        this->setPage(page);
        this->load(QUrl("http://youtube.com"));
    }
}
