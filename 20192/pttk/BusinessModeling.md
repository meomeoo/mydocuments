### Mục đích: 
    * Hiểu cấu trúc hoạt động của tổ chức sẽ triển khai hệ thống
    * Xác định vấn đề cải tiến, các yêu cầu của hệ thống mà mình sẽ triển khai
    * Cung cấp thông tin cho các bên liên quan
* Xác định đối tác nghiệp vụ (business actor): 
    + Các đối tượng bên ngoài tổ chức có tương tác với tổ chức vd: khách hàng, nhà cung cấp, có thể là hệ thống khác,..
    + (chú ý dễ nhập lẫn đối tác trong ca nghiệp vụ và đối tác trong ca sử dụng)
    + Muốn xác định đối tượng: dựa theo hoạt động nghiệp vụ mà ta quan tâm
    + Vi dụ: tổ chức: Trường đại học quan tâm đến hoạt động dạy và học thì các đối tác là: sinh viên, công nhân, nhân công,..
* Xác định thừa tác viên nghiệp vụ (business worker):
    + Đối tượng bên trong tổ chức tham gia và trực tiếp quá trình thực hiện nghiệp vụ (xác định theo vai trò với tổ chức chứ không xác định theo một cá nhân cụ thể; ví dụ: giáo viên, ban giám hiệu, cán bộ phòng đào tạo,. ), khó khăn khi một cá nhân có nhiều vai trò
    + Các thừa tác viên kèm theo note(mô tả) để làm rõ: 
        - Trách nhiệm, kĩ năng
        - Tương tác với các thừa tác viên khác 
        - Tham gia vào luồng công việc gì? Trách nhiệm trong luồng công việc? (phần quan trọng nhất)
    + VD: Nhân viên kế toán, giáo viên
    + Vi dụ: tổ chức: Trường đại học quan tâm đến hoạt động dạy và học thì các thừa tác viên nghiệp vụ là: cán bộ nhân viên, giảng viên,..
* Xác định ca nghiệp vụ (business usecase) và xây dựng biểu đồ ca nghiệp vụ
    + Ca nghiệp vụ (business uescase) (các hoạt động nghiệp vụ chính của tổ chức): 
        - Mỗi hoạt động nghiệp vụ chính gồm một chuỗi các hoạt động nghiệp vụ (work flow), 1 luồng cụ thể (luồng công việc trong 1 hoạt động nghiệp vụ) 
        - Cần xác định danh giới của ca nghiệp vụ: bắt đầu -> kết thúc
            ví dụ: 
                * Hoạt động nghiệp vụ: Bán hàng trong siêu thị
                Các chuỗi hoạt động nghiệp vụ gồm: Khách hàng bước vào siêu thị ->> lấy giỏ hàng ->> lựa chọn hàng ->> bỏ vào giỏ hàng ->> yêu cầu tư vấn từ nhân viên (nếu có) ->> các nhân viên trả lời ->> khách hành bỏ lại giỏ hàng hoặc đi thanh toán ->> đem giỏ hàng đi thanh toán ->> nhân viên thu ngân tính giá trị giỏ hàng ->> yêu cầu thanh toán ->> nhận tiền ->> nhân viên đưa hóa đơn ->> khách hàng rời khỏi siêu thị
                * Hoạt động nghiệp vụ: Nhập hàng
                Các chuỗi hoạt động nghiệp vụ gồm: Khi có yêu cầu nhập mặt hàng ->> bộ phận kinh doanh tìm kiếm nhà cung cấp ->> liên hệ các nhà cung cấp để lấy giá ->> lựa chọn nhà cung cấp có giá tối ưu ->> kết nối nhà cung cấp ->> đàm phán hợp đồng ->> xây dựng hợp đồng ->> nhà cung cấp vận chuyển về kho cho siêu thị -> kết thúc
        - Công việc business alistic là đi phân tích các tổ chức , phân tích hoạt động ->> phân tích được họ cần gì từu hệ thống phần mềm, nếu họ chưa có ->> đề xuất, nếu có rồi cải tiến
        - Chú ý luồng hoạt động nghiệp vụ phải bao quát hoạt động trong phạm vi rộng hơn (chứ k phải chỉ hoạt động trong phần mềm) có cả những hoạt động không sử dụng phần mềm
            - Ví dụ: Hoạt động bán hàng trong siêu thị: thì luồng hoạt động đó gồm một chuỗi các hoạt động liên quan đến bán hàng liên quan tới cả các business actor và business worker
    + Biểu đồ ca nghiệp vụ (biến đổi biểu đồ ca sử dụng thành biểu đồ ca nghiệp vụ) :
        - Thể hiện các hoạt động nghiệp vụ
        - Thể hiện các đối tác nghiệp vụ, thừa tác viên
        - Mối liên quan: đối tác/thừa tác viên tham gia ca nghiệp vụ, đối tác/thừa tác viên khởi xướng ca nghiệp vụ
* Đặc tả ca nghiệp vụ:
    + Mô tả bằng cách xác định trình tự tương tác của đối tượng của ca nghiệp vụ
    + Đặc tả chi tiết hoạt động nghiệp vụ: Có thể dùng biểu đồ hoạt động để đặc tả
    + Bao gồm các luồng chính, luồng ngoại lệ
    + Sử dụng biểu đồ hoạt động (mỗi ca nghiệp vụ chính một biểu đồ): 
        - Mỗi ca nghiệp vụ được chia ra các luồng, mỗi luồng tương ứng với một đối tác hoặc vùng đối tác: business actor hoặc business worker
        - Sử dụng biểu đồ đồ mô tả hoạt động của từng ca nghiệp vụ giúp từ đó phân tích và xem xét đề suất đưa phần mềm vào hỗ trợ
        - Thường vẽ 2 bản: 
            Một biều hoạt động mô tả hiện trạng hiện thời của hoạt động nghiệp vụ, sau đó đem về phân tích  
            Đưa ra biểu đồ hoạt động mới của ca nghiệp vụ với sự thay đổi khi đưa phần mềm vào( nhưngx cải tiến hay những thay đổi) từ đó giúp xác định vai trò của phần mềm trong tổ chức

* Xác định các thực thể nghiệp vụ (business usecase): 
    Có thể là các đối tượng vất lí, thông tin, .. được đề cập trong các hoạt động nghiệp vụ