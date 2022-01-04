// graphUnfoldingPathfindingAlgorithm.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <iterator>
#include "graph.h"
#include "modifiedLeeAlgorithm.h"
#include "timeGraph.h"
#include "nextNodeAlgorithm.h"
#include "restrictedArea.h"
#include "routeManager.h"
#include <clocale>
#include <cstdlib>

int main()
{
    setlocale(LC_CTYPE, "Russian");
    Graph mainGraph;
    mainGraph.Push({ 1, 2, 5 });//0,1,2
    mainGraph.Push({ 0, 2, 3 });//3,4,5
    mainGraph.Push({ 0, 1, 3, 5 });//6,7,8,9
    mainGraph.Push({ 1, 2, 4 });//10,11,12
    mainGraph.Push({ 3, 5 });//13,14
    mainGraph.Push({ 0, 2, 4 });//15,16,17
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

    
    vector<GTN*> routes;


    
   RestrictedArea r= RestrictedArea(gEdge.GetEdge(2), 4 , 9 );
    //RestrictedArea a = RestrictedArea(gEdge.GetEdge(12), 10, 12);
   /*
    NextNodeAlgorithm alg;

   ModifiedLeeAlgoritm finder = ModifiedLeeAlgoritm(alg);

    GTN res = finder.SearchWay(gEdge.GetEdge(6), gEdge.GetEdge(13), 4);
    routes.push_back(&res);
    res.PrintPath();
    
    GTN res1 = finder.SearchWay(gEdge.GetEdge(6), gEdge.GetEdge(13), 0 );
    routes.push_back(&res1);
    res1.PrintPath();

    GTN res2 = finder.SearchWay(gEdge.GetEdge(6), gEdge.GetEdge(13), 0);
    routes.push_back(&res2);
    res2.PrintPath();
   */

    RouteManager RManager=RouteManager(&gEdge);
    RManager.AddRoute(10, gEdge.GetEdge(6), gEdge.GetEdge(13), 4);
    RManager.DeleteRoute(10);
    RManager.AddRoute(10, gEdge.GetEdge(6), gEdge.GetEdge(13), 4);
    //RManager.AddRoute(10, gEdge.GetEdge(6), gEdge.GetEdge(13), 0);
    //RManager.AddRoute(10, gEdge.GetEdge(6), gEdge.GetEdge(13), 0);
}
