class UndergroundSystem {
public:
    
    unordered_map<int , pair<string , int>> entry;
    unordered_map<string , pair<double , int>> route;
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        entry[id] = {stationName , t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto In = entry[id];
        entry.erase(id);
        
        string routeName = In.first + "_" + stationName;
        route[routeName].first += t - In.second;
        route[routeName].second +=1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string routeName = startStation + "_" + endStation;
        auto Finalroute = route[routeName];
        return Finalroute.first / Finalroute.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */