#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSvgRenderer>
#include <QPainter>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Generate SVG content (this is just an example)
    QString svgContent = "<svg width='100' height='100'>"
                         "<circle cx='50' cy='50' r='40' stroke='black' stroke-width='3' fill='red' />"
                         "</svg>";

    // Load SVG content into the QSvgWidget
    ui->svgWidget->load(svgContent.toUtf8());

    // Set aspect ratio mode using the renderer
    if (ui->svgWidget->renderer())
    {
        ui->svgWidget->renderer()->setAspectRatioMode(Qt::KeepAspectRatio);
    }
    else
    {
        std::cerr << "ui->svgWidget->renderer() not found" << std::endl;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
