````````````````````````````````````````````````````````````````````````````````````````````````````````````1````````````````````````````````````````````````````````````````````````````````````````````````````
#include<bits/stdc++.h>
using namespace std;

double f(double a){
    return (a*a) + (5*a) + 6;
}

void findAns(double a, double b){

    double prev = a;

    if(f(a) * f(b) > 0){
        cout << "Root not found";
    }
    else{
        double current = (a+b)/2.00;
        while(abs(current - prev) > 0.0002){
            prev = current;
            cout << current << endl ;
            if(f(a) * f(current) < 0){
                b = current;
            }
            else if(f(b) * f(current) < 0){
                a = current;
            }
            else cout << "Root Found" << endl;

            current = (a+b)/2.00;
        }
    }
}

int main(){

    findAns(-4,-2.5);
}






