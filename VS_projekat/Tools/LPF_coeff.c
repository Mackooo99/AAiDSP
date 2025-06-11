/**************************************************************
WinFilter version 0.8
http://www.winfilter.20m.com
akundert@hotmail.com

Filter type: Low Pass
Filter model: Butterworth
Filter order: 4
Sampling Frequency: 48 KHz
Cut Frequency: 1.000000 KHz
Coefficents Quantization: float

Z domain Zeros
z = -1.000000 + j 0.000000
z = -1.000000 + j 0.000000
z = -1.000000 + j 0.000000
z = -1.000000 + j 0.000000

Z domain Poles
z = 0.884752 + j -0.044575
z = 0.884752 + j 0.044575
z = 0.944278 + j -0.114854
z = 0.944278 + j 0.114854
***************************************************************/
#define NCoef 4
float iir(float NewSample) {
    float ACoef[NCoef+1] = {
        0.00001592264636101550,
        0.00006369058544406199,
        0.00009553587816609298,
        0.00006369058544406199,
        0.00001592264636101550
    };

    float BCoef[NCoef+1] = {
        1.00000000000000000000,
        -3.65806030240188340000,
        5.03143353336760680000,
        -3.08322830175881530000,
        0.71010389834158660000
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
