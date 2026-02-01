// writen by mmd 

#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
using namespace std;

class Student {
private:
    string name;
    string identical_num;
    int entering_year;
    string field;
    vector<string> classes;
    map<string, int> marks;

public:
    Student() {}
    
    Student(string n, string id, int year, string f) : 
        name(n), identical_num(id), entering_year(year), field(f) {}
    
    string getName() { return name; }
    string getIdenticalNum() { return identical_num; }
    int getEnteringYear() { return entering_year; }
    string getField() { return field; }
    vector<string> getClasses() { return classes; }
    
    bool isRegisteredInClass(string class_id) {
        for (string c : classes) {
            if (c == class_id) return true;
        }
        return false;
    }
    
    void addClass(string class_id) {
        classes.push_back(class_id);
    }
    
    void setMark(string class_id, int mark) {
        marks[class_id] = mark;
    }
    
    int getMark(string class_id) {
        if (marks.find(class_id) != marks.end()) return marks[class_id];
        return -1;
    }
    
    double getAverage() {
        if (marks.empty()) return -1.0;
        double sum = 0;
        for (auto pair : marks) {
            sum += pair.second;
        }
        return sum / marks.size();
    }
    
    bool hasMarks() {
        return !marks.empty();
    }
};

class Professor {
private:
    string name;
    string identical_num;
    string field;
    vector<string> classes;

public:
    Professor() {}
    
    Professor(string n, string id, string f) : 
        name(n), identical_num(id), field(f) {}
    
    string getName() { return name; }
    string getIdenticalNum() { return identical_num; }
    string getField() { return field; }
    vector<string> getClasses() { return classes; }
    
    bool teachesClass(string class_id) {
        for (string c : classes) {
            if (c == class_id) return true;
        }
        return false;
    }
    
    void addClass(string class_id) {
        classes.push_back(class_id);
    }
};

class Class {
private:
    string name;
    string class_id;
    string field;
    string professor_id;
    vector<string> students;

public:
    Class() {}
    
    Class(string n, string id, string f) : 
        name(n), class_id(id), field(f), professor_id("") {}
    
    string getName() { return name; }
    string getClassId() { return class_id; }
    string getField() { return field; }
    string getProfessorId() { return professor_id; }
    vector<string> getStudents() { return students; }
    
    bool hasProfessor() { return !professor_id.empty(); }
    
    bool isStudentRegistered(string student_id) {
        for (string s : students) {
            if (s == student_id) return true;
        }
        return false;
    }
    
    void addStudent(string student_id) {
        students.push_back(student_id);
    }
    
    void setProfessor(string prof_id) {
        professor_id = prof_id;
    }
};

class GolestanSystem {
private:
    map<string, Student> students;
    map<string, Professor> professors;
    map<string, Class> classes;

public:
    void register_student(string name, string identical_num, 
                         int entering_year, string field) {
        if (students.find(identical_num) != students.end() || 
            professors.find(identical_num) != professors.end()) {
            cout << "this identical number previously registered" << endl;
            return;
        }
        Student s(name, identical_num, entering_year, field);
        students[identical_num] = s;
        cout << "welcome to golestan" << endl;
    }
    
    void register_professor(string name, string identical_num, 
                           string field) {
        if (students.find(identical_num) != students.end() || 
            professors.find(identical_num) != professors.end()) {
            cout << "this identical number previously registered" << endl;
            return;
        }
        Professor p(name, identical_num, field);
        professors[identical_num] = p;
        cout << "welcome to golestan" << endl;
    }
    
    void make_class(string name, string class_id, string field) {
        if (classes.find(class_id) != classes.end()) {
            cout << "this class id previously used" << endl;
            return;
        }
        Class c(name, class_id, field);
        classes[class_id] = c;
        cout << "class added successfully" << endl;
    }
    
    void add_student(string identical_num, string class_id) {
        if (students.find(identical_num) == students.end()) {
            cout << "invalid student" << endl;
            return;
        }
        if (classes.find(class_id) == classes.end()) {
            cout << "invalid class" << endl;
            return;
        }
        
        Student& s = students[identical_num];
        Class& c = classes[class_id];
        
        if (s.getField() != c.getField()) {
            cout << "student field is not match" << endl;
            return;
        }
        
        if (s.isRegisteredInClass(class_id)) {
            cout << "student is already registered" << endl;
            return;
        }
        
        s.addClass(class_id);
        c.addStudent(identical_num);
        cout << "student added successfully to the class" << endl;
    }
    
    void add_professor(string identical_num, string class_id) {
        if (professors.find(identical_num) == professors.end()) {
            cout << "invalid professor" << endl;
            return;
        }
        if (classes.find(class_id) == classes.end()) {
            cout << "invalid class" << endl;
            return;
        }
        
        Professor& p = professors[identical_num];
        Class& c = classes[class_id];
        
        if (p.getField() != c.getField()) {
            cout << "professor field is not match" << endl;
            return;
        }
        
        if (c.hasProfessor()) {
            cout << "this class has a professor" << endl;
            return;
        }
        
        p.addClass(class_id);
        c.setProfessor(identical_num);
        cout << "professor added successfully to the class" << endl;
    }
    
    void student_status(string identical_num) {
        if (students.find(identical_num) == students.end()) {
            cout << "invalid student" << endl;
            return;
        }
        
        Student& s = students[identical_num];
        cout << s.getName() << " " << s.getEnteringYear() << " " << s.getField();
        
        for (string class_id : s.getClasses()) {
            cout << " " << classes[class_id].getName();
        }
        cout << endl;
    }
    
    void professor_status(string identical_num) {
        if (professors.find(identical_num) == professors.end()) {
            cout << "invalid professor" << endl;
            return;
        }
        
        Professor& p = professors[identical_num];
        cout << p.getName() << " " << p.getField();
        
        for (string class_id : p.getClasses()) {
            cout << " " << classes[class_id].getName();
        }
        cout << endl;
    }
    
    void class_status(string class_id) {
        if (classes.find(class_id) == classes.end()) {
            cout << "invalid class" << endl;
            return;
        }
        
        Class& c = classes[class_id];
        if (!c.hasProfessor()) {
            cout << "None";
        } else {
            cout << professors[c.getProfessorId()].getName();
        }
        
        for (string stu_id : c.getStudents()) {
            cout << " " << students[stu_id].getName();
        }
        cout << endl;
    }
    
    void set_final_mark(string professor_id, string student_id, 
                       string class_id, int mark) {
        if (professors.find(professor_id) == professors.end()) {
            cout << "invalid professor" << endl;
            return;
        }
        if (students.find(student_id) == students.end()) {
            cout << "invalid student" << endl;
            return;
        }
        if (classes.find(class_id) == classes.end()) {
            cout << "invalid class" << endl;
            return;
        }
        
        Class& c = classes[class_id];
        if (c.getProfessorId() != professor_id) {
            cout << "professor class is not match" << endl;
            return;
        }
        
        if (!students[student_id].isRegisteredInClass(class_id)) {
            cout << "student did not registered" << endl;
            return;
        }
        
        students[student_id].setMark(class_id, mark);
        cout << "student final mark added or changed" << endl;
    }
    
    void mark_student(string student_id, string class_id) {
        if (students.find(student_id) == students.end()) {
            cout << "invalid student" << endl;
            return;
        }
        if (classes.find(class_id) == classes.end()) {
            cout << "invalid class" << endl;
            return;
        }
        
        Student& s = students[student_id];
        if (!s.isRegisteredInClass(class_id)) {
            cout << "student did not registered" << endl;
            return;
        }
        
        int mark = s.getMark(class_id);
        if (mark == -1) {
            cout << "None" << endl;
        } else {
            cout << mark << endl;
        }
    }
    
    void mark_list(string class_id) {
        if (classes.find(class_id) == classes.end()) {
            cout << "invalid class" << endl;
            return;
        }
        
        Class& c = classes[class_id];
        if (!c.hasProfessor()) {
            cout << "no professor" << endl;
            return;
        }
        
        if (c.getStudents().empty()) {
            cout << "no student" << endl;
            return;
        }
        
        bool first = true;
        for (string stu_id : c.getStudents()) {
            if (!first) cout << " ";
            first = false;
            
            int mark = students[stu_id].getMark(class_id);
            if (mark == -1) {
                cout << "None";
            } else {
                cout << mark;
            }
        }
        cout << endl;
    }
    
    void average_mark_professor(string professor_id) {
        if (professors.find(professor_id) == professors.end()) {
            cout << "invalid professor" << endl;
            return;
        }
        
        Professor& p = professors[professor_id];
        vector<int> all_marks;
        
        for (string class_id : p.getClasses()) {
            Class& c = classes[class_id];
            for (string stu_id : c.getStudents()) {
                int mark = students[stu_id].getMark(class_id);
                if (mark != -1) {
                    all_marks.push_back(mark);
                }
            }
        }
        
        if (all_marks.empty()) {
            cout << "None" << endl;
        } else {
            double sum = 0;
            for (int mark : all_marks) sum += mark;
            double avg = sum / all_marks.size();
            cout << fixed << setprecision(2) << avg << endl;
        }
    }
    
    void average_mark_student(string student_id) {
        if (students.find(student_id) == students.end()) {
            cout << "invalid student" << endl;
            return;
        }
        
        Student& s = students[student_id];
        if (!s.hasMarks()) {
            cout << "None" << endl;
            return;
        }
        
        cout << fixed << setprecision(2) << s.getAverage() << endl;
    }
    
    void top_student(string field, int entering_year) {
        string top_student_name = "None";
        double top_avg = -1.0;
        
        for (auto pair : students) {
            Student& s = pair.second;
            if (s.getField() == field && s.getEnteringYear() == entering_year) {
                if (s.hasMarks()) {
                    double current_avg = s.getAverage();
                    if (current_avg > top_avg) {
                        top_avg = current_avg;
                        top_student_name = s.getName();
                    }
                }
            }
        }
        
        cout << top_student_name << endl;
    }
    
    void top_mark(string class_id) {
        if (classes.find(class_id) == classes.end()) {
            cout << "invalid class" << endl;
            return;
        }
        
        Class& c = classes[class_id];
        int top_mark = -1;
        
        for (string stu_id : c.getStudents()) {
            int mark = students[stu_id].getMark(class_id);
            if (mark != -1 && mark > top_mark) {
                top_mark = mark;
            }
        }
        
        if (top_mark == -1) {
            cout << "None" << endl;
        } else {
            cout << top_mark << endl;
        }
    }
};

int main() {
    GolestanSystem sys;
    string cmd;
    
    while (cin >> cmd) {
        if (cmd == "end") break;
        
        if (cmd == "register_student") {
            string name, identical_num, field;
            int entering_year;
            cin >> name >> identical_num >> entering_year >> field;
            sys.register_student(name, identical_num, entering_year, field);
        }
        else if (cmd == "register_professor") {
            string name, identical_num, field;
            cin >> name >> identical_num >> field;
            sys.register_professor(name, identical_num, field);
        }
        else if (cmd == "make_class") {
            string name, class_id, field;
            cin >> name >> class_id >> field;
            sys.make_class(name, class_id, field);
        }
        else if (cmd == "add_student") {
            string identical_num, class_id;
            cin >> identical_num >> class_id;
            sys.add_student(identical_num, class_id);
        }
        else if (cmd == "add_professor") {
            string identical_num, class_id;
            cin >> identical_num >> class_id;
            sys.add_professor(identical_num, class_id);
        }
        else if (cmd == "student_status") {
            string identical_num;
            cin >> identical_num;
            sys.student_status(identical_num);
        }
        else if (cmd == "professor_status") {
            string identical_num;
            cin >> identical_num;
            sys.professor_status(identical_num);
        }
        else if (cmd == "class_status") {
            string class_id;
            cin >> class_id;
            sys.class_status(class_id);
        }
        else if (cmd == "set_final_mark") {
            string professor_id, student_id, class_id;
            int mark;
            cin >> professor_id >> student_id >> class_id >> mark;
            sys.set_final_mark(professor_id, student_id, class_id, mark);
        }
        else if (cmd == "mark_student") {
            string student_id, class_id;
            cin >> student_id >> class_id;
            sys.mark_student(student_id, class_id);
        }
        else if (cmd == "mark_list") {
            string class_id;
            cin >> class_id;
            sys.mark_list(class_id);
        }
        else if (cmd == "average_mark_professor") {
            string identical_num;
            cin >> identical_num;
            sys.average_mark_professor(identical_num);
        }
        else if (cmd == "average_mark_student") {
            string identical_num;
            cin >> identical_num;
            sys.average_mark_student(identical_num);
        }
        else if (cmd == "top_student") {
            string field;
            int entering_year;
            cin >> field >> entering_year;
            sys.top_student(field, entering_year);
        }
        else if (cmd == "top_mark") {
            string class_id;
            cin >> class_id;
            sys.top_mark(class_id);
        }
    }
    
    return 0;
}