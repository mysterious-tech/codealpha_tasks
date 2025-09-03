#include<iostream>
using namespace std;
void intro(){
	cout<<">>>>>>>>>>>>>>>>>>> WELCOME TO CGPA CALCULATOR <<<<<<<<<<<<<<<<<<<<<"<<endl;
}
int main(){
	intro();
	string name;
	cout<<"Enter your name:";
	cin>>name;
	int num_course,credit_hour, total_credit=0;
	double grade, total_gradepoints=0;
	//taking number of course from user
	cout<<name<<"! Enter of number of your courses: ";
	cin>> num_course;

	//taking gradepoint and credit hour of courses from user
	for(int i=1; i<=num_course;i++){
		cout<<"\n Course "<<i<<" grade points: ";
		cin>> grade;
		cout<<" Credit hour of course: ";
		cin>> credit_hour;
		
		total_gradepoints +=grade *credit_hour;
		total_credit +=credit_hour;
	}
	cout<<endl;
	cout<<name<<"! Your total_grade points are: "<<total_gradepoints
	<<" for total "<<total_credit<<" credit hour "<<endl;
	//here we have the total_gradepoints of user 
	//and total credit hour of user courses
	//let's find the cgpa 
	double cgpa;
	cgpa=total_gradepoints/total_credit;
	cout<<"\n HERE IS YOUR CGPA: "<<cgpa<<endl;

}
