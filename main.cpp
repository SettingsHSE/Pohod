#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Основная задача - реализовать данный метод
int countMaxCross(string& riverMap)
{
    int answer = 0;

    std::string tmp;
    for (auto &c : riverMap) {
        if (c == 'B')
            answer++;
        else
            tmp += c;
    }
    tmp += ";;";

    char place = 'L';

    for (int i = 0; i < tmp.length() - 1; i++)
    {
        if (place == 'L')
        {
            if (tmp[i] == 'L' && tmp[i + 1] == 'L')
            {
                answer++;
                place = 'R';
                i++;
            }
            else if (tmp[i] == 'L' && tmp[i + 1] == 'R')
                answer++;
            else if ((tmp[i] == 'L' && tmp[i + 1] == ';' ) || tmp[i] == ';')
            {
                answer++;
                break;
            }
        }
        if (place == 'R')
        {
            if (tmp[i] == 'R' && tmp[i + 1] == 'R')
            {
                answer++;
                place = 'L';
                i++;
            }
            else if ((tmp[i] == 'R' && tmp[i + 1] == 'L') || (tmp[i] == 'R'))
                answer++;
        }
    }


    return answer;
}


int main()
{
    string riverMap;
    int res;

    ifstream fin;
    fin.open("input.txt");
    if (fin.is_open())
    {
        getline(fin, riverMap);
        fin.close();
    }

    res = countMaxCross(riverMap);

    fstream fout;
    fout.open("output.txt", ios::out);
    fout << res;
    fout.close();

    return 0;
}