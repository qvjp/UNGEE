#ifndef __GRAPH_H
#define __GRAPH_H

#include "../../Common/src/types.h"
#define MAXVERTEXNUM 10

// [Begin] 邻接矩阵存储
struct Graph
{
    VertexType vex[MAXVERTEXNUM];
    int edge[MAXVERTEXNUM][MAXVERTEXNUM];
    int vexnum;        // 图当前顶点数
    int arcnum;        // 当前弧数
};
// [End] 邻接矩阵存储

// [Begin] 邻接表存储
struct AArcNode
{
    int adjvex;            // 该弧指向的顶点位置
    int weigh;             // 权值
    struct ArcNode *next;  // 该弧指向的下一条弧
};
struct AVexNode
{
    VertexType data;
    struct ArcNode *first;  // 指向从该顶点出发的第一条弧的指针
};
struct AGraph
{
    struct AVexNode adjList[MAXVERTEXNUM]; // 邻接表
    int vexnum;                           // 图的顶点数
    int arcnum;                           // 图的弧数
};
// [End] 邻接表存储

// [Begin] 十字链表存储
struct GArcNode
{
    int start;
    int end;
    struct GVexNode* nextin;
    struct GVexNode* nextout;
    int weight;

};
struct GVexNode
{
    VertexType data;
    struct GArcNode *firstin;
    struct GArcNode *firstout;
};
struct GGraph
{
    struct GVexNode list[MAXVERTEXNUM];
    int vexnum;
    int arcnum;
};
// [End] 十字链表存储

// [Begin] 邻接多重表
struct AMArcNode
{
    int ivex;
    int jvex;
    struct AMArcNode *inext;
    struct AMArcNode *jnext;
    int weight;
};
struct AMVexNode
{
    VertexType data;
    AMArcNode *firstedgt;
};
struct AMGraph
{
    struct AMVexNode list[MAXVERTEXNUM];
    int vexnum;
    int arcnum;
};
// [End] 邻接多重表


#endif /* __GRAPH_H */
