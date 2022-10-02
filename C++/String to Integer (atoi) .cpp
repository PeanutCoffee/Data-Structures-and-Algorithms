class Solution {
public:
    int myAtoi(string s) {
    
    if(s.length()==0)
        return 0;
    string ans="",temp="";
    int n=s.length();
    bool negative=false;
    int i=0;
    while((i<n) && (s[i]==' ')){
        i++;
    }
    if(i<n && s[i]=='-'){
        negative=true;i++;}
    else if(i<n && s[i]=='+'){
        i++;}
    if(i<n && (s[i]<48 || s[i]>57))
        return 0;
    while(i<n && (s[i]>=48 && s[i]<=57)){
        ans+=s[i];i++;
    }
    bool flag=false;
    for(i=0;i<ans.length();i++){
        if(ans[i]!=48){
            flag=true;}
        if(!flag) {continue;}
        temp+=ans[i];
    }
    if(temp.length()==0){
        temp="0";}
    ans=temp;
    string x=to_string(INT_MAX);
    string y="2147483648";
    bool z=(ans.length())>(x.length());
    if(z){
        ans=x;
        if(negative) return -2147483648;}
    else if(ans.length()==x.length()){
        if(negative==false){
            if(ans.compare(x)>=0)
                return INT_MAX;
        }
        else{
            if(ans.compare(y)>=0 )
                return -2147483648;
        }
    }
    int val=stoi(ans);
    if(negative==true){
        if(val==INT_MAX){
            val*=-1;
        }
        else
            val*=-1;
    }
    
    return val;;
}
};