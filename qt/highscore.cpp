//highscore.cpp
#include "highscore.h"

highscore::highscore()
{
}

//Anropas när det har blivit game over.
//Sparar (ev.) poängen till highscore-listan och sedan till filen.
void highscore::save()
{
}

//Anropas när "highscore" väljs i startmenyn.
//Laddar in highscore-listan och visar den på skärmen.
void highscore::load()
{

}

//Borde vi inte t.ex. ha en sådan här funktion i private i highscore.h?
void highscore::insert(int score)
{
    //TODO: Loop som går igenom och jämför poängen i listan med de nya poängen,
    //och lägger in scoren på den plats som de ska ligga.
    /*
    if (!find(name))
    {
        v_table.insert(pair<string, double> (name, value));
    }
    */
}

//Tar bort sista så att listan fortsätter att vara 10 lång?
void highscore::remove_last()
{
    //v_table.erase(name);
}

