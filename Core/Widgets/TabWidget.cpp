#include "TabWidget.hpp"
#include "WebView.hpp"
#include "UrlInput.hpp"

namespace Bn
{
    TabWidget::TabWidget(Bn::MainWidget *parent):
    QTabWidget(parent)
    {
        TabWidget::parent = parent;
        this->setTabPosition(QTabWidget::North);
        this->setMovable(true);
        this->addTab(this->parent->view, "Browthon");
        this->parent->view->show();
    }

    void TabWidget::changeTab()
    {
        WebView* viewTemp = dynamic_cast<WebView*>(this->currentWidget());
        this->parent->setView(viewTemp);
        viewTemp->createConnection();
        this->parent->urlInput->setUrl();
        this->parent->backButton->disconnect();
        this->parent->reloadButton->disconnect();
        this->parent->forwardButton->disconnect();
        connect(this->parent->backButton, &QPushButton::clicked, viewTemp, &WebView::back);
        connect(this->parent->reloadButton, &QPushButton::clicked, viewTemp, &WebView::reload);
        connect(this->parent->forwardButton, &QPushButton::clicked, viewTemp, &WebView::forward);
    }

    void TabWidget::addView()
    {
        auto tab = new WebView(this->parent);
        this->addTab(tab, "Youtube");
        tab->show();
        this->setCurrentWidget(tab);
    }

    void TabWidget::deleteView()
    {
        if (this->count() == 1)
        {
            this->parent->parent->close();
        }
        else
        {
            this->removeTab(this->currentIndex());
        }
    }

    void TabWidget::setTitle()
    {
        this->parent->parent->setWindowTitle(this->parent->view->title().append(" - Browthon"));
        QString title;
        if (this->parent->view->title().size() >= 13)
        {
            title = this->parent->view->title().mid(0,9)+"...";
        }
        else
        {
            title = this->parent->view->title();
        }
        this->setTabText(this->currentIndex(), title);
    }
}
