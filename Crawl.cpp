#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

int main() {
    int count;
    string text, img, file, find_img = "<img src=\"https://camo";

    //system("curl https://voz.vn/t/thu-tuong-anh-chap-nhan-tu-chuc.579379/page-1.html >> VOZ.txt");
    //https://voz.vn/attachments/1639063273139-png.913705/
    //if (text[i] == char(34) && text[i + 1] == char(32)) {
again:
    cout << "File name: ";
    cin >> file;
    fstream f1(file + ".txt");

    while (getline(f1, text)){
        if (text.find(find_img) != string::npos) {
            for (int i = 0; i <= text.length() - 2; i++) {
                if (text[i] == char(34) && text[i + 1] == char(32)) {
                    img = text.substr(10,i - 10);
                    time_t now = time(0);
                    system(("wget --user-agent=\"Mozilla/5.0 (X11; Fedora; Linux x86_64; rv:52.0) Gecko/20100101 Firefox/52.0\"" + img + " -O Picture_" + to_string(now) + ".jpg").c_str());
                    count++;
                    cout << img << endl;
                    cout << endl;
                    break;
                }             
            }
        }
    }
    f1.close();
    goto again;
}