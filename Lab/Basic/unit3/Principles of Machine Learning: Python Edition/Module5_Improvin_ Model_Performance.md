### 28/2/2020

## 5.1 Principles of Model Improvement 

#### 5.1.1 Improving ModelsKhám phá

- Một số cách để ta cải thiện mô hình của mình
 * Feature Selection
 * Regularization
 * Intergreting Features
 * Sweeping Model Parameters
 * Cross-Validation

1. Feature Selection

- Theo lí thuyết thông kê thì ta cần phải cân bằng giữa accuracy và tính simple của model
- Khi ta traing một mô hình, không nhất thiết tất cả các feature vector là cần thiết, nhiều quá thì sẽ là một model phức tạp(not simple) và ít qúa thì k đủ thông tin để xây dựng một mô hình tốt =>>> Việc giảm số lượng vector(đến một số lượng thích hợp) cũng làm cho model của chúng ta simple hơn (và kết quả có thể sẽ tốt hơn với nhiều lí do)
- Thế nào là một mô hình simple ?
  * Mô hình đơn giản hơn là mô hình dự đoán tốt hơn
  * mô hình đơn giản hơn là mô hình dê hiểu với con người hơn
  * Mô hình đơn giản hơn là mô hình dễ dàng đưa ra predict hơn (đơn giản trong việc tính toán)

  + Nhưng việc lựa chọn được những thành phần quan trọng trong các feature là một việc làm khó khăn

- Sẽ có 2 menthod được giới thiệu đó là Greedy Backward Selection và Greedy Forward Selection
- Cùng gọi là Greedy vì các bước thực hình r sẽ k được thực hiện lại (không nhìn lại - don'n look back)

 * Greedy Backward Selection
- Các bước thực hiện: 
 1. Bắt đầu với toàn bộ feature
 2. Tìm feature(mà khi xóa nó đi) gây ảnh hưởng ít nhất đến khả năng predict của model và ta sẽ xóa nó
 3. Quay lại bước 2 cho đến khi một số tiêu chí được đáp ứng 

 * Greedy Forward Selection
- Thuật toán này là ngược lại với GBS
 1. Bắt đầu với không có feature nào
 2. Tìm một feature mà với chỉ mình nó ta đưa ra được model tốt nhất và add feature
 3. Tìm thêm tiếp feature thứ 2 với xem xét sao cho model với 2 feature là tốt nhất và add nó
 4. Tìm tiếp các feature với tiêu chí tương tự 
 5. Tìm cho đến khi số feature đạt một số tiêu chí đáp ứng thì dừng lại

- Có 2 vấn đề quan tâm ở thuật toán GFS
 * Cách chọn feature để add thêm: NGười ta chọn feature làm tăng độ chính xác cho mô hình là lớn nhất 
 * Tiêu chí dừng việc add feature: Dùng Adjusted R^2
    
<img src ="https://i.imgur.com/0yJx24f.png" />

 + R^2: Đo mức độ fit của model và data  
Dựa theo công thức thì R^2 (lớn) sẽ gần đến 1 với model mà model với data là rất gần nhau (sai số nhỏ)
 + Adjusted R^2: Đo mức độ fit của model với data và mức độ phức tạp của model  
  + Ta có thẻ thế R^2 chỉ đo được mức độ fit của model mà k đo được mức đô simple của model, trong trường hợp số feature là lớn(quá mức) dẫn dến p lớn, suy ra Adjusted R^2 nhỏ (dù R^2 vẫn tốt, trong trường hợp  số feature nhỏ(quá ít) giá trị Adjusted cũng rất tệ
  + Giá trị của Adjusted sẽ gần 1(tốt) nhất cả cả sai số (accuracy)là nhỏ và mức độ simple của mô hình (số lượng feature) là phù hợp
  + Dựa vào việc thay đổi số lượng feature (tăng dần từ 0) ta sẽ có những giá trị Adjusted R^2 nhất đinh từ đó ta có biểu đồ như sau 

<img src ="https://i.imgur.com/kJezLKY.png" />

Nhìn qua biểu đồ ta thấy Số lượng feature là 4,5,6 có thể được sử dùng làm tiêu chí để dừng việc add feature ở thuật toán GFS 


2. Regularization

- Một số khái niệm cần biết:
 * __The variance__ : is how much the predictions for a given point vary between different realizations of the model.
 * __Bias__ : measures how far off in general these models' predictions are from the correct value.
 
<img src = "https://i.imgur.com/XIhRFXs.png" />

- Khi ta tìm một mô hình thông qua việc train và test, khi mô hình của chúng ta có thể rơi vào những trường hợp không tốt như:

 * Underfit ( __high bias__ ) tức là mô hình quá đơn giản để thực hiện dự đoán.
 * Overfit ( __high variance__) tức là mô hình quá phức tạp dẫn đến hiện tượng mô hình bám lấy từng dữ liệu và ghi nhớ chúng (biễu diễn cả những điểm là nhiễu)
- Trong đó ta quan tâm đến l2 và l1
 + L2:
  * Sử dụng Reg = tổng bình phương các tham số
  * Khi sử dụng l2, các tham số sẽ được tối ưu hóa theo hướng làm gía trị của tất cả các tham số cùng nhỏ đi, cằng tăng hệ số của hàm Reg các bộ tham số sẽ đi từ các giá trị overfit ->>. tốt ->>> underfit
 + L1:
 * Sử dự Reg = tổng trị tuyệt đối các tham số
 * Khi dùng l1, các tham số tôi ưu sẽ về dạng sparse, tức là một nhóm các tham số sẽ cực tiểu hóa về 0, đôi khi nó sẽ là feature selection cho bạn, bạn chỉ cần quan tâm đến các feature khác 0

3. Interpreting Features 
- Việc giải thích quan hệ giữa các feature bằng việc sử dụng các tham sô mô hình là một việc nguy hiểm
 + Ví dụ khi ta có trong tập dữ liệu các collinear features (là những feature có độ tương quan hay tương tự cao) có cả những điều tốt và xấu từ những feature như này: 
  * Tốt: Ta có thể tạo ra thêm những feature như vậy vì ta không biết được rằng thêm những feature như vậy trong từng trường hợp lại có thể mang thêm kết quả tốt cho công việc cụ thể nào đó
  * Xấu: Khi hoàn thành việc tìm các tham số của mô hình, các hệ số của nhưng feature giống nhau có thể triệt tiêu lẫn nhau (ví dụ 100 và -100) như vậy nó không mang lại kết quả cho Interpreting Features.
 + Ví dụ khi ta chuẩn hóa 2 feature ->> các feature có những khoảng giá trị khác nhau, sử dụng Reg sẽ mạng lại hệ số khác nhau dấn đến đánh giá sai
 
4. Features Selection

- Có 2 phương pháp (hay 2 hướng quan tâm khi lựa chọn các feature)
 * Loại bỏ những feature có low variance and zero variance. Thường những feature này không mang lại  thông tin hữu ích 
 * Loại bỏ những feature mang ít thông tin (không mang thông tin hữu ích để cải thiện mô hình) Trong Video sử dụng cross validation cho việc loại bỏ những feature mang tin thông tin 


#### 5.2 Techniques for Improving Models 

1. Sweeping Parameters

- Có những cách để ta chọn hệ số ở hàm Reg 
 * Sử dụng nested cross validation để xác định hệ số
 * Hoặc sử dụng Azure ML:
  + "Sweep entire grid": Nó thực hiện vòng lặp và thử tất cả những giá trị tham số và chọn ra giá trị tốt nhất
  + "Random sweep": Nó chọn radom bất kì một giá trị tham số, may mắn thông thường hiệu suất của mô hình không quá phụ thuộc vào hệ số đó nên mọi việc vẫn ổn với việc ta chọn random

2. Model Selection and Cross Validation

- Quá trình model selection thường được áp dụng theo những trường hợp: 
  * Lựa chọn hyperparameters tối ưu
  * Feature selection
  * So sánh các model 
->>> Model selection là một phần của quá trình traing model.
- __k-fold cross validation__ : T
   * Thường được sử dụng để đánh giá mô hình, nhưng nó không được dùng để lựa chọn các hyperparameters vì nó sẽ gây ra hiện tượng overfit vì data để model selection và data để evalution là giống nhau.
   * Sau mỗi K lần train test với k-fold các giá trị model parameter sẽ được chia lấy giá trị trung bình
   * Vì kết quả của model parameter được lấy trung bình qua k lần vì vậy nếu k là số nhỏ sẽ gây ảnh hưởng đến giá trị cuối cùng, nhưng với bố dự liệu lớn và mô hình phức tạp cũng cần phải giới hạn về số k để đảm bảo thời gian train test hết k lần đảm bảo yêu cầu  về thời gian.
   * Vì vậy trong thực tế ta đôi khi phải đánh đổi độ chính xác của kết quả thông qua cross validation tùy vào điều kiện của tài nguyên. 



- Ta sử dụng Nested Cross Validation để thực hiện model selection, với việc dùng outer loop để  evalutaion và inner loop(giống Cross validation) để  thưc hiện việc model selection   