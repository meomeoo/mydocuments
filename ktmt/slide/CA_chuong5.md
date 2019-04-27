# Kiến trúc tập lệnh
1. Giới thiệu chung về kiến trúc tập lệnh
2. Lệnh hợp ngữ và toán hạng
3. Mã máy
4. Cơ bản về lập trình hợp ngữ
5. Các phương pháp định địa chỉ
6. Dịch và chạy chương trình hợp ngữ
## 1 Giơí thiệu chung về kiến trúc tập lệnh
### Các khai niệm cơ bản
*  Instruction Set Architecture: Cách nhìn máy tính bởi người lập trình
*  Microarchitecture: Cách thực hiện kiến trúc tập lệnh bằng phần cứng
*  Ngôn ngữ máy tính
  * Hợp ngữ (Assembly language): Là ngôn ngữ chung gian giữa ngôn ngữ bậc cao và ngôn ngữ máy
  * Ngôn ngữ máy (machine code): máy tính chỉ đọc ngôn ngữ này để chạy, được biểu diễn bằng 0 và 1

1. Mô hình lập trình của máy tính
* CPU nhận lệnh từ bộ nhớ chính 
  * Các lệnh của chương trình, dữ liệu,.. trước khi được CPU xử lí, thử hiện phải được nạp vào trong bộ nhớ chính (RAM) trước. 
  * Trong RAM sẽ phân vùng lưu trữ: Vùng lưu trữ lệnh, vùng lưu trữ dữ liệu,.. một cách riêng biệt.Trong bộ nhớ chính mỗi ngăn nhớ được đánh địa chỉ cụ thể để CPU có thể  phát đến chính xác và nập dữ liệu và thanh ghi.
  <img src ="https://i.imgur.com/45TrH2B.png">

  * Trong CPU có thanh ghi PC để chứa địa chỉ của lệnh cần nhận và thực hiện trong bộ nhớ. CPU sẽ dựa vào địa chỉ có trong PC và phát đến ngăn nhớ chứa lệnh trong bộ nhớ chính sau đó nạp lệnh đó vào các thanh ghi để thực hiện lệnh, địa chỉ trong PC sẽ tự động tăng đến địa chỉ của ngăn nhớ tiếp theo ngay sau lệnh trước vừa được nạp.
  <img src = "https://i.imgur.com/zKmVGJS.png">
* Giải mã và thực hiện lệnh 
  * Bộ xử lí giải mã lệnh đã được nạp vào thanh ghi và phát đi các tín hiệu điều khiển thực hiện các thao tác mà lệnh yêu cầu.
  Các
  * Các thao tác chính của lệnh:
    * Trao đổi dữ liệu giữa CPU và bộ nhớ chính hoặc cổng vào-ra
    * Thực hiện các phép toán số học hoặc phép toán logic với các dữ liệu(được thực hiện bởi ALU)
    * Chuyển điều khiển trong chương trình (rẽ nhánh, nhảy) - Những lệnh sẽ thay đổi địa chỉ của thanh ghi PC

  * Trong đó việc trao đổi dữ liệu giữa CPU và bộ nhớ chính hoặc cổng vào ra cần xác định được địa chỉ của ngăn nhớ cần đọc ghi, như vậy các lệnh yêu cầu các thao tác này sẽ chỉ định cách xác định địa chỉ theo các cách khác nhau gồm có: 
    * Hằng địa chỉ được cho trực tiếp trong lệnh
    * Giá trị địa chỉ nằm trong thanh ghi con trỏ 
    * Địa chỉ = Địa chỉ cơ sở + giá trị dịch chuyển
  * Giá trị địa chỉ được nằm trong thanh ghi con trỏ: Trong lệnh cho biết tên thanh ghi con trỏ - chứa giá trị địa chỉ, dựa vào giá trị này mà CPU phát ra ngăn nhớ chứa dữ liệu cần đọc ghi
  * Địa chỉ = Địa chỉ cơ sở + dịch chuyển: 
  Gồm có Địa chỉ cơ sở (base address): địa chỉ của ngăn nhớ cơ sở 
  Giá trị dịch chuyển địa chỉ (offset): gia số địa chỉ giữa ngăn nhớ cần đọc/ghi so với ngăn nhớ cơ sở
  Địa chỉ của ngăn nhớ cần đọc/ghi= (địa chỉ cơ sở) + (offset)
  Có thể sử dụng các thanh ghi để quản lý các tham số này
  <img src="https://i.imgur.com/9yZGq86.png">
  + Trường hợp này thường nói đến dữ liệu được lưu dạng mảng hoặc lưu trong ngăn nhớ stack
    * Ví dụ dữ liệu lưu trữ trong mảng:
    <img src = "https://i.imgur.com/XE31cSJ.png">
    * Dữ liệu đươc lưu trữ trong stack:
    Địa chỉ cở sở là địa chỉ đỉnh của ngăn sếp (Có thể thay đổi được)
    Khi cât một thông tin vào ngăn xếp: 
      Giảm nội dung của SP
      Thông tin được cất vào ngăn nhớ được trỏ bởi SP
    Khi lấy một thông tin ra khỏi ngăn xếp:
      Thông tin được đọc từ ngăn nhớ được trỏ bởi SP 
      Tăng nội dung của SP
    Khi ngăn xếp rỗng, SP trỏ và đáy
    <img src="https://i.imgur.com/3xoEffd.png">
* Tập lệnh
  * Mỗi bộ xử lí có một tập lệnh xác định
  * Tập lệnh thường có hàng chục đến hàng trăm lệnh
  * Mỗi lệnh máy là chuỗi bit (0,1) mà Bộ xử lí hiểu được để thực hiện một thao tác xác định
  * Các lệnh có thể được mô tả bằng các kí hiệu dạng text (assembly language) để người lâp trình có thể hiểu được các thao tác lệnh
* Các thành phần của lệnh máy
<img src= "https://i.imgur.com/sauGafa.png">       
Số lượng địa chỉ toán hạng có thể là: 3;2 hoặc 1
Trong đó: <img src="https://i.imgur.com/8eQSLWd.png">

* 
<img src="https://i.imgur.com/O7DxuNF.png">
## Lệnh hợp ngữ và các toán hạng
* Tập thanh ghi của MIPS 
  * MIPS có tập 32 thanh ghi 32-bit
    * Được sử dụng thường xuyên và được đánh số từ 0 - 31 (được mã hóa trong lệnh bằng 5 bit)
    * Chương trình dịch Assembler đăt tên cho các thanh ghi: 
      * Bắt đầu bằng $
    Trong MIPS : 
      * Dữ liệu 32-bit được gọi là "word"
      * Dữ liệu 16-bit được gọi là "halfword"
    <img src = "https://i.imgur.com/oYvUbc7.png">
  
  * Toán hạng là thanh ghi
  <img Scr ="https://i.imgur.com/0N1soGt.png">

  * Toán hạng ở bộ nhớ
  Chúng ta cần nạp, ghi dữ lệu từ bộ nhớ vào thanh ghi
  MIPS 32bíts sử dụng 32bit để đánh địa chỉ bộ nhớ
  Một địa chỉ có độ dài 32bit sẽ được lưu trong một thanh ghi cũng có độ dài 32bit
## Mã máy
* MIPS có 3 kiểu lệnh máy
<img src ="https://i.imgur.com/bFwGKP1.png">

<img src ="https://i.imgur.com/1fmE0mv.png">
<img src ="https://i.imgur.com/GL9sQ8f.png">
<img src ="https://i.imgur.com/g40GXxg.png">

## Cơ bản về lập trình hợp ngữ




    

