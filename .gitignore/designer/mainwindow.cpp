#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QPixmap>
#include <QString>
#include <QFileDialog>
#include <QImage>
#include <QGraphicsPixmapItem>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    saveAdres = "";
    isSaved = true;
    ui->setupUi(this);
    connect(ui->close, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->openInMenuFile, SIGNAL(triggered(bool)), this, SLOT(openPicture()));
    connect(ui->pushButtonResize, SIGNAL(clicked(bool)), this, SLOT(imageResize()));
    connect(ui->saveAs, SIGNAL(triggered(bool)), this, SLOT(saveAs()));
    connect(ui->save, SIGNAL(triggered(bool)), this, SLOT(justSave()));
}


void MainWindow::viewPicture() {
    scene.clear();
    ui->graphicsView->setScene(&scene);
    QGraphicsPixmapItem *pixmap_item = new QGraphicsPixmapItem();
    scene.addItem(pixmap_item);

    pixmap_item->setVisible(true);
    QPixmap pixmap = QPixmap::fromImage(this->img);
    pixmap_item->setPixmap(pixmap);

    scene.setSceneRect(0, 0, pixmap.width(), pixmap.height());
    ui->graphicsView->fitInView(pixmap_item, Qt::KeepAspectRatio);
    QString size = QString::number((this->img).size().width()) + "x" + QString::number((this->img).size().height());
    ui->label_6->setText(size);
}


void MainWindow::openPicture() {
    QString fn = QFileDialog::getOpenFileName(this, trUtf8("Open image"));
    this->img = QImage(fn);
    isSaved = false;
    saveAdres = fn;

    viewPicture();
}


void MainWindow::saveAs() {
    QString fn = QFileDialog::getSaveFileName(this, trUtf8("Save as..."));
    this->img.save(fn, "jpg");
    isSaved = true;
    saveAdres = fn;
}


void MainWindow::justSave() {
    this->img.save(saveAdres, "jpg");
    isSaved = true;
}


QImage MainWindow::resizeFunction(QImage img, int width, int height) {
    return img;
}


void MainWindow::imageResize() {
    img = resizeFunction(this->img, ui->spinBox->value(), ui->spinBox_2->value());
    isSaved = false;

    viewPicture();
}


void MainWindow::endSave() {
    justSave();
    close();
}


void MainWindow::myClose() {
    isSaved = true;
    close();
}


void MainWindow::closeEvent(QCloseEvent *event) {
    if (isSaved) {
        event->accept();
    } else {
        event->ignore();
        SaveChanges *sc = new SaveChanges();
        connect(sc->getSave(), SIGNAL(clicked(bool)), this, SLOT(endSave()));
        connect(sc->getSave(), SIGNAL(clicked(bool)), sc, SLOT(close()));
        connect(sc->getDoNotSave(), SIGNAL(clicked(bool)), this, SLOT(myClose()));
        connect(sc->getDoNotSave(), SIGNAL(clicked(bool)), sc, SLOT(close()));
        sc->show();
    }
}


void MainWindow::resizeEvent(QResizeEvent *event) {
    viewPicture();
}


MainWindow::~MainWindow()
{
    delete ui;
}



