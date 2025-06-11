/**************************************************************
WinFilter version 0.8
http://www.winfilter.20m.com
akundert@hotmail.com

Filter type: High Pass
Filter model: Butterworth
Filter order: 4
Sampling Frequency: 48 KHz
Cut Frequency: 0.500000 KHz
Coefficents Quantization: float

Z domain Zeros
z = 1.000000 + j 0.000000
z = 1.000000 + j 0.000000
z = 1.000000 + j 0.000000
z = 1.000000 + j 0.000000

Z domain Poles
z = 0.940999 + j -0.023602
z = 0.940999 + j 0.023602
z = 0.973494 + j -0.058949
z = 0.973494 + j 0.058949
***************************************************************/
#define NCoef 4
float iir(float NewSample) {
    float ACoef[NCoef+1] = {
        0.91911566251649501000,
        -3.67646265006598010000,
        5.51469397509896990000,
        -3.67646265006598010000,
        0.91911566251649501000
    };

    float BCoef[NCoef+1] = {
        1.00000000000000000000,
        -3.82898609567844690000,
        5.50142959334597940000,
        -3.51519386532860700000,
        0.84276723741100146000
    };

    static float y[NCoef+1]; //output samples
    static float x[NCoef+1]; //input samples
    int n;

    //shift the old samples
    for(n=NCoef; n>0; n--) {
       x[n] = x[n-1];
       y[n] = y[n-1];
    }

    //Calculate the new output
    x[0] = NewSample;
    y[0] = ACoef[0] * x[0];
    for(n=1; n<=NCoef; n++)
        y[0] += ACoef[n] * x[n] - BCoef[n] * y[n];
    
    return y[0];
}
