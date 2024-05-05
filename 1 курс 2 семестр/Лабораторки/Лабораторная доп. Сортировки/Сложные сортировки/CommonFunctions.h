#pragma once
#include <iostream>

using namespace std;

struct Series
{
    int* elements;
    int lenght;

    void PrintSeriers()
    {
        if (lenght <= 0)
            return;

        cout << elements[0];
        for (int i = 1; i < lenght; i++)
            cout << " " << elements[i];

        cout << endl;
    }
};

void HoareQuickSorting(int* Arr, int startIndex, int endIndex)
{
    //Åñëè èíäåêñ íà÷àëñÿ <= èíäåêñ êîíöà
    if (startIndex <= endIndex)
    {
        int middleElement = Arr[(startIndex + endIndex) / 2]; //Íàõîäèì ñðåäíèé ýëåìåíò

        //Çàâîäèì èíäåêñû ëåâîãî è ïðàâîãî ýëåìåíòîâ
        int LeftIndex = startIndex;
        int RightIndex = endIndex;

        while (LeftIndex <= RightIndex) //Ïîêà ëåâûé èíäåêñ <= ïðàâîãî
        {
            while (Arr[LeftIndex] < middleElement) //Ïîêà çíà÷åíèå ïî ëåâîìó èíäåêñó < ñðåäíåãî ýëåìåíòà
                LeftIndex++; //Óâåëè÷èâàåì ëåâûé èíäåêñ

            while (Arr[RightIndex] > middleElement) //Ïîêà çíà÷åíèå ïî ïðàâîìó èíäåêñó > ñðåäíåå çíà÷åíèå
                RightIndex--; //Óìåíüøàåì ïðàâûé èíäåêñ

            if (LeftIndex <= RightIndex) //Åñëè ëåâûé èíäåêñ <= ïðàâîãî
            {
                //Ìåíÿåì çíà÷åíèå ïî íèì ìåñòàìè
                int tmp = Arr[LeftIndex];
                Arr[LeftIndex] = Arr[RightIndex];
                Arr[RightIndex] = tmp;

                LeftIndex++; //Óâåëè÷èâàåì ëåâûé èíäåêñ
                RightIndex--; //Óìåíüøàåì ïðàâûé èíäåêñ
            }
        }

        HoareQuickSorting(Arr, startIndex, RightIndex); //Óõîäèì â ðåêóðñèþ. Íà÷àëî íå ìåíÿåì, êîíåö = ïðàâûé èíäåêñ
        HoareQuickSorting(Arr, LeftIndex, endIndex); //Íà÷àëî = ëåâûé èíäåêñ, êîíåö íå ìåíÿåì
    }
}

void HoareQuickSorting(int* Arr, int Lenght)
{
    if (Lenght > 1)
        HoareQuickSorting(Arr, 0, Lenght - 1); //Çàïóñêàåì ðåêóðñèþ ñ íà÷àëüíûì èíäåêñîì 0 è èíäåêñîì êîíöà ìàññèâà  
}

Series MergeSeries(Series& SeriesOne, Series& SeriesTwo)
{
    Series NewSeries;
	NewSeries.elements = new int[SeriesOne.lenght + SeriesTwo.lenght];

	for (int i = 0; i < SeriesOne.lenght; i++)
		NewSeries.elements[i] = SeriesOne.elements[i];

	int counter = SeriesOne.lenght;

	for (int i = 0; i < SeriesTwo.lenght; i++)
	{
		NewSeries.elements[counter] = SeriesTwo.elements[i];
		counter++;
	}

	NewSeries.lenght = SeriesOne.lenght + SeriesTwo.lenght;

	HoareQuickSorting(NewSeries.elements, NewSeries.lenght);

	return NewSeries;
}

void RemoveElement(Series* Arr, int Index, int Lenght)
{
	delete[] Arr[Index].elements;
	for (int i = Index; i < Lenght - 1; i++)
		Arr[i] = Arr[i + 1];
}