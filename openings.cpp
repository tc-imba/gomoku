//
// Created by liu on 2016/11/22.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

int main()
{
    ofstream out("openings.txt");
    int order[3] = {0, 2, 1};
    for (int i = 1; i <= 26; i++)
    {
        stringstream ss;
        string num;
        ss << i;
        ss >> num;
        string filename = "./openings/opening";
        filename += num + ".json";
        ifstream in(filename);
        string temp;
        char c;
        int a[3][2] = {};
        for (int j = 0; j < 3; j++)
        {
            getline(in, temp);
            in >> c >> a[j][0] >> c >> a[j][1];
        }
        in.close();
        for (int j = 0; j < 3; j++)
        {
            out << "openings[" << i - 1 << "][" << order[j] << "].x=" << a[j][0] << ";" << endl;
            out << "openings[" << i - 1 << "][" << order[j] << "].y=" << a[j][1] << ";" << endl;
        }
        out << endl;
    }
    out.close();
    return 0;
}