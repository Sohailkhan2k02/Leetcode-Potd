class Robot {
public:
    int w, h;
    int tar = 0;
    int dir = 1;
    int tdir = 1;
    Robot(int width, int height) {
        w = width;
        h = height;
    }
    
    void step(int num) {
        int temp = tar + num;
        tar = (tar + num) % (2*(w+h-2));
        
        if(tar<=w-1) dir = 1;
        else if(tar<=(w-1)+(h-1)) dir=2;
        else if(tar<=(w-1)*2+h-1) dir=3;
        else dir = 4;

        if(temp!=0 && tar==0) tdir = 4;
        else tdir = dir;
        
    }
    
    vector<int> getPos() {
        cout<<dir<<" "<<tar<<endl;
        if(dir==1) return {tar%(w), 0};
        else if(dir==2) return {w-1, (tar-w+1)%h};
        else if(dir==3) return { ((2*w+h-3) - tar)%w, h-1};
        else return {0, (2*(w+h-2)-tar)%h};
    }
    
    string getDir() {
        if(tdir==1) return "East";
        else if(tdir==2) return "North";
        else if(tdir==3) return "West";
        else return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
