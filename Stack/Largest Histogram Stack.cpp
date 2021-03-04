

vector<vector<int>> getMergedIntervals(vector<vector<int>> intervals) {
    
    sort(intervals.begin(),intervals.end());
    stack <pair<int,int>> s;
    s.push(make_pair(intervals[0][0], intervals[0][1]));
    for(int i=0;i<intervals.size();i++){
       int start =  s.top().first;
       int end =  s.top().second;
        
        if(end < intervals[i][0]){
            s.push(make_pair(intervals[i][0], intervals[i][1]));
        }
        else if(end<intervals[i][1]){
            end = intervals[i][1];
            s.pop();
            s.push(make_pair(start,end));
        }
    }
    int count=0;
    vector<vector<int>>results(s.size());
    
    while(!s.empty()){
        results[count].push_back(s.top().first);
        results[count].push_back(s.top().second);
        count++;
        s.pop();
    }
    sort(results.begin(),results.end());
    return results;
}
