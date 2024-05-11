#ifndef DELEDGEWINDOW_H
#define DELEDGEWINDOW_H
#include <QDialog>
#include "graph.h"

namespace Ui
{
    class DelEdgeWindow;
}

class DelEdgeWindow :  public QDialog
{
    Q_OBJECT
public:
    explicit DelEdgeWindow(const Graph&graph, QWidget *parent = nullptr);
    ~DelEdgeWindow();

public slots:
    void DelEdge();

private:
    const Graph&m_graph;
    Ui::DelEdgeWindow *ui;
};


#endif // DELEDGEWINDOW_H
