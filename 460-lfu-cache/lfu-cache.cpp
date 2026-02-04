class LFUCache {
private:
    int capacity;
    int minFreq;

    // key -> {value, frequency}
    unordered_map<int, pair<int, int>> keyValFreq;

    // frequency -> list of keys (LRU order)
    unordered_map<int, list<int>> freqList;

    // key -> iterator in freqList
    unordered_map<int, list<int>::iterator> keyIter;

public:
    LFUCache(int cap) {
        capacity = cap;
        minFreq = 0;
    }

    int get(int key) {
        if (capacity == 0 || keyValFreq.find(key) == keyValFreq.end())
            return -1;

        int val = keyValFreq[key].first;
        int freq = keyValFreq[key].second;

        // Remove key from current frequency list
        freqList[freq].erase(keyIter[key]);

        // If this was the last key of minFreq list
        if (freqList[freq].empty()) {
            freqList.erase(freq);
            if (minFreq == freq)
                minFreq++;
        }

        // Add key to freq+1 list
        freq++;
        freqList[freq].push_front(key);
        keyIter[key] = freqList[freq].begin();
        keyValFreq[key].second = freq;

        return val;
    }

    void put(int key, int value) {
        if (capacity == 0)
            return;

        // Key exists → update value & freq
        if (keyValFreq.find(key) != keyValFreq.end()) {
            keyValFreq[key].first = value;
            get(key); // reuse get() to update frequency
            return;
        }

        // Cache full → evict LFU
        if (keyValFreq.size() == capacity) {
            int evictKey = freqList[minFreq].back(); // LRU among LFU
            freqList[minFreq].pop_back();

            if (freqList[minFreq].empty())
                freqList.erase(minFreq);

            keyValFreq.erase(evictKey);
            keyIter.erase(evictKey);
        }

        // Insert new key
        keyValFreq[key] = {value, 1};
        freqList[1].push_front(key);
        keyIter[key] = freqList[1].begin();
        minFreq = 1;
    }
};
/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */