#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <forward_list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

/* ================= VECTOR<int> + сортировка ================= */

void vectorIntExample() {
    cout << "\n--- vector<int> + QuickSort ---\n";

    vector<int> numbers;
    srand(time(nullptr));

    for (int i = 0; i < 10; i++) {
        numbers.push_back(rand() % 100);
    }

    cout << "Original: ";
    for (int n : numbers) cout << n << " ";
    cout << endl;

    sort(numbers.begin(), numbers.end());

    cout << "Sorted:   ";
    for (int n : numbers) cout << n << " ";
    cout << endl;
}

/* ================= VECTOR<string> ================= */

void vectorStringExample() {
    cout << "\n--- vector<string> ---\n";

    vector<string> langs{ "C++", "Python", "Java", "Rust", "Go" };

    cout << "All: ";
    for (const auto& s : langs) cout << s << " ";
    cout << endl;

    cout << "Even indexes: ";
    for (size_t i = 0; i < langs.size(); i += 2)
        cout << langs[i] << " ";
    cout << endl;
}

/* ================= array ================= */

void arrayExample() {
    cout << "\n--- array ---\n";

    array<int, 5> arr;
    srand(time(nullptr));

    for (int& x : arr) {
        x = rand() % 50;
        cout << x << " ";
    }
    cout << endl;

    rotate(arr.begin(), arr.begin() + 2, arr.end());

    cout << "Rotated: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
}

/* ================= list ================= */

void listExample() {
    cout << "\n--- list ---\n";

    list<int> lst{ 1, 2, 2, 3, 4, 4, 5 };

    lst.sort();
    lst.unique();

    for (int x : lst) cout << x << " ";
    cout << endl;
}

/* ================= forward_list ================= */

void forwardListExample() {
    cout << "\n--- forward_list ---\n";

    forward_list<int> fl{ 10, 20, 30, 40 };

    for (int x : fl) cout << x << " ";
    cout << endl;
}

/* ================= deque ================= */

void dequeExample() {
    cout << "\n--- deque ---\n";

    deque<string> dq{ "one", "two", "three" };

    dq.push_front("zero");
    dq.push_back("four");

    for (const auto& s : dq) cout << s << " ";
    cout << endl;
}

/* ================= stack ================= */

bool areParenthesesBalanced(const string& str) {
    stack<char> s;

    for (char ch : str) {
        if (ch == '(' || ch == '[' || ch == '{')
            s.push(ch);
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (s.empty()) return false;
            char top = s.top(); s.pop();
            if ((ch == ')' && top != '(') ||
                (ch == ']' && top != '[') ||
                (ch == '}' && top != '{'))
                return false;
        }
    }
    return s.empty();
}

void stackExample() {
    cout << "\n--- stack ---\n";
    cout << "Balanced: " << areParenthesesBalanced("{[()]}") << endl;
}

/* ================= queue ================= */

void queueExample() {
    cout << "\n--- queue ---\n";

    queue<string> q;
    q.push("doc1");
    q.push("doc2");

    while (!q.empty()) {
        cout << "Printing: " << q.front() << endl;
        q.pop();
    }
}

/* ================= set ================= */

void setExample() {
    cout << "\n--- set ---\n";

    set<int> a{ 1,2,3,4 };
    set<int> b{ 3,4,5 };
    set<int> result;

    set_intersection(
        a.begin(), a.end(),
        b.begin(), b.end(),
        inserter(result, result.begin())
    );

    cout << "Intersection: ";
    for (int x : result) cout << x << " ";
    cout << endl;
}

/* ================= map ================= */

void mapExample() {
    cout << "\n--- map ---\n";

    map<string, int> students{
        {"Sano", 10},
        {"Samvel", 20},
        {"Artur", 8}
    };

    for (const auto& [name, score] : students)
        cout << name << " -> " << score << endl;
}

/* ================= OOP + STL ================= */

class Device {
public:
    void turnOn() { cout << "Device ON\n"; }
    void turnOff() { cout << "Device OFF\n"; }
};

class WiFiEnabled : virtual public Device {
public:
    void connectWiFi() { cout << "WiFi connected\n"; }
};

class BluetoothEnabled : virtual public Device {
public:
    void connectBT() { cout << "Bluetooth connected\n"; }
};

class SmartSpeaker : public WiFiEnabled, public BluetoothEnabled {
public:
    friend ostream& operator<<(ostream& os, const SmartSpeaker&) {
        return os << "Smart Speaker";
    }
};

template <typename T>
class SmartContainer : public vector<T> {
public:
    void printAll() const {
        for (const auto& el : *this)
            cout << el << endl;
    }
};

/* ================= MAIN ================= */

int main() {

    vectorIntExample();
    vectorStringExample();
    arrayExample();
    listExample();
    forwardListExample();
    dequeExample();
    stackExample();
    queueExample();
    setExample();
    mapExample();

    cout << "\n--- OOP + STL ---\n";
    SmartContainer<SmartSpeaker> speakers;
    speakers.push_back(SmartSpeaker{});
    speakers.push_back(SmartSpeaker{});
    speakers.printAll();

    return 0;
}
