#include "NewEdgeWindow.h"
#include "ui_NewEdgeWindow.h"
#include <QGraphicsScene>

NewEdgeWindow::NewEdgeWindow(const Graph&graph, QWidget *parent)
    : QDialog(parent), m_graph(graph), ui(new Ui::NewEdgeWindow)
{
    ui->setupUi(this);
    connect(ui->NewEdgeButton, SIGNAL(clicked()), this, SLOT(NewEdge()));
}

NewEdgeWindow::~NewEdgeWindow()
{
    delete ui;
}

void NewEdgeWindow::NewEdge()
{
    QString FromLine = ui->FromLine->text();
    QString ToLine = ui->ToLine->text();
    QString WeightLine = ui->WeightLine->text();
    int from = FromLine.toInt();
    int to = ToLine.toInt();
    int weight = WeightLine.toInt();
    m_graph.AddEdge(from, to, weight);
    close();
}
