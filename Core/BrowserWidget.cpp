#include "BrowserWidget.hpp"

#include "Widgets/WebView.hpp"
#include "Widgets/UrlInput.hpp"
#include "Widgets/TabWidget.hpp"
#include "Browser.hpp"
#include "Windows/AboutWindow.hpp"

#include <QGridLayout>
#include <QPushButton>
#include <QWebEngineSettings>
#include <QMenuBar>

namespace Bn
{
    MainWidget::MainWidget(MainWindow* parent = nullptr) :
    QWidget(parent)
    {
        this->parent = parent;
        this->versionAll = "0.0.1 : Beta";
        this->versionMinimal = "0.0.1";
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

        auto menuBar = this->parent->menuBar();
        menuBar->addAction("Historique", this, &MainWidget::openHistory);
        menuBar->addAction("Favoris", this, &MainWidget::openFav);
        menuBar->addAction("Téléchargements", this, &MainWidget::openDownload);
        menuBar->addAction("Sessions", this, &MainWidget::openSession);
        menuBar->addAction("Raccourcis URL", this, &MainWidget::openRaccourci);
        menuBar->addAction("Paramètres", this, &MainWidget::openParameters);
        auto aboutMenu = menuBar->addMenu("A Propos");
        aboutMenu->addAction("Browthon", this, &MainWidget::openInfoBrowthon);
        aboutMenu->addAction("Qt", this, &MainWidget::openInfoQt);

        this->browthonInfo = new AboutWindow(this, "Browthon");
        this->qtInfo = new AboutWindow(this, "Qt");

        view->createConnection();
        connect(urlInput, SIGNAL(returnPressed()), urlInput, SLOT(enterUrl()));
        connect(tabWidget, &TabWidget::currentChanged, tabWidget, &TabWidget::changeTab);
        connect(addTabButton, &QPushButton::clicked, tabWidget, &TabWidget::addView);
        connect(deleteTabButton, &QPushButton::clicked, tabWidget, &TabWidget::deleteView);
        connect(backButton, &QPushButton::clicked, view, &WebView::back);
        connect(reloadButton, &QPushButton::clicked, view, &WebView::reload);
        connect(forwardButton, &QPushButton::clicked, view, &WebView::forward);
        connect(homeButton, &QPushButton::clicked, this, &MainWidget::showHome);

        QWebEngineSettings::globalSettings()->setAttribute(QWebEngineSettings::FullScreenSupportEnabled, true);

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

    void MainWidget::createTabWithUrl(QString url)
    {
        auto tab = new WebView(this);
        this->tabWidget->addTab(tab, "Browthon");
        tab->show();
        this->tabWidget->setCurrentWidget(tab);
        this->urlInput->enterUrlGiven(url);
    }

    void MainWidget::openFav()
    {}

    void MainWidget::openHistory()
    {}

    void MainWidget::openDownload()
    {}

    void MainWidget::openSession()
    {}

    void MainWidget::openRaccourci()
    {}

    void MainWidget::openParameters()
    {}

    void MainWidget::openInfoBrowthon()
    {
        this->browthonInfo->setWindowModality(Qt::ApplicationModal);
        this->browthonInfo->show();
    }

    void MainWidget::openInfoQt()
    {
        this->qtInfo->setWindowModality(Qt::ApplicationModal);
        this->qtInfo->show();
    }
}