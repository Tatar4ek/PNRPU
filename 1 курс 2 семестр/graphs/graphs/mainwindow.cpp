#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "DelEdgeWindow.h"
#include "ui_DelEdgeWindow.h"
#include "DelNodeWindow.h"
#include "ui_DelNodeWindow.h"
#include "graph.h"
#include "NewEdgeWindow.h"
#include "ui_NewEdgeWindow.h"
#include <QDebug>
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <QGraphicsItemGroup>
#include <QtMath>
#include <QPolygonF>
#include <QPlainTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , AddEdgeWindow(graph)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    PrintGraph = ui->PrintGraph;
    scene = new QGraphicsScene;
    PrintGraph -> setScene(scene);
    connect(ui->NodeBtn, SIGNAL(clicked()), this, SLOT(AddNode()));
    connect(ui->EdgeBtn, SIGNAL(clicked()), this, SLOT(AddEdge()));
    connect(ui->DelNodeBtn, SIGNAL(clicked()), this, SLOT(DelNode()));
    connect(ui->DelEdgeBtn, SIGNAL(clicked()), this, SLOT(DelEdge()));
    connect(ui->TspBtn, SIGNAL(clicked()),this, SLOT(TspSolve()));
    connect(ui->MatrixBtn, SIGNAL(clicked()), this, SLOT(Matrix()));
}
void MainWindow::TspSolve()
{
    graph.SolveTSP();
}
void MainWindow::Matrix()
{
    graph.PrintMatrix();
}
void MainWindow::AddNode()
{
    QGraphicsEllipseItem *Node = scene->addEllipse(0,0,50,50, QPen(Qt::black), QBrush(Qt::lightGray));
    QString NodeNumber = QString::number(graph.GetNumber());
    QGraphicsTextItem *TextItem = scene->addText(NodeNumber);
    TextItem->setPos(Node->boundingRect().center().x() - TextItem->boundingRect().width() / 2,
                     Node->boundingRect().center().y() - TextItem->boundingRect().height() / 2);
    QList<QGraphicsItem*> items;
    items << Node << TextItem;
    QGraphicsItemGroup *group = scene->createItemGroup(items);
    group->setFlag(QGraphicsItem::ItemIsMovable, true);
    graph.NewSizeMatrix(1);
    graph.AddLastNode(Node, group);
    graph.IncreaseNumber();
    graph.PrintMatrix();
}

void MainWindow::DelNode()
{
    DelNodeWindow DelNodeWindow(graph, scene, PrintGraph, graph.GetGroupMatrix());
    DelNodeWindow.setModal(true);
    DelNodeWindow.exec();
    UpdateNumber();
    UpdateArrows();
    graph.PrintMatrix();
}

void MainWindow::UpdateNumber()
{
    int size = graph.GetSize();
    QGraphicsItemGroup** groups = graph.GetGroupMatrix();
    for (int i = 1; i < size; i++)
    {
        foreach (QGraphicsItem *item, groups[i]->childItems())
        {
            QGraphicsTextItem *textItem = qgraphicsitem_cast<QGraphicsTextItem*>(item);
            if (textItem)
            {
                textItem->setPlainText(QString::number(i));
            }
        }
    }
    scene->update();
}

void MainWindow::AddEdge()
{
    NewEdgeWindow EdgeWindow(graph);
    EdgeWindow.setModal(true);
    EdgeWindow.exec();
    UpdateArrows();
    graph.PrintMatrix();
}

void MainWindow::DelEdge()
{
    DelEdgeWindow DelEdge(graph);
    DelEdge.setModal(true);
    DelEdge.exec();
    UpdateArrows();
    graph.PrintMatrix();
}

void MainWindow::UpdateArrows()
{
    int** matrix = graph.GetMatrix();
    QGraphicsItemGroup** matrixOfGroups = graph.GetGroupMatrix();
    std::vector<QGraphicsItemGroup*> vectorOfArrows = graph.GetVectorArrows();
    for (int i = 0; i < vectorOfArrows.size(); i++)
    {
        scene->removeItem(vectorOfArrows[i]); // Удаляем группы со сцены
        delete vectorOfArrows[i]; // Освобождаем память
    }
    vectorOfArrows.clear();
    for (int i = 1; i < graph.GetSize(); i++)
    {
        for (int j = i + 1; j < graph.GetSize(); j++)
        {
            if (matrix[i][j] > 0 && matrix[i][j] == matrix[j][i])
            {
                QPointF center1 = matrixOfGroups[i]->mapToScene(matrixOfGroups[i]->boundingRect().center());
                QPointF center2 = matrixOfGroups[j]->mapToScene(matrixOfGroups[j]->boundingRect().center());
                qDebug() << center1;
                qDebug() << center2;
                qreal angle = qAtan2(center2.y() - center1.y(), center2.x() - center1.x());
                QPointF newStart(center1.x() + 32 * qCos(angle), center1.y() + 32 * qSin(angle));
                QPointF newEnd(center2.x() - 32 * qCos(angle), center2.y() - 32 * qSin(angle));
                QGraphicsLineItem *line = new QGraphicsLineItem();
                line->setLine(QLineF(newStart, newEnd));
                QPointF textPos((center1.x() + center2.x()) / 2, (center1.y() + center2.y()) / 2);
                QGraphicsTextItem* textItem = scene->addText(QString::number(matrix[i][j]));
                textItem->setPos(textPos);
                QList<QGraphicsItem*> items;
                items << line << textItem;
                QGraphicsItemGroup *group = scene->createItemGroup(items);
                vectorOfArrows.push_back(group);
            }

        }
    }
    graph.NewVector(vectorOfArrows);
}



MainWindow::~MainWindow()
{
    delete scene;
    delete ui;
}

