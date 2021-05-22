class NPOD  
    {  
    int x_;  
    char* buf_;  
  
    NPOD() : buf_(0) {}  
    ~NPOD() { delete buf_; }  
    NPOD& operator=(const NPOD& other)  
        {  
        x_ = other.x_;  
        int bufLen = strlen(other.buf_);  
        buf_ = new char[bufLen+1];  
        memcpy(buf_, other.buf_, bufLen);  
        }  
    }  
  
NPOD t1, t2;  
...  
t1 = t2;  
memcpy(&t1, &t2);  

