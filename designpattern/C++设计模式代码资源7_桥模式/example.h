#include<string>
#include<iostream>

class PayMode{ //pay mode
    public:
    virtual bool Security() = 0;
};

class Pay{//pay
protected:
    PayMode* payM_;
    public:
    virtual bool Transfer(std::string uID, float amount) = 0; //pay function
};

class FacePay: public PayMode{ // Face Pay
    public:
    bool Security(){
        std::cout << "FacePay Verify: " << std::endl;
        std::cout << "Verification success"<<std::endl;
        return true;
    }
};

class FingerPrintPay : public PayMode{ //FingerPrint Pay
    public:
    bool Security(){
        std::cout << "FingerPrintPay Verify: " << std::endl;
        std::cout << "Verification success" << std::endl;
        return true;
    }
};

class WechatPay : public Pay{ // Wechat Pay
    public:
    WechatPay(PayMode* paymode){ //construction
        payM_ = paymode;
        std::cout << "Wechat Pay" << std::endl;
    }
    bool Transfer(std::string uID, float amount){
        if(payM_->Security()){
            std::cout << "Transfer RMB " << amount << " to "<< uID << std::endl;
            return true;
        }
        return false;
    }
};

class AliPay: public Pay{ //Ali Pay
    public:
    AliPay(PayMode* paymode){
        payM_ = paymode;
        std::cout << "Ali Pay" << std::endl;
    }
    bool Transfer(std::string uID, float amount){
        if(payM_->Security()){
            std::cout << "Transfer RMB " << amount << " to " << uID << std::endl;
            return true;
        }
        return false;
    }
};
