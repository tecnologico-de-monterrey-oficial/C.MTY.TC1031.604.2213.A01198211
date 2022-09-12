#include <iostream>
#include<string.h>
#include <string>

using namespace std;

#pragma once
struct Log {
    bool checked;
    string date;
    string time;
    string entry;
    string ubi;
    string key;
    int formatedDate;
    Log(string date, int formateDdate , string time, string entry, string ubi);
    bool operator<(Log log);
    void setKeyToDate();
    void setChecked();
    bool operator<=(Log log);
};

Log::Log(string date, int formatedDate , string time, string entry, string ubi) {
    this->formatedDate = formatedDate;
    this->date = date;
    this->time = time;
    this->entry = entry;
    this->ubi = ubi;
    this->key = ubi + " " + to_string(formatedDate)+ " " + time;
}

bool Log::operator<(Log log) {
    return this->ubi < log.ubi;
}
bool Log::operator<=(Log log){
    return this->formatedDate<log.formatedDate;
}

