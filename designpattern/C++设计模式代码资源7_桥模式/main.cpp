#include "example.h"

int main(){
    std::string uid = "FooQiuling";
    float amount=10000;

    PayMode* facepay = new FacePay();
    WechatPay* wechatpay = new WechatPay(facepay);
    wechatpay->Transfer(uid, amount);

    PayMode* fingerpirntpay = new FingerPrintPay();
    AliPay* alipay = new AliPay(fingerpirntpay);
    alipay->Transfer(uid, amount);
    
    return 0;
}