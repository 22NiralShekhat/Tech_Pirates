#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
class Calculate{
    public:
    int P,N;
    float R;
    void get(){
        cout<<"\n\t\t\t\t\t<-----------------Home Loan Interest Calculator----------------->"<<endl<<endl
            <<"Enter Amount Of Loan::";
        cin>>P;
        cout<<"\nEnter Rate Of Interst::";
        cin>>R;
        cout<<"\nEnter Year For Returning Entered Amount::";
        cin>>N;
    }
    void EMI(){
        float emi;
        float r = R / (12 * 100); // one month interest
        float n = N * 12; // one month period
        emi = (P * r * pow(1 + r, n)) / (pow(1 + r, n) - 1);
        float inte,pa,ra=P;
        cout<<"EMI\t\t-->  "<<fixed<<setprecision(0)<<emi<<endl;
        cout<<"Total Amount    -->  "<<emi*N*12<<endl;
        cout<<"Total Interest  -->  "<<emi*N*12-P<<endl<<endl;

        cout<<"Month\t|\tPrincipal Amount\t|\tinterest\t|\tRemaining Amount\n";
        for (int i = 0; i < N; i++)
        {
            inte=R*ra/1200;
            pa=emi-inte;
            cout<<fixed<<setprecision(0);
            for (int j = 0; j < 90; j++)
                cout<<"-";
                cout<<"\n";
            cout<<setw(2)<<i<<"\t|"<<"\t"<<pa<<"\t\t\t|\t"<<inte<<"\t\t|\t"<<ra<<endl;
            ra=ra-pa;      
        }
    }
};
int main(){
    Calculate c;
    c.get(); 
    c.EMI();
    return 0;
}