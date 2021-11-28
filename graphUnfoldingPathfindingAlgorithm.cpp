// graphUnfoldingPathfindingAlgorithm.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <iterator>
#include "graph.h"
#include "DijkstraAlgorithm.h"
#include "timeGraph.h"
#include "nextNodeAlgorithm.h"
#include "restrictedArea.h"
#include <clocale>

int main()
{
    setlocale(LC_CTYPE, "Russian");
    //Graph mainGraph;
    vector<Edge> graph;
    

    //-------Wiki--------//
    graph.push_back(Edge(1, 2, 2));//0
    graph.push_back(Edge(1, 3, 3));//1
    graph.push_back(Edge(1, 6, 4));//2
    graph.push_back(Edge(2, 1, 2));//3
    graph.push_back(Edge(2, 3, 1));//4
    graph.push_back(Edge(2, 4, 5));//5
    graph.push_back(Edge(3, 1, 3));//6
    graph.push_back(Edge(3, 6, 12));//7
    graph.push_back(Edge(3, 4, 3));//8
    graph.push_back(Edge(3, 2, 1));//9
    graph.push_back(Edge(4, 5, 5));//10
    graph.push_back(Edge(4, 3, 3));//11
    graph.push_back(Edge(4, 2, 5));//12
    graph.push_back(Edge(6, 1, 4));//13
    graph.push_back(Edge(6, 3, 2));//14
    graph.push_back(Edge(6, 5, 3));//15
    graph.push_back(Edge(5, 6, 3));//16
    graph.push_back(Edge(5, 4, 5));//17
    graph[0].SetNext(vector<Edge*> { &graph[4], &graph[5], &graph[3]});
    graph[1].SetNext(vector<Edge*> { &graph[7], &graph[8], &graph[9], &graph[6]});
    graph[2].SetNext(vector<Edge*> { &graph[14], &graph[15], &graph[13]});
    graph[3].SetNext(vector<Edge*> { &graph[1], &graph[2], &graph[0]});
    graph[4].SetNext(vector<Edge*> { &graph[7], &graph[8], &graph[9], &graph[6]});
    graph[5].SetNext(vector<Edge*> { &graph[10], &graph[11], &graph[12]});
    graph[6].SetNext(vector<Edge*> { &graph[0], &graph[2], &graph[1]});
    graph[7].SetNext(vector<Edge*> { &graph[13], &graph[15], &graph[14]});
    graph[8].SetNext(vector<Edge*> { &graph[10], &graph[12], &graph[11]});
    graph[9].SetNext(vector<Edge*> { &graph[3], &graph[5], &graph[4]});
    graph[10].SetNext(vector<Edge*> { &graph[16], & graph[17]});
    graph[11].SetNext(vector<Edge*> { &graph[9], &graph[7], &graph[6], &graph[8]});
    graph[12].SetNext(vector<Edge*> { &graph[3], &graph[4], &graph[5]});
    graph[13].SetNext(vector<Edge*> { &graph[0], &graph[1], &graph[2]});
    graph[14].SetNext(vector<Edge*> { &graph[6], &graph[8], &graph[9], &graph[7]});
    graph[15].SetNext(vector<Edge*> { &graph[17], &graph[16]});
    graph[16].SetNext(vector<Edge*> { &graph[13], &graph[14], &graph[15]});
    graph[17].SetNext(vector<Edge*> { &graph[11], &graph[12], &graph[10]});
    //
    //RestrictedArea r=RestrictedArea(&graph[2], 4 , 6 );
    RestrictedArea a = RestrictedArea(&graph[6], 1, 3); 
    RestrictedArea c = RestrictedArea(&graph[15], 11, 12);
    /*
    graph.push_back( Edge(0, 2, 15));
    graph.push_back(Edge(0, 1, 5));
    graph.push_back(Edge(1, 2, 2));
    graph.push_back(Edge(2, 1, 2));
    graph.push_back(Edge(3, 0, 3));
    graph[0].SetNext(vector<Edge*> { &graph[3]} );
    graph[1].SetNext(vector<Edge*> { &graph[2]});
    graph[2].SetNext(vector<Edge*> { &graph[3]});
    graph[3].SetNext(vector<Edge*> { &graph[2]});
    graph[4].SetNext(vector<Edge*> { &graph[0], &graph[1]});
  */
    NextNodeAlgorithm alg;

    DijkstraAlgoritm finder = DijkstraAlgoritm(alg);
    GTN res = finder.SearchPath(graph[6], graph[17]);

    while (res.GetPrev() != nullptr) {
        cout << "(" << res.GetEdge().GetBegin() << ", " << res.GetEdge().GetEnd() << ") P:" << res.GetPlace() << " T:" << res.GetTime() << " S: " << res.GetStatusGTN() << endl;
        res = *res.GetPrev();
    }
    cout << "(" << res.GetEdge().GetBegin() << ", " << res.GetEdge().GetEnd() << ") P:" << res.GetPlace() << " T:" << res.GetTime() << " S: " << res.GetStatusGTN() << endl;



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
    
    /*
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
    */
 
}
/*
//-------Wiki--------//
graph.push_back(Edge(1, 2, 2));
graph.push_back(Edge(1, 3, 3));
graph.push_back(Edge(1, 6, 4));
graph.push_back(Edge(2, 1, 2));
graph.push_back(Edge(2, 3, 1));
graph.push_back(Edge(2, 4, 5));
graph.push_back(Edge(3, 1, 3));
graph.push_back(Edge(3, 6, 2));
graph.push_back(Edge(3, 4, 3));
graph.push_back(Edge(3, 2, 1));
graph.push_back(Edge(4, 5, 5));
graph.push_back(Edge(4, 3, 3));
graph.push_back(Edge(4, 2, 5));
graph.push_back(Edge(6, 1, 4));
graph.push_back(Edge(6, 3, 2));
graph.push_back(Edge(6, 5, 3));
graph.push_back(Edge(5, 6, 3));
graph.push_back(Edge(5, 4, 2));
graph[0].SetNext(vector<Edge> { graph[4], graph[5]});
graph[1].SetNext(vector<Edge> { graph[7], graph[8], graph[9]});
graph[2].SetNext(vector<Edge> { graph[14], graph[15]});
graph[3].SetNext(vector<Edge> { graph[1], graph[2]});
graph[4].SetNext(vector<Edge> { graph[7], graph[8], graph[9]});
graph[5].SetNext(vector<Edge> { graph[10], graph[11]});
graph[6].SetNext(vector<Edge> { graph[0], graph[2]});
graph[7].SetNext(vector<Edge> { graph[13], graph[15]});
graph[8].SetNext(vector<Edge> { graph[10], graph[12]});
graph[9].SetNext(vector<Edge> { graph[3], graph[5]});
graph[10].SetNext(vector<Edge> { graph[16]});
graph[11].SetNext(vector<Edge> { graph[9], graph[7], graph[6]});
graph[12].SetNext(vector<Edge> { graph[3], graph[4]});
graph[13].SetNext(vector<Edge> { graph[0], graph[1]});
graph[14].SetNext(vector<Edge> { graph[6], graph[8], graph[9]});
graph[15].SetNext(vector<Edge> { graph[17]});
graph[16].SetNext(vector<Edge> { graph[13], graph[14]});
graph[17].SetNext(vector<Edge> { graph[11], graph[12]});
//
*/
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
