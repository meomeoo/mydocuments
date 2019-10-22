#### Mô hình mạng OSI
- Là hệ thống mạng thành 7 tầng.

##### Mô hình TCP/IP
- Gộp 3 tầng trên cùng của mô hình OSI thành một tầng: tầng application
- Các gói packet (dữ liệu) được đóng gói dần dần lần lượt qua từng tầng tầng của hệ thống mạng
- Mỗi tầng có những giao thức riêng để đảo bảo quá trình truyền dữ liệu qua mạng
- Thông tin mà các giao thức sử dụng được thêm vào header của packet lần lượt qua từng tầng.
##### Đinh danh
- Mỗi tầng của hệ thống mạng dùng một dãy mã định danh để định danh thiết bị/ứng dụng trong mạng.
  * Tầng Transport layer: cổng port. cổng giao tiếp của các ứng dụng trong mạng
  * Tầng NetWork Layer: sử dụng địa chỉ IP. Địa chỉ định danh kết nối trong mạng (đinh danh node tham gia vào mạng)
  * Tầng Data Link: sử dụng  MAC adress: mã định danh phần cứng trong mạng
    * MAC adress: mã định danh được nhà sản suất cung cấp, được gắn trực tiếp với những thành phần kết nối của máy như: Wifi, bluetooth,.. mỗi máy có ít nhất một mã MAC
##### Domain name and IP address
- Domain name: một dạng địa chỉ định danh máy chủ/node theo cách mà người sử dụng có thể dễ dàng ghi nhớ. Luôn có tương ứng 1-1 giữa domain name và ip address.
- Người dùng truy cập máy chủ trong mạng thông qua domain name, domain name đó sẽ được gửi tới một máy chủ (Domain name server - DNS) có tác dụng chuyển đổi domain name đó sang địa chỉ IP của máy chủ cần tìm rồi thực hiện việc truy cập thông qua mạng  

