#include "BrowserWidget.hpp"

#include "Widgets/WebView.hpp"
#include "Widgets/UrlInput.hpp"

#include <QGridLayout>

namespace Bn
{
    MainWidget::MainWidget(QWidget* parent = nullptr) :
    QWidget(parent)
    {
        QGridLayout* layout = new QGridLayout();

        view = new WebView(this);
        urlInput = new UrlInput(this);
        connect(urlInput, SIGNAL(returnPressed()), urlInput, SLOT(enterUrl()));

        layout->addWidget(urlInput, 1, 2);

        this->setLayout(layout);
    }

    void MainWidget::setView(WebView *view)
    {
        this->view = view;
    }
}