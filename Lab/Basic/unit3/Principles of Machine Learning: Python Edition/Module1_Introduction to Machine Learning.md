### Ngày 3/1/2020

## 1.1 High Level Data Science Process 

- Luồng phân tích của BigData
<img src = "https://i.imgur.com/Fg1VyqP.png" />

1. Acquisition/Recording: Tổng hợp, thu thập dữ liệu từ hành vi của người dùng trên mạng hay bất cứ đâu
2. Extraction/Cleaning/Annotation: Giống bước tiền xử lí, làm sạch loại bỏ những dữ liệu dư thừa, nhiễu không cần thiết hay chú thích những thông tin cần thiết
3. Integration/Aggregation/Representation: Đưa dữ liệu và các cấu trúc cần thiết và phù hợp, những văn bản sẽ được liên kết đến mạng bảng cấu trúc phù hợp nào đó.
4. Phân tích và mô hình hóa, xử lí MachineLearning và khai thác giữ liệu
5. Đưa ra những kết quả, hay nhận được từ quá trình xử lí dữ liệu 

- Dù có do ai hay vào thời điểm nào các giai đoạn của quá trình là tương tự nhau 
- Quá trình làm việc khoa học là một quá trình lặp đi lặp lại, không thể nào chỉ thực hiện một lần

Exampel: 
1. Bước 1: Xác định mục tiêu
nhiệm vụ 1: Thực hiện dự đoán xảy ra vụ nổ (và so sánh hiệu suất của dự đoán bằng cách sử dụng dữ liệu trong quá khứ)
        Nhiệm vụ 2: Thức hiện đánh giá 2 hàm chi phí(chi phí kiểm tra và chi phí xảy ra vụ nổ ) để xác định một tần suất các vụ nổ cần được kiểm tra (cảm kiểm tra nhiều thì tỉ lệ các vụ nổ càng ít và ngược lại )
2. Bước 2: Hiểu và thu thập dữ liệu cần thiết.  
- Nhận được thông tin từ các nhân viên điều phối khi sự việc diễn ra
- Thu thập dữ liệu các loại khác như: vị trí hố ga, loại vỏ bọc 
- Nhận được một số dữ liệu về các cáp ngầm nhưng nó lại khác khớp với dữ liệu về hố ga, 
- Và phải thực hiện xem cái hố nào phù hợp với hố nào: giống như bước tiền xử lí, làm sạch dữ liệu cần thiết
- Ta thu được rất nhiều các bảng độc lập về dữ liệu thông qua các cuộc kiểm tra mới (không khớp với những dữ liệu cũ)
- 4 Điều cần của Big Data : Tốc độ, Tính chính xác, đa dạng, khối lượng và tính đa dạng và tính chính xác đang là chở ngại cho quá trình làm việc 

3. Bước 3: Data cleaning và chuyển đổi (loại bỏ dữ liệu dư thừa) 
- Thường chiếm thời gian lớn trong công việc, chuyển free data và những dạng vecter

4. Modeling: Thực hiện tính toán các mô hình và đưa vào dữ liệu thô (đã được chuẩn bị) và đưa ra những dữ liệu có ý nghĩa
- Một số dạng machinelearning thông dụng:
<img src="https://i.imgur.com/b9lt9mf.png" />

5. Evaluation: Bước đánh giá xem những kết quả bạn đưa gia từ mô hình có đáng giá, hay có đúng hay không
6. Deployment: Thực hiện triển khai mô hình vào thực tế
- Dừng chỉ thực hiện những thứ mà không được trỉển khai, thực tế và có sự quan suát với dòng thời gian vì theo thời gian mọi thứ thay đổi: mục đích, dữ liệu,..
- Khi thực hiện cần phải bảo trì và phát triển hệ thống, vì vậy ta sẽ phải lặp đi lặp lại ở một vài bước 
### Ngày 4/1/2020

## 1.2 Overview of Machine Learning
### Video1
- Các bước cơ bản của quá trình ML
 * Thu thập và nhập dữ liệu
 * Khám phá dữ liệu: hiểu mối quan hệ giữa các feature và lable và giữa các feature với nhau
 * Chuẩn bị dữ liệu: 
        * Thực hiện loại bỏ những dữ liệu dư thừa, loại nhiễu, bỏ những thành phần không cần thiết
        * Chuẩn hóa dữ liệu
        * Chia tập dữ liệu (train và test)
  * Cấu trúc và đánh giá mô hình ML 

Thuật toán KNN
 * Là thuật toán không yêu cầu bước training
 * Một điểm mới được thêm vào và dữ đoán được dựa trên khoảng cách với các điểm đã có
        - Sử dụng số liệu về khoảng cách
        - Sử dụng khoảng cách eulidian
        - Đánh trọng số khoảng cách cho điểm (khoảng cách càng lớn thì trọng số càng lớn)