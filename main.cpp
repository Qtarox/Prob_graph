#include <stdint.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <iostream>
#include "fstream"
#include "random"
#include <cinttypes>
const int ROUND_NUM=2;
# define ROW 2048
# define COL 32
# define tst_key_num 2048
const std::string file_pth=R"(D:\YURI\PHD_NTU\linear_equation\Z-tech\GENERAL_AUTO\Data_Reader\array.txt)";//tweakey mat
const std::string save_pth=R"(D:\YURI\PHD_NTU\linear_equation\Z-tech\GENERAL_AUTO\Data_Reader\1.txt)";
const std::string save_pth2=R"(D:\YURI\PHD_NTU\linear_equation\Z-tech\GENERAL_AUTO\New_C\2.txt)";
const uint8_t CH_MAT[5][2][16] =
        {{{2,0,0,2,0,2,0,0,0,0,0,0,2,2,8,0},{6,0,0,1,0,1,0,0,0,0,0,0,1,1,4,0}},
         {{1,4,0,0,0,0,0,1,0,0,1,5,0,0,0,1},{11,2,0,0,0,0,0,11,0,0,11,2,0,0,0,8}},
         {{0,0,8,0,11,2,0,0,0,2,0,0,0,0,0,0},{0,0,4,0,1,6,0,0,0,1,0,0,0,0,0,0}},
         {{0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1},{0,0,0,8,0,0,0,0,0,8,0,0,0,0,0,11}},
         {{0,0,11,0,0,0,0,8,0,0,0,8,0,0,0,0},{0,0,1,0,0,0,0,4,0,0,0,4,0,0,0,0}}};
const uint8_t PLT_CONS[16][16]=
        {{1,3,8,10,1,3,8,10,1,3,8,10,1,3,8,10},
         {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15},
         {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15},
         {5,7,13,15,5,7,13,15,5,7,13,15,5,7,13,15},
         {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15},
         {5,7,13,15,5,7,13,15,5,7,13,15,5,7,13,15},
         {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15},
         {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15},
         {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15},
         {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15},
         {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15},
         {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15},
         {5,7,13,15,5,7,13,15,5,7,13,15,5,7,13,15},
         {5,7,13,15,5,7,13,15,5,7,13,15,5,7,13,15},
         {5,7,13,15,5,7,13,15,5,7,13,15,5,7,13,15},
         {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}};
const uint8_t KEY_DIFF[5][2][16]=
        {{{8,0,0,0,15,0,4,0,0,0,0,0,0,0,0,0},{14,0,0,0,15,0,1,0,0,0,0,0,0,0,0,0}},
         {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }},
         {{0,0,8,0,0,4,15,0,0,0,0,0,0,0,0,0},{0,0,12,0,0,2,14,0,0,0,0,0,0,0,0,0}},
         {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }},
         {{0,0,0,4,8,14,0,0,0,0,0,0,0,0,0,0},{0,0,0,4,8,12,0,0,0,0,0,0,0,0,0,0}}};

//const uint8_t TST_MAT[5][2][16]=
//        {{{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
//         {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
//         {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
//         {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
//         {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}}};
// S-box substitution table
const uint8_t SBOX[16] = {
    0xc , 0x6 , 0x9 , 0x0 ,
    0x1 , 0xa , 0x2 , 0xb ,
    0x3 , 0x8 , 0x5 , 0xd ,
    0x4 , 0xe , 0x7 , 0xf };

// Permutation table
const uint8_t SR[16] = {
    0,  1,  2, 3,
    7,  4,  5, 6,
    10, 11, 8, 9,
    13, 14, 15, 12
};

const uint8_t K_PERM[16] = {
9 , 15 , 8 , 13 ,
10 , 14 , 12 , 11 ,
0 , 1 , 2 , 3 ,
4 , 5 , 6 , 7
};

// Round constant table
// const uint8_t round_constants[16] = {
//     0x00, 0x01, 0x02, 0x04,
//     0x08, 0x10, 0x20, 0x40,
//     0x41, 0x42, 0x44, 0x48,
//     0x50, 0x60, 0x70, 0x00
// };

// Key schedule
void show_4x4mat(const uint8_t *t)
{
    for(int i=0;i<16;i++)
    {
        if(i%4==0 && i!=0)
        {
            printf("\n");
        }
        printf(" %" PRIu8 "  ", t[i]);
    }
    printf("\n");
}
uint8_t * Create(int len)
{
    auto *res=new uint8_t [len];
    return res;
}
void deleteArray(uint8_t* arr)
{
    delete[] arr;
}

void loadTXT(const std::string&  file,uint8_t mat[][32])
{
    std::ifstream infile;
    infile.open(file.data(),std::ios::in);
    if (!infile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }
    char c;
    int row=0;
    infile>>std::noskipws;
    int tmp=0;
    int col=0;
    while(!infile.eof())
    {
        infile>>c;
        if(c==' '){
//            std::cout<<" ";
            tmp=0;
            col=col+1;
        }
        if(c=='\n'){
            // std::cout<<"\n";
            tmp=0;
            if(row==2047) break;
            row++;
            col=0;
        }
        else if(c>='0' && c<='9')
        {tmp=tmp*10+int(c)-48;
            mat[row][col]=tmp;
            //printf(" %" PRIu8 "  ", mat[row][col]);
        }
    }
    infile.close();
}

void show2Darr(uint8_t arr[][32])
{
    for(int i=0;i<2048;i++)
    {
        for(int j=0;j<32;j++)
        {
            printf(" %" PRIu8 " ", arr[i][j]);

        }
        std::cout<<std::endl;
    }
}


///////////////////////preparation end/////////////////////////////

//================================key operation===================================================
uint8_t LFSR2(uint8_t input)// input is a int value and output another int variable
{
    uint8_t x=input;
    uint8_t res=0;
    uint8_t x3=x/8;
    x=x%8;
    uint8_t x2=x/4;
    x=x%4;
    uint8_t x1=x/2;
    x=x%2;
    uint8_t x0=x;
    res=x2*8+x1*4+x0*2+x3^x2;
    return res;
}
void key_pt(uint8_t *k)
{
    uint8_t tmp[16];
    for (int i=0;i<16;i++)
    {
        tmp[i]=k[K_PERM[i]];//key[i]=key[Pt[i]]
    }
    for (int i=0;i<16;i++)
    {
        k[i]=tmp[i];//key[i]=key[Pt[i]]
    }
}
uint8_t* keyXOR(const uint8_t *t1,const uint8_t *t2)//text and key shape(4,4)
{
    auto*  res= Create(16);
    for (int i=0;i<16;i++)
    {
        if(i<8)
        {
            res[i]=t1[i]^t2[i];
        }
        else
        {
            res[i]=0;
        }
    }
    return res;
}
void  key_sch2(uint8_t* k2)// for tk2
{
    key_pt(k2);
    for (int i=0;i<8;i++) {
        k2[i] = LFSR2(k2[i]);
    }
}
void key_sch1(uint8_t *tk1)
{
    key_pt(tk1);//pass
}
// ======================round func================================//
void SubCell(uint8_t* t1)//input text shape(4*4)
{
    for (int i=0;i<16;i++)
    {
            t1[i]=SBOX[t1[i]];
    }

}

void AddKey(uint8_t *t1,const uint8_t* k)//text and key shape(16,)
{
    for (int i=0;i<16;i++)
    {
            t1[i]=t1[i]^k[i];
    }
}
void ShiftRow(uint8_t *t1)//text and key shape(16,)
{
    uint8_t t2[16];
    for (int i=0;i<16;i++)
    {
        t2[i]=t1[SR[i]];
    }
    for (int i=0;i<16;i++)
    {
        t1[i]=t2[i];
    }
}
uint8_t* CellXOR(const uint8_t *t1,const uint8_t *t2)//text and key shape(16,)
{
    auto*  res= Create(16);
    for (int i=0;i<16;i++)
    {
            res[i]=t1[i]^t2[i];
    }
    return res;
}
void CellXOR2(uint8_t *r,const uint8_t *t1,const uint8_t *t2)
{
    for(int i=0;i<16;i++)
    {
        r[i]=t1[i]^t2[i];
    }
}
void gen_rnd(uint8_t *mat)
{
    static std::random_device rd; // 获取随机设备种子
    static std::mt19937 eng(rd()); // 创建随机数生成器
    std::uniform_int_distribution<> distr(0, 15); // 创建一个整数分布，范围为1到100

    for(int i=0;i<16;i++)
    {mat[i]=PLT_CONS[i][distr(eng)];}

}



void MixCol(uint8_t* t1)
{
    uint8_t t2[16];
    for (int j=0;j<16;j++)
    {
        if(j<4)
        {
            t2[j]=t1[j]^t1[j+8]^t1[j+12];
        }
        else if(j<8)
        {
            t2[j]=t1[j-4];
        }
        else if(j<12)
        {
            t2[j]=t1[j-4]^t1[j];
        }
        else
        {
            t2[j]=t1[j-12]^t1[j-4];
        }
    }
    for (int j=0;j<16;j++)
    {
        t1[j]=t2[j];
    }
}
//=================================pair func=================================
uint8_t* get_tk(const uint8_t * tk1,const uint8_t* diff)
{
    auto*  tk2= Create(16);
    for (int i=0;i<16;i++)
    {
        tk2[i]=tk1[i]^diff[i];
    }
    return tk2;
}
void LoadKey(uint8_t * tk_r,const uint8_t* twk,int tk_num=0)
{
    for(int i=0;i<16;i++)
    {
        tk_r[i]=twk[16*tk_num+i];
    }
}
//============================= Check function==================================
uint8_t * rn_fn_exp( uint8_t *t0, uint8_t *rn_key)//return a array of shape (32,) where 0-15 is before SB, 16-31 is after SB
{
    uint8_t *c_PTH=Create(32);
    for(int i=0;i<16;i++)
    {
        c_PTH[i]=t0[i];
    }
    SubCell(t0);//t0,t1 is to be checked
    for(int i=16;i<32;i++)
    {
        c_PTH[i]=t0[i-16];
    }
    AddKey(t0,rn_key);
    ShiftRow(t0);
    MixCol(t0);//t4 is the new round_function
    return c_PTH;
}
bool mSame(const uint8_t *t1,const uint8_t *t2)
{
//    printf("Calculated one:\n");
//    show_4x4mat(t1);
//    printf("True one:\n");
//    show_4x4mat(t2);

    for (int i = 0; i < 16; ++i) {
            if(t1[i]!=t2[i]) return false;
        }
    return true;
}
bool check_CH(const uint8_t *pt_1,const uint8_t *pt_2,const uint8_t *tk_1,const uint8_t *tk_2,const uint8_t *tk_3, const uint8_t *tk_4,
              int rn=ROUND_NUM)
{
//    std::cout<<"tk1: \n";
//    show_4x4mat(tk1);
//    std::cout<<"tk2: \n";
//    show_4x4mat(tk2);
//    std::cout<<"tk3: \n";
//    show_4x4mat(tk3);
//    std::cout<<"tk4: \n";
//    show_4x4mat(tk4);
    uint8_t pt1[16];
    uint8_t pt2[16];
    uint8_t tk1[16];
    uint8_t tk2[16];
    uint8_t tk3[16];
    uint8_t tk4[16];
    for(int m=0;m<16;m++)
    {
        pt1[m]=pt_1[m];
        pt2[m]=pt_2[m];
        tk1[m]=tk_1[m];
        tk2[m]=tk_2[m];
        tk3[m]=tk_3[m];
        tk4[m]=tk_4[m];


    }


    for (int i=0;i<rn;i++)
    {
//        std::cout<<"pt1:\n";
//        show_4x4mat(pt1);
//        std::cout<<"pt2:\n";
//        show_4x4mat(pt2);

        uint8_t *key1=keyXOR(tk1,tk2);
        uint8_t *c_pth1=rn_fn_exp(pt1,key1);
        uint8_t cp_1_0[16];
        uint8_t cp_1_1[16];
        for(int j=0;j<16;j++)
        {
            cp_1_0[j]=c_pth1[j];
            cp_1_1[j]=c_pth1[j+16];
        }
        key_sch1(tk1);
        key_sch2(tk2);

        uint8_t *key2=keyXOR(tk3,tk4);
        uint8_t *c_pth2=rn_fn_exp(pt2,key2);
        uint8_t cp_2_0[16];
        uint8_t cp_2_1[16];
        for(int j=0;j<16;j++)
        {
            cp_2_0[j]=c_pth2[j];
            cp_2_1[j]=c_pth2[j+16];
        }
        key_sch1(tk3);
        key_sch2(tk4);

//        std::cout<<"pth1_0: \n";
//        show_4x4mat(cp_1_0);
//        std::cout<<"pth1_1: \n";
//        show_4x4mat(cp_1_1);
//        std::cout<<"pth2_0: \n";
//        show_4x4mat(cp_2_0);
//        std::cout<<"pth2_1: \n";
//        show_4x4mat(cp_2_1);
//        std::cout<<"k1: \n";
//        show_4x4mat(key1);
//        std::cout<<"k2: \n";
//        show_4x4mat(key2);
        //chech if satisify the characteristic
        uint8_t *ch1=CellXOR( cp_1_0,cp_2_0);
        uint8_t *ch2=CellXOR( cp_1_1,cp_2_1);
//        std::cout<<"round"<<i<<"ch1: \n";
//        show_4x4mat(ch1);
//        std::cout<<"round"<<i<<"ch2: \n";
//        show_4x4mat(ch2);
        uint8_t true_ch1[16];//before S_box
        uint8_t true_ch2[16];// after S_box
        for(int k=0;k<16;k++)
        {
            true_ch1[k]=CH_MAT[i][0][k];
            true_ch2[k]=CH_MAT[i][1][k];
        }
        if(mSame(ch1, true_ch1) && mSame(ch2, true_ch2))
        {
            //pass
        }
        else
        {
            deleteArray(key1);
            deleteArray(key2);
            deleteArray(c_pth1);
            deleteArray(c_pth2);
            deleteArray(ch1);
            deleteArray(ch2);
            return false;
        }
        deleteArray(key1);
        deleteArray(key2);
        deleteArray(c_pth1);
        deleteArray(c_pth2);
        deleteArray(ch1);
        deleteArray(ch2);

    }
    return true;
}
int cal_prob(int exp_t,uint8_t* tk1, uint8_t *tk2, uint8_t *tk3,uint8_t*tk4,uint8_t *char_diff1,int rn=ROUND_NUM)
{
    int count=0;
    std::cout<<"running....\n";
    uint8_t pt[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    uint8_t pt1[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    for (int i=0;i<exp_t;i++)
    {
//        if(i%(exp_t/100)==0){
//            std::cout<<"Progress"<<(pro++)<<"%\n";
//        }
        gen_rnd(pt);
        CellXOR2(pt1,pt,char_diff1);

//        pt=p1;
//        pt1=p2;

        bool flag=check_CH(pt,pt1,tk1,tk2,tk3,tk4,rn);
        //print("the pattern is valid: ",flag)

        if(flag)
        {
            count=count+1;
//            std::cout<<"got "<<count<<" valid samples\n";
        }
    }
    return count;
}
//===================Load Read Data============================
void writeTXT(const std::string&  file,const uint8_t *array,int size)
{
    std::ofstream OutFile(file);
    for(int i=0;i<size;i++)
    {
        OutFile<<array[i]<<' ';

    }
    OutFile.close();
}
void SaveDat(const std::string&  file,const uint8_t *array,int size)
{
    std::ofstream ouF;
    ouF.open(file, std::ofstream::binary);
    ouF.write(reinterpret_cast<const char*>(array), sizeof(uint8_t)*size);
    ouF.close();
}
void LoadDat(const std::string&  file,int size)
{
    uint8_t b[size];
    std::ifstream inF;
    inF.open(file, std::ifstream::binary);
    inF.read(reinterpret_cast<char*>(b), sizeof(int)*size);
    inF.close();

    for (int i = 0; i < size; i++)
    {
        std::cout << int(b[i]) <<" ,";
    }
}

void readTXT(const std::string&  file)
{
    std::cout<<"the counts of at path: "<<file;
    std::ifstream infile;
    infile.open(file.data(),std::ios::in);
    if (!infile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }
    char c;
    int row=0;
    infile>>std::noskipws;
    while(!infile.eof())
    {
        infile>>c;
        if(c==' '){
            std::cout<<" ";

        }
        else
        {
            std::cout<<int(c);
        }
    }
    infile.close();
}

//==================================================

int main() {
    uint8_t TK_array[ROW][COL];
    loadTXT(file_pth,TK_array);//load tweaky mats
    uint8_t cnt_arr[tst_key_num];
    uint8_t char_diff1[16]={2,0,0,2,0,2,0,0,0,0,0,0,2,2,8,0};
    clock_t start,end;
    start = clock();
    long int exp_t=1<<23;
    for(int n=0;n<tst_key_num;n++)
    {
        uint8_t tk1[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
        uint8_t tk2[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
        uint8_t tk3[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
        uint8_t tk4[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
        LoadKey(tk1,TK_array[n],0);
        LoadKey(tk2,TK_array[n],1);
//        show_4x4mat(tk1);
//        show_4x4mat(tk2);
        CellXOR2(tk3,tk1,KEY_DIFF[0][0]);
        CellXOR2(tk4,tk2,KEY_DIFF[0][1]);
        int count=0;
        count=cal_prob(exp_t,tk1,tk2,tk3,tk4,char_diff1,3);
        std::cout<<"possibility for key set"<<n+1<<": "<<count<<"/"<<exp_t<<";   count : "<<count<<std::endl;
        cnt_arr[n]=count;
    }
    end = clock();   //结束时间
    std::cout<<"time = "<<double(end-start)/CLOCKS_PER_SEC<<"s"<<std::endl;
//    writeTXT(save_pth2,cnt_arr,tst_key_num);
//    readTXT(save_pth2);
    SaveDat("./3R.dat",cnt_arr,tst_key_num);
    LoadDat("./3R.dat",tst_key_num);

    return 0;

//    uint8_t p1[16]=//two round valid plaintext and tweakeys
//            {8 , 6 , 0 , 5 ,2 , 5, 11,  8 , 10 , 8, 13,  5, 15, 13 , 7 , 2};
//
//    uint8_t p2[16]=
//            {10,  6 , 0 , 7,2 , 7 ,11 , 8 ,10 , 8 ,13 , 5,13 ,15, 15 , 2};
//    uint8_t tk1[16]={2 ,15,  5, 10,  0,  2, 13,  8, 11,  0, 12,  6, 15,  0,  5,  2 };
//    uint8_t tk2[16]={8 , 2,  1,  8,  7,  9,  4, 12,  0, 12, 11,  4,  1, 10,  5,  2 };

}