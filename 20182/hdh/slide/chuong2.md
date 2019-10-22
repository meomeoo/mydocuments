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

 ### 2.1.4 Hợp tác tiến trình 

Mục đích: 
* Chia sẻ thông tin
* Tăng tốc độ tính toán
* Module hóa
* Tiện dụng

Đòi hỏi cơ chế cho phép:
  * Truyền thông giữa các tiến trình
  * Đồng bộ hóa hoạt động của các tiến trình

### 2.1.5 Truyền thông liên tiến trình

Có 2 mô hình: 
* Dùng mô hình bộ nhớ phân chia: các tiến trình dùng chung bộ nhớ chính

* Dùng mô hình truyền thông liên tiến trình:
  * Cho phép truyền thông và đồng bộ các hoạt động
  * Thường dùng cho các hệ thống phân tán
  * Được đảm bảo bởi *Hệ thống truyền thông điệp*

##### Hệ thống truyền thông điệp 

* Có 2 thao tác cơ bản: Send và Receive nhận thông tin
* 2 Tiến trình muốn trao đổi chúng cần:
  * Thiết lập liên kết truyền thông (cầu nối) vật lí\logic giữa chúng
  * Trao đổi các messages nhớ các theo tác send/receive

###### Truyền thông trực tiếp:
* Các tiến trình phải chỉ rõ tiên tiến trình nhận, gửi messages rõ ràng:
  * send (P,message)- gửi mess đến P
  * receive(Q,message)- nhận mess từ Q
* Các tính chất:
  * Các liên kết được thiếp lập tự động
  * Một liên kết chỉ gắn với cặp tiền trình truyền  thông
  * Chỉ tồn tại một liên kết giữa cặp tiến trình
  * Liên kết có thể là 1 chiều nhưng thường là 2 chiều

###### Truyền thông gián tiếp

Sử dụng mailbox, port chung để truyền thông điệp

<img src = "https://i.imgur.com/CMXpbRr.png">


