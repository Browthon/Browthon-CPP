#include "AboutWindow.hpp"

#include <QPushButton>
#include <QLabel>
#include <QFont>
#include <QGridLayout>

namespace Bn
{
    AboutWindow::AboutWindow(MainWidget *parent, QString type)
    {
        this->parent = parent;
        this->setFixedSize(500, 350);

        auto button = new QPushButton("Site");
        auto title = new QLabel();
        auto description = new QLabel();

        if(type == "Browthon")
        {
            this->setWindowTitle("Informations sur Browthon");
            title->setText("Browthon");
            description->setText(QString("Version : ").append(this->parent->versionAll).append("\nCréé par LavaPower\n\n Site :"));
            connect(button, &QPushButton::clicked, this, &AboutWindow::openWebsiteBrowthon);
        }
        else if(type == "Qt")
        {
            this->setWindowTitle("Informations sur Qt");
            title->setText("Qt");
            description->setText(QString("Version : ").append(QT_VERSION_STR).append("\nCréé par The Qt Company\n\nSite :"));
            connect(button, &QPushButton::clicked, this, &AboutWindow::openWebsiteQt);
        }

        title->setAlignment(Qt::AlignHCenter);
        description->setAlignment(Qt::AlignHCenter);
        title->setFont(QFont("Arial", 23, QFont::Bold));
        description->setFont(QFont("Arial", 18));
        auto grid = new QGridLayout();
        grid->addWidget(title, 1, 1);
        grid->addWidget(description, 2, 1);
        grid->addWidget(button, 3, 1);
        this->setLayout(grid);
    }

    void AboutWindow::openWebsiteBrowthon()
    {
        this->close();
        this->parent->createTabWithUrl("http://pastagames.fr.nf/browthon");
    }

    void AboutWindow::openWebsiteQt()
    {
        this->close();
        this->parent->createTabWithUrl("https://www.qt.io/");
    }
}
