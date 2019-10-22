# Bộ xử lý

1. Tổ chức của CPU
2. Thiết kế đơn vị điều khiển
3. Kỹ thuật đường ống lệnh
4. Ví dụ thiết kế bộ xử lý theo kiến trúc MIPS (*)

## 6.1 Tô chức của CPU 

1. Cấu trúc cơ bản của CPU

<img src = "https://i.imgur.com/s4Pp2qo.png" >

2. ALU (Đơn vị số học và logic)
  * Chức năng: Thực hiện phép toán số học và phép toán logic 
<img src = "https://i.imgur.com/NM30pgA.png">

3. CU (Đơn vị điều khiển) 

<img src = "https://i.imgur.com/jEi9fLI.png">

<img src = "https://i.imgur.com/7ymcQOm.png">

4. Hoạt động của chu trình lệnh

<img src = "https://i.imgur.com/dzausv7.png">

* Nhận lệnh (quá trình lệnh được nạp từ bộ nhớ vào thanh ghi )
<img src = "https://i.imgur.com/LT4pBz9.png">

* Giải mã lệnh ( quá trình CU giải mã lệnh để xác định công việc mà lệnh yêu cầu )
<img src = "https://i.imgur.com/k9SNw4V.png">

* Nhận dữ liệu từ bộ nhớ (Nhận toán hạng) ( Qúa trình chuẩn bị dữ liệu nếu cần nạp dữ liệu từ bộ nhớ vào các toán hạng -thanh ghi để thực hiện lệnh)

<img src = "https://i.imgur.com/vb6LPv2.png">

* Thực hiện lệnh ( quá trình CU phát ra những tín hiệu mà lệnh yêu cầu =>> các thành phần được điều khiển sẽ thực hiện thao tác mà lệnh yêu cầu)
<img src = "https://i.imgur.com/fl6k3aT.png">

* Ngắt 
<img src = "https://i.imgur.com/mqOPrCq.png">

## 6.2 Các phương pháp thiết kế CU

<img src = "https://i.imgur.com/ZCB703T.png">

<img src = "https://i.imgur.com/zPen5p1.png">

## 6.3 Kĩ thuật đường ống lệnh
Mục đích: Tối ưu hóa thời gian sử dụng CPU để sử lí luồng va cai gi do t dang test gitq sdvfdsvdsvvds