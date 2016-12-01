//
// Created by liu on 2016/11/22.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

struct Position
{
    int x, y;
};

Position getPos(string str)
{
    stringstream ss(str);
    char c;
    int n;
    ss >> c >> n;
    n = 15 - n;
    Position pos;
    pos.x = n;
    pos.y = c - 'A';
    return pos;
}


int main()
{

    int openings[26][3][2] = {};
    ofstream out("includes/openings.h");
    int order[3] = {0, 2, 1};
    out << "const int openings[OPENING_NUM][3][2]={";
    for (int i = 0; i < 26; i++)
    {
        stringstream ss;
        string num;
        ss << i + 1;
        ss >> num;
        string filename = "./openings/opening";
        filename += num + ".json";
        ifstream in(filename);
        string temp;
        char c;
        //int a[3][2] = {};
        for (int j = 0; j < 3; j++)
        {
            getline(in, temp);
            in >> c >> openings[i][j][0] >> c >> openings[i][j][1];
        }
        in.close();
        out << "{";
        for (int j = 0; j < 3; j++)
        {
            out << "{" << openings[i][order[j]][0] << "," << openings[i][order[j]][1] << "},";
            //out << "openings[" << i << "][" << order[j] << "].x=" << openings[i][j][0] << ";" << endl;
            //out << "openings[" << i << "][" << order[j] << "].y=" << openings[i][j][1] << ";" << endl;
        }
        out << "},";
    }
    out << "};" << endl;
    ifstream in("./openings/formula.txt");
    out << "const char* formula[OPENING_NUM][4]={";
    int formula_pos[26][2] = {};
    for (int i = 0; i < 26; i++)
    {
        int n, a, b;
        in >> n >> a >> b;
        if (n != i + 1)
        {
            cerr << "File Error at fornula " << i + 1 << endl;
            return -1;
        }
        formula_pos[i][0] = a;
        formula_pos[i][1] = b;
        string temp;
        getline(in, temp);
        out << "{";
        for (int j = 0; j < a; j++)
        {
            string str;
            getline(in, temp);
            out << "\"" << temp << " \",";
            stringstream ss(temp);
            ss >> str;
            auto pos = getPos(str);
            while (!ss.eof())
            {
                ss >> str;
            }
        }
        out << "},";
        getline(in, temp);
    }
    out << "};" << endl;
    out << "const int formula_pos[OPENING_NUM][2]={";
    for (int i = 0; i < 26; i++)
    {
        out << "{" << formula_pos[i][0] << "," << formula_pos[i][1] << "},";
    }
    out << "};" << endl;
    out.close();
    return 0;
}