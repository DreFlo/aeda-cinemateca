cmake_minimum_required(VERSION 3.17)
project(projeto)

set(CMAKE_CXX_STANDARD 14)

add_executable(projeto main.cpp Cinemateca.cpp Cinemateca.h Evento.cpp Evento.h Aderente.cpp Aderente.h Data.cpp Data.h Hora.cpp Hora.h DataEHora.cpp DataEHora.h IntervaloDeTempo.cpp IntervaloDeTempo.h Utils.h Utils.cpp Sala.h Sala.cpp Cliente.h Cliente.cpp)