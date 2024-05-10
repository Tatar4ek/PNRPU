#include "graph.h"
#include <QDebug>
#include <algorithm>
#include <limits>
#include <vector>

Graph::Graph()
{
    SizeMatrix = 1;
    CurNumber = 1;
    Matrix = new int*[SizeMatrix];
    for (int i = 0; i < SizeMatrix; i++)
    {
        Matrix[i] = new int [SizeMatrix];
    }
    Matrix[0][0] = 0;
    EllipseMatrix = new QGraphicsEllipseItem* [SizeMatrix];
    EllipseMatrix[0] = nullptr;
    GroupMatrix = new QGraphicsItemGroup* [SizeMatrix];
    EllipseMatrix[0] = nullptr;
}
int Graph::GetSize()
{
    return SizeMatrix;
}
int Graph::GetNumber()
{
    return CurNumber;
}
void Graph::IncreaseNumber()
{
    CurNumber += 1;
}
void Graph::NewSizeMatrix(int dif)
{
    // Создаем новую матрицу и заполняем значениями из текущей матрицы
    int** NewMatrix = new int*[SizeMatrix + dif]();
    for (int i = 0; i < SizeMatrix + dif; i++)
    {
        NewMatrix[i] = new int[SizeMatrix + dif]();
        if (i < SizeMatrix)
        {
            copy(Matrix[i], Matrix[i] + SizeMatrix, NewMatrix[i]);
            // Заполняем нулями новые строки и столбцы
            fill(NewMatrix[i] + SizeMatrix, NewMatrix[i] + SizeMatrix + dif, 0);
            fill(NewMatrix[i] + SizeMatrix, NewMatrix[i] + SizeMatrix + dif, 0);
        }
    }

    // Удаляем старую матрицу
    for (int i = 0; i < SizeMatrix; i++)
    {
        delete[] Matrix[i];
    }
    delete[] Matrix;

    // Обновляем матрицу
    Matrix = NewMatrix;

    // Обновляем массив узлов QGraphicsEllipseItem
    QGraphicsEllipseItem** NewEllipseMatrix = new QGraphicsEllipseItem*[SizeMatrix + dif]();
    copy(EllipseMatrix, EllipseMatrix + SizeMatrix, NewEllipseMatrix);
    delete[] EllipseMatrix;
    EllipseMatrix = NewEllipseMatrix;

    // Обновляем массив групп элементов QGraphicsItemGroup
    QGraphicsItemGroup** NewGroupMatrix = new QGraphicsItemGroup*[SizeMatrix + dif]();
    copy(GroupMatrix, GroupMatrix + SizeMatrix, NewGroupMatrix);
    delete[] GroupMatrix;
    GroupMatrix = NewGroupMatrix;

    SizeMatrix += dif;
}


void Graph::AddLastNode(QGraphicsEllipseItem* Node, QGraphicsItemGroup* group)
{
    Matrix[0][SizeMatrix-1] = CurNumber;
    Matrix[SizeMatrix-1][0] = CurNumber;
    EllipseMatrix[SizeMatrix-1] = Node;
    GroupMatrix[SizeMatrix-1] = group;
}


void Graph::DelNode(int num)
{
    int CurSize = GetSize();
    for (int i = num; i < CurSize-1; ++i)
    {
        for (int j = 0; j < CurSize; ++j)
        {
            if (i < num || j < num)
                Matrix[i][j] = Matrix[i][j];
            else
                Matrix[i][j] = Matrix[i+1][j+1];
        }
    }
    int** NewMatrix = new int*[CurSize-1];
    for (int i = 0; i < CurSize - 1; ++i)
    {
        NewMatrix[i] = new int[CurSize-1];
    }
    for (int i = 0; i < CurSize - 1; ++i)
    {
        for (int j = 0; j < CurSize - 1; ++j)
        {
            NewMatrix[i][j] = Matrix[i][j];
        }
    }
    delete[] Matrix;
    Matrix = NewMatrix;

    QGraphicsEllipseItem** NewEllipseMatrix = new QGraphicsEllipseItem*[CurSize-1];
    QGraphicsItemGroup** NewGroupMatrix = new QGraphicsItemGroup*[CurSize-1];
    for (int i = 0; i < num; ++i)
    {
        NewEllipseMatrix[i] = EllipseMatrix[i];
        NewGroupMatrix[i] = GroupMatrix[i];
    }

    for (int i = num + 1; i < CurSize; ++i)
    {
        NewEllipseMatrix[i - 1] = EllipseMatrix[i];
        NewGroupMatrix[i - 1] = GroupMatrix[i];
    }
    delete[] EllipseMatrix;
    delete[] GroupMatrix;
    EllipseMatrix = NewEllipseMatrix;
    GroupMatrix = NewGroupMatrix;
    SizeMatrix--;
    CurNumber--;
    for (int i = 0; i < SizeMatrix; ++i)
    {
        Matrix[0][i] = i;
        Matrix[i][0] = i;
    }
}

void Graph::SolveTSP() {
    int n = GetSize() - 1;  // Исключаем фиктивную вершину, реальные вершины начинаются с индекса 1
    if (n < 2) {
        qDebug() << "Граф должен содержать минимум 2 вершины.";
        return;
    }

    int min_cost = std::numeric_limits<int>::max();  // Инициализация минимальной стоимости
    std::vector<int> min_route;  // Для хранения лучшего маршрута
    std::vector<bool> visited(n + 1, false);  // Посещенные вершины
    std::vector<int> path;  // Текущий путь
    path.reserve(n);

    // Функция для рекурсивного поиска маршрута
    std::function<void(int, int)> dfs = [&](int current, int cost) {
        path.push_back(current);
        if (path.size() == n && Matrix[current][1] > 0) {  // Замыкание цикла
            cost += Matrix[current][1];
            if (cost < min_cost) {
                min_cost = cost;
                min_route = path;
            }
            path.pop_back();
            return;
        }

        visited[current] = true;
        for (int next = 1; next <= n; ++next) {
            if (!visited[next] && Matrix[current][next] > 0) {
                dfs(next, cost + Matrix[current][next]);
            }
        }
        visited[current] = false;
        path.pop_back();
    };

    // Начинаем обход с первой реальной вершины
    dfs(1, 0);

    // Вывод результатов
    if (min_cost == std::numeric_limits<int>::max()) {
        qDebug() << "Решение не найдено";
    } else {
        QString result = "Минимальная стоимость: " + QString::number(min_cost) + "; Маршрут: ";
        for (size_t i = 0; i < min_route.size(); ++i) {
            result += QString::number(min_route[i]);
            if (i < min_route.size() - 1) result += " -> ";
        }
        result += " -> 1";  // Возвращаемся в начальную точку
        qDebug() << result;
    }
}



QGraphicsEllipseItem** Graph::GetEllipseMatrix()
{
    return EllipseMatrix;
}

int** Graph::GetMatrix()
{
    return Matrix;
}

QGraphicsItemGroup** Graph::GetGroupMatrix() const
{
    return GroupMatrix;
}

void Graph::NewGroupMatrix(int index, QGraphicsItemGroup* group)
{
    GroupMatrix[index] = group;
}

void Graph::NewEllipseMatrix(int index, QGraphicsEllipseItem* node)
{
    EllipseMatrix[index] = node;
}

vector<QGraphicsItemGroup*> &Graph::GetVectorArrows()
{
    return VectorArrows;
}

void Graph::NewVector(vector<QGraphicsItemGroup*>& vect)
{
    VectorArrows = vect;
}

void Graph::AddEdge(int from, int to, int weight) const
{
    Matrix[to][from] = weight;
    Matrix[from][to] = weight;
}

void Graph::DelEdge(int from, int to) const
{
    Matrix[to][from] = 0;
    Matrix[from][to] = 0;
}

void Graph::PrintMatrix()
{
    for (int i = 0; i < SizeMatrix; i++)
    {
        QString RowString;
        for (int j = 0; j < SizeMatrix; j++)
        {
            RowString += QString::number(Matrix[i][j]) + " ";
        }
        qDebug() << RowString;
    }
    qDebug() << endl;
}

Graph::~Graph()
{
    for (int i = 0; i < SizeMatrix; i++)
    {
        delete[] Matrix[i];
        delete[] EllipseMatrix[i];
        delete[] GroupMatrix[i];
    }
    delete[] Matrix;
    delete[] EllipseMatrix;
    delete[] GroupMatrix;
}
