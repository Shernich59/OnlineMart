#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include <ctime>
#include <windows.h>
#include <climits>

using namespace std;

void showchoice ();
void ReadFromFile(string [], double [], double [],const int );
void displayFromFile(string [], double [], double []);
double cdis_applied(double);
double cdis_total(double);
double mdis_applied(double);
double mdis_total(double);
double s_subsidy(double);
double sdis_applied(double,double);


//********************************
// Main Function of Program
//********************************
int main()
{
    //declare array
    const int Array_size = 8;
    string itemArray[Array_size];
    double priceArray[Array_size];
    double M_priceArray[Array_size];

    string name;
    string m_keycode = "MEMBER";
    string s_keycode = "STAFF";

    int choice;
    int itemcode;
    int n1=0,n2=0,n3=0,n4=0,n5=0,n6=0,n7=0,n8=0,num1=0,num2=0,num3=0,num4=0,num5=0,num6=0,num7=0,num8=0;
    double sum1=0,sum2=0,sum3=0,sum4=0,sum5=0,sum6=0,sum7=0,sum8=0;
    double msum1=0,msum2=0,msum3=0,msum4=0,msum5=0,msum6=0,msum7=0,msum8=0,msum;
    double discount,amount,c_totaldiscount,m_totaldiscount,subsidy;
    double custotal=0, membertotal=0, stafftotal=0;
    char *L = " ---------------------------------------------------------------------------------\n";

    time_t ttime = time(0);
    char* dt = ctime(&ttime);
    HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);

     ReadFromFile(itemArray, priceArray, M_priceArray,Array_size);
     showchoice();
     cin >> choice;

     // Input validation
     while (cin.fail()){
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        SetConsoleTextAttribute(color,12);
        cout << "\t\t\t\t You can only enter numbers.\n";
        cout << "\t\t\t\t Please re-enter your choice :";
        SetConsoleTextAttribute(color, 7);
        cin >> choice;
    }

     switch(choice){
     case 1 :
              break;
     case 2 : system("cls");
              cout << "\t\t\t\tPlease Enter Member's secret KEYCODE : ";
              cin  >> m_keycode;
              cout << endl;
                while (m_keycode != "MEMBER"){
                   SetConsoleTextAttribute(color,12);
		           cout << "\t\t\t\tWRONG CODE! Reenter again : ";
                   SetConsoleTextAttribute(color, 7);
		           cin >> m_keycode;
		           cout << endl;
                }
             SetConsoleTextAttribute(color, 14);
             cout << "\n\n\t\t********************   BIG MEMBER DISCOUNT % on some items    *************************\n\n";
             cout << "\n\n\t*************** BUY MORE, SAVE MORE !! enjoy 5% discount if total buy reached RM 300 !! *******************\n";
             system("pause");
             break;
    case 3 : system("cls");
             cout << "\t\t\t\tPlease Enter Staff's secret KEYCODE : ";
             cin  >> s_keycode;
             cout << endl;
               while (s_keycode != "STAFF"){
                  SetConsoleTextAttribute(color,12);
                  cout << "\t\t\t\tWRONG CODE! Reenter again : ";
                  SetConsoleTextAttribute(color,7);
                  cin >> s_keycode;
                  cout << endl;
                 }
             SetConsoleTextAttribute(color, 14);
             cout << "\n\n\t\t\t******************** Thanks for your Hardworking!! ****************************\n\n";
             cout << "\n\n\t\t\t\t*************** Special for you *******************\n";
             cout << "\n\n\t\t\t If purchase : 1. RM5-RM30           reductions of RM1.00\n";
             cout << "\n\n\t\t\t               2. RM31-RM99          reductions of RM5.00\n";
             cout << "\n\n\t\t\t               3. RM100 ++           reductions of RM10.00\n";
             system("pause");
             break;
    case 4 : SetConsoleTextAttribute(color,3);
             cout << "\n\t\t\t~~~~~~~~~~ Thanks for support Catherine Mart!~~~~~~~~~~~~ \n\n\t\t\t\t\t Have a nice day ~ \n";
             system("pause");
             return 0;
    default: SetConsoleTextAttribute(color, 12);
             cout << "\n\t\t\t\t\t\tInvalid Input! " << endl;
             cout << "\t\t\t\t\tSystem will close soon ~~~ " << endl;
             system("pause");
             return 0;
    }

    system("cls");
    SetConsoleTextAttribute(color, 15);
    cout << "\t\t\tPlease enter your name: ";
    cin.ignore();
    getline (cin, name, '\n');
    system("cls");

    cout << "\n\t\t\t\t\t\tDear "<<name << endl << endl;
    cout << "\t\t\t\t\tWelcome to Catherine Mart!!\n\n";
    cout << setw(70) << "\t\t========================  Items and Price Listing  ========================\n\n";
    cout << setw(30) << "Item"<< setw(25) <<"Price(RM)"<< setw(33) <<"Member Price(RM)\n";

    displayFromFile(itemArray, priceArray, M_priceArray);

    cout << endl;
    cout << "\t\t===========================================================================\n";

    cout << "\t\t\tWhat do you want to buy? Enter item code (1-8) : ";
          while (cin >> itemcode){
          switch (itemcode){
          case 1: cout <<"\t\t\tHow many " << itemArray[0] << " would u like to buy : ";
                  cin  >> num1;
                  if(choice==1 || choice==3){
                    amount = priceArray[0]*num1;
                    sum1 += amount;
                    n1 += num1;
                    }
                  else{
                    amount = M_priceArray[0]*num1;
                    msum1 += amount;
                    n1 += num1;
                    }
                  break;
          case 2: cout <<"\t\t\tHow many " << itemArray[1] << " would u like to buy : ";
                  cin  >> num2;
                  if(choice==1 || choice==3){
                    amount = priceArray[1]*num2;
                    sum2 += amount;
                    n2 += num2;
                    }
                  else{
                    amount = M_priceArray[1]*num2;
                    msum2 += amount;
                    n2 += num2;
                    }
                 break;
         case 3: cout <<"\t\t\tHow many " << itemArray[2] << " would u like to buy : ";
                 cin  >> num3;
                 if(choice==1 || choice==3){
                    amount = priceArray[2]*num3;
                    sum3 += amount;
                    n3 += num3;
                    }
                 else{
                    amount = M_priceArray[2]*num3;
                    msum3 += amount;
                    n3 += num3;
                    }
                 break;
         case 4: cout <<"\t\t\tHow many " << itemArray[3] << " would u like to buy : ";
                 cin  >> num4;
                 if(choice==1 || choice==3){
                    amount = priceArray[3]*num4;
                    sum4 += amount;
                    n4 += num4;
                    }
                 else{
                    amount = M_priceArray[3]*num4;
                    msum4 += amount;
                    n4 += num4;
                    }
                 break;
         case 5: cout <<"\t\t\tHow many " << itemArray[4] << " would u like to buy : ";
                 cin  >> num5;
                 if(choice==1 || choice==3){
                    amount = priceArray[4]*num5;
                    sum5 += amount;
                    n5 += num5;
                    }
                 else{
                    amount = M_priceArray[4]*num5;
                    msum5 += amount;
                    n5 += num5;
                    }
                 break;
         case 6: cout <<"\t\t\tHow many " << itemArray[5] << " would u like to buy : ";
                 cin  >> num6;
                 if(choice==1 || choice==3){
                    amount = priceArray[5]*num6;
                    sum6 += amount*num6;
                    n6 += num6;
                    }
                 else{
                    amount = M_priceArray[5];
                    msum6 += amount;
                    n6 += num6;
                    }
                 break;
        case 7:  cout <<"\t\t\tHow many " << itemArray[6] << " would u like to buy : ";
                 cin  >> num7;
                 if(choice==1 || choice==3){
                    amount = priceArray[6]*num7;
                    sum7 += amount;
                    n7 += num7;
                    }
                 else{
                    amount = M_priceArray[6]*num7;
                    msum7 += amount;
                    n7 += num7;
                    }
                 break;
         case 8: cout <<"\t\t\tHow many " << itemArray[7] << " would u like to buy : ";
                 cin  >> num8;
                 if(choice==1 || choice==3){
                    amount = priceArray[7]*num8;
                    sum8 += amount;
                    n8 += num8;
                    }
                 else{
                    amount = M_priceArray[7]*num8;
                    msum8 += amount;
                    n8 += num8;
                    }
                 break;
         default:SetConsoleTextAttribute(color, 12);
                 cout << "\n\t\t\tInvalid input. Please try again.\n";
                 break;
        } // end switch
     SetConsoleTextAttribute(color, 7);
    cout << "\n\t\t\tEnter item code (1-8) for buying or any alphabet for checkout: ";
    } // end while


    system("cls");
    cout << "\t\t" << dt << "\t\t\t\t\t\t" << "CATHERINE MART " << endl;
    cout << "\t\t\t\t\t\t" << "Address : 54, ABC street" << endl;
    cout << "\t\t\t\t\t\t" << "Telp    : 123456789" << endl;
    cout << "\t\t" << L;
    cout << "\t\t" << setw(50) << " RECEIPT " << endl;
    cout << "\t\t" << L;
    cout << "\t\t ACQUIRENTI : " << name << endl;
    cout << "\t\t" << L;
    cout << "\t\t ITEM\t\t\t\tQUANTITY\tUNIT PRICE\tAMOUNT OF SALE\n";
    cout << "\t\t" << L;

//************
// Customer
//************

    if(choice==1){
       if(n1!=0)
          cout << "\t\t" << setw(10) << itemArray[0] << "\t\t\t   " << n1 << "\t\tRM  " << priceArray[0] <<"\t RM "<< sum1 <<"\n";
       else
          cout << "";
       if(n2!=0)
          cout << "\t\t" << setw(5) << itemArray[1] << "\t\t\t\t   " << n2 << "\t\tRM   " << priceArray[1] <<"\t RM "<< sum2 <<"\n";
       else
          cout << "";
       if(n3!=0)
          cout << "\t\t" << setw(12) << itemArray[2] << "\t\t\t   " << n3 << "\t\tRM   " << priceArray[2] <<"\t RM "<< sum3 <<"\n";
       else
          cout << "";
       if(n4!=0)
          cout << "\t\t" << setw(11) << itemArray[3] << "\t\t\t   " << n4 <<"\t\tRM   " << priceArray[3] <<"\t RM "<< sum4 <<"\n";
       else
          cout << "";
       if(n5!=0)
          cout << "\t\t" << setw(10) << itemArray[4] << "\t\t\t   " << n5 <<"\t\tRM   " << priceArray[4] <<"\t RM "<< sum5 <<"\n";
       else
          cout << "";
       if(n6!=0)
          cout << "\t\t" << setw(15) << itemArray[5] << "\t\t\t   " << n6 << "\t\tRM   " << priceArray[5] <<"\t RM "<< sum6 <<"\n";
       else
          cout << "";
       if(n7!=0)
           cout << "\t\t" << setw(8) << itemArray[6] << "\t\t\t   " << n7 <<"\t\tRM   " << priceArray[6] <<"\t RM "<< sum7 <<"\n";
       else
          cout << "";
       if(n8!=0)
          cout << "\t\t" << setw(13) << itemArray[7] << "\t\t\t   " << n8 <<"\t\tRM   " << priceArray[7] <<"\t RM "<< sum8 <<"\n";
       else
          cout << "";

    cout << fixed << showpoint << setprecision(2);
    custotal = sum1+sum2+sum3+sum4+sum5+sum6+sum7+sum8;

    cout<< "\t\t" << L;
    SetConsoleTextAttribute(color, 14);
    cout<<"\t\t\t\t\t\t\t\tTotal buys :     RM "<< custotal <<"\n";
    SetConsoleTextAttribute(color, 15);
    cout<< "\t\t" << L;

       if(custotal>=300){
           discount = cdis_applied(custotal);
           SetConsoleTextAttribute(color, 14);
           cout << "\t\tAmount of discount applied : RM " << discount << endl;
           c_totaldiscount = cdis_total(custotal);
           cout << "\t\tTotal after discount       : RM " <<  c_totaldiscount << endl;
           cout << endl << endl;
           cout << "\t\t\t Congratulation!! You have achived 5% discount, buy more save more !! " << endl;
       }
       else{
           cout << endl;
           SetConsoleTextAttribute(color, 14);
           cout << "\t\t\t Sorry ~ you almost hit the target, purchase more and save more next time! " << endl;
        }
    }// end if

//************
// Member
//************

    else if(choice==2){
        if(n1!=0)
           cout <<  "\t\t" << setw(10) << itemArray[0] << "\t\t\t   " << n1 << "\t\tRM  " << M_priceArray[0] <<"\t RM "<< msum1 <<"\n";
        else
           cout << "";
        if(n2!=0)
           cout <<  "\t\t" << setw(5) << itemArray[1] << "\t\t\t\t   " << n2 << "\t\tRM   " << M_priceArray[1] <<"\t RM "<< msum2 <<"\n";
        else
           cout << "";
        if(n3!=0)
           cout <<  "\t\t" << setw(12) << itemArray[2] << "\t\t\t   " << n3 << "\t\tRM   " << M_priceArray[2] <<"\t RM "<< msum3 <<"\n";
        else
           cout << "";
        if(n4!=0)
           cout <<  "\t\t" << setw(11) << itemArray[3] << "\t\t\t   " << n4 <<"\t\tRM   " << M_priceArray[3] <<"\t RM "<< msum4 <<"\n";
        else
           cout << "";
        if(n5!=0)
           cout <<  "\t\t" << setw(10) << itemArray[4] << "\t\t\t   " << n5 <<"\t\tRM   " << M_priceArray[4] <<"\t RM "<< msum5 <<"\n";
        else
           cout << "";
        if(n6!=0)
           cout <<  "\t\t" << setw(15) << itemArray[5] << "\t\t\t   " << n6 << "\t\tRM   " << M_priceArray[5] <<"\t RM "<< msum6 <<"\n";
        else
           cout << "";
        if(n7!=0)
           cout <<  "\t\t" << setw(8) << itemArray[6] << "\t\t\t   " << n7 <<"\t\tRM   " << M_priceArray[6] <<"\t RM "<< msum7 <<"\n";
        else
           cout << "";
        if(n8!=0)
           cout <<  "\t\t" << setw(13) << itemArray[7] << "\t\t\t   " << n8 <<"\t\tRM   " << M_priceArray[7] <<"\t RM "<< msum8 <<"\n";
        else
           cout << "";


    cout << fixed << showpoint << setprecision(2);
    membertotal = msum1+msum2+msum3+msum4+msum5+msum6+msum7+msum8;
    cout << "\t\t" << L;
    SetConsoleTextAttribute(color, 14);
    cout << "\t\t\t\t\t\t\t\tTotal buys :     RM "<< membertotal <<"\n";
    SetConsoleTextAttribute(color, 15);
    cout <<  "\t\t" << L;
       if(membertotal>=300){
           discount = mdis_applied(membertotal);
           SetConsoleTextAttribute(color, 14);
           cout << "\t\t Savings that u have achieved : RM " << discount << endl;
           m_totaldiscount = mdis_total(membertotal);
           cout << "\t\t Total after discount       : RM " <<  m_totaldiscount << endl << endl;
           cout << "\t\t\t Congratulation!! You have achived 5% discount, buy more save more ~~~~ " << endl;
       }
       else{
           cout << endl;
           SetConsoleTextAttribute(color, 14);
           cout << "\t\t\t Sorry ~ you almost hit the target, purchase more and save more next time! " << endl;
        }
    }// end if

//**********
// Staff
//**********

    else if(choice==3){
       if(n1!=0)
          cout <<  "\t\t" << setw(10) << itemArray[0] << "\t\t\t   " << n1 << "\t\tRM  " << priceArray[0] <<"\t RM "<< sum1 <<"\n";
       else
          cout << "";
       if(n2!=0)
          cout <<  "\t\t" << setw(5) << itemArray[1] << "\t\t\t\t   " << n2 << "\t\tRM   " << priceArray[1] <<"\t RM "<< sum2 <<"\n";
       else
          cout << "";
       if(n3!=0)
          cout <<  "\t\t" << setw(12) << itemArray[2] << "\t\t\t   " << n3 << "\t\tRM   " << priceArray[2] <<"\t RM "<< sum3 <<"\n";
       else
          cout << "";
       if(n4!=0)
          cout <<  "\t\t" << setw(11) << itemArray[3] << "\t\t\t   " << n4 <<"\t\tRM   " << priceArray[3] <<"\t RM "<< sum4 <<"\n";
       else
          cout << "";
       if(n5!=0)
          cout <<  "\t\t" << setw(10) << itemArray[4] << "\t\t\t   " << n5 <<"\t\tRM   " << priceArray[4] <<"\t RM "<< sum5 <<"\n";
       else
          cout << "";
       if(n6!=0)
          cout <<  "\t\t" << setw(15) << itemArray[5] << "\t\t\t   " << n6 << "\t\tRM   " << priceArray[5] <<"\t RM "<< sum6 <<"\n";
       else
          cout << "";
       if(n7!=0)
          cout <<  "\t\t" << setw(8) << itemArray[6] << "\t\t\t   " << n7 <<"\t\tRM   " << priceArray[6] <<"\t RM "<< sum7 <<"\n";
       else
          cout << "";
       if(n8!=0)
          cout <<  "\t\t" << setw(13) << itemArray[7] << "\t\t\t   " << n8 <<"\t\tRM   " << priceArray[7] <<"\t RM "<< sum8 <<"\n";
       else
          cout << "";


    cout << fixed << showpoint << setprecision(2);
    stafftotal = sum1+sum2+sum3+sum4+sum5+sum6+sum7+sum8;

    cout <<  "\t\t" << L;
    SetConsoleTextAttribute(color, 14);
    cout <<"\t\t\t\t\t\t\t\tTotal buys :     RM "<< stafftotal <<"\n";
    SetConsoleTextAttribute(color, 15);
    cout <<  "\t\t" << L;

    subsidy = s_subsidy(stafftotal);

    discount = sdis_applied(subsidy,stafftotal);
    SetConsoleTextAttribute(color, 14);
    cout << "\t\tSavings that u have achieved : RM " << subsidy << endl;
        if(discount > 0){
          cout << "\t\tTotal amount after subsidize : RM " << discount << endl;
          cout << endl << endl;
          cout << "\t\t\t Congratulation!! You can enjoy staff subsidy, buy more save more ~~~~ " << endl;
         }
        else{
          cout << endl;
          SetConsoleTextAttribute(color, 14);
          cout << "\t\t\t Sorry ~ you almost hit the target, purchase more and save more next time! " << endl;
         }
    }// end if

    else{
      SetConsoleTextAttribute(color, 12);
      cout << "The data is invalid X..X " << endl;
    }

    SetConsoleTextAttribute(color, 14);
    cout << endl;
    cout << "\t\t\t\t Thanks for supporting Catherine Mart, Have A Nice Day ~ " << endl;

    system("pause");
    return 0;
}


//**************************************
// The Main Menu Function of Program
//**************************************

void showchoice()
{
        cout << "\n\n" << setw(60) << "MAIN MENU ";
        cout << "\n\n\t\t******************************************************************************\n\n";
        cout << setw(62) << "1. CUSTOMER\n\n\n";
        cout << setw(60) << "2. MEMBER\n\n\n";
        cout << setw(59) << "3. STAFF\n\n\n";
        cout << setw(56) << "4. EXIT\n";
        cout << "\n\n\t\t******************************************************************************\n\n";
        cout << setw(68) << "Please enter your choice (1 - 4) : ";
}

//*************************************************
// Function Read Text File and stored in array
//*************************************************

void ReadFromFile(string itm[], double p[], double mp[] , const int arraySize)
{
       ifstream inFile;
       inFile.open("products.txt");
       if(!inFile){ // check for file open failure
           cout << "File open failure!" << endl;
           cout << endl << "System closing ~ " << endl;
           exit(0);
        }
        else if(inFile.peek(), inFile.eof() )
        {
            cout << "File is empty! " << endl;
            cout << endl << "Program will be halted soon ~ " << endl;
            exit(0);
        }
        else{
        for(int i=0; i<arraySize;i++)
           {
            getline(inFile,itm[i]);
           inFile >> itm[i] >> p[i] >> mp[i];
           }
        }
       inFile.close();
}

//***************************
// Function to display Text
//***************************

void displayFromFile(string itm[], double p[], double mp[])
{

           cout << fixed << showpoint << setprecision(2);
           cout << "\t\t\t1. " << itm[0] << "\t\t" << p[0] << "\t\t\t" << mp[0] << endl;
           cout << "\t\t\t2. " << itm[1] << "\t\t\t" << p[1] << "\t\t\t" << mp[1] << endl;
           cout << "\t\t\t3. " << itm[2] << "\t\t" << p[2] << "\t\t\t" << mp[2] << endl;
           cout << "\t\t\t4. " << itm[3] << "\t\t" << p[3] << "\t\t\t" << mp[3] << endl;
           cout << "\t\t\t5. " << itm[4] << "\t\t" << p[4] << "\t\t\t" << mp[4] << endl;
           cout << "\t\t\t6. " << itm[5] << "\t" << p[5] << "\t\t\t" << mp[5] << endl;
           cout << "\t\t\t7. " << itm[6] << "\t\t" << p[6] << "\t\t\t" << mp[6] << endl;
           cout << "\t\t\t8. " << itm[7] << "\t\t" << p[7] << "\t\t\t" << mp[7] << endl;


}

//*******************************************
// Function to calculate customer discount
//*******************************************
double cdis_applied(double  c)
{
    double discount;
    discount = c*0.05;
    return discount;
}

//******************************************************
// Function to calculate customer total after discount
//******************************************************
double cdis_total(double  ct)
{
    double ctotal;
    ctotal = ct*0.95;
    return ctotal;
}

//********************************************
// Function to calculate member discount
//********************************************

double mdis_applied(double m)
{
    double discount;
    discount = m*0.05;
    return discount;
}

//******************************************************
// Function to calculate customer total after discount
//******************************************************
double mdis_total(double  mt)
{
    double mtotal;
    mtotal = mt*0.95;
    return mtotal;
}





//****************************************
// Function to calculate staff subsidy
//****************************************
double s_subsidy(double s)
{
    double subsidy;
    if(s>=5 && s<=30){
          subsidy = 1.00;
        }
    else if(s>=31 && s<=99){
          subsidy = 5.00;
        }
    else if(s>=100){
          subsidy = 10.00;
        }
    else{
          subsidy = 0.00;
        }
    return subsidy;
}

//************************************************
// Function to calculate staff saving achieved
//************************************************
double sdis_applied(double sb,double s)
{
    double discount;
    if(s>=5 && s<=30){
          sb = 1.00;
          discount = s - sb;
        }
    else if(s>=31 && s<=99){
          sb = 5.00;
          discount = s - sb;
        }
    else if(s>=100){
          sb = 10.00;
          discount = s - sb;
        }
    else{
          sb = 0.00;
          discount = s;
        }
    return discount;
}
