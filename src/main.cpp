#include <iostream>
#include <fstream>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace cv;

int main(){

	struct data {
		float a, b, c;
	};
	string Folders[15] = { "030719_Lukas_4_Thermal",
		                   "030719_Sebastian_4_Thermal",
		                   "030719_Shio_4_Thermal"};
	for (size_t index = 0; index < 3; index++)
	{
		cout << Folders[index] << "----------------" << endl;
		ofstream DataOutputHead;
		DataOutputHead.open("D:/openpose/bin/output/"+Folders[index]+"/Data_OpenPose_Head.csv");
		ofstream DataOutputHandL;
		DataOutputHandL.open("D:/openpose/bin/output/"+Folders[index]+"/Data_OpenPose_HandL.csv");
		ofstream DataOutputHandR;
		DataOutputHandR.open("D:/openpose/bin/output/"+Folders[index]+"/Data_OpenPose_HandR.csv");
		vector<vector<data> > D; // use a dynamic container
		int number_files=668;
		for(int j=1;j< number_files;j++){
			FileStorage fs("D:/openpose/bin/output/"+Folders[index]+"/ ("+std::to_string(j)+").json", 0);
			FileNode root = fs["people"];
			//DataOutputHead << j << ";";
			//DataOutputHandL << j << ";";
			//DataOutputHandR << j << ";";
			for (int i = 0; i < root.size(); i++)
			{
				FileNode val1 = root[i]["pose_keypoints_2d"]; // we only want the content of val1
				vector<data> row;

				//if(i==0){
				DataOutputHead  << val1[0].real()<<",";
				DataOutputHead << val1[1].real() << ",";
				DataOutputHandL << val1[12].real()<<",";
				DataOutputHandL << val1[13].real() << ",";
				DataOutputHandR << val1[21].real()<<",";
				DataOutputHandR << val1[22].real() << ",";

				cout << val1[0].real() << endl;
				cout << val1[1].real() << endl;
				cout << val1[12].real() << endl;
				cout << val1[13].real() << endl;
				cout << val1[21].real() << endl;
				cout << val1[22].real() << endl;
				//}
				/*if(i==1){
				DataOutputHead1  << val1[0].real() << "\n";
				DataOutputHandL1 << val1[4].real() << "\n";
				DataOutputHandR1 << val1[7].real() << "\n";
				}
				*/
			
				cout << "Person number " << i<<endl;
			
			
			
				/*
				for (int j = 0; j < val1.size(); j += 3) { // read 3 consecutive values
					data  d;
					d.a = val1[j].real();
					d.b = val1[j + 1].real();
					d.c = val1[j + 2].real();
					row.push_back(d);
					cout << d.a << d.b << d.c;
				}
				*/
				//D.push_back(row);
			}
			DataOutputHead << "\n";
			DataOutputHandL << "\n";
			DataOutputHandR << "\n";
		}
	}
  return 0;
}
