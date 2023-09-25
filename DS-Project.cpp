#include <bits/stdc++.h>
using namespace std;
class people{
public:
    string fname;
    string lname;
    string city;
    string job;
    string birthday;
};
class account{
public:
    string bankname;
    string accountNumber;
    string iban;
};
class home{
public:
    string price;
    string size;
    string address;
    string postalcode;

};
class cars{
public:
    string model;
    string color;
    string plate;

};
class phone{
public:
    string operatorname;
    string phonenumber;
};
class calls{
public:
    string callid;
    string date;
    string duration;
};
class relation{
public:
    string relate;
    string date;
};
class transactions{
public:
    string transid;
    string date;
    string amount;
};
class ownership{
public:
    string ownershipid;
    string date;
    string amount;
};
class edge{
public:
    string from;
    string to;
    string label;
    transactions* p_transaction;
    ownership* p_ownership;
    calls* p_call;
    relation* p_relation;
    edge(){
        transactions* p_transaction = nullptr;
        ownership* p_ownership = nullptr;
        calls* p_call = nullptr;
        relation* p_relation = nullptr;
    }
};
class node {
public:
    string key;
    string snn;
    string label;
    cars* p_cars;
    people* p_people;
    phone* p_phone;
    home* p_homes;
    account* p_account;
    unordered_map<string,edge*> adj;
    node (){
        cars* p_cars = nullptr;
        people* p_people = nullptr;
        phone* p_phone = nullptr;
        home* p_homes = nullptr;
        account* p_account = nullptr;
    }
};
unordered_map<string,node*> graph;
void read_people(){
    ifstream infile;
    string s,s1;
    ofstream smFile("C:\\Users\\rezapm\\Desktop\\smuggler.csv");
    ofstream crFile("C:\\Users\\rezapm\\Desktop\\corrupt.csv");
    infile.open("C:\\Users\\rezapm\\Desktop\\data\\people.csv");
    if (!infile)
        cout <<"unable to find file";
    getline(infile,s);
    while (getline(infile,s)) {
        s+=",";
        node * p = new node();
        people * q = new people();
        p->label = "people";
        p->p_people = q;

        s1 = s.substr(0,s.find(','));
        s.erase(s.begin(),s.begin()+s1.size()+1);
        q->fname = s1;

        s1 = s.substr(0,s.find(','));
        s.erase(s.begin(),s.begin()+s1.size()+1);
        q->lname = s1;

        s1 = s.substr(0,s.find(','));
        s.erase(s.begin(),s.begin()+s1.size()+1);
        p->snn = s1;
        p->key = s1;

        s1 = s.substr(0,s.find(','));
        s.erase(s.begin(),s.begin()+s1.size()+1);
        q->birthday = s1;

        s1 = s.substr(0,s.find(','));
        s.erase(s.begin(),s.begin()+s1.size()+1);
        q->city = s1;

        s1 = s.substr(0,s.find(','));
        s.erase(s.begin(),s.begin()+s1.size()+1);
        q->job = s1;

        graph[p->key] = p;
        if(p->p_people->job == "\"قاچاقچی\""){
            s.clear();
            s += p->p_people->fname;
            s += ",";
            s += p->p_people->lname;
            s += ",";
            s += p->p_people->job;
            s += ",";
            s += p->p_people->city;
            s += ",";
            s += p->p_people->birthday;
            s += ",";
            s += p->snn;
            smFile << s;
            smFile << endl;
        }
        else if( p->p_people->job == "\"گمرک\"" || p->p_people->job =="\"سازمان بنادر\""){
            s.clear();
            s += p->p_people->fname;
            s += ",";
            s += p->p_people->lname;
            s += ",";
            s += p->p_people->job;
            s += ",";
            s += p->p_people->city;
            s += ",";
            s += p->p_people->birthday;
            s += ",";
            s += p->snn;
            crFile << s;
            crFile << endl;
        }
    }
}
void read_cars(){
    ifstream infile;
    string s,s1;
    infile.open("C:\\Users\\rezapm\\Desktop\\data\\cars.csv");
    if (!infile)
        cout <<"unable to find file";
    getline(infile,s);
    while (getline(infile,s)) {
        s+=",";
        node * p = new node();
        cars * q = new cars();
        p->label = "car";
        p->p_cars = q;

        s1 = s.substr(0,s.find(','));
        s.erase(s.begin(),s.begin()+s1.size()+1);
        q->plate = s1;
        p->key = s1;

        s1 = s.substr(0,s.find(','));
        s.erase(s.begin(),s.begin()+s1.size()+1);
        p->snn = s1;

        s1 = s.substr(0,s.find(','));
        s.erase(s.begin(),s.begin()+s1.size()+1);
        q->model = s1;

        s1 = s.substr(0,s.find(','));
        s.erase(s.begin(),s.begin()+s1.size()+1);
        q->color = s1;

        graph[p->key] = p;
    }
}
void read_accounts(){
    ifstream infile;
    string s,s1;
    infile.open("C:\\Users\\rezapm\\Desktop\\data\\accounts.csv");
    if (!infile)
        cout <<"unable to find file";
    getline(infile,s);
    while (getline(infile,s)) {
        s+=",";
        node * p = new node();
        account * q = new account();
        p->label = "account";
        p->p_account = q;

        s1 = s.substr(0,s.find(','));
        s.erase(s.begin(),s.begin()+s1.size()+1);
        p->snn = s1;

        s1 = s.substr(0,s.find(','));
        s.erase(s.begin(),s.begin()+s1.size()+1);
        q->bankname = s1;

        s1 = s.substr(0,s.find(','));
        s.erase(s.begin(),s.begin()+s1.size()+1);
        q->iban = s1;

        s1 = s.substr(0,s.find(','));
        s.erase(s.begin(),s.begin()+s1.size()+1);
        q->accountNumber = s1;
        p->key = s1;

        graph[p->key] = p;
    }
}
void read_homes(){
    ifstream infile;
    string s,s1;
    infile.open("C:\\Users\\rezapm\\Desktop\\data\\homes.csv");
    if (!infile)
        cout <<"unable to find file";
    getline(infile,s);
    while (getline(infile,s)) {
        node * p = new node();
        home * q = new home();
        p->label = "home";
        p->p_homes = q;

        s1 = s.substr(0,s.find(','));
        s.erase(s.begin(),s.begin()+s1.size()+1);
        p->snn = s1;

        s1 = s.substr(0,s.find(','));
        s.erase(s.begin(),s.begin()+s1.size()+1);
        q->price = s1;

        s1 = s.substr(0,s.find(','));
        s.erase(s.begin(),s.begin()+s1.size()+1);
        p->key = s1;
        q->postalcode = s1;

        s1 = s.substr(0,s.find(','));
        s.erase(s.begin(),s.begin()+s1.size()+1);
        q->size = s1;

        q->address = s;

        graph[p->key] = p;
    }
}
void read_phones(){
    ifstream infile;
    string s,s1;
    infile.open("C:\\Users\\rezapm\\Desktop\\data\\phones.csv");
    if (!infile)
        cout <<"unable to find file";
    getline(infile,s);
    while (getline(infile,s)) {
        s += ',';
        node * p = new node();
        phone* q = new phone();
        p->label = "phone";
        p->p_phone = q;

        s1 = s.substr(0,s.find(','));
        s.erase(s.begin(),s.begin()+s1.size()+1);
        p->snn = s1;

        s1 = s.substr(0,s.find(','));
        s.erase(s.begin(),s.begin()+s1.size()+1);
        q->phonenumber = s1;
        p->key = s1;

        s1 = s.substr(0,s.find(','));
        s.erase(s.begin(),s.begin()+s1.size()+1);
        q->operatorname = s1;


        graph[p->key] = p;
    }
}
void write_people(){
    ofstream newFile("C:\\Users\\rezapm\\Desktop\\people.txt");
    unordered_map<string,node*>::iterator iter;
    string s;
    for (iter = graph.begin(); iter != graph.end(); iter++)
    {
        if(iter->second->label == "people"){
            s.clear();
            s += iter->second->p_people->fname;
            s += " ";
            s += iter->second->p_people->lname;
            s += " ";
            s += iter->second->p_people->job;
            s += " ";
            s += iter->second->p_people->city;
            s += " ";
            s += iter->second->p_people->birthday;
            s += " ";
            s += iter->second->snn;
            s += " ";
            newFile << s;
            newFile << endl;
        }
    }
}
void write_cars(){
    ofstream newFile("C:\\Users\\rezapm\\Desktop\\cars.txt");
    unordered_map<string,node*>::iterator iter;
    string s;
    for (iter = graph.begin(); iter != graph.end(); iter++)
    {
        if(iter->second->label == "car"){
            s.clear();
            s += iter->second->p_cars->plate;
            s += " ";
            s += iter->second->snn;
            s += " ";
            s += iter->second->p_cars->model;
            s += " ";
            s += iter->second->p_cars->color;
            s += " ";
            newFile << s;
            newFile << endl;
        }
    }
}
void write_accounts(){
    ofstream newFile("C:\\Users\\rezapm\\Desktop\\account.txt");
    unordered_map<string,node*>::iterator iter;
    string s;
    for (iter = graph.begin(); iter != graph.end(); iter++)
    {
        if(iter->second->label == "account"){
            s.clear();
            s += iter->second->snn;
            s += " ";
            s += iter->second->p_account->bankname;
            s += " ";
            s += iter->second->p_account->iban;
            s += " ";
            s += iter->second->p_account->accountNumber;
            s += " ";
            newFile << s;
            newFile << endl;
        }
    }
}
void write_homes(){
    ofstream newFile("C:\\Users\\rezapm\\Desktop\\homes.txt");
    unordered_map<string,node*>::iterator iter;
    string s;
    for (iter = graph.begin(); iter != graph.end(); iter++)
    {
        if(iter->second->label == "home"){
            s.clear();
            s += iter->second->snn;
            s += " ";
            s += iter->second->p_homes->price;
            s += " ";
            s += iter->second->p_homes->postalcode;
            s += " ";
            s += iter->second->p_homes->size;
            s += " ";
            s += iter->second->p_homes->address;
            s += " ";
            newFile << s;
            newFile << endl;
        }
    }
}
void write_phones(){
    ofstream newFile("C:\\Users\\rezapm\\Desktop\\phones.txt");
    unordered_map<string,node*>::iterator iter;
    string s;
    for (iter = graph.begin(); iter != graph.end(); iter++)
    {
        if(iter->second->label == "phone"){
            s.clear();
            s += iter->second->snn;
            s += " ";
            s += iter->second->p_phone->phonenumber;
            s += " ";
            s += iter->second->p_phone->operatorname;
            s += " ";
            newFile << s;
            newFile << endl;
        }
    }
}
void read_ownerships(){
    ifstream infile;
    string s,s1;
    infile.open("C:\\Users\\rezapm\\Desktop\\data\\ownerships.csv");
    if (!infile)
        cout <<"unable to find file";
    getline(infile,s);
    while (getline(infile,s)) {
        s += ",";
        edge * p = new edge();
        ownership * q = new ownership();
        p->label = "ownership";
        p->p_ownership = q;

        s1 = s.substr(0,s.find(','));
        s.erase(s.begin(),s.begin()+s1.size()+1);
        p->from = s1;

        s1 = s.substr(0,s.find(','));
        s.erase(s.begin(),s.begin()+s1.size()+1);
        p->to = s1;

        s1 = s.substr(0,s.find(','));
        s.erase(s.begin(),s.begin()+s1.size()+1);
        q->ownershipid = s1;

        s1 = s.substr(0,s.find(','));
        s.erase(s.begin(),s.begin()+s1.size()+1);
        q->date = s1;

        s1 = s.substr(0,s.find(','));
        s.erase(s.begin(),s.begin()+s1.size()+1);
        q->amount = s1;

        unordered_map<string,node*>::iterator iter = graph.find(p->from);
        iter->second->adj[p->to] = p;
    }
}
void read_transaction(){
    ifstream infile;
    string s,s1;
    infile.open("C:\\Users\\rezapm\\Desktop\\data\\transactions.csv");
    if (!infile)
        cout <<"unable to find file";
    getline(infile,s);
    while (getline(infile,s)) {
        s += ",";
        edge * p = new edge();
        transactions * q = new transactions();
        p->label = "transaction";
        p->p_transaction = q;

        s1 = s.substr(0,s.find(','));
        s.erase(s.begin(),s.begin()+s1.size()+1);
        p->from = s1;

        s1 = s.substr(0,s.find(','));
        s.erase(s.begin(),s.begin()+s1.size()+1);
        p->to = s1;

        s1 = s.substr(0,s.find(','));
        s.erase(s.begin(),s.begin()+s1.size()+1);
        q->transid = s1;

        s1 = s.substr(0,s.find(','));
        s.erase(s.begin(),s.begin()+s1.size()+1);
        q->date = s1;

        s1 = s.substr(0,s.find(','));
        s.erase(s.begin(),s.begin()+s1.size()+1);
        q->amount = s1;

        unordered_map<string,node*>::iterator iter = graph.find(p->from);
        iter->second->adj[p->to] = p;
    }
}
void read_calls(){
    ifstream infile;
    string s,s1;
    infile.open("C:\\Users\\rezapm\\Desktop\\data\\calls.csv");
    if (!infile)
        cout <<"unable to find file";
    getline(infile,s);
    while (getline(infile,s)) {
        s += ",";
        edge * p = new edge();
        calls * q = new calls();
        p->label = "call";
        p->p_call = q;

        s1 = s.substr(0,s.find(','));
        s.erase(s.begin(),s.begin()+s1.size()+1);
        p->from = s1;

        s1 = s.substr(0,s.find(','));
        s.erase(s.begin(),s.begin()+s1.size()+1);
        p->to = s1;

        s1 = s.substr(0,s.find(','));
        s.erase(s.begin(),s.begin()+s1.size()+1);
        q->callid = s1;

        s1 = s.substr(0,s.find(','));
        s.erase(s.begin(),s.begin()+s1.size()+1);
        q->date = s1;

        s1 = s.substr(0,s.find(','));
        s.erase(s.begin(),s.begin()+s1.size()+1);
        q->duration = s1;

        unordered_map<string,node*>::iterator iter = graph.find(p->from);
        iter->second->adj[p->to] = p;
    }
}
void read_relationships(){
    ifstream infile;
    string s,s1;
    infile.open("C:\\Users\\rezapm\\Desktop\\data\\relationships.csv");
    if (!infile)
        cout <<"unable to find file";
    getline(infile,s);
    while (getline(infile,s)){
        s += ",";
        edge * p = new edge();
        relation * q = new relation();
        p->label = "relation";
        p->p_relation = q;

        s1 = s.substr(0,s.find(','));
        s.erase(s.begin(),s.begin()+s1.size()+1);
        p->from = s1;

        s1 = s.substr(0,s.find(','));
        s.erase(s.begin(),s.begin()+s1.size()+1);
        p->to = s1;

        s1 = s.substr(0,s.find(','));
        s.erase(s.begin(),s.begin()+s1.size()+1);
        q->relate = s1;

        s1 = s.substr(0,s.find(','));
        s.erase(s.begin(),s.begin()+s1.size()+1);
        q->date = s1;

        unordered_map<string,node*>::iterator iter = graph.find(p->from);
        iter->second->adj[p->to] = p;
    }
}
int twoyears = 730;
int today = 737684;
bool time_counter(string s){
    string year,month,day;
    year = s.substr(1,4);
    month = s.substr(6,2);
    day = s.substr(9,2);
    if (today-(stoi(year)*365+stoi(month)*30-(30-stoi(day))) <= twoyears)
        return true;
}
unordered_map<string,bool> sus;
unordered_map<string,string> sus2;
void phase2(){
    ofstream newFile("C:\\Users\\rezapm\\Desktop\\phase2.csv");
    string s,snn;
    unordered_map<string,node*>::iterator iter = graph.begin();
    while (iter != graph.end()) {
        if (iter->second->label == "people"){
            if (iter->second->p_people->job == "\"سازمان بنادر\"" || iter->second->p_people->job == "\"گمرک\""){
                unordered_map<string,edge*>::iterator ite = iter->second->adj.begin();
                while (ite != iter->second->adj.end()) {
                    if (ite->second->label == "ownership"){
                        string date = ite->second->p_ownership->date;
                        if(time_counter(date)){
                            s = iter->second->p_people->fname;
                            s += ",";
                            s += iter->second->p_people->lname;
                            s += ",";
                            s += iter->second->snn;
                            s += ",";
                            s += iter->second->p_people->birthday;
                            s += ",";
                            s += iter->second->p_people->city;
                            s += ",";
                            s += iter->second->p_people->job;
                            newFile << s;
                            newFile <<endl;
                            sus[iter->second->snn] = true;
                            goto A;
                        }
                    }
                    else {
                        snn = ite->second->to;
                        auto it = graph.find(snn);
                        unordered_map<string,edge*>::iterator i = it->second->adj.begin();
                        while (i != it->second->adj.end()) {
                            if (i->second->label == "ownership"){
                                string date = i->second->p_ownership->date;
                                if(time_counter(date)){
                                    s = iter->second->p_people->fname;
                                    s += ",";
                                    s += iter->second->p_people->lname;
                                    s += ",";
                                    s += iter->second->snn;
                                    s += ",";
                                    s += iter->second->p_people->birthday;
                                    s += ",";
                                    s += iter->second->p_people->city;
                                    s += ",";
                                    s += iter->second->p_people->job;
                                    newFile << s;
                                    newFile <<endl;
                                    sus[iter->second->snn] = true;
                                    goto A;
                                }
                            }
                            i++;
                        }
                    }
                    ite++;
                }
            }
        }
A:
        iter++;
    }
}
ofstream File("C:\\Users\\rezapm\\Desktop\\phase3.csv");
string ss;
void rec_phase3(int counter,string accountid,string smugler_snn){
    if (counter == 8)
        return;
    else{
        auto iter = graph.find(accountid);
        if (sus.find(iter->second->snn) != sus.end()){
            auto it = graph.find(iter->second->snn);
            ss = it->second->p_people->fname;
            ss += ",";
            ss += it->second->p_people->lname;
            ss += ",";
            ss += it->second->snn;
            ss += ",";
            ss += it->second->p_people->birthday;
            ss += ",";
            ss += it->second->p_people->city;
            ss += ",";
            ss += it->second->p_people->job;
            File << ss;
            File <<endl;
            sus.erase(iter->second->snn);
            sus2[iter->second->snn] = smugler_snn;
        }
        unordered_map<string,edge*>::iterator ite = iter->second->adj.begin();
        while (ite != iter->second->adj.end()) {
            rec_phase3(counter+1,ite->second->to,smugler_snn);
            ite++;
        }
    }
}
void phase3(){
    unordered_map<string,node*>::iterator iter = graph.begin();
    while (iter != graph.end()) {
        if (iter->second->label == "account"){
            auto iterr = graph.find(iter->second->snn);
            if (iterr->second->p_people->job == "\"قاچاقچی\""){
                rec_phase3(1,iter->second->key,iterr->second->snn);
            }
        }
        iter++;
    }
}
void phase4(){
    ofstream newFile("C:\\Users\\rezapm\\Desktop\\phase4.csv");
    unordered_map<string,node*>::iterator iter = graph.begin();
    string s;
    while (iter != graph.end()) {
        if (iter->second->label == "phone"){
            if (sus2.find(iter->second->snn) != sus2.end()){
                auto it = sus2.find(iter->second->snn);
                unordered_map<string,edge*>::iterator ite = iter->second->adj.begin();
                while (ite != iter->second->adj.end()){
                    if (graph.find(ite->second->to)->second->snn == it->second){
                        auto i = graph.find(iter->second->snn);
                        s = i->second->p_people->fname;
                        s += ",";
                        s += i->second->p_people->lname;
                        s += ",";
                        s += i->second->snn;
                        s += ",";
                        s += i->second->p_people->birthday;
                        s += ",";
                        s += i->second->p_people->city;
                        s += ",";
                        s += i->second->p_people->job;
                        newFile << s;
                        newFile <<endl;
                        sus2.erase(iter->second->snn);
                        break;
                    }
                    ite++;
                }
            }
            else if (graph.find(iter->second->snn)->second->p_people->job == "\"قاچاقچی\""){
                unordered_map<string,string>::iterator ite = sus2.begin();
                while (ite != sus2.end()) {
                    if (ite->second == iter->second->snn){
                        unordered_map<string,edge*>::iterator it = iter->second->adj.begin();
                        while (it != iter->second->adj.end()) {
                            if (graph.find(it->second->to)->second->snn == ite->first){
                                auto i = graph.find(it->first);
                                s = i->second->p_people->fname;
                                s += ",";
                                s += i->second->p_people->lname;
                                s += ",";
                                s += i->second->snn;
                                s += ",";
                                s += i->second->p_people->birthday;
                                s += ",";
                                s += i->second->p_people->city;
                                s += ",";
                                s += i->second->p_people->job;
                                newFile << s;
                                newFile <<endl;
                                sus2.erase(it->first);
                                break;
                            }
                            it++;
                        }
                    }
                    ite++;
                }
            }
        }
        iter++;
    }
}
void write(){
    ofstream newFile("C:\\Users\\rezapm\\Desktop\\phase5.txt");
    string s;
    unordered_map<string,string>::iterator iter = sus2.begin();
    while (iter != sus2.end()) {
        s = iter->first;
        s+= "         ";
        s+= iter->second;
        newFile << s;
        newFile << endl;
        iter++;
    }
    s.clear();
    newFile <<endl;
    newFile <<endl;
    newFile <<endl;
    newFile <<endl;
}
int main()
{
    read_cars();
    read_homes();
    read_people();
    read_phones();
    read_accounts();
    read_transaction();
    read_ownerships();
    read_calls();
    read_relationships();
    phase2();
    phase3();
    //phase4();
    //write();
}
