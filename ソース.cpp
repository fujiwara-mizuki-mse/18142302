#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>


using namespace std;

//comic�N���X�̐錾
class comic {//�����o��錾
private:
	string title;
	string autor;
	string date;
public:
	void Deftitle( string str){title = str;}//����^�C�g��
	void Defautor(string str) { autor = str; }//���
	void Defdate(string str) { date = str; }//���\��(�A�ڊJ�n��)
	string Readtitle() { return title; }
	string Readautor() { return autor; }
	string Readdate() { return date; }
};

int main() {
	vector<vector<string>>linenum(3, vector<string>(1));//�t�@�C���̃f�[�^��ێ�����vector
	ifstream ifs("comiclist.txt");

	int linecount = 0;
	int j = 0;
	string tmp;
	string line;
	//�J���}��؂�Ƀf�[�^�ǂݍ���
	while (getline(ifs, line)) {//�t�@�C���̏I���܂ŌJ��Ԃ�
		stringstream ss{ line };

		while (getline(ss, tmp, ',')) {
			linenum[j].push_back(tmp);
			j++;
		}
		
		linecount++;
		j = 0;
	 }
	
	comic* obj = new comic[linecount];//�I�u�W�F�N�g

	for (int k = 0;k < linecount; k++) {
		obj[k].Deftitle(linenum[0][k + 1]);
		obj[k].Defautor(linenum[1][k + 1]);
		obj[k].Defdate(linenum[2][k + 1]);
	}

	for (int k = 0;k < linecount; k++) {
		cout << obj[k].Readtitle() << endl;//����^�C�g�����o��
	}


	cout << endl;
	delete[]obj;
}