#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
char formartChar(char c){
	if(isupper(c)) return c-'A'+'a';
	return c;
} 
vector<string> word2={"is","am","it","in","of"};
vector<string> word3={"mat","cat","bat","rat","hat","vat","dog","box"};
vector<string> word4={"cube","swim","flat","bank","frog","club","doge","pipe"};
vector<string> word5={"float","clown","stage","frame","gloom","happy","stack","queue"};
vector<string> word6={"eating","played","padded","adding","banana","vector"};
vector<string> word7={"playing","pouring","machine","worried"};
vector<string> word8={"elephant","gulpping","swimming","floating"};
int main(){
	srand(time(0));
	while(true){
		loop:
		cout<<"==============WordLess，猜单词=============="<<endl;
		cout<<"请输入要猜的单词长度(2-8): ";
		unsigned len;
		cin>>len;
		if(len<2) len=2;
		if(len>8) len=8;
		string word;
		switch(len){
			case 2:
				word=word2[rand()%word2.size()];
				break;
			case 3:
				word=word3[rand()%word3.size()];
				break;
			case 4:
				word=word4[rand()%word4.size()];
				break;
			case 5:
				word=word5[rand()%word5.size()];
				break;
			case 6:
				word=word6[rand()%word6.size()];
				break;
			case 7:
				word=word7[rand()%word7.size()];
				break;
			case 8:
				word=word8[rand()%word8.size()];
				break;
		}
		MessageBox(NULL,"游戏规则：\n输入单词以完成游戏，系统将判断单词正误，机会只有6次，加油啊！","游戏规则",MB_OK|MB_TOPMOST);
		string guess;
		int attem=6;
		cout<<"======================\n";
		while(attem--){
			if(attem>1) cout<<"还剩"<<attem+1<<"次机会\n";
			else if(attem>0) cout<<"就两次机会了！\n";
			else cout<<"最后一次！\n";
			for(int i=0;i<len;i++){
				char c;
				cin>>c;
				guess.push_back(formartChar(c));
			}
			for(int i=0;i<guess.size();i++){
				if(guess[i]==word[i]){
					cout<<"O";
				}else if(word.find(guess[i])!=string::npos){
					cout<<"Δ";
				}else{
					cout<<"X";
				}
			}
			cout<<endl;
			if(guess==word){
				if(MessageBox(NULL,"恭喜您，答对啦！\n您要继续玩吗？","您赢了",MB_YESNO)==IDYES){
					system("cls");
					goto loop;
				}else{
					return 0;
				}
			}
			guess="";
		}
		string mess="您输了，下次走运~\n正确的单词是"+word+"\n您要继续玩吗？";
		if(MessageBox(NULL,mess.c_str(),"游戏失败",MB_YESNO)==IDYES){
			system("cls");
			goto loop;
		}else{
			return 0;
		}
	}
	return 0;