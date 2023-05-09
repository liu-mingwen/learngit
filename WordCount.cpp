#include<iostream>
#include<ctype.h>
#include<string>
#include<string.h>
#include<fstream>
using namespace std;
#define OUT 0
#define IN 1
int staute=OUT;
int count_alpha(char* filename)
{
    ifstream in(filename);
    in.seekg(0,in.end);
    int len=in.tellg();
    in.close();
    return len;
}

int count_word(char* filename)
{
    ifstream in(filename);
    char ch;
    int count=0;
    while((ch=in.get())!=EOF)
    {
        //if(ch=='-') continue;
        if(isalpha(ch))
        {
            if(staute==OUT) {
                staute=IN;
                count++;
            }
        }else{
            if(staute==IN){
                staute=OUT;
            }
        }
    }
    in.close();
    return count;
}
int main(int argc,char*argv[])
{
    if(argc<3) return -1;
    string option(argv[1]);
    if(option=="-c")
        cout << count_alpha(argv[2])<<endl;
    else if(option=="-w")
        cout << count_word(argv[2])<<endl;
    return 0;
}

