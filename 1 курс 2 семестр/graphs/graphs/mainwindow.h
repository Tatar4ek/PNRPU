#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <graph.h>
#include <NewEdgeWindow.h>
#include "ui_NewEdgeWindow.h"
#include <QMainWindow>
#include <QGraphicsScene>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void AddNode();
    void DelNode();
    void UpdateNumber();
    void AddEdge();
    void DelEdge();
    void UpdateArrows();
    void TspSolve();
    void Matrix();
private:
    Graph graph;
    NewEdgeWindow AddEdgeWindow;
    QGraphicsScene *scene;
    QGraphicsView *PrintGraph;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
