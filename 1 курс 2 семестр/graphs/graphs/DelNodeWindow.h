#ifndef DELNODEWINDOW_H
#define DELNODEWINDOW_H

#include <QDialog>
#include <QGraphicsView>
#include "graph.h"

namespace Ui
{
    class DelNodeWindow;
}

class DelNodeWindow : public QDialog
{
    Q_OBJECT
public:
    explicit DelNodeWindow(Graph&graph, QGraphicsScene* scene, QGraphicsView* PrintGraph, QGraphicsItemGroup** MatrixOfGroups, QWidget *parent = nullptr);
    ~DelNodeWindow();
public slots:
    void DelNode();
private:
    Graph& m_graph;
    QGraphicsScene* m_scene;
    QGraphicsItemGroup** m_MatrixOfGroups;
    QGraphicsView* m_PrintGraph;
    Ui::DelNodeWindow *ui;
};
#endif // DELNODEWINDOW_H
