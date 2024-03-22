#include<string>
#include<fstream>
#include<sstream>
#include<iostream>

/*前処理1 市バス停留所一覧(xxxxxxxx).csv 市バス系統一覧(xxxxxxxx).csv 市バス停留所並順一覧.csvを
Shift-JISからUTF-8に変換して teiryuujyo.csv keitou.csv narabijyunn.csv として保存する*/
/*前処理2 それぞれの行数を調べ tbcn_bus_graph_cpp_line.cpp の teiryuujyo_line keitou_line narabijyunn_line に保存する*/

int main(void){
    #include"tbcn_bus_graph_cpp_line.cpp"
    //////////
    --teiryuujyo_line;
    --keitou_line;
    --narabijyunn_line;
    std::string* t_namae = new std::string [teiryuujyo_line];
    std::string* t_kana = new std::string [teiryuujyo_line];
    std::string* t_basutei = new std::string [teiryuujyo_line];
    std::string* t_teiryuujyo = new std::string [teiryuujyo_line];
    std::string* t_hyoutyuu = new std::string [teiryuujyo_line];
    std::string* t_noriba = new std::string [teiryuujyo_line];
    long* t_y = new long [teiryuujyo_line];
    long* t_x = new long [teiryuujyo_line];
    std::string* k_keitou = new std::string [keitou_line];
    std::string* k_rosenn = new std::string [keitou_line];
    std::string* k_houkou = new std::string [keitou_line];
    std::string* k_kigou = new std::string [keitou_line];
    std::string* k_kitenn = new std::string [keitou_line];
    std::string* k_syuutenn = new std::string [keitou_line];
    std::string* k_keiyu = new std::string [keitou_line];
    std::string* n_keitou = new std::string [narabijyunn_line];
    std::string* n_rosenn = new std::string [narabijyunn_line];
    std::string* n_houkou = new std::string [narabijyunn_line];
    int* n_narabijyunn = new int [narabijyunn_line];
    std::string* n_basutei = new std::string [narabijyunn_line];
    {
        std::ifstream ifs("teiryuujyo.csv");
        std::string line;
        std::getline(ifs,line);
        for(int i=0;i<teiryuujyo_line;++i){
            std::getline(ifs,line);
            std::istringstream ls(line);
            std::string element;
            std::getline(ls,element,',');
            t_namae[i] = element;
            std::getline(ls,element,',');
            t_kana[i] = element;
            std::getline(ls,element,',');
            t_basutei[i] = element;
            std::getline(ls,element,',');
            t_teiryuujyo[i] = element;
            std::getline(ls,element,',');
            t_hyoutyuu[i] = element;
            std::getline(ls,element,',');
            t_noriba[i] = element;
            std::getline(ls,element,',');
            t_y[i] = std::stol(element.erase(2,1));
            std::getline(ls,element,'\r');
            t_x[i] = std::stol(element.erase(3,1));
        };
    };
    {
        std::ifstream ifs("keitou.csv");
        std::string line;
        std::getline(ifs,line);
        for(int i=0;i<keitou_line;++i){
            std::getline(ifs,line);
            std::istringstream ls(line);
            std::string element;
            std::getline(ls,element,',');
            k_keitou[i] = element;
            std::getline(ls,element,',');
            k_rosenn[i] = element;
            std::getline(ls,element,',');
            k_houkou[i] = element;
            std::getline(ls,element,',');
            k_kigou[i] = element;
            std::getline(ls,element,',');
            k_kitenn[i] = element;
            std::getline(ls,element,',');
            k_syuutenn[i] = element;
            std::getline(ls,element,'\r');
            k_keiyu[i] = element;
        };
    };
    {
        std::ifstream ifs("narabijyunn.csv");
        std::string line;
        std::getline(ifs,line);
        for(int i=0;i<narabijyunn_line;++i){
            std::getline(ifs,line);
            std::istringstream ls(line);
            std::string element;
            std::getline(ls,element,',');
            n_keitou[i] = element;
            std::getline(ls,element,',');
            n_rosenn[i] = element;
            std::getline(ls,element,',');
            n_houkou[i] = element;
            std::getline(ls,element,',');
            n_narabijyunn[i] = std::stoi(element);
            std::getline(ls,element,'\r');
            n_basutei[i] = element;
        };
    };
    //////////
    std::cout << "digraph G{graph[splines=polyline;forcelabels=true;layout=neato;size=\"25,25\";fontsize=100;outputorder=edgesfirst;penwidth=10;sep=0];\
                            node[shape=\"point\";fontsize=150;label=\"\"];\
                            edge[penwidth=25;labelfloat=true];";
    //////////
    int x_max = 0;
    int y_max = 0;
    int x_min = 1000000000;
    int y_min = 1000000000;
    for(int i=0;i<teiryuujyo_line;++i){
        if(x_max < t_x[i]){
            x_max = t_x[i];
        };
        if(y_max < t_y[i]){
            y_max = t_y[i];
        };
        if(x_min > t_x[i]){
            x_min = t_x[i];
        };
        if(y_min > t_y[i]){
            y_min = t_y[i];
        };
        bool flag = false;
        if(i < teiryuujyo_line-1){
            if(t_teiryuujyo[i] != t_teiryuujyo[i+1]){
                flag = true;
            };
        }
        else{
            flag = true;
        };
        if(flag){
            std::cout << "\"" << t_teiryuujyo[i] << "\"[fontsize=500;style=solid;color=black;shape=box;pos=\"" << (x_max+x_min)/2 << "," << (y_max+y_min)/2 << "!\";];";
            x_max = 0;
            y_max = 0;
            x_min = 1000000000;
            y_min = 1000000000;
        };
    };
    //////////
    for(int i=0;i<narabijyunn_line-1;++i){
        if(n_narabijyunn[i] < n_narabijyunn[i+1]){
            if(n_basutei[i].substr(0,5) != n_basutei[i+1].substr(0,5)){
                std::cout << "\"" << n_basutei[i].substr(0,5) << "\"->\"" << n_basutei[i+1].substr(0,5) << "\"[penwidth=50];";
            };
        };
    };
    //////////
    std::cout << "}";
    //////////
    delete [] t_namae;
    delete [] t_kana;
    delete [] t_basutei;
    delete [] t_teiryuujyo;
    delete [] t_hyoutyuu;
    delete [] t_noriba;
    delete [] t_y;
    delete [] t_x;
    delete [] k_keitou;
    delete [] k_rosenn;
    delete [] k_houkou;
    delete [] k_kigou;
    delete [] k_kitenn;
    delete [] k_syuutenn;
    delete [] k_keiyu;
    delete [] n_keitou;
    delete [] n_rosenn;
    delete [] n_houkou;
    delete [] n_narabijyunn;
    delete [] n_basutei;
    return 0;
};
