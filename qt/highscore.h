#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <map>
#include <string>

class highscore
{
public:
    highscore() = default;
    ~highscore() = default;

    highscore(const highscore&) = default;

    void load();
    void save();

private:
    std::map<int, int> list_of_score;

};

#endif // HIGHSCORE_H
