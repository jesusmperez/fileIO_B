#include<iostream>
#include<string>
#include<iomanip>
#include<cstdlib>
#include<fstream>
using namespace std;


int main()
{
    string word ="";
    ifstream fin;
    ofstream fout;
    cout <<"Please enter the name of the file" << endl;
    cin >> word;
    while(word!= "scores.txt")
    {
        cout <<" try again please " << endl;
        cout <<" hint: name of file is "<< "---->" << "scores.txt" << endl;
        cin >> word;
    }
    fin.open("scores.txt");
    fout.open("results.txt");
    
    if(fin.fail())
    {
        cout <<" Error in opening the file" << endl;
        exit(1);
    }
    if(fout.fail())
    {
        cout <<" Error with the file " << endl;
        exit(1);
    }

    string name1, name2;
    double s1, s2, s3, s4, s5, s6;
    double average = 0.0;
    double counter = 0.0;
    string winner = "";
    while(fin >> name1 >> name2>> s1>> s2>> s3>> s4>> s5>> s6)
    {
        fout.setf(ios::fixed);
        fout.setf(ios::showpoint);
        fout.precision(1);
        fout.setf(ios::left);
        average = (s1 + s2 + s3 + s4 + s5 + s6)/6;
        fout <<setw(10)<< name1 << setw(12) << name2 << setw(10) << s1 << setw(10) << s2 << setw(10)
             <<s2 << setw(10) << s3 << setw(10) << s4 << setw(10) << s5 << setw(10) << s6  << setw(10) << "average is: "<<average << endl;
    //cout << name1 <<" " << name2 << endl;
    //cout << average << endl;
    
        if(average > counter)
        {
             winner = name1 +" "+ name2;
             counter = average;
        }
      // cout <<"The highest average score is : " << counter << endl;
      //cout <<"The Winner is: " <<  winner << endl;
        
    }   
        fout<<"************************************************************************************************************"<<endl;
        fout <<"The highest average score is : " << counter << endl;
        fout <<"The Winner is: " <<  winner << endl;
        fin.close();
        fout.close();
        
    return 0;
}
