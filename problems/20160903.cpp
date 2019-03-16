#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct card{
    int attack;
    int health;
};


int main(){
    int n;
    cin>>n;
    vector<card> player0;
    vector<card> player1;
    card hero;
    hero.attack = 0;
    hero.health = 30;
    player0.push_back(hero);
    player1.push_back(hero);
    int player_num = 0;
    for(int i=0; i<n; i++){
        string temp;
        cin>>temp;
        if(temp == "end"){
            player_num = 1-player_num;
            continue;
        }
        if(temp == "summon"){
            int pos, attack, health;
            cin>>pos>>attack>>health;
            card temp_card;
            temp_card.attack = attack;
            temp_card.health = health;
            if(player_num == 0){
                player0.insert(player0.begin()+pos,temp_card);
            }
            if(player_num == 1){
                player1.insert(player1.begin()+pos,temp_card);
            }
        }
        if(temp == "attack"){
            int attacker, defender;
            cin>>attacker>>defender;
            if(player_num == 0){
                int my_att, other_att;
                my_att = player0[attacker].attack;
                other_att = player1[defender].attack;
                player1[defender].health -= my_att;
                if(player1[defender].health <= 0){
                    player1.erase(player1.begin()+defender);
                }
                player0[attacker].health -= other_att;
                if(player0[attacker].health <= 0){
                    player0.erase(player0.begin()+attacker);
                }
            }
            if(player_num == 1){
                int my_att, other_att;
                my_att = player1[attacker].attack;
                other_att = player0[defender].attack;
                player0[defender].health -= my_att;
                if(player0[defender].health <= 0){
                    player0.erase(player0.begin()+defender);
                }
                player1[attacker].health -= other_att;
                if(player1[attacker].health <= 0){
                    player1.erase(player1.begin()+attacker);
                }
            }
        }
    }
    if(player0[0].health <= 0){
        cout<<-1<<endl;
    }
    if(player1[0].health <= 0){
        cout<<1<<endl;
    }
    if(player0[0].health > 0 && player1[0].health > 0){
        cout<<0<<endl;
    }
    cout<<player0[0].health<<endl;
    cout<<player0.size()-1;
    for(int i = 1; i<player0.size(); i++){
        cout<<" "<<player0[i].health; 
    }
    cout<<endl;
    cout<<player1[0].health<<endl;
    cout<<player1.size()-1;
    for(int i = 1; i<player1.size(); i++){
        cout<<" "<<player1[i].health; 
    }
    cout<<endl;
    return 0;
}