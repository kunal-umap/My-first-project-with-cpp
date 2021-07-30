#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

void Reg_output_1()
{

    cout << "\n\n\n";

    cout << "PRESS 1 -> Registered Components\n";

    cout << "PRESS 2 -> Return Components\n";

    cout << "PRESS 3 -> EXIT\n";

    return;
}
void Reg_output_2()
{   
    cout << "\n\n\n";

    cout << "PRESS 1 To check Component Status\n";

    cout << "PRESS 2 To register other component\n";

    cout << "PRESS 3 To Exit REGISTER PORTAL\n";

    return;
}

int Random_No_generator(){

    int upper=999999,lower=100000;
    srand(time(NULL));
    int num=rand()%(upper-lower+1) + lower;
    
    return num;
}

class all
{

    private:

    volatile bool capacitor[21];

    volatile int cap_pin[21];

    volatile bool registor[21];

    volatile int reg_pin[21];

    string ic[14] = {"741", "8038", "3524", "555", "7404", "7408", "7432", "7486", "7400", "7402", "MAX232", "ADC0808", "LM324", "L2930"};

    volatile bool ic_check[14];

    volatile int ic_pin[14];

    public:

    void initialize_capacitor();

    void initialize_registor();

    void initialize_ic();

    void initialize_cap_pin();

    void initialize_reg_pin();

    void initialize_ic_pin();

    void regestration();

    void capacitor_regestration();

    void regestration_for_output2();

    void ic_regestration();

    void registor_regestration();

    void check_component_registered();

    void check_component_returned();

    void return_component();

    void return_capacitor();

    void return_registor();

    void return_ic();

};

void all :: check_component_registered(){

 cout<<"<-----Your component Status is ----->\n";

    cout<<"registered Capacitor--->\n";

    int count=1;

    for (int i=0;i<21;i++){

        if (capacitor[i]==true){
            
            cout<<"Capacitor registered no"<<count<<" is : "<<i+1<<"μF\n";

            count++;

        }
    }
    cout<<"registered Registor--->\n";

    count=1;

    for (int i=0;i<21;i++){

        if (registor[i]==true){
            
            cout<<"Registor registered no"<<count<<" is : "<<i+1<<"K\n";
            count++;

        }
    }
    cout<<"IC Registor--->\n";
    count =1;
    for (int i=0;i<14;i++){

        if (ic_check[i]==true){

            cout<<"I/C registered no"<<count<<" is : "<<ic[i]<<"\n";
            count++; 
            
        }

    }

    Reg_output_2();

    regestration_for_output2();

}

void all :: initialize_capacitor(){

    for(int i=0;i<21;i++){

        capacitor[i]=false;

    }
}

void all :: initialize_registor(){

    for(int i=0;i<21;i++){

        registor[i] = false;

    }
}

void all :: initialize_ic(){

    for(int i=0;i<14;i++){

        ic_check[i]=false;

    }
}

void all :: initialize_cap_pin(){

    for(int i=0;i<21;i++){

        cap_pin[i]=0;

    }

}

void all :: initialize_reg_pin(){

    for(int i=0;i<21;i++){

        reg_pin[i]=0;

    }

}

void all :: initialize_ic_pin(){

    for(int i=0;i<14;i++){

        ic_pin[i]=0;

    }

}

void all :: return_capacitor(){

    cout<<"\nEnter the no of capacitor you want to return : ";

    int a;

    cin>>a;

    cout<<endl;

    for(int i=0;i<a;i++){

        int temp;

        cout<<"Enter pin of capacitor "<<i+1<<"in __F"<<endl;

        cin>>temp;

        int check=0;

        for(int j =0;j<21;j++){

            if(cap_pin[j]==temp){

                capacitor[j]=false;

                check=1;

                cap_pin[j]=0;

            }

        }

        if(check==0){

            cout<<"This Pin Not Exist \nReturn Another Component : \n";

        }

    }

    cout<<"you have returned capacitor successfully!!!!!"<<endl;

    Reg_output_2();

    regestration_for_output2();

    return;
}

void all :: return_registor(){

    cout<<"\nEnter the no of registor you want to return : "<<endl;

    int a;

    cin>>a;

    cout<<endl;

    for(int i=0;i<a;i++){

        int temp;

        cout<<"Enter pin of Registor "<<i+1<<"in __F"<<endl;

        cin>>temp;

        int check=0;

        for(int j =0;j<21;j++){

            if(reg_pin[j]==temp){

                registor[j]=false;

                check=1;

                reg_pin[j]=0;

            }

        }

        if(check==0){

            cout<<"This Pin Not Exist \nReturn Another Component : \n";

        }

    }
    
    cout<<"you have returned registor successfully!!!!!"<<endl;

    Reg_output_2();

    regestration_for_output2();

    return;
}

void all :: return_ic(){

    cout<<"No of component you want to return : ";

    int n;

    cin>>n;

    for(int i=0;i<n;i++){

        int pin;

        cout<<"Enter Pin For component no "<<i+1<<" : ";

        cin>>pin;

        int check=0;

        for(int j=0;j<14;j++){

            if(ic_pin[j] == pin){

                ic_check[j]=false;

                check=1;

                ic_pin[j]=0;

            }

        }
        if(check==0){

            cout<<"This Pin Not Exist \nReturn Another Component : \n";

        }

    }
    cout<<"you have successfully returned!!! \nThank You!!";

    Reg_output_2();

    regestration_for_output2();
    
    return;
}


void all :: return_component(){

    cout<<"Which component you want to return : \nFor Capacitor press. 1\n For registor press. 2\n For IC press. 3\n";
    
    int n;

    cout<<"Enter input here : ";

    cin>>n;

    if(n==1){

        return_capacitor();

        return ;

    }else if(n==2){

        return_registor();

        return ;

    }else if(n==3){

        return_ic();

        return ;

    }else{

        cout<<"Invalid Input!!";

        regestration();

    }
    return ;

}


void all :: regestration_for_output2(){

    int What_To_Proceed;

    cout<<"Enter input here : ";

    cin >> What_To_Proceed;

    cout<<endl;

    if (What_To_Proceed ==1){

        check_component_registered();

        return ;

    }

    else if (What_To_Proceed ==2){

        regestration();

        return ;

    }

    else if (What_To_Proceed ==3){

        Reg_output_1();
        return ;

    }
    else{

        cout << "      INVALID VALUE!!!      ";

        Reg_output_2();

        regestration_for_output2();
       
    }

    return;

}

void all :: capacitor_regestration(){

    cout<<"\nEnter the no of capacitor you want to register : ";

    int a;

    cin>>a;

    cout<<endl;

    for(int i=0;i<a;i++){

        int temp;

        cout<<"Enter Capacitance of "<<i+1<<"in __μF : ";

        cin>>temp;

        if(capacitor[temp-1]!=true){

            capacitor[temp-1]=true;

            int pin;

            pin = Random_No_generator();

            cap_pin[temp-1]=pin;

            cout<<"Note That No This Is The Pin For This Component : "<<pin<<"\n";

        }else{

            cout<<"This Component Is Already Registered \nEnter Another Component : \n";

        }

    }
    cout<<"you have successfully regester!!! \nThank You!!";

    Reg_output_2();

    regestration_for_output2();

    return;

}

void all :: registor_regestration(){

    cout<<"\nEnter the no of registor you want to register : ";

    int a;

    cin>>a;

    cout<<endl;

    for(int i=0;i<a;i++){

        int temp;

        cout<<"Enter resistance of "<<i+1<<"in __K : ";

        cin>>temp;

        if(registor[temp-1]!=true){

            registor[temp-1]=true;

            int pin;

            pin = Random_No_generator();

            reg_pin[temp-1]=pin;

            cout<<"Note That No This Is The Pin For This Component : "<<pin<<"\n";

        }else{

            cout<<"This Component Is Already Registered \nEnter Another Component : \n";

        }

    }
    cout<<"you have successfully regester!!! \nThank You!!";

    Reg_output_2();

    regestration_for_output2();

    return;

}

void all :: ic_regestration(){

    cout<<"No of component you want to register : ";

    int n;

    cin>>n;

    cout<<"  \n      ENTER IN BOLD LETTER!!";

    for(int i=0;i<n;i++){

        string name;

        cout<<"Enter component no "<<i+1<<" : ";

        cin>>name;

        for(int j=0;j<14;j++){

            if(ic[j] == name){

                if(ic_check[j]!=true){

                    ic_check[j]=true;

                    int pin;

                    pin = Random_No_generator();

                    ic_pin[j]=pin;

                    cout<<"Note That No This Is The Pin For This Component : "<<pin<<"\n";


                }else{

                    cout<<"This Component Is Already Registered \nEnter Another Component : \n";

                }

            }
        }

    }
    cout<<"you have successfully regester!!!\n                 Thank You!!";

    Reg_output_2();

    regestration_for_output2();
    
    return;

}

void all :: regestration(){

    cout<<endl<<"Enter component you want to registerFor:\nFor Capacitor press. 1\n For registor press. 2\n For IC press. 3\n";

    int n;

    cout<<"Enter input here : ";

    cin>>n;

    if(n==1){

        capacitor_regestration();

        return ;

    }else if(n==2){

        registor_regestration();

        return ;

    }else if(n==3){

        ic_regestration();

        return ;

    }else{

        cout<<"Invalid Input!!";

        regestration();

    }
    return ;

}


int main(){

    all data;

    data.initialize_capacitor();

    data.initialize_ic();

    data.initialize_registor();

    data.initialize_cap_pin();

    data.initialize_reg_pin();
    
    data.initialize_ic_pin();


    cout << "                       @@@@@@ COMPONENTS @@@@@@\n\n";

    cout << "                          CAPACITOR               \n\n";

    for(int i=0;i<21;i++)
    {
        if(i==7 || i==14 ){

            cout<<endl;
        }

        cout << i+1 << " μF -> a"<< "   ";
    }

    cout << "\n                         REGISTOR   \n            \n";

    for(int i=0;i<21;i++)
    {
        if(i==7 || i==14 ){

            cout<<endl;
        }

        cout << i+1 << " K -> a"<< "   ";

    }

    cout << "\n                         I/C   \n            \n";

    string ic_component[14] = {"741", "8038", "3524", "555", "7404", "7408", "7432", "7486", "7400", "7402", "MAX232", "ADC0808", "LM324", "L2930"};

    for (int i = 0; i < 14; i++)
    {
        if (i == 7)
        {
            cout << "\n";
        }

        cout << "  " << ic_component[i] << " -> a";

    }
    Reg_output_1();

    int proceed_input;

    cout<<"Enter input here : ";

    cin>>proceed_input;

    while(proceed_input!=3){
        
        cout<<endl;

        if(proceed_input==1){

            data.regestration();

            Reg_output_1();

            cout<<"Enter input here : ";

            cin>>proceed_input;            

            

        }else if(proceed_input==2){

            data.return_component();

            Reg_output_1();

            cout<<"Enter input here : ";

            cin>>proceed_input;


        }else{

            cout<<"Invalid inputput!!\n";

            cout<<"Enter input here : ";

            cin>>proceed_input;
        
        }
        
    }
    cout<<"Thank you!";

    return 0;
}
