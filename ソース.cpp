#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>


using namespace std;

//comicクラスの宣言
class comic {//メンバを宣言
private:
	string title;
	string autor;
	string date;
public:
	void Deftitle( string str){title = str;}//漫画タイトル
	void Defautor(string str) { autor = str; }//作者
	void Defdate(string str) { date = str; }//発表日(連載開始日)
	string Readtitle() { return title; }
	string Readautor() { return autor; }
	string Readdate() { return date; }
};

int main() {
	vector<vector<string>>linenum(3, vector<string>(1));//ファイルのデータを保持するvector
	ifstream ifs("comiclist.txt");

	int linecount = 0;
	int j = 0;
	string tmp;
	string line;
	//カンマ区切りにデータ読み込み
	while (getline(ifs, line)) {//ファイルの終わりまで繰り返す
		stringstream ss{ line };

		while (getline(ss, tmp, ',')) {
			linenum[j].push_back(tmp);
			j++;
		}
		
		linecount++;
		j = 0;
	 }
	
	comic* obj = new comic[linecount];//オブジェクト

	for (int k = 0;k < linecount; k++) {
		obj[k].Deftitle(linenum[0][k + 1]);
		obj[k].Defautor(linenum[1][k + 1]);
		obj[k].Defdate(linenum[2][k + 1]);
	}

	for (int k = 0;k < linecount; k++) {
		cout << obj[k].Readtitle() << endl;//漫画タイトルを出力
	}


	cout << endl;
	delete[]obj;
}