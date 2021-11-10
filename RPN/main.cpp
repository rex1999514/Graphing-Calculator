#include <iostream>
#include "shunting_yard.h"
#include "rpn.h"
#include "evaluate.h"
#include "tokenize.h"

using namespace std;

int main()
{
    string str("2 + 3");
//        char ch[] = " 2 * ln ( 1 ) ";
            Evaluate e(str);
//    for (int i = 0; i < 10; i++)
//    {
//        Evaluate e(str, i);
//        cout << "Result is " << e.eval() << endl;
//    }
            cout << "Result is " << e.eval() << endl;
//        Queue<Token*> result;
//        char ch = 'C';
//        string str("2+sin(3.1415926/6)^3*2");
//        Tokenize t;
//        t.Tokenizing(str, result);
//        while (toupper(ch) != 'X')
//        {
//            cout << *result.pop();
//            cin >> ch;
//        }
    return 0;
}
