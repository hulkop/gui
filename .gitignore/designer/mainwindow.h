#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QGraphicsScene>
#include <savechanges.h>
#include <QMouseEvent>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    QImage img;
    QGraphicsScene scene;
    bool isSaved;
    QString saveAdres;

public:
    explicit MainWindow(QWidget *parent = 0);
    void viewPicture() ;
    QImage resizeFunction(QImage img, int width, int height);
    void closeEvent(QCloseEvent *event);
    void resizeEvent(QResizeEvent *event);
    ~MainWindow();

signals:

private slots:
    void openPicture();
    void saveAs();
    void justSave();
    void imageResize();
    void endSave();
    void myClose();
};

#endif // MAINWINDOW_H
