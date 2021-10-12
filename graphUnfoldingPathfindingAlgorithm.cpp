// graphUnfoldingPathfindingAlgorithm.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <iterator>
#include "graph.h"
#include "scanGraph.h"
#include "DijkstraAlgorithm.h"
#include "tactCalculation.h"
#include <clocale>

int main()
{
    setlocale(LC_CTYPE, "Russian");
    Graph mainGraph;
    /*
    mainGraph.Push({ 1, 2, 3 }, { 1000, 1200, 5000 }, { 60, 80, 70 });
    mainGraph.Push({ 0, 3 }, { 1000, 3000 }, { 60, 90 });
    mainGraph.Push({ 0, 3 }, { 1200, 2500 }, { 80, 90 });
    mainGraph.Push({ 1, 2 }, { 3000, 2500 }, { 90, 90 });
    /*
    mainGraph.Push({ 1, 2, 3 }, { 5367, 5798, 14876 }, { 60, 80, 70 });
    mainGraph.Push({ 0, 3 }, { 5367, 7654 }, { 60, 90 });
    mainGraph.Push({ 0, 3 }, { 5798, 9258 }, { 80, 90 });
    mainGraph.Push({ 1, 2 }, { 7654, 9258 }, { 90, 90 });
    
    /**/
    mainGraph.Push({ 4 }, { 14876 }, { 70 });
    mainGraph.Push({ 2, 3 }, { 5367, 7654 }, { 60, 90 });
    mainGraph.Push({ 1, 4 }, { 5367, 9258 }, { 80, 90 });
    mainGraph.Push({ 1, 4, 5 }, { 7654, 7983, 10493 }, { 90, 90, 80 });
    mainGraph.Push({  2, 3, 5 }, { 9258, 7983, 11493 }, { 90, 90, 80 });
    mainGraph.Push({ 3, 4 }, { 10493, 11493 }, { 80, 90 });
    //cout << mainGraph.checkQuantityApex() << endl;
    
    mainGraph.Print();
    Scan scan;
    scan.Initialization(mainGraph);
    scan.Print();
    TactCalculation tactCalculation;
    tactCalculation.Initialization(mainGraph);
    tactCalculation.Print();
    DijkstraAlgoritm algorithm;
    algorithm.SearchTrack(tactCalculation, 1, 0);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
