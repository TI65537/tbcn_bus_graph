名古屋市交通局のバス路線グラフ

注意

* 名古屋市交通局 "非公式" です。そのため、誤りや不正確な情報を含んでいる可能性があります。

* このC++コード、svgデータ、pdfデータで損害を負っても保証はしません。自己責任で使用してください。

名古屋市交通局のオープンデータを利用して作った路線図風グラフです。

使用法

1. 作りたいグラフ用のC++コードファイルとtbcn_bus_graph_cpp_line.cppを作業ディレクトリに配置する。

2. 名古屋市交通局Webサイトから停留所一覧、系統一覧、並順一覧のcsvファイルをダウンロードし、作業ディレクトリに配置する。
   これらのファイルの名前をそれぞれにteiryuujyo.csv、keitou.csv、narabijyunn.csvに改名し文字コードをUTF-8にする。
   各ファイルの行数をtbcn_bus_graph_cpp_line.cppに書き込む。

3. 作りたいグラフ用のC++コードファイルをコンパイルして、実行する。標準出力にDOT言語のコードが出力されるので、ファイルに保存する。
4. 保存したファイルを-n1オプションを付けてGraphvizに入力する。

コマンド実行例
c++ tbcn_bus_graph_cpp_1.cpp -o tbcn_bus_graph_cpp_1.exe
tbcn_bus_graph_cpp_1>tbcn_bus_graph_cpp_1.dot
dot tbcn_bus_graph_cpp_1.dot -n1 -Tsvg -o tbcn_bus_graph_cpp_1.svg

各グラフの説明
tbcn_bus_graph_cpp_1  標柱の位置, 乗り場番号, 停留所の囲い, 停車する系統, 停車する路線, 停車する順番 を表示
tbcn_bus_graph_cpp_2  標柱の位置, 乗り場番号, 停留所の囲い, 停車する系統 を表示
tbcn_bus_graph_cpp_3  標柱の位置, 乗り場番号, 停留所の囲い を表示
tbcn_bus_graph_cpp_4  標柱の位置 を表示
tbcn_bus_graph_cpp_a  路線図風
tbcn_bus_graph_cpp_b  停留所を順に線で結んだもの 路線ごとに色分け
tbcn_bus_graph_cpp_c  停留所を順に線で結んだもの
tbcn_bus_graph_cpp_d  標柱を順に線で結んだもの 路線ごとに色分け
tbcn_bus_graph_cpp_e  標柱を順に線で結んだもの

