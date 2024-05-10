#include "DelEdgeWindow.h"
#include "ui_DelEdgeWindow.h"

DelEdgeWindow::DelEdgeWindow(const Graph&graph, QWidget *parent)
    : QDialog(parent), m_graph(graph), ui(new Ui::DelEdgeWindow)
{
    ui->setupUi(this);
    connect(ui->DelEdgeBtn, SIGNAL(clicked()), this, SLOT(DelEdge()));
}

DelEdgeWindow::~DelEdgeWindow()
{
    delete ui;
}

void DelEdgeWindow::DelEdge()
{
    QString FromLine = ui->FromLine->text();
    QString ToLine = ui->ToLine->text();
    int from = FromLine.toInt();
    int to = ToLine.toInt();
    m_graph.DelEdge(from,to);
    close();
}

