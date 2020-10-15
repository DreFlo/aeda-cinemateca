//
// Created by andre on 10/15/2020.
//

#ifndef PROJETO_INTERVALODETEMPO_H
#define PROJETO_INTERVALODETEMPO_H

#include "DataEHora.h"

using namespace std;

class IntervaloDeTempo {
private:
    const DataEHora start, end;
public:
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
