# Chapter3 Processes

## 3.1 process Concept
### 3.1.1 The Process

* Một process là một thể hoạt động, là trạng thái hoạt động của một chương tình, có thể là: Gía trị trong thanh ghi PC, giá trị trong các thanh ghi, quá trình stack,...
* Một process bắt đầu khi executable file của nó được đưa vào RAM\
* 2 process của cùng một program vẫn được coi là 2 chuỗi thực hiện riêng biệt
* Một process có thể là môi trường để thực hiện process khác 
### 3.1.2 Process State

* New: Quá trình exect file được nạp vào RAM
* Running: Quá trình CPU chạy xử lí tiến trình
* Waiting: tiến trình đợi cho một số hoạt động khác thực hiên ( truy suất vào ra,..)
* Ready: Sẵn sàng để được CPU xử lí
* Terminated: kết thực tiến trình

+ CHú ý: 
* Tại một thời điểm một CPU chỉ có thể running một process
* Nhiều tiến trình có thể ready và waiting  