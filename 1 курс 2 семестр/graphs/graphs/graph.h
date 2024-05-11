#ifndef GRAPH_H
#define GRAPH_H

#include <QGraphicsEllipseItem>
#include <QGraphicsItemGroup>
#include <QGraphicsLineItem>

using namespace std;



class Graph
{
private:
    int SizeMatrix;
    int** Matrix;
    int CurNumber;
    QGraphicsEllipseItem** EllipseMatrix;
    QGraphicsItemGroup** GroupMatrix;
    vector<QGraphicsItemGroup*> VectorArrows;
public:
    Graph();
    int GetSize();
    int GetNumber();
    void IncreaseNumber();
    void NewSizeMatrix(int);
    void AddLastNode(QGraphicsEllipseItem*, QGraphicsItemGroup*);
    void DelNode(int);
    void SetDelNumber(int);
    int GetLastDelNumber();
    int** GetMatrix();
    QGraphicsItemGroup** GetGroupMatrix() const;
    void NewGroupMatrix(int, QGraphicsItemGroup*);
    void NewEllipseMatrix(int, QGraphicsEllipseItem*);
    void AddEdge(int, int, int) const;
    void DelEdge(int, int) const;
    void PrintMatrix();
    QGraphicsEllipseItem** GetEllipseMatrix();
    vector<QGraphicsItemGroup*> &GetVectorArrows();
    void NewVector(vector<QGraphicsItemGroup*>&);
    void SolveTSP();
    ~Graph();
};

#endif // GRAPH_H
