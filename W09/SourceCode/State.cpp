#include "State.h"

void NormalState::displayState(){
    cout << "Rồng đang ở trạng thái bình thường" << endl;
}

void NormalState::attack(Dragon& dragon){
    cout << "Rồng " << dragon.getName() << " phun lửa màu vàng" << endl;
}

void NormalState::move(Dragon& dragon){
    cout << "Rồng " << dragon.getName() << " di chuyển với tốc độ bình thường" << endl;
}

int NormalState::calculatePower(Dragon& dragon){
    return (dragon.getAttack() + dragon.getDefense() + dragon.getHealth()) * double(dragon.getLevel());
}

void RageState::displayState(){
    cout << "Rồng đang ở trạng thái cuồng nộ" << endl;
}

void RageState::attack(Dragon& dragon){
    cout << "Rồng " << dragon.getName() << " phun lửa màu đỏ" << endl;
}

void RageState::move(Dragon& dragon){
    cout << "Rồng " << dragon.getName() << " di chuyển với tốc độ nhanh" << endl;
}

int RageState::calculatePower(Dragon& dragon){
    return (dragon.getAttack() * 2 + dragon.getDefense() + dragon.getHealth()) * double(dragon.getLevel());
}

void DefenseState::displayState(){
    cout << "Rồng đang ở trạng thái phòng thủ" << endl;
}

void DefenseState::attack(Dragon& dragon){
    cout << "Rồng " << dragon.getName() << " phun lửa màu xanh lá" << endl;
}

void DefenseState::move(Dragon& dragon){
    cout << "Rồng " << dragon.getName() << " di chuyển với tốc độ chậm" << endl;
}

int DefenseState::calculatePower(Dragon& dragon){
    return (dragon.getAttack() + dragon.getDefense() * 1.5 + dragon.getHealth() * 1.5) * double(dragon.getLevel());
}