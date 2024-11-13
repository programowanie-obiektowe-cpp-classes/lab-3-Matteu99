#pragma once
#include "Stocznia.hpp"

unsigned int transportujFlota(unsigned int towar)
{
    unsigned int przetransportowano = 0;
    unsigned int liczbaZaglowcow = 0;
    Stocznia stocznia;

    while (przetransportowano < towar) {
        // Tworzymy statek przy pomocy fabryki
        Statek* statek = stocznia();

        // Transportujemy towar przy pomocy statku
        unsigned int iloscPrzetransportowana = statek->transportuj();
        przetransportowano += iloscPrzetransportowana;

        // Sprawdzamy, czy stworzony statek to Zaglowiec
        if (dynamic_cast<Zaglowiec*>(statek)) {
            liczbaZaglowcow++;
        }

        // Niszczenie stworzonego statku
        delete statek;
    }

    return liczbaZaglowcow;
}