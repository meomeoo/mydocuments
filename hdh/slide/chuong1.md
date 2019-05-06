# Chương 1: Tổng quan hệ điều hành
1.  Khái niệm Hệ điều hành
2.  Lịch sử phát triển Hệ điều hành
3.  Định nghĩa và phân loại Hệ điều hành
4.  Tính chất cơ bản của Hệ điều hành
5.  Các khái niệm trong hệ điều hành
6.  Cấu trúc hệ điều hành
7.  Vấn đề xây dựng Hệ điều hành
## 1.1 Khái niệm hđh
1.  Cấu trúc phân lớp của hệ thống tính toán
2.  Chức năng hệ điều hành
### 1.1.1 Cấu trúc phân lớp hệ thống tính toán
*  Hệ điều hành (Operating system) nằm giữa phần cứng của hệ thống và các chương trình ứng dụng

<img srs="https://i.imgur.com/i6UGUZs.png">

Mục tiêu: Cung cấp một môi trường để người sử dụng có thể thực hiện các chương trình ứng dụng và làm cho máy tính dễ sử dụng hơn, thuận lợi hơn và hiệu quả hơn.
*  Chuẩn hóa giao diện người dùng đối với các hệ thống phần cứng khác nhau
*  Sử dụng hiệu quả tài nguyên phần cứng và khai thác tối đa hiệu suất của phần cứng
### 1.1.2 Chức năng của hệ điều hành
1.  Giả lập một máy tính ảo
2.  Quản lý tài nguyên của hệ thống
#### 1.1.2.1 Giả lập một máy tính 

Ẩn đi các chi tiết tài nguyên vật lí của máy tính, trừu tượng hóa các chức năng của phần cứng để dàng giao tiếp và sử dụng tài nguyên phần cứng một cách đơn giản hơn thông qua một giao diện được chuẩn hóa.Từ đó:

*  Đơn giản hóa việc lập trình (giao tiếp với phần cứng máy tính)
  * Không phải làm việc với các dãy nhị phân
  * Mỗi tiến trình nghĩ nó sở hữu toàn bộ bộ nhớ, thời gian CPU, thiết bị...
  * Giúp giao tiếp với thiết bị dễ dàng hơn so với phần cứng thuần túy. Ethernetcard: Trao đổi tin cậy, theo thứ tự (TCP/IP)
*  Mở rộng hệ thống (trừ tượng hóa những chức năng) :máy in ảo, bộ nhớ ảo,.
*  Các tiến trình không ảnh hưởng trực tiếp đến tiến trình khác → lỗi ở một tiến trình không làm hỏng toàn bộ hệ thống
*  Máy ảo: Hữu ích cho phát triển hệ điều hành
  * Nếu HĐH thử nghiệm bị lỗi, chỉ giới hạn trong máy ảo
  * Trợ giúp kiểm tra các chương trình trên các HĐH khác
#### 1.1.2.2 Quản lí tài nguyên hệ thống
* HĐH phải quản lý tài nguyên để hoạt động của máy tính một cách hiệu quả nhất
* Phân phối các tài nguyên cho các chương trình khi cần thiết
* Giải quyết tranh chấp
* Quyết định thứ tự cấp phát tài nguyên cho những yêu cầu
* Ví dụ: quản lý tài nguyên bộ nhớ (hữu hạn)
  * Nhiều chương trình cùng có thể được thực hiện
  * Tránh truy cập bất hợp lệ
  * Phải đảm bảo toàn vẹn dữ liệu (dùng chung vùng nhớ: file)

## 1.2 Lịch sử phát triển HĐh 

## 1.3 Đinh nghĩa và phân loại hđh

### 1.3.1 Đinh Nghĩa

Có 4 định nghĩa từ 4 góc độ khác nhau

* Người sử dụng
* Người quản lý
* Quan điểm kỹ thuật
* Quan điểm hệ thống

Và chúng ta sẽ theo quan điểm của hệ thống: *Hệ điều hành là một hệ thống mô hình hoá, mô phỏng hoạt động của máy tính, của người sử dụng và của các thao tác viên, hoạt động trong chế độ đối thoại nhằm tạo môi trường khai thác thuận lợi hệ thống máy tính và quản lý tối ưu tài nguyên của hệ thống.*

<img src = "https://i.imgur.com/8cw4Vyx.png">

Mô phỏng 3 thành phần ⇒đòi hỏi 3 loại ngôn ngữ
* Ngôn ngữ máy
  * Là ngôn ngữ thực hiện duy nhất
của hệ thống
  * Mọi ngôn ngữ khác phải dịch ra
ngôn ngữ máy
* Ngôn ngữ vận hành của hệ thống
  * Câu lệnh của HĐH (DOS: Dir, Del..;Unix: ls, rm,..)
  * Dịch bởi Shell
* Ngôn ngữ thuật toán
  * Ngôn ngữ lập trình
  * Chương trình dịch

### 1.3.2 Phân loại 
* Hệ thống xử lí theo lô đơn chương trình
* Hệ thống xử lí theo lô đa chương trình
* Hệ thống phân chia thời gian 
* Hế thống xử lí thời gian thực 
* Hệ thống song song
* Hệ thống phân tán 

#### 1.3.2.1 Hệ thống xử lí theo lô đơn chương trình

* Thực hiện các trình chình một cách lần lượt và tự động =>> yếu cầu cần có bộ giám sát để theo dõi các công việc
* Đòi hỏi phỉa có tổ chức hàng đợi công việc
* Vấn đề: Khi chương trình truy cập I\O, processor rơi vào trạng thái chờ đợi

#### 1.3.2.2 Hệ thống xử lí lô đa chương trình

* Cho phép thực hiện nhiều chương trình đồng thời 
  * Nạp một phần mã mã và dữ liệu của các chương trình\tiến trình vào RAM để thực hiện (phần còn lại sẽ được nạp khi thích hợp) ==> Chương trình sẵn sàng được thực hiện
  * Thực hiện chương trình như hệ thống đơn chương trình
  * Nếu chương trình đang thực hiện đến phần truy cập vào I\O, processor được cho chương trình đang sẵn sàng khác
* Tiết kiệm bộ nhớ (không cần nạp toàn bộ chương trình) 
* Hạn chế thời gian dỗi của processor 

* Yêu cầu:
  * Chi phí cao cho điều phối processor: Chương trình nào tiếp theo sẽ được prosessor được sử dụng?
  * Giải quyết vấn đề chia sẻ bộ nhớ giữa các chương trình?

#### 1.3.2.3 Hệ thống phân chia thời gian (Thường được gọi là hệ điều hành đa nhiệm)

* Chia sẻ thời gian của processor cho các chương trình\tiến trình đang sẵn sàng thực hiện
* Nguyên tắc giống như hệ thống xử lý theo lô đa chương trình (Nạp một phần của chương trình vào RAM)
* Processor được phân phôi phụ thuộc chủ yếu vào sự điều phối của HĐH
* Thời gian hoán đổi giữa các tiền trình nhỏ, các chương trình cảm giác song song

#### 1.3.2.4 Hệ thống xử lí thời gian thực
* Được sử dụng trong lĩnh vực điều khiển (IOT)
* Cần giải quyết bài toán có giới hạn của độ chễ 
  * Có hạn định (deadline)
  * Hệ thống phải cho kết quả chính xác trong khoảng thời gian xác định
* Đòi hỏi sự tương thích cao giữa phần mềm vào phần cứng

#### 1.3.2.5 Hệ thống song song 

* Xây dựng cho các hệ thống có nhiều CPU 
  * Nhiều CPU =>> thực nhiện công việc nhanh hơn 
  * Độ tin cậy cao: Khả năng chịu lỗi cao hơn =>> 1 CPU hỏng không ảnh hưởng đến hệ thống
  * Ưu thế hơn hệ thống nhiều máy có một CPU vì chia sẻ bộ nhớ, thiết bị ngoại vi

* Đa xử lý đối xứng và đa xử lý không đối xứng

  * Đa xử lý đối xứng 
    * Mỗi CPU thực hiện một công việc (tiến trình\tiểu trình)
    * Các CPU giao tiếp với nhau thông qua 1 bộ nhớ chung
    * Cơ chế chịu lỗi và khả năng cân bằng tải tối ưu
    Vấn đề: Đồng bộ giữa các CPU

  * Đa xử lý không đối xứng
    * Một bộ xử lý chính kiểm soát toàn bộ hệ thống
    * Các CPU xử lý khác thực hiện theo lệnh của CPU chính hoặc theo lệnh chỉ thị được định nghĩa trước
    * Mô hình chủ tớ: CPU chính lập lịch hoạt động cho các CPU khác

    <img src = "https://i.imgur.com/i25mvQT.png" >

#### 1.3.2.6 Hệ thống phân tán

* Mỗi CPU có bộ nhớ cụ bộ tiêng và trao đổi thông tin với nhau thông qua đường truyền 
* Các CPU thường khác nhau về kích thước và chức năng (Máy cá nhân, máy trạm, Máy mini,..)
* Hệ thống được dùng để:  
  * Chia sẻ tài nguyên: Cung cấp cơ chế để chia sẻ dữ liệu, in ấn tại một vị trí xa,..
  * Tăng tốc độ tính toán: Một thao tác tính toàn được chia làm nhiều phần nhỏ được thực hiện một lúc trên nhiều CPU ở các vị trí khác nhau 
  An toàn: Một vị trí trong hệ thống bị hỏng, các vị trí khác vẫn tiếp tục làm việc

## 1.4 Các khai niệm trong HĐH

* Tiến trình và luồng
* Tài nguyên hệ thống
* Bộ xử lí lệnh (Shell)
* Lời gọi hệ thống (System calls)

### 1.4.1 Tiến trình và luồng

#### 1.4.1.1 Tiến trình

1. Tiến trình

* Là một chương trình đang thực hiện
  * Mã lệnh chương trình có thể thực thi 
  * Dữ liệu của chương trình
  * Ngăn xếp, con trỏ ngăn xếp, các thanh ghi 
  * Các thông tin cần thiết cho việc thực thi chương trình

* Tiến trình >< chương trình 
  * Chương trình: thực thể thụ động, chức đựng các chỉ thị điều khiển máy tính thực hiện một nhiệm vụ nào đó
  * Tiến trình: trạng thái động của chương trình

2. Hê thống đa tiến trình

Hệ thống da tiến trình phân chia thời gian:

* HĐH theo chu kỳ: dừng một tiến trình để bắt đầu một tiến trình khác
  * Cần lưu thông tin các tt =>> Bảng tiến trình (proces table)
* Một tiến trình có thể khởi tạo tiến trình khác 
  * vd: Shell của HĐH kích hoạt một tiến trình thực hiện lệnh: thực xong -> hủy tiến trình -> mới được thực hiện lệnh 
* Các tiến trình có thể trao đổi thông tin oviws nhau 
* Một tiến trình có thể bao gồm nhiều luồng (tiểu trình)

#### 1.4.1.1 Luồng (tiểu trình)

* Luồng: chuổi lệnh được thực hiện trong tiến trình
   * Mã thực thi, dữ liệu
   * Ngăn xếp, con trỏ lệnh, các thanh ghi 

* Gồm :
  * Tiến trình chỉ chứa một luồng (Heavyweight Process)
  * Tiến trình gồm nhiều luồng (Lightweight process)
* Mô hình đa luồng (Mulit_threading):
  * Các luồng hoạt động song song, chia sẻ biến toàn cục của tt

### 1.4.2 Tài nguyên hệ thống 

#### Định Nghĩa
* Là tất cả những gì cần thiết để cho một tiến trình có thể thực hiện được
  * Không gian: Không gian lưu trữ của hệ thống
  * Thời gian: thời gian thực hiện lệnh/truy xuất dữ liệu

#### Tài nguyên hệ thống gồm: 
  * Bộ nhớ: 
    * Đặc trưng: *dung lượng* và *thời gian truy cập* trực tiếp, tuần tự
    * Phân cấp: Bộ nhớ trong, Bộ nhớ trong, Bộ nhớ mở rộng, Bộ nhớ ngoài
    Phân biệt: 
      * Bộ nhớ: Vùng vật lí chứa dữ liệu: RAM, DISK,..
      * Thời truy cập tới bộ nhớ: Qúa trình tìm đến dữ liệu trên bộ nhớ 

  * CPU 
    * Là phần quan trọng nhất 
    * Được truy cập ở mức câu lệnh
    * Quan tâm đến thời gian xử lí 
    * Hệ thống nhiều CPU, thời gian từng CPU được quản lí và phân phối độc lập

  * Thiết bị ngoại vi
    * Tiếp nhận, kết xuất thông tin (I\O)
    * Gắn với hệ thống bởi các thiết bị điều khiển
    * Xét chung thiết bị ngoại vi - thiết bị điều khiển
    
#### Phân loại 
* Kiểu tài nguyên
  * Tài nguyên vật lý: Các thiết bị vật lý 
  * Tài nguyên logic: Biến nhớ, thiết bị ảo

* Khả năng sử dụng chung
  * Tài nguyên dùng chung được: Tại một thời điểm nó có thể cấp phát cho nhiều tiến trình khác nhau. Ví dụ: Bộ toán
  * Tài nguyên không dùng chung được nhưng phân chia được: Có thể phân chia nhau để sử dụng. Vd: Processor
  * Tài nguyên không dùng chung được và không phân chia được: tại một thời điểm chỉ có một tiến trình có thể sử dụng. Vd Máy in

* Tài nguyên ảo
  * Là loại tài nguyên cung cấp cho chương trình người sử dụng dưới dạng đã trừu tượng hóa
  * Chỉ xuật hiện khi hệ thống cần tới nó hoặc khi hệ thống tạo ra nó 
  * Tự động mất đi khi hệ thống kết thức hay chính xác hơn là khi tiến trình gắn với nó đã kết thúc 
  VD: Máy in ảo

#### Bộ xử lí lệnh (Shell)

* Tiến trình đặc biết: Nơi giao tiếp trực tiếp giữa người dùng và HĐH
* Nhiệm vụ:
  * Nhận lệnh của người sử dụng
  * phân tích lệnh
  * Phát sinh tiến trình mới để thực hiện yêu cầu của lệnh
* Nhận lệnh *thông qua cơ chế dòng lệnh*
* Các kiểu môi trường hoạt động Shell
  * Môi trường đơn nhiệm (MS-DOS):
    * Shell sẽ chờ cho tới khi tiến trình này kết thúc mới có thể nhận lệnh mới 
  * Môi trường đa nhiệm (UNIX, WINXP,..) Sau khi khởi tạo và đưa tiến trình mới vào hoạt động, Shell có thể nhận lệnh mới

#### Lời gọi hệ thống (System calls)

* Tạo môi trường giao tiếp giữa chương trình của người sử dụng và HĐH 
  * Chương trình dùng *lời gọi hệ thống* để yêu cầu các dịch vụ từ HĐH
    vd: Tạo, xóa, sử dụng các dối tượng phần mềm khác nhau được vận hành bởi HĐH 
  * Mỗi lời gọi hệ thống ứng với một thư viện các chương trình con 
* Lời gọi hệ thống được thực hiện dưới dạng:
  * Các câu lệnh trong khôn ngữ lập trình bậc thấp
  * Lệnh gọi ngắt trong hợp ngữ (Int)
  * Thủ tục gọi hàm API trong windows
* Tham số cho các dịch vụ và kết quả trả về được đặt tại các vùng nhớ đặc biết
  vd: Khi gọi ngắt mã chức năng được đặt trọng thanh ghi AH
  Int 05 : In màn hình; Int 13/AH=03h - DISK - WRITE DISK SECTOR

## 1.5 Cấu trúc HĐH 
* Các thành phần của hệ thống
* Dịch vụ Hệ điều hành
* Lời gọi hệ thống
* Các cấu trúc hệ thống 

### 1.5.1 Các thành phần của hệ thống 

* Quản lý tiến trình
* Quản lý bộ nhớ chính
* Quản lý hệ thống vào ra
* Quản lý file
* Quản lý bộ nhớ lưu trữ
* Hệ thống trao đổi dữ liệu (mạng)
* Hệ thống bảo vệ
* Giao diện người dùng

#### 1.5.1.1  Quản lí tiến trình 

* Hệ thống có thể tồn tại nhiều tiến trình tại một thời điểm
  * Tiến trình hệ thống
  * Tiến trình người sử dụng
* Nhiệm của hệ điều hành trong việc quản lý tiến trình
  * Tạo và hủy các tiến trình của người sử dụng và của hệ thống
  * Ngưng và thực hiện lại một tiến trình
  * Cung cấp cơ chế đồng bộ tiến trình
  * Cung cấp cách thông tin giữa các tiến trình
  * Cung cấp cơ chế kiểm soát bế tắc giữa các tiến trình

#### 1.5.1.2 Quản lí bộ nhớ chính 

* Vai trò của Hệ điều hành trong việc quản lý bộ nhớ chính
  * Lưu giữ thông tin về các vị trí trong bộ nhớ đã được sử dụng
và ai sử dụng
  * Quyết định tiến trình nào được nạp vào bộ nhớ chính, khi bộ
nhớ đã có thể dùng được
  * Cấp phát và thu hồi bộ nhớ khi cần thiết

#### 1.5.1.3 Quản lí hệ thống vào ra 

Múc đích: Trừu tượng hóa những đặc thù của các thiệt bị phần cứng, giups người dùng sử dụng dễ thao tác hơn
* Quản lí hệ thống vòa ra bao gồm 
  * Thành phần quản lý bộ nhớ gồm buffering, caching, spooling
  * Giao tiếp điều khiển thiết bị (device drivers) tổng quát.
  * Bộ điều khiển cho các thiết bị phần cứng đặc biệt. Chỉ có
device driver mới hiểu đến cấu trúc đặc thù của thiết bị mà nó
mô tả.

#### 1.5.1.4 Quản lí file 

* Nhiệm vụ của quản lý file
  * Tạo/ xoá một tập tin/ thư mục.
  * Hỗ trợ các thao tác trên file và thư mục
  * Ánh xạ file trên hệ thống lưu trữ phụ.
  * Backup hệ thống file trên các thiết bị lưu trữ.

#### 1.5.1.5 Quản lý bộ nhớ lưu trữ

* Vai trò của hệ điều hành trong việc quản lý đĩa
  * Quản lý vùng trống trên đĩa
  * Cung cấp vùng lưu trữ theo yêu cầu
  * Lập lịch cho truy nhâp đĩa hiệu quả

#### 1.5.1.6 Hệ thống trao đổi dữ liệu (Hệ thống phân tán)

#### 1.5.1.7 Bảo vệ hệ thống 

* Bảo vệ sự hoạt động giữa các tiền trình đang hoạt động
* Bảo vệ là cơ chế kiểm soát truy nhập của chương trình,
tiến trình hay người dùng tới hệ thống hoặc các tài
nguyên người dùng
Cơ chế bảo vệ đòi hỏi 
  * Phân biệt giữa sử dụng hợp pháp và không hợp pháp
  * Xác lập các kiểm soát được áp đặt
  * Cung cấp phương tiện ép buộcư

#### 1.5.1.8 

* Giúp thực hiện thao tác người dùng 
* Tạo cho người dùng những giao diện trực quan để giao tiếp với máy tính 

### 1.5.2 Dịch vụ HĐH

* Thi hành chương trình
* Thao tác nhập xuất
* Thao tác trên hệ thống tập tin
* Truyền thông
* Phát hiện lỗi

1. Thi hành chương trình : nạp chương trình vào bộ nhớ và
thi hành.
  * Chấm dứt thi hành theo cách thông thường hay bất thường (lỗi)
2. Thao tác nhập xuất : Để tăng tính hiệu quả, chương trình không truy xuất trực tiếp các thiết bị vào/ra.
  * HĐH phải cung cấp phương tiện để thực hiện vào ra.
3. Thao tác trên hệ thống tập tin : Chương trình có khả năng đọc, viết, tạo, xóa file
4. Truyền thông: Trao đổi thông tin giữa các tiến trình đang thực thi trên cùng một máy hoặc trên các máy trong mạng.
  * Thực hiện nhờ chia sẻ bộ nhớ hoặc bằng kỹ thuật chuyển thông điệp.
5. Phát hiện lỗi: Đảm bảo việc thực hiện được chính xác bởi chỉ ra lỗi tại CPU, bộ nhớ, trong thiết bị vào ra hay trong các chương trình.
  * Mỗi dạng lỗi, HĐH sẽ có cách giải quyết tương ứng.
 
Dịch vụ phụ trợ

Không nhằm trợ giúp người dùng mà dùng để vận hành hệ thống hiệu quả

1. Cung cấp tài nguyên: Phân phối tài nguyên cho nhiều người dùng hoặc nhiều công việc thực hiện trong cùng thời điểm
2. Thống kê báo cáo: Lưu giữ thông tin về loại và số lượng tài nguyên sử dụng, nhằm sử dụng cho tính toán (giá thành sử dụng), nghiên cứu (cải tiến hệ thống)
3. Bảo vệ: Đảm bảo mọi truy nhập tới các tài nguyên hệ thống
đều được kiểm soát

### 1.5.3 Lời gọi hệ thống 
<img src = "https://i.imgur.com/g5dwjcl.png">

Cung cấp các lời gọi hệ thống 

## 1.6 Tích chất cơ bản của hệ thống

1. Độ tin cậy cao
Mọi hoạt động của HĐH đều phaỉ chính xác và được kiêm tra kĩ khi thực hiện.

<img src = "https://i.imgur.com/laRvBqP.png">
<img src = "https://i.imgur.com/hUA00mt.png">

2. An toàn

<img src = "https://i.imgur.com/nqTyFc2.png">

3. Hiệu quả 

<img src = "https://i.imgur.com/GVdnYov.png">

4. Tổng quát theo thời gian 

<img src ="https://i.imgur.com/vgJ8BJ0.png">

5. Thuận tiện 

<img src = "https://i.imgur.com/NRydYum.png">
































