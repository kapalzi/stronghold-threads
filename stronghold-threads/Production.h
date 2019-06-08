
class Production{
private:
    int stock;
    int workers;
public:
    
    Production();
    ~Production();
    
    void setStock(int x);
    void setWorkers(int x);
    void work();
};
