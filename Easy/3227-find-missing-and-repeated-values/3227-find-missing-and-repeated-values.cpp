class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int>res;
        int n=grid.size();

        cout<< "Grid Size: " << n << endl; 
        vector<int> freq(n*n, 0); // all elements in freq are initialized to zero
        long long a{}, b{}, ts{}, os{}; // ts=theoretical sum, os=observational sum
        ts= n*n*(n*n+1)/2;
        cout << "ts = " << ts << endl;

        for(int i{}; i<n; i++){
            for(int j{}; j<n;j++){
                int num=grid[i][j];
                int num_as_index= grid[i][j]-1;
                os+=num;
                if(freq[num_as_index]){
                    a=num;
                    freq[num_as_index]++;
                }else freq[num_as_index]++;
            }
        }
   cout<< "os = " << os << endl;
    res.push_back(a);
    b=ts-os+a;
    res.push_back(b);

    cout<<"Value of the repeating element = " << a <<" Value of the missing element = "<<b<<endl;
   // for(int i{}; i < res.size(); i++){
     //   cout << res[i] << " " ;
   // }

    return res;

    }
    
};
