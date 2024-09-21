#ifndef PAIR
#define PAIR

template<typename T, typename H> class Pair{
    public:
        T first;
        H second;
        Pair(T f, H s): first(f), second(s){}
        
        bool operator<(const Pair<T, H> other){
            if(this->first == other.first) return this->second < other.second;
            return this->first < other.first;
        }

        bool operator>(const Pair<T, H> other){
            if(this->first == other.first) return this->second > other.second;
            return this->first > other.first;
        }

        bool operator==(const Pair<T, H> other){
            return (this->first == other.first and this->second==other.second);
        }

};

#endif
