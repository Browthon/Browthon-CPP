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
        this->parent->view->load(QUrl(this->text()));
    }

    void UrlInput::enterUrl(char* url)
    {
        this->parent->view->load(QUrl(url));
    }

    void UrlInput::setUrl()
    {
        this->setText(this->parent->view->url().toString());
    }
}
