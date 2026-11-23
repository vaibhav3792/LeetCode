class ProductOfNumbers {
private:
    vector<int> pre;
    int size = 0;
public:
    ProductOfNumbers() {
        pre.push_back(1);
        size = 0;
    }
    
    void add(int num) {
        if(num==0){
            pre = {1};
            size = 0;
        } else{
            pre.push_back(pre[size]*num);
            size++;
        }
    }
    
    int getProduct(int k) {
        if(k>size) return 0;

        return pre[size] / pre[size-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */