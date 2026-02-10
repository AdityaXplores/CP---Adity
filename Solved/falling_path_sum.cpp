int main(){
    return f(0, 0, matrix);
}
int f(){
    if( i == 0) return m[0][j];
    int u = m[i][j] + dp[i-1][j-1];
    int ld = m[i][j];
    if (j-1 >= 0) ld += dp[i][j-1];
    int rd = m[i][j];
    if(i-1 >=0 && j+1 <= n) rd += dp[i-1][j+1];
    return max(u, max(ld, rd));
    
}