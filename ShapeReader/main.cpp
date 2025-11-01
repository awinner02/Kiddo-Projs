#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

// Calculations
double sq_area(double side){
    double area = side * side;
    return area;
}

double cir_area(double rad){
    double area = 3.14 * rad * rad;
    return area;
}

double tri_area(double side){
    double s = (side + side + side)/2;
    double area = sqrt(s*(s-side)*(s-side)*(s-side));
    return area;
}

// MAIN
int main(int argc, char *argv[]){
	if(argc != 2){
		cout<<"Usage: "<<argv[0]<<" [filename]"<<endl;
		return 1;
	}

	ifstream inFile(argv[1]);

	if(!inFile){
		cout<<"Error: Unable to open file: '"<<argv[1]<<"'"<<endl;
		return 1;
	}

	string temp;

	while(getline(inFile, temp)){
		stringstream sstr(temp);
		string shape_name, side_length_str;

		getline(sstr, shape_name, ',');
		getline(sstr, side_length_str);
		
        double side_length = stod(side_length_str);
		
        // output
        if (shape_name == "triangle"){
            double shape_area = tri_area(side_length);
            cout << "The area of " << shape_name << ": " << shape_area << endl;
        } else if (shape_name == "circle") {
            double shape_area = cir_area(side_length);
            cout << "The area of " << shape_name << ": " << shape_area << endl;
        } else if (shape_name == "square") {
            double shape_area = sq_area(side_length);
            cout << "The area of " << shape_name << ": " << shape_area << endl;
        } else {
            cout<< "no shape to calculate :("<< endl;
        }
    }
    return 0;
	}