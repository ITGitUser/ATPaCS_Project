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
/*
int GetGraphIndex(vector<Edge> evec, Edge e) {
    for (int i = 0; i < evec.size(); i++)
    {
        if (evec[i].GetBegin() == e.GetBegin() &&
            evec[i].GetEnd() == e.GetEnd())
        {
            return i;
        }
        
    }
};
*/
int main()
{
    setlocale(LC_CTYPE, "Russian");
    Graph mainGraph;
    mainGraph.Push({ 1, 2, 5 });
    mainGraph.Push({ 0, 2, 3 });
    mainGraph.Push({ 0, 1, 3, 5 });
    mainGraph.Push({ 1, 2, 4 });
    mainGraph.Push({ 3, 5 });
    mainGraph.Push({ 0, 2, 4 });
    GraphEdge gEdge= GraphEdge(mainGraph);
    gEdge.SetDistance(0, 2);
    gEdge.SetDistance(1, 3);
    gEdge.SetDistance(2, 4);
    gEdge.SetDistance(3, 2);
    gEdge.SetDistance(4, 1);
    gEdge.SetDistance(5, 5);
    gEdge.SetDistance(6, 3);
    gEdge.SetDistance(7, 1);
    gEdge.SetDistance(8, 3);
    gEdge.SetDistance(9, 12);
    gEdge.SetDistance(10, 5);
    gEdge.SetDistance(11, 3);
    gEdge.SetDistance(12, 5);
    gEdge.SetDistance(13, 5);
    gEdge.SetDistance(14, 3);
    gEdge.SetDistance(15, 4);
    gEdge.SetDistance(16, 2);
    gEdge.SetDistance(17, 3);
    //gEdge.Print();
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
    
    


    
    RestrictedArea r= RestrictedArea(gEdge.GetEdge(2), 4 , 6 );
   // gEdge.GetEdge(2)->AdLimit(4, 6);
    //RestrictedArea(&graph[2], 6, 6);
    //RestrictedArea(&graph[6], 1, 2); 
   //RestrictedArea(&graph[6], 2, 3, 1, 5);
    //RestrictedArea(&graph[15], 7, 11);
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
   // GTN res = finder.SearchPath(graph[6], graph[17]);

    GTN res = finder.SearchPath(gEdge.GetEdge(6), gEdge.GetEdge(13), 4);
    
    res.PrintPath();
    /*
    while (res.GetPrev() != nullptr) {
        cout << "(" << res.GetEdge().GetBegin() << ", " << res.GetEdge().GetEnd() << ") P:" << res.GetPlace() << " T:" << res.GetTime() << " S: " << res.GetStatusGTN() << endl;
        new RestrictedArea(&graph[GetGraphIndex(graph,res.GetEdge())], res.GetTime(), res.GetTime());
        res = *res.GetPrev();
    }
    cout << "(" << res.GetEdge().GetBegin() << ", " << res.GetEdge().GetEnd() << ") P:" << res.GetPlace() << " T:" << res.GetTime() << " S: " << res.GetStatusGTN() << endl;
    */

    //GTN res1 = finder.SearchPath(graph[6], graph[17]);
    GTN res1 = finder.SearchPath(gEdge.GetEdge(6), gEdge.GetEdge(13), 0 );
    res1.PrintPath();
    /*
    while (res1.GetPrev() != nullptr) {
        cout << "(" << res1.GetEdge().GetBegin() << ", " << res1.GetEdge().GetEnd() << ") P:" << res1.GetPlace() << " T:" << res1.GetTime() << " S: " << res1.GetStatusGTN() << endl;
        res1 = *res1.GetPrev();
    }
    cout << "(" << res1.GetEdge().GetBegin() << ", " << res1.GetEdge().GetEnd() << ") P:" << res1.GetPlace() << " T:" << res1.GetTime() << " S: " << res1.GetStatusGTN() << endl;
    */

   
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
