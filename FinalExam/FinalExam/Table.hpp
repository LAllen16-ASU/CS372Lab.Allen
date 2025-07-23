template <class RecordType>
class Table {
public:
    static const std::size_t CAPACITY = 1024;
    Table() = default;
    void insert(const ReacordType& entry) {
        bool alreadyPresent;
        std::size_t index;
        assert(entry.key >= 0);
        findIndex(entry.key, alreadyPresent, index);
        if (!alreadyPresent) {
            assert(size() < CAPACITY);
            index = hash(entry.key);
            // Added an iterator to count up the quadratic probing value to be squared.
            int iter = 1;
            while (!isVacant(index)) {
                index = nextIndex(index, iter);
                iter++;
            }
            ++used;
        }
        data[index] = entry;
    }
    void remove(int key) {
        bool found;
        std::size_t index;
        assert(key >= 0);
        findIndex(key, found, index);
        if (found) {
            data[index].key = PREVIOUSLYUSED;
            --used;
        }
    }
    bool isPresent(int key) const;
    void find(int key, bool& found, RecordType& result) const;
    std::size_t size() const { return used; }
private:
    static const int NEVERUSED = -1;
    static const int PREVIOUSLYUSED = -2;
    RecordType data[CAPACITY];
    std::size_t used;
    std::size_t hash(int key) const
    {
        return key % CAPACITY;
    }
    // Changed the nextIndex function to calculate the resulting index based on the index + N*N formula.
    std::size_t nextIndex(std::size_t index, int& iter) const
    {
            int result = index + (iter * iter);
            return result;
    }
    void findIndex(int key, bool& found, std::size_t& index) const {
        std::size_t count;
        int count = 0;
        i = hash(key);
        while ((count < CAPACITY) && (!never_used(i)) && (data[i].key != key)) {
            ++count;
            i = nextIndex(i);

        }
        found = (data[i].key == key);
    }
    bool neverUsed(std::size_t index) const { return (index == NEVERUSED); }
    bool isVacant(std::size_t index) const { return (index == PREVIOUSLYUSED); }
};