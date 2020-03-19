#include <bits/stdc++.h>

using namespace std;

int f(vector<int> in){
    vector<int> out;
    vector<int> v = {3,225,1,225,6,6,1100,1,238,225,104,0,1102,9,19,225,1,136,139,224,101,-17,224,224,4,224,102,8,223,223,101,6,224,224,1,223,224,223,2,218,213,224,1001,224,-4560,224,4,224,102,8,223,223,1001,224,4,224,1,223,224,223,1102,25,63,224,101,-1575,224,224,4,224,102,8,223,223,1001,224,4,224,1,223,224,223,1102,55,31,225,1101,38,15,225,1001,13,88,224,1001,224,-97,224,4,224,102,8,223,223,101,5,224,224,1,224,223,223,1002,87,88,224,101,-3344,224,224,4,224,102,8,223,223,1001,224,7,224,1,224,223,223,1102,39,10,225,1102,7,70,225,1101,19,47,224,101,-66,224,224,4,224,1002,223,8,223,1001,224,6,224,1,224,223,223,1102,49,72,225,102,77,166,224,101,-5544,224,224,4,224,102,8,223,223,1001,224,4,224,1,223,224,223,101,32,83,224,101,-87,224,224,4,224,102,8,223,223,1001,224,3,224,1,224,223,223,1101,80,5,225,1101,47,57,225,4,223,99,0,0,0,677,0,0,0,0,0,0,0,0,0,0,0,1105,0,99999,1105,227,247,1105,1,99999,1005,227,99999,1005,0,256,1105,1,99999,1106,227,99999,1106,0,265,1105,1,99999,1006,0,99999,1006,227,274,1105,1,99999,1105,1,280,1105,1,99999,1,225,225,225,1101,294,0,0,105,1,0,1105,1,99999,1106,0,300,1105,1,99999,1,225,225,225,1101,314,0,0,106,0,0,1105,1,99999,1008,677,226,224,1002,223,2,223,1005,224,329,1001,223,1,223,107,226,677,224,1002,223,2,223,1006,224,344,101,1,223,223,1007,677,677,224,1002,223,2,223,1006,224,359,1001,223,1,223,8,677,226,224,102,2,223,223,1005,224,374,101,1,223,223,108,226,677,224,102,2,223,223,1006,224,389,1001,223,1,223,1008,677,677,224,1002,223,2,223,1006,224,404,1001,223,1,223,1107,677,677,224,102,2,223,223,1005,224,419,1001,223,1,223,1008,226,226,224,102,2,223,223,1005,224,434,101,1,223,223,8,226,677,224,1002,223,2,223,1006,224,449,101,1,223,223,1007,677,226,224,102,2,223,223,1005,224,464,1001,223,1,223,107,677,677,224,1002,223,2,223,1005,224,479,1001,223,1,223,1107,226,677,224,1002,223,2,223,1005,224,494,1001,223,1,223,7,677,677,224,102,2,223,223,1006,224,509,101,1,223,223,1007,226,226,224,1002,223,2,223,1005,224,524,101,1,223,223,7,677,226,224,102,2,223,223,1005,224,539,101,1,223,223,8,226,226,224,1002,223,2,223,1006,224,554,101,1,223,223,7,226,677,224,102,2,223,223,1005,224,569,101,1,223,223,1108,677,226,224,1002,223,2,223,1005,224,584,101,1,223,223,108,677,677,224,1002,223,2,223,1006,224,599,101,1,223,223,107,226,226,224,1002,223,2,223,1006,224,614,101,1,223,223,1108,226,226,224,1002,223,2,223,1005,224,629,1001,223,1,223,1107,677,226,224,1002,223,2,223,1005,224,644,101,1,223,223,108,226,226,224,1002,223,2,223,1005,224,659,101,1,223,223,1108,226,677,224,1002,223,2,223,1005,224,674,1001,223,1,223,4,223,99,226};

    int ip = 0;
    while(true){
        int opcode = v[ip] % 100;
        // parameter modes
        int pm1 = (v[ip]/100)%10;
        int pm2 = (v[ip]/1000)%10;
        int pm3 = (v[ip]/10000)%10;
        // parameters
        int *p1 = pm1 ? &v[ip+1] : &v[v[ip+1]];
        int *p2 = pm2 ? &v[ip+2] : &v[v[ip+2]];
        int *p3 = pm3 ? &v[ip+3] : &v[v[ip+3]];
        if(opcode == 1) {
            assert(pm3 == 0);
            *p3 = *p1 + *p2;
            ip += 4;
        }
        else if(opcode == 2) {
            assert(pm3 == 0);
            *p3 = *p1 * *p2;
            ip += 4;
        }
        else if(opcode == 3) {
            assert(pm3 == 0);
            *p1 = in[0];
            ip += 2;
        } 
        else if(opcode == 4) {
            out.push_back(*p1);
            cout << "output:" << *p1 << endl;
            ip += 2;
        } 
        else if(opcode == 5) {
            cout << "jump-if-true" << endl;
            if(*p1 != 0)    ip = *p2;
            else            ip += 3;       
        } 
        else if(opcode == 6) {
            cout << "jump-if-false" << endl;
            if(*p1 == 0)    ip = *p2;
            else            ip += 3;
        }
        else if(opcode == 7) {
            cout << "less than" << endl;
            if(*p1 < *p2)   *p3 = 1;
            else            *p3 = 0;
            ip += 4;
        }
        else if(opcode == 8) {
            cout << "equal" << endl;
            if(*p1 == *p2)  *p3 = 1;
            else            *p3 = 0;
            ip += 4;
        }
        else if(opcode == 99) {
            ip+=1;
            return v[0]; 
        }
        else {
            cout << "ERROR opcode=" << v[ip] << endl;
            break;
        }        
    }
}

int main(){
    f({5});

    return 0;
}