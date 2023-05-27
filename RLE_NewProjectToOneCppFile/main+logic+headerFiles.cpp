
#include <iostream>
#include <string>

using namespace std;


string converting_to_zip(string convert, int sizex, int sizey) {
    char w = 'w', b = ' b';
    int count = 1, count2 = 1;
    char char1, char2;
    bool flag = true;
    string msg = "";
    int all_size = sizex * sizey;

    for (int i = 0; i < all_size; i++)
    {
        char1 = convert[i];
        char2 = convert[i + 1];


        if (char1 != w and char1 != b)
        {
            return "Error input! Your gay";
        }

        if (char1 == char2)
        {
            count++;
        }
        else if (count != 1) {
            msg += to_string(count);
            msg += char1;
            flag = false;
            count = 1;
        }
        else {
            msg += char1;
            flag = false;
            count = 1;
        }


        if (count2 == sizex)
        {
            if (sizex - count < sizex and count > 2)
            {

                msg += to_string(count - 1);
                msg += char1;
            }
            else if (flag) {
                msg += char1;
                count = 1;
            }
            msg += "\n";
            count = 1;
            count2 = 0;
        }
        flag = true;
        count2++;
    }

    return msg;
}


int main() {
 /*   string convetirng_string;
    string string;
    int sizex, sizey;
    cout << "Input Y size picture: ";
    cin >> sizey;
    cout << "Input X size picture: ";
    cin >> sizex;
    getchar();

    cout << "Input your picture (w/b): " << endl;
    for (int i = 0; i < sizey; i++)
    {
        getline(cin, string);
        convetirng_string += string;
    }

    system("cls");
    cout << "Converting your picture to RLE\n" + converting_to_zip(convetirng_string, sizex, sizey);*/





    return 0;
}