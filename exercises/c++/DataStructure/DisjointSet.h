#ifndef _DISJOINt_SET_H_
#define _DISJOINt_SET_H_

#define ROOT -1
#include <vector>

//记录父节点的位置 和 该树的大小
class Node
{
public:
    int parent;
    int size;
    explicit Node(int parent, int size)
    {
        this->parent = parent;
        this->size = size;
    }
};

class DisjointSet
{
public:
    explicit DisjointSet(int size)
    {
        for (int i = 0; i < size; ++i)
        {    
            v.push_back(new Node(ROOT, 1));
        }
    } 

    ~DisjointSet()
    {
        for (std::vector<Node*>::const_iterator i = v.begin(); i != v.end(); ++i)
        {
            if (*i)
                delete (*i);
        }
    }

    int find(int pos)
    {
        if (v.at(pos)->parent == ROOT)
            return pos;
        return v.at(pos)->parent = find(v.at(pos)->parent);  //路径压缩
    }

    //对集合的根节点合并
    void unionSet(int pos1, int pos2)
    {
        int root1 = find(pos1);
        int root2 = find(pos2);
        if (root1 == root2) return;
        if (v.at(root1)->size >= v.at(root2)->size)
        {
            v.at(root2)->parent = root1;
            v.at(root1)->size += v.at(root2)->size;
        }
        else
        {
            v.at(root1)->parent = root2;
            v.at(root2)->size += v.at(root1)->size;   
        }
    }

    void initDebug()
    {
        for (std::vector<Node*>::iterator i = v.begin(); i != v.end(); ++i)
        {
            (*i)->parent = ROOT;
            (*i)->size = 1;
        }
    }
private:
    std::vector<Node*> v;
};

#endif