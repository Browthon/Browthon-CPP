#include "UrlInput.hpp"
#include "../BrowserWidget.hpp"
#include "WebView.hpp"

namespace Bn
{
    UrlInput::UrlInput(MainWidget* parent = nullptr):
    QLineEdit(parent)
    {
        this->parent = parent;
    }

    void UrlInput::enterUrl()
    {
        auto urlTemp = this->text();
        if (!(urlTemp.contains("http://") || urlTemp.contains("https://")))
        {
            if (urlTemp.contains("."))
            {
                urlTemp = QString("http://").append(urlTemp);
            }
            else
            {
                urlTemp = QString("https://www.google.fr/?gws_rd=ssl#q=").append(urlTemp);
            }
        }
        this->parent->view->load(QUrl(urlTemp));
    }

    void UrlInput::enterUrl(QString url)
    {
        this->parent->view->load(QUrl(url));
    }

    void UrlInput::setUrl()
    {
        this->setText(this->parent->view->url().toString());
    }

    void UrlInput::enterUrlGiven(QString url)
    {
        auto urlT = url;
        if(!(urlT.contains("https://") || urlT.contains("https://")))
        {
            urlT = QString("http://").append(urlT);
        }
        this->parent->view->load(QUrl(urlT));
    }
}
