# chương 2
1. Tiến trình
2. Luồng 
3. Điều phối CPU
4. Tài nguyên găn và điều độ tiến trình
5. Bế tắc và xử lý bế tắc

## 2.1 Tiến trình
### 2.1.1 Khái niệm tiến trình
* Tiến trình là một dãy thay đổi trạng thái hệ thống (xuất phát từ một trạng thái ban đầu)
* Một chương tình có thể là một phần của trạng thái tiến trình 

- Dịch và thực hiện một chươg trình:
  * Đọc và dịch file thực thi
  * Thiếp lập không gian trên bộ nhớ cho tiến trình từ việc đọc file thực thi
  * Đặt các tham số, biến, dòng lệnh,.. trên bộ nhớ
  * Thiết lập các thanh ghi và bắt đầu gọi tớ hàm _start() (hàm của hệ thống ) =>> gọi tới hàm main() ==>> khi hàm main() kết thúc ==> OS gọi tới hàm _exit() để hủy tiến trình và thu hồi tài nguyên 

<img src = "https://i.imgur.com/Aolrf0Q.png">

<img src = "https://i.imgur.com/e6yyIFY.png">

### 2.1.2 Điều phối tiến trình

Mục đích: Sử dụng tối đa 

<img src = "https://i.imgur.com/Zg4tbhI.png">

<img src = "https://i.imgur.com/e6yyIFY.png">

<img src = "https://i.imgur.com/NjIOQg9.png">

Việc lựa trọn tiến trình trong các hàng đợi: 
  * Điều phối công việc: Việc lựa chọn tiến trình được lưu trong vùng đệm ==> chuyển vào bộ nhớ để sẵn sàng thực hiện
  * Điều phối CPU: Lựa chọn các tiến trình đang ở hạng đợi sẵn sàng ==>> CPU xử lí 

+ Hoán chuyển tiến trình: Luân chuyển tiến trình ra ngoài bộ nhớ sau đó đưa vào quay trở lại: Nhằm giải phóng vùng nhớ.
+ Chuyển ngữ cảnh: Việc CPU chuyển giữa các tiến trình (xảy ra khi xuất hiện tín hiệu ngắt)
### 2.1.3 Thao tác trên tiến trình
 * Tạo tiến trình 
 <img src = "https://i.imgur.com/Itf7GTz.png">
 * Kết thúc tiến trình 
 <img src = "https://i.imgur.com/H865UWN.png">