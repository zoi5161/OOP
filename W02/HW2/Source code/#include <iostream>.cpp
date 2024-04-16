#include <iostream>
#include <vector>

using namespace std;

class Project{
    private:
        string name;
        int time;
    public:
        Project(string s, int t) : name(s), time(t){}
        string getName(){
            return name;
        }
        int getTime(){
            return time;
        }
        virtual long long grantMoney() = 0;
        virtual void print() = 0;
};

class Idea : public Project {
    private:
        int time;
    public:
        Idea(string s, int t) : Project(s, t) {
            time = t;
        }

        long long grantMoney(){
            return time * 20000000;
        }

        void print(){
            cout << "Ý tưởng: " << getName() << " . Phát triển: " << time << " tháng. Kinh phí: " << grantMoney() << endl;
        }
};

class Mvp : public Project {
    private:
        int time1;
        int time2;
    public:
        Mvp(string s, int t1, int t2) : Project(s, t1 + t2) {
            time1 = t1;
            time2 = t2;
        }

        long long grantMoney(){
            return getTime() * 15000000;
        }

        void print(){
            cout << "Ý tưởng: " << getName() << " . Vận hành: " << time1 << " tháng. Marketing: " << time2 << " tháng. Kinh phí: " << grantMoney() << endl;
        }
};

int main(){
    cout << "Chương trình hỗ trợ Hackathon của AlphaTech tháng 6/2023" << endl;
    vector<Project *> projects;

    projects.push_back(new Idea("SeperTech", 6));
    projects.push_back(new Mvp("FutureCar", 6, 3));
    projects.push_back(new Idea("VirtualHouse", 7));
    projects.push_back(new Idea("NightVision", 4));
    projects.push_back(new Mvp("SmartKey", 4, 5));

    cout << "Số dự án: " << projects.size() << endl;
    int sum = 0;
    for(int i = 0; i < projects.size(); i++){
        sum += projects[i] -> grantMoney();
        cout << i + 1 << ".";
        projects[i] -> print();
    }
    cout << "Tổng tiền tài trợ: " << sum;
    return 0;
}

/*
        Project(){
            this -> name = "N/A";
            this -> time = 0;
            this -> cost = 0;
        }
        Project(string s, int time, long long cost){
            this -> name = s;
            this -> time = time;
            this -> cost = cost;
        }
*/
