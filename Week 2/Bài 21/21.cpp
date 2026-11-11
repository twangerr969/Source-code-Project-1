#include<iostream>
#include<vector>
using namespace std;
int m, n; //Số giảng viên và số môn học
vector<vector<int>> canTeach; //Lưu các giảng viên có thể dạy của từng môn
int crd[31]; //Số tín chỉ của từng môn
int lb[11]; //Số môn tối thiểu của từng giảng viên
int maxLoad;
int min_maxLoad;
vector<vector<int>> schedule;
int cur_crd[11]; //Lưu số tín chỉ của từng giảng viên trong phương án hiện tại 
bool conflict[31][31]; //Kiểm tra nếu conflict[i][j] = true tức là hai môn i, j trùng thời khoá biểu
int cur_courses[11]; //Lưu số môn của từng giáo viên trong phương án hiện tại 
bool check(int idCourse, int idTeacher) {
    for(int x : schedule[idTeacher]) {
        if(conflict[idCourse][x]) return false;
    }
    return true;
}
bool check_teacher() {
    for(int i = 1; i <= m; i++) {
        if(cur_courses[i] < lb[i]) return false; 
    }
    return true;
}
void Try(int idCourse) {
    if(idCourse > n) {
        if(check_teacher()) {
            min_maxLoad = min(maxLoad, min_maxLoad);
        }
        return;
    }
    for(int x : canTeach[idCourse]) {
        if(check(idCourse, x)) {
            schedule[x].push_back(idCourse);
            cur_courses[x]++;
            cur_crd[x] += crd[idCourse];
                int cur_maxLoad = maxLoad;
            maxLoad = max(cur_crd[x], maxLoad);
            if(idCourse == n && check_teacher()) {
                min_maxLoad = min(maxLoad, min_maxLoad);
            }
            else {
                if(maxLoad < min_maxLoad) Try(idCourse + 1);
            }
            schedule[x].pop_back();
            cur_courses[x]--;
            cur_crd[x] -= crd[idCourse];
            maxLoad = cur_maxLoad;
        }   
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> m >> n;
    int num_can_teach, idCourse;
    canTeach.resize(31);
    schedule.resize(11);
    min_maxLoad = 1e9;
    for(int i = 1; i <= m; i++) {
        cin >> num_can_teach;
        for(int j = 0; j < num_can_teach; j++) {
            cin >> idCourse;
            canTeach[idCourse].push_back(i);
        }
    }
    for(int i = 1; i <= n; i++) cin >> crd[i];
    for(int i = 1; i <= m; i++) cin >> lb[i];
    int num_pairConflict, course1, course2;
    cin >> num_pairConflict;
    for(int i = 0; i < num_pairConflict; i++) {
        cin >> course1 >> course2;
        conflict[course1][course2] = true;
        conflict[course2][course1] = true;
    }
    Try(1);
    if(min_maxLoad == 1e9) cout << -1;
    else cout << min_maxLoad;
    return 0;
}