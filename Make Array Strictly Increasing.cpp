class Solution {
public:
  int makeArrayIncreasing(vector<int>& a, vector<int>& c) {
    constexpr int kInf = 1e9;
    int m = a.size();    
    // Sort b and make it only containing unique numbers.
    sort(begin(c), end(c));
    vector<int> b;
    for (int i = 0; i < c.size(); ++i) {
      if (!b.empty() && c[i] == b.back()) continue;
      b.push_back(c[i]);
    }    
    int n = b.size();
    
    // min steps to make a[0~i] valid by keeping a[i]
    vector<int> keep(m, kInf);
    keep[0] = 0;
    // swap[i][j] := min steps to make a[0~i] valid by a[i] = b[j]
    vector<int> swap(n, 1);
    
    for (int i = 1; i < m; ++i) {
      int min_keep = kInf;
      int min_swap = kInf;
      vector<int> temp(n, kInf);
      for (int j = 0; j < n; ++j) {
        if (j > 0) min_swap = min(min_swap, swap[j - 1] + 1);
        if (a[i] > b[j]) min_keep = min(min_keep, swap[j]);        
        if (a[i] > a[i - 1]) keep[i] = keep[i - 1];
        if (b[j] > a[i - 1]) temp[j] = keep[i - 1] + 1;        
        temp[j] = min(temp[j], min_swap);
        keep[i] = min(keep[i], min_keep);
      }
      temp.swap(swap);
    }
    
    int s = *min_element(begin(swap), end(swap));
    int k = keep.back();
    int ans = min(s, k);
    return ans >= kInf ? -1 : ans;
  }
};
