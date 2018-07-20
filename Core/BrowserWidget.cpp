#include "BrowserWidget.hpp"

#include "Widgets/WebView.hpp"
#include "Widgets/UrlInput.hpp"
#include "Widgets/TabWidget.hpp"

#include <QGridLayout>
#include <QPushButton>

namespace Bn
{
    MainWidget::MainWidget(QWidget* parent = nullptr) :
    QWidget(parent)
    {
        this->parent = parent;
        auto layout = new QGridLayout();

        view = new WebView(this);
        tabWidget = new TabWidget(this);
        urlInput = new UrlInput(this);
        auto addTabButton = new QPushButton("+", this);
        auto deleteTabButton = new QPushButton("-", this);
        backButton = new QPushButton("<", this);
        reloadButton = new QPushButton("↺", this);
        forwardButton = new QPushButton(">", this);
        auto homeButton = new QPushButton("⌂", this);

        view->createConnection();
        connect(urlInput, SIGNAL(returnPressed()), urlInput, SLOT(enterUrl()));
        connect(tabWidget, &TabWidget::currentChanged, tabWidget, &TabWidget::changeTab);
        connect(addTabButton, &QPushButton::clicked, tabWidget, &TabWidget::addView);
        connect(deleteTabButton, &QPushButton::clicked, tabWidget, &TabWidget::deleteView);
        connect(backButton, &QPushButton::clicked, view, &WebView::back);
        connect(reloadButton, &QPushButton::clicked, view, &WebView::reload);
        connect(forwardButton, &QPushButton::clicked, view, &WebView::forward);
        connect(homeButton, &QPushButton::clicked, this, &MainWidget::showHome);

        layout->addWidget(backButton, 1, 1);
        layout->addWidget(reloadButton, 1, 2);
        layout->addWidget(forwardButton, 1, 3);
        layout->addWidget(urlInput, 1, 4);
        layout->addWidget(homeButton, 1, 5);
        layout->addWidget(addTabButton, 1, 6);
        layout->addWidget(deleteTabButton, 1, 7);
        layout->addWidget(tabWidget, 2, 1, 1, 7);

        this->setLayout(layout);
    }

    void MainWidget::setView(WebView *view)
    {
        this->view = view;
    }

    void MainWidget::showHome()
    {
        this->urlInput->enterUrl("http://pastagames.fr.nf/browthon");
    }
}