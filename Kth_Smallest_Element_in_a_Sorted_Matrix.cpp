// Brute force approach O((nm)log nm)

int kthSmallest(vector<vector<int>>& matrix, int k) {
    int m = matrix.size();
    int n = matrix[0].size();

    if(m==1 && n==1 && k==1)
        return matrix[0][0];

    int ans;
    vector<int> vec;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            vec.push_back(matrix[i][j]);
        }
    }

    sort(vec.begin(), vec.end());

    return vec[k-1];
}


// Using heap(max) O(M * N * logK)

int kthSmallest(vector<vector<int>>& matrix, int k) {
    int m = matrix.size();
    int n = matrix[0].size();

    if(m==1 && n==1 && k==1)
        return matrix[0][0];

    priority_queue<int> pq;

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            pq.push(matrix[i][j]);

            if(pq.size() > k)
                pq.pop();
        }
    }

    return pq.top();
}


// using binary search
// Time: O((M+N) * logD), where M <= 300 is the number of rows, N <= 300 is the number of columns, D <= 2*10^9 is the 
// difference between the maximum element and the minimum element in the matrix.


kthSmallest(vector<vector<int>>& matrix, int k) {
    int m = matrix.size();
    int n = matrix[0].size();

    if(m==1 && n==1 && k==1)
        return matrix[0][0];

    int s = matrix[0][0] , e = matrix[m-1][n-1];
    int mid,temp,c;

    while(s<e){
        mid = s + (e - s)/2;
        temp = m-1;
        c = 0;

        for(int i=0;i<m;i++){
            while(temp>= 0 && matrix[i][temp] > mid){
                temp--;
            }

            c += (temp+1);
        }

        if(c < k)
            s = mid+1;

        else
            e = mid;
    }

    return s;
}
