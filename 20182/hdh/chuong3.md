# Quản lí bộ nhớ
1. Tổng quan
2. Các chiến lược quản lí bộ nhớ 
3. Bộ nhớ ảo
4. Quản lí bộ nhớ trong VXL họ Intel

## 4.1 Tổng quan
1. Bộ nhớ và chương trình
2. Liên kết địa chỉ
3. Các cấu trúc chương trình

### 4.1.1 Bộ nhớ và chương trình

- Chương trình phải nằm trong bộ nhớ để thự hiện
- Bộ nhớ được đặc trưng bởi kích thước và tốc độ truy cập (được phân cấp dựa trên tốc độ truy cập)

* Chương trình:
  * Được lưu trữ trên các thiết bị lưu trữ ngoài
  * Là các file nhị phân thực thi được (vùng tham số, lệnh máy, vùng dữ liệu)
  * Muốn được thực hiện thì phải được đưa vào bộ nhớ chính
* Hàng đợi  vào:
  * Tập các tiến trình ở bộ nhớ ngoài
  * Đợi để được đưa vào bố nhớ chính để thực thi
* Thực hiện chương trình 
  * Đọc và dịch file thực thi (vd file.com, file.exe) để chuẩn bị các yêu tố  ban đầu: xin vùng nhớ và nạp file vào bộ nhớ chính, thiết lập các tham số thích hợp cho thanh ghi
  * Thực thi chương trình: 
    CPU lấy  lệnh trong bộ nhớ chính tại thanh ghi PC để giải mã và thực hiện
  * Thực hiện xong: Giải phóng không gian nhớ dành cho chương trình
  * Vấn đề: Vị trí nạp chương trình có thể ở bất kì đâu, khi thực hiện sẽ sinh ra chuỗi địa chỉ bộ nhớ
  ###### ? Truy cập đĩa chỉ bộ nhớ như nào

  ### 4.1.2 Liên kết địa chỉ
Các chương trình sau khi được dịch sẽ được chia thành các modul --> Khi thực hiện sẽ là các modul thực hiện trong bộ nhớ chính

Các kiểu địa chỉ:
 * Địa chỉ biểu tượng: biểu thị đối tượng trong mã nguồn
 * Địa chỉ tương đối: ví trí của đối tượng so với đầu mỗi modul (sinh ra trong giai đoạn compiler) 
 * Địa chỉ tuyệt đối: Vị trí cụ thể của đối tượng trong bộ nhớ vật lí- địa chỉ vật lí

 Cách xác định địa chỉ các đối tượng:
 * Giai đoạn dịch:
  * Sử dụng khi biết trước chương trình sẽ nằm ở đâu trong bộ nhớ
  * Sau khi dịch sẽ sinh ra mã địa chỉ cụ thể của đối tượng
  * Phải dịch lại khi vị trí bắt đầu thay đổi
 * Thời điểm nạp:
  * Sử dụng khi không biết chương trình sẽ nằm ở đâu trong bộ nhớ
  * Các đối tượng sau khi dịch sẽ chỉ mang địa chỉ tương đối
  * Xác định địa chỉ được hoanj cho tới khi nạp chương trình vào bộ nhớ
 * Trong khi thực hiện:
  * Sử dụng khi các chương trình có thể thay đổi vị trí khi thực hiện
  * Xác định địa chỉ được hoãn cho tới khi thực thi chương trình
  * Thường đòi hỏi sự trợ giúp của phần cứng
  * Được sử dụng trong nhiều hệ điều hành

### 4.1.3 Các cấu trúc chương trình

1. Cấu trúc tuyến tính
* Toàn bộ các modul của chương trình sẽ được nạp hết vào bộ nhớ chính sau đó mới được thi hiện
* Nhược điểm: Lãng phí bộ nhớ, không thực hiện được những chương trình có kích thước lớn hơn bộ nhớ chính

2. Cấu trúc nạp động
* Nạp một modul gốc, sau đó thực hiện lần lượt thêm và loại bỏ các modul cần thiến và không cần thiết một cách thủ công
* Nhược điểm: Chậm, yêu cầu người dùng hiểu rõ về hệ thống --> Giảm tính lưu động

3. Cấu trúc liên kết động
* Một phần của đoạn mã(stub) sẽ được sử dụng để tìm kiếm thủ tục trong bộ nhớ --> khi tìm thấy stub sẽ được thay thế bằng địa chỉ của đoạn mã trong thư viện
* Thích hợp để xây dựng thư viện

4. Cấu trúc Overlays
* Chương trình được chia thành các mức khác nhau: Ở mỗi mức là các modul tương ứng ( Mức 0 chứa modul gốc, nạp và định vị chương trình - được biên tập thành file thực thi riêng )
* Bộ nhớ cũng chia thành các mức tương ứng với các mức của chương trình: kích thực mức bằng với kích thực modul lớn nhất của mức đó
* Mỗi mức chỉ chia một moudul tại một thời điểm (khi nạp modul vào mức nào đó --> modul trong mức đó sẽ bị đẩy ra )
* Phụ thuộc nhiều vào việc tổ chức modul trong các chương trình

## Các chiến lược quản lí bộ nhớ
1. Chiến lược phân chương cố định
2. Chiến lược phân chương động
3. Chiến lược phân đoạn
4. Chiến lược phân trang 
5. Chiến lược kết hợp phân đoạn-phân chương

### Chiến lược phân chương cố định
Chia bộ nhớ thành các phần - có kích thước khác nhau (gọi là chương)- được sử dụng như một vùng nhớ độc lập - mỗi thời điểm mỗi chương chỉ cho phép 1 chương trình tồn tại 
### Chiến lược phân chương động
- Ban đầu, toàn bộ vùng nhớ là tự do với các tiến trình (vùng trống lớn nhất)
- Khi một tiến trình yêu cầu bộ nhớ -> tìm trong danh sách một phần tử đủ lớn cho yêu cầu ->> 
* Nếu tìm thấy:
  * Vùng trống được chia thành 2 phần: vùng cung cấp và vùng trống tự do 
* Nếu không tìm thấy:
  * Phải chờ tới khi có được vùng chống thỏa mãn
  * Cho phép tiến trình khác trong hàng đợi thực hiện (nếu độ ưu tiên đảm bảo)
* Khi một tiến trình kết thúc: vùng nhớ được trả về cho vùng chống tự do 

* Các chiến lược chọn vùng trống cho yêu cầu

- Nguyên tắc: Chia đôi liên tiếp vùng trống tự do cho tới khi thu được vùng trống nhỏ nhất thỏa mãn
+ Cung cấp nhớ:
  * Chia vùng chống tìm được thành 2 khoảng bằng nhau 
  * Tiếp tục chia cho tới khi đạt vùng trống nhỏ nhất kích thước lớn hơn n
  
  * Hệ thống duy trì danh sách vùng trống kích thước 1,2,...2^n bytes 
  * Với yêu cầu K, tìm phần tử nhỏ nhất kích thước lớn hơn K
  * Nếu vùng nhỏ nhất lớn hơn 2K, tiếp tục tục chia nhỏ để được vùng nhớ nhỏ nhất lớn hơn k
  * Nhận xét: Với bộ nhớ kích thước n, cần duyệt log2n danh sách --> nhanh
+ Thu hồi nhớ:
  * Kết hợp 2 vùng nhớ kề nhau có cùng kích thước liên tục để thu được vùng trống lớn nhất có thể 

- Nhận xét:

### Chiến lược phân đoạn



