//complexity: O(k^3 * log2(n))
//practice: https://codeforces.com/gym/102644
//the product of the state matrix * the ith column of the transition matrix is the new ith value

template<typename T>
struct matrix{
    int rows, columns;
    vector<vector<T> > rep;
    
    vector<T>& operator[](int r){
        return rep[r];
    }
    
    vector<T> const & operator[](int r) const{ 
        return rep[r];
    }
    
    matrix(vector<vector<T> > v){
        rep = v;
        rows = rep.size();
        columns = rep[0].size();
    }
    
    matrix(int n, int m){
        rows = n;
        columns = m;
        
        for (int i = 0; i < n; i ++)
            rep.push_back(vector<T> (m));
    }
    
    matrix operator *(const matrix &a){
        if (columns != a.rows)
            return matrix(0, 0);
                
        matrix ret(rows, a.columns);
            
        for (int r = 0; r < rows; r ++)
            for (int c = 0; c < a.columns; c ++)
                for (int k = 0; k < columns; k ++){
                    ret[r][c] += (1ll * rep[r][k] * a[k][c]) % MOD;
                    ret[r][c] %= MOD;
                }
            
        return ret;
    }
};