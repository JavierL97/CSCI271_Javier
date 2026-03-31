#include <iostream>
#include <string>
using namespace std;

class CPU {
private:
    string id;
    int ff, mf, cof, cot;
    int cmips;

    // private helper function
    void computeMIPS() {
        cmips = cof; // 1 Hz = 1 MIPS
    }

public:
    // constructor
    CPU(string cpuID, int fF, int mF, int cOF, int cOT) {
        id = cpuID;
        ff = (fF >= 2000) ? fF : 2000;
        mf = (mF <= 5000) ? mF : 5000;
        cof = cOF;
        cot = cOT;
        computeMIPS();
    }

    // display function (lab format)
    void display() {
        cout << id << " " << ff << " " << mf << " " << cof << " " << cot << " " << cmips << endl;
    }

    // set temperature and adjust frequency
    void setTemperature(int newTemp) {
        cot = newTemp;
        if (cot < 176) {
            cof += 200;
            if (cof > mf) cof = mf;
        } else if (cot > 176) {
            cof -= 200;
            if (cof < ff) cof = ff;
        }
        computeMIPS();
    }

    // get MIPS for total calculation
    int getMIPS() {
        return cmips;
    }
};

// =================== Main Program ===================
int main() {
    const int N = 4; // number of CPUs
    CPU cluster[N] = {
        CPU("001", 2000, 4800, 2800, 132),
        CPU("002", 2200, 5000, 3200, 131),
        CPU("003", 2100, 4900, 3400, 142),
        CPU("004", 2500, 4500, 3700, 144)
    };

    int choice;
    do {
        cout << "\n===== CPU Cluster Menu =====\n";
        cout << "1. Display all CPUs\n";
        cout << "2. Display one CPU\n";
        cout << "3. Set temperature of one CPU\n";
        cout << "4. Display total MIPS of cluster\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            for (int i = 0; i < N; i++)
                cluster[i].display();
        }
        else if (choice == 2) {
            int index;
            cin >> index;
            if (index >= 0 && index < N)
                cluster[index].display();
        }
        else if (choice == 3) {
            int index, temp;
            cin >> index >> temp;
            if (index >= 0 && index < N)
                cluster[index].setTemperature(temp);
        }
        else if (choice == 4) {
            int totalMIPS = 0;
            for (int i = 0; i < N; i++)
                totalMIPS += cluster[i].getMIPS();
            cout << totalMIPS << endl;
        }
    } while (choice != 5);

    cout << "Program exited.\n";
    return 0;
}
