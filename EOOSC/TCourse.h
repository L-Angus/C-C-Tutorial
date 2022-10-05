#ifndef TCOURSE_H_
#define TCOURSE_H_

typedef long CourseId;
class TCourse {
public:
    TCourse(const char name[], long id);
    TCourse(const TCourse& other);
    TCourse& operator=(const TCourse& other);
    ~TCourse();
    bool operator==(const TCourse& other);
    bool operator!=(const TCourse& other);
    TString GetCourseName() const;
    void SetCourseName(const char name[]);
    CourseId GetCourseId() const;
    void SetCourseId(CourseId newId);

private:
    TString courseName;
    CourseId courseId;
};


#endif// TCOURSE_H_