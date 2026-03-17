#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


class Player{

    int id;
    string name;
    int level;
    char type; // V = VIP , N = NORMAL
    int arrivalOrder;
    bool active;
    static int counter;

public:

    Player(int id, string name, int level, char type){

        this->id = id;
        this->name = name;
        this->level = level;
        this->type = type;

        active = true;     // Player is active when created

        counter++;
        arrivalOrder = counter;
    }

    int getID(){ return id; }
    string getName(){ return name; }
    int getLvl(){ return level; }
    char getType(){ return type; }
    int getArrival(){ return arrivalOrder; }

    bool isActive(){ return active; }

    void markleft(){ active = false; }

    void revive(){ active = true; }      // For UNDO
};

int Player::counter = 0;


struct UndoOp {

    string type;    // REGISTER, PLAY, WITHDRAW
    Player player;  // Player involved
    int pos;        // Position (for PLAY)
};


struct Queue{

    vector<Player> v1;

    unordered_map<int, Player*> umap;

    int fronts = 0;
    int rear = -1;

    vector<UndoOp> undoStack;



    void REGISTER(Player p1){

        v1.push_back(p1);

        umap[p1.getID()] = &v1.back();

        rear++;

        undoStack.push_back({"REGISTER", p1, -1});
    }



    void WITHDRAW(int ID){

        if(umap.find(ID) == umap.end()){
            cout << "Player not found!" << endl;
            return;
        }

        Player* p = umap[ID];

        p->markleft();

        undoStack.push_back({"WITHDRAW", *p, -1});

        umap.erase(ID);

        cout << "Player " << p->getName() << " withdrawn!" << endl;
    }



    void PLAY(){

        while(fronts <= rear && !v1[fronts].isActive()){
            fronts++;
        }

        if(fronts > rear){
            cout << "All Players are Gone!" << endl;
            return;
        }

        Player p = v1[fronts];

        cout << p.getName() << " successfully played!" << endl;

        umap.erase(p.getID());

        undoStack.push_back({"PLAY", p, fronts});

        fronts++;
    }



    void UNDO(){

        if(undoStack.empty()){
            cout << "Nothing to undo!" << endl;
            return;
        }

        UndoOp last = undoStack.back();
        undoStack.pop_back();



        if(last.type == "REGISTER"){

            int id = last.player.getID();

            umap.erase(id);

            v1.pop_back();

            rear--;

            cout << "Undo REGISTER successful!" << endl;
        }


        else if(last.type == "WITHDRAW"){

            int id = last.player.getID();

            for(int i = fronts; i <= rear; i++){

                if(v1[i].getID() == id){

                    v1[i].revive();

                    umap[id] = &v1[i];

                    break;
                }
            }

            cout << "Undo WITHDRAW successful!" << endl;
        }


        else if(last.type == "PLAY"){

            fronts--;

            v1[fronts] = last.player;

            umap[last.player.getID()] = &v1[fronts];

            cout << "Undo PLAY successful!" << endl;
        }
    }


    void printQueue(){

        for(int i = fronts; i <= rear; i++){

            if(!v1[i].isActive()) continue;

            cout << "Name: " << v1[i].getName() << endl;
            cout << "ID: " << v1[i].getID() << endl;
            cout << "Level: " << v1[i].getLvl() << endl;
            cout << "Type: " << v1[i].getType() << endl;
            cout << "-------------------" << endl;
        }
    }
};



struct PriorQueue{

    vector<Player> v2;


    void REGISTER(Player p1){

        if(v2.size() == 0){
            v2.push_back(p1);
            return;
        }

        for(int i = 0; i < v2.size(); i++){

            if(p1.getLvl() > v2[i].getLvl()){

                v2.insert(v2.begin() + i, p1);
                return;
            }

            else if(p1.getLvl() == v2[i].getLvl()){

                if(p1.getArrival() < v2[i].getArrival()){

                    v2.insert(v2.begin() + i, p1);
                    return;
                }
            }
        }

        v2.push_back(p1);
    }


    void PLAY(){

        if(v2.size() == 0){
            cout << "All Players are Gone!" << endl;
            return;
        }

        cout << v2[0].getName() << " successfully played!" << endl;

        v2.erase(v2.begin());
    }


    void printQueue(){

        for(int i = 0; i < v2.size(); i++){

            cout << "Name: " << v2[i].getName() << endl;
            cout << "ID: " << v2[i].getID() << endl;
            cout << "Level: " << v2[i].getLvl() << endl;
            cout << "Type: " << v2[i].getType() << endl;
            cout << "-------------------" << endl;
        }
    }
};


int main(){

    Queue q;

    q.REGISTER(Player(111,"Shahid",2,'N'));
    q.REGISTER(Player(210,"Asim",4,'N'));
    q.REGISTER(Player(391,"Hassan",1,'N'));
    q.REGISTER(Player(213,"Rohan",7,'N'));

    cout << "\n--- After Registration ---\n";
    q.printQueue();


    q.WITHDRAW(210);

    cout << "\n--- After Withdraw (Asim) ---\n";
    q.printQueue();


    q.UNDO();

    cout << "\n--- After Undo Withdraw ---\n";
    q.printQueue();



    q.PLAY();

    cout << "\n--- After Play ---\n";
    q.printQueue();


    q.UNDO();

    cout << "\n--- After Undo Play ---\n";
    q.printQueue();


    q.UNDO();

    cout << "\n--- After Undo Last Register ---\n";
    q.printQueue();



    q.UNDO();
    q.UNDO();

    cout << "\n--- After Multiple Undo ---\n";
    q.printQueue();



    cout << "\n===== VIP QUEUE =====\n";

    PriorQueue pq;

    pq.REGISTER(Player(210,"Asim",4,'V'));
    pq.REGISTER(Player(391,"Hassan",2,'V'));
    pq.REGISTER(Player(111,"Shahid",2,'V'));
    pq.REGISTER(Player(213,"Rohan",7,'V'));

    cout << "\n--- VIP Queue ---\n";
    pq.printQueue();



    pq.PLAY();

    cout << "\n--- After VIP Play ---\n";
    pq.printQueue();



    return 0;
}

