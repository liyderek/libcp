int binpow(int b, int p) {
    int res = 1;
    while(p) {
        if(p&1) res = (res*b)%MOD;
        b = (b*b)%MOD;
        p >>= 1;
    }
    return res;
}
 
        //Modular Inverse
int inv(int b) {
    return binpow(b, MOD-2);
}
 
        //Binomial Coefficients
int nCr(int n, int r, vi &facts) {
    return (facts[n]*inv((facts[r]*facts[n-r])%MOD))%MOD;
}
 
    //Geometry
        //Distance Formula
double distanceab(double x1, double y1, double x2, double y2) {
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}
