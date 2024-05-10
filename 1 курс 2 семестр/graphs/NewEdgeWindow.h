#ifndef NEWEDGEWINDOW_H
#define NEWEDGEWINDOW_H

#include <QDialog>
#include "graph.h"

namespace Ui
{
    class NewEdgeWindow;
}
class NewEdgeWindow : public QDialog
{
    Q_OBJECT
public:
    explicit NewEdgeWindow(const Graph&graph, QWidget *par = nullptr);
    ~NewEdgeWindow();

private slots:
    void NewEdge();

private:
    const Graph& m_graph;
    Ui::NewEdgeWindow *ui;
};

#endif // NEWEDGEWINDOW_H
