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
    std::cout << "digraph G{graph[forcelabels=true;layout=neato;size=\"25,25\";fontsize=100];\
                            node[fontsize=100;pin=true;label=\"\"];";
    //////////
    for(int i=0;i<teiryuujyo_line;++i){
        std::cout << "\"" << t_basutei[i] << "\"[style=filled;fillcolor=black;color=white;penwidth=20;";
        std::cout << "pos=\"" << t_x[i] << "," << t_y[i] << "!\";";
        if(t_hyoutyuu[i].substr(0,1) == "1"){
            std::cout << "shape=triangle;orientation=0;width=4;height=4;";
        }
        else if(t_hyoutyuu[i].substr(0,1) == "2"){
            std::cout << "shape=triangle;orientation=315;width=5.656854;height=5.656854;";
        }
        else if(t_hyoutyuu[i].substr(0,1) == "3"){
            std::cout << "shape=triangle;orientation=270;width=4;height=4;";
        }
        else if(t_hyoutyuu[i].substr(0,1) == "4"){
            std::cout << "shape=triangle;orientation=225;width=5.656854;height=5.656854;";
        }
        else if(t_hyoutyuu[i].substr(0,1) == "5"){
            std::cout << "shape=triangle;orientation=180;width=4;height=4;";
        }
        else if(t_hyoutyuu[i].substr(0,1) == "6"){
            std::cout << "shape=triangle;orientation=135;width=5.656854;height=5.656854;";
        }
        else if(t_hyoutyuu[i].substr(0,1) == "7"){
            std::cout << "shape=triangle;orientation=90;width=4;height=4;";
        }
        else if(t_hyoutyuu[i].substr(0,1) == "8"){
            std::cout << "shape=triangle;orientation=45;width=5.656854;height=5.656854;";
        }
        else{
            std::cout << "shape=diamond;width=4;height=4;";
        };
        std::cout << "];";
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
