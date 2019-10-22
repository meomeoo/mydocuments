### Network architecture 
Topology: Hình dáng mô hình kết nối mạng giữa các nút
Protocol: Các quy tắc trong truyền thông mạng, gồm nhiều giao thức để đảm bảo kết nối và giao tiếp giữa các nút trong mạng

## Transmission models
### Packet switching vs. Circuit switching
#### Packet switching 
- Chia dữ liệu gần gửi thành các packet độc lập để vận truyển trong mạng 
- Mỗi packet mang thông tin để đảm baỏ sự vận chuyển trong mạng, Ví dụ: thông địa chỉ IP điểm đầu và cuối, loại dữ liệu,.. 
- Nhiều packet từ nhiều điểm đầu cuối khác nhau có thể dùng chung một băng thông
 * Có 2 loại packet switching:
   * Datagram switching: Các packet được gửi đi có thể sử dụng băng thông ở các đường chuyền khác nhau
   * Virtual circuit switching: Các packet từ 1 điểm đầu cuối được gửi qua một 1 kênh truyền (được thiết lập) cố định cho đến khi hoàn tất chuyền tải, các packet từ điểm đầu cuối khác cũng có thể sử dụng băng thông trên một đoạn nào đó của đường truyền đó.

#### Circuit switching
- Dữ liệu được truyền thông qua một kênh chuyền (được thiết lập) giữa 2 điểm đầu cuối.
- 3 gia đoạn của thiệt lập đường truyền
  - Thiết lập kênh chuyền
  - Truyền dữ liệu qua kênh truyền
  - Huỷ đường chuyền
- Sử dùng toàn bộ băng thông của kênh chuyền đã được thiết lập cho phiên giao tiếp giữa 2 nút.

### Connection oriented transmission vs. connectionless
#### Connection ori