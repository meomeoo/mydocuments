
- Học thêm về phần khai báo phạm vi truy cập với cac phương thức khởi tạo 
- tìm hiểu lại về Downcasting , trường hợp ép kiểu từ cha thành con ??

## 25/10/2019

- Tìm hiểu về liên kết tĩnh và liên kết động khi có mạng
- equals của lớp tự viết

## 1/11/2019

- Có 3 công cụ để xây dựng project:
  - Ant 
  - Maven 
  - Gradle
* Ant: 
  - Được xem công cụ hiện đại đầu tiên, được phát hành năm 2000, sử dụng XML để xây dựng build script (XML là ngôn ngữ phân cấp - không phù hợp để viết lập trình tủ tục)
  - Một vấn đề là XML sẽ trở nên rất lớn với việc dùng với nhiều thành phần nhỏ
* Maven: 
  - Được phát hành năm 2004, mục tiêu là cải tiến những vấn đề gặp phải với Ant.
  - Vẫn sử dụng XML để viết build script, trong khi Ant yêu cầu người dùng tự viết toàn bộ build script thì Maven dựa trên các quy ước có sẵn, các bản phụ thuộc của Maven có thể dow được về
  - Việc xử lí xung đột ở các phiên bản libaryly khác nhau không được tốt (Ant tốt hơn trong một số trường hợp)

* Gradle:
  - Được phát triển dựa trên ưu điểm của 2 công cụ nêu trên, buils script được viết bằng DSL 
