#include<bits/stdc++.h>
using namespace std;

class Shape{
    protected:
        int height;
        int weidht;
    public:
        void setHeight(int h){
            height=h;
        }
        void setWeidth(int w){
            weidht=w;
        }
};

class Reactangle : public Shape{//syntax for dervided class with public mode.
    public :
        int area(){
            return (height*weidht);
        }
};

int main(){
    Reactangle re;
    re.setHeight(3);
    re.setWeidth(4);
    cout<<re.area();
}


