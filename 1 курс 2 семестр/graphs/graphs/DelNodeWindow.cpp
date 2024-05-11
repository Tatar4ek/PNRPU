#include "DelNodeWindow.h"
#include "ui_DelNodeWindow.h"

DelNodeWindow::DelNodeWindow(Graph& graph, QGraphicsScene* scene, QGraphicsView* PrintGraph, QGraphicsItemGroup** MatrixOfGroups, QWidget *parent)
    : QDialog(parent), m_graph(graph), m_scene(scene), m_MatrixOfGroups(MatrixOfGroups), m_PrintGraph(PrintGraph), ui(new Ui::DelNodeWindow)
{
    ui->setupUi(this);

    connect(ui->DelNodeBtn, SIGNAL(clicked()), this, SLOT(DelNode()));
}

DelNodeWindow::~DelNodeWindow()
{
    delete ui;
}

void DelNodeWindow::DelNode()
{
    QString NodeNumber = ui->NumberLine->text();
    int number = NodeNumber.toInt();
    m_scene->removeItem(m_MatrixOfGroups[number]);
    delete m_MatrixOfGroups[number];
    m_MatrixOfGroups[number] = nullptr;
    m_graph.DelNode(number);
    close();
}
