//
// Created by andre on 10/15/2020.
//

#ifndef PROJETO_INTERVALODETEMPO_H
#define PROJETO_INTERVALODETEMPO_H

#include "DataEHora.h"

using namespace std;

class IntervaloDeTempo {
private:
    DataEHora start, end;
public:
    /**
     * Default constructor.
     */
    IntervaloDeTempo() = default;
    /**
     * Class constructor. Initializes beginning and end of interval.
     * @param st - Beginning of the interval.
     * @param ed - End of the interval.
     */
    IntervaloDeTempo(DataEHora st, DataEHora ed);
    /**
     * Initializes beginning and end of interval.
     * @param st - Beginning of the interval.
     * @param ed - End of the interval.
     */
    void init(DataEHora st, DataEHora ed);
    /**
     * @return Returns the beginning of the interval.
     */
    DataEHora getStart() const;
    /**
     * @return Returns the end of the interval.
     */
    DataEHora getEnd() const;
    /**
     * Checks if two time intervals don´t overlap.
     * @return True if there is no overlap. False otherwise.
     */
    bool operator^(IntervaloDeTempo timeInterval) const;
};


#endif //PROJETO_INTERVALODETEMPO_H
