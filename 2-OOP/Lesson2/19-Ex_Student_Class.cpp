// Define a Student Class
#include <cassert>
#include <stdexcept>
#include <string>

class Student {
  public:
    Student(std::string name, int grade, double gpa) : name_(name),
                                                      grade_(grade),
                                                      gpa_(gpa) {
        ValidateGrade();
        ValidateGpa();
    }

    // accessors
    std::string Name() const { return name_; }
    int Grade() const { return grade_; }
    double Gpa() const { return gpa_; }

    // mutators
    void Name (std::string name) {
        name_ = name;
    }
    void Grade(int grade) {
        grade_ = grade;
        ValidateGrade();
    }
    void Gpa(double gpa) {
        gpa_ = gpa;
        ValidateGpa();
    }

  private:
    std::string name_;
    int grade_;
    double gpa_;
    void ValidateGrade() {
        if (Grade() < 0 || Grade() > 12) {
            throw std::invalid_argument("Invalid grade");
        }
    }
    void ValidateGpa() {
        if (Gpa() < 0 || Gpa() > 4.0) {
            throw std::invalid_argument("Invalid gpa");
        }
    }
};

int main() {
    Student student("Ja Brony", 2, 3.6);
    assert( student.Name() == "Ja Brony" );
    assert( student.Grade() == 2 );
    assert( student.Gpa() == 3.6 );

    bool caught {false};
    try {
        Student invalid("Invalid Irma", -2, 8.7);
    } catch(...) {
        caught = true;
    }

    assert( caught );

    return 0;
}
