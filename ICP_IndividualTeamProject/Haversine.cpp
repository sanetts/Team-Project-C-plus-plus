//
// Created by Morgan Sarpong on 29/11/2022.
//

#include "Haversine.h"
#include "GetObject.h"
#include <vector>
#include<cmath>
using namespace std;

double Haversine::haversine(double lat1, double lon1,
                        double lat2, double lon2) {
    // distance between latitudes
    // and longitudes
    double dLat = (lat2 - lat1) *
                  M_PI / 180.0;
    double dLon = (lon2 - lon1) *
                  M_PI / 180.0;

    // convert to radians
    lat1 = (lat1) * M_PI / 180.0;
    lat2 = (lat2) * M_PI / 180.0;

    // apply formulae
    double a = pow(sin(dLat / 2), 2) +
               pow(sin(dLon / 2), 2) *
               cos(lat1) * cos(lat2);
    double rad = 6371;
    double c = 2 * asin(sqrt(a));
    return rad * c;
}

double Haversine::getDistance(int sourceAirportId, int destinationAirportId) {
    Airport sourceAirport = GetObject::AirportObjects[0];
    Airport destinationAirport = GetObject::AirportObjects[0];

    for (Airport airport: GetObject::AirportObjects) {
        if (airport.getAirportid() == sourceAirportId) {
            sourceAirport = airport;
        } else if (airport.getAirportid() == destinationAirportId) {
            destinationAirport = airport;
        }
    }

    return haversine(sourceAirport.getLatitude(), sourceAirport.getLongitude(),
                     destinationAirport.getLatitude(), destinationAirport.getLongitude());
}