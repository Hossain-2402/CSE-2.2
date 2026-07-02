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
        // double current = a - ((f(a)*(b-a))/(f(b)-f(a))); // False position
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
            // double current = a - ((f(a)*(b-a))/(f(b)-f(a))); // False position
        }
    }
}

int main(){

    findAns(-4,-2.5);
}




























#include<bits/stdc++.h>
using namespace std;



double f(double x){
    double angle = x*x;
    return ((sin(angle)) + (x/3) - (x/2));
}

void findRoot(double a, double b){
    cout << fixed << setprecision(7);

    int counter = 0;
    double prev = a;
    if(f(a)*f(b) > 0){
        cout << "Invalid Interval" << endl;
        return;
    }

    double current = (a+b)/2.0;

    //cout << "No|\t   a|\t   b|\t   f(a)|\t   f(b)|\t   x0|\t   f(x0)|\t   Rel Error|\t   Interval|\t   Update|\t   " << endl;

    cout <<"No|" << setw(8) << "a|" << setw(16) << "b|" << setw(18) << "f(a)|" << setw(18) << "f(b)" << setw(12) << "x0" << setw(18) << "f(x0)" << setw(18) << "Rel Error" << setw(18) << "Interval" << setw(8) << "Update"  << endl;



    while(fabs((current-prev)/current) >= 0.00001){

        double error = fabs((current-prev)/current);
        prev = current;



        if(f(a)*f(current) < 0){
            b = current;
            cout << counter+1 << "\t" << a << "\t" << b << "\t" << f(a) << "\t" << f(b) << "\t" << current << "\t" << f(current) << "\t" << error << "\t" << b-a << "\t" << "b" << endl;
        }
        else if(f(b)*f(current) < 0){
            a = current;

            cout << counter+1 << "\t" << a << "\t" << b << "\t" << f(a) << "\t" << f(b) << "\t" << current << "\t" << f(current) << "\t" << error << "\t" << b-a << "\t" << "a" << endl;
        }
        else{
            cout << "Root Found" << endl;
        }


        current = (a+b)/2.00;


        counter ++;
    }

    cout << endl << "Final Root(approx): " << current << endl ;
    cout << "Total iterations: " << counter;



}

int main(){

    findRoot(1,2);

}

