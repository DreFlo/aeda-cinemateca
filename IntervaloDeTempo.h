//
// Created by andre on 10/15/2020.
//

#ifndef PROJETO_INTERVALODETEMPO_H
#define PROJETO_INTERVALODETEMPO_H

#include <iostream>
#include "DataEHora.h"

using namespace std;

class StartDataEHora: public DataEHora {
public:
    StartDataEHora() = default;
    explicit StartDataEHora(const DataEHora & dataEHora);
};

class EndDataEHora: public DataEHora {
public:
    EndDataEHora() = default;
    explicit EndDataEHora(const DataEHora & dataEHora);
};

class IntervaloDeTempo: public StartDataEHora, public EndDataEHora {
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
    IntervaloDeTempo(const DataEHora& st, const DataEHora& ed);
    /**
     * Sets beginning and end of interval.
     * @param st - Beginning of the interval.
     * @param ed - End of the interval.
     */
    void set(const DataEHora& st, const DataEHora& ed);
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
    bool operator^(const IntervaloDeTempo& timeInterval) const;
    /**
     * Checks if two time intervals are equal.
     * @return True if they are equal. False otherwise.
     */
    bool operator==(const IntervaloDeTempo& timeInterval) const;
    /**
     * Output operator.
     */
    friend ostream &operator<<(ostream &output, const IntervaloDeTempo &timeInterval);
};


#endif //PROJETO_INTERVALODETEMPO_H
