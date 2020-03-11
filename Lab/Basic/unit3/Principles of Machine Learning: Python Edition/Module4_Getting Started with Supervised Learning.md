### 13/1/2030

## 4.1 Regression 

- Để sử dụng scikit-learn ta cần than số đầu vào là mảng numpy các biến là numeric. Mảng tham số đầu vào là model matrix. để tạo được model matrix trước tiên ta cần biến đổi tập dữ liệu:
  * Numeric featrues cần được thu nhỏ kích thước
  * Categorical feature cần được chuyển đổi sang dummy variables

## 4.2 Classification
- Một số lưu ý rút ra từ phần 4.1

1. Statistical Learning Theory for Supervised Learning
 + Không phải lúc nào tìm được một mô hình có giá trị loss càng nhỏ cũng càng tốt
 + Một mô hình tốt là một mô hình đảm bảo vừa có loss nhỏ và vừa là một mô hình đơn giản
<img src="https://i.imgur.com/01x2ZiG.png" />

 + Đôi khi mô hình quá đơn giản (underfiting - giá trị loss cao khi traing và giá trị loss tại test cũng cao), hay mô hình quá phực tạp (overfitting - giá trị loss rất nhỏ khi traing nhưng giá trị loss khi test lại cao), ta vần chọn mô hình với mức độ đơn giản hợp lí và có giá trị loss khi train và test đều thấp - cân bằng giữa accuracy và simplicity.

 + Ta có thể cải thiệt điều này bằng cách thay đổi một chút ở hàm loss

 <img src = " https://i.imgur.com/yvpWMXN.png[/img]"/>

 + Ta thêm phần Regularization(f) và để có thể cải thiện ở khả năng tránh overfiting.
 + Thay đổi hàng số c để thay đổi mức độ ảnh hưởng(mức độ quan tâm đến simple so với accuracy) của việc giữ cho hàm số là simple trong khi ta tối ưu hàm loss - c càng lớn thì việc quan tâm đến sự simple của mô hình càng được quan tâm.


3. Imbalanced Data

- Là hiện tượng số lượng observetion ở các class trong sample không đều nhau (chêch lệch lớn) vd: có 10 point ở class (+) và chỉ 90 point ở class (-),  =>>>  điều này dẫn đến đôi khi ta tìm được một mô hình mà mô hình đó đưa ra các giá trị pridiect đạt accuracy >= 90% nhưng trưa chắc mô hình đã là tốt (ví dụ mô hình pridiect 100% các point đều thuộc negative thì như vậy tất cả các point ở class positive đều bị dự đoán sai =>> như vậy mô hình hoàn toàn không tốt  mặc dù acciracy vẫn đạt giá trị rất tốt ) 

- Khi đó ta có thể cải thiệt loss của chúng ta bằng cách chia loss ra cho từng loại điểm thuộc từng class bị phân loại sai.

<img src = "https://i.imgur.com/kzblQ4F.png"/>

 + Lúc này với mỗi điểm thuộc từng class mà bị pridiect sai class ta sẽ sử phạt theo mức độ khác nhau để khác phụ imbalenced. Mức sử phạt này sẽ tùy thuộc vào tỉ lệ số điểm ở các class (ví dụ ở những class có số điểm ít hơn thì việc sử phạt những điểm ở class đó bị pridiect sẽ nặng hơn số với những điểm ở class có số điểm nhiều hơn )

 + Ví dụ trong trường hợp trên với mỗi điểm ở class positive mà bị pridiect sai class sẽ bị sử phạt gấp C lần so với 1 điểm ở class negative mà bị pridiect sai class.

 + Việc sử dụng C ở đây chỉ đạt được kết quả tốt ở một số thuật toán:logistic regression,support factor machines,...
 + Hoạt động không tốt ở một số thuật toán khác, ví dụ: Decision trees

4. ROC Curves

Có 2 cách áp dùng ROC để đánh giá
- Ta thay đổi giá trị ngưỡng (threshold) để được các giá trị Recall (TPR) và FPR khác nhau để vẽ ROC =>>> lúc này ROC dùng để đánh giá model classfier
- Ta thay đổi giá chị C (dùng trong loss khi bài toàn là imbalance) và với mỗi giá trị C ta cũng được TPR và FPR tương ứng để vẽ ROC =>>> lúc này ROC sẽ là để đánh giá toàn bộ thuật toán mà ta đang sử dụng.

 + Thường thì ROC cho toàn bộ thuật toán đượcc đánh giá cao hơn, vì ROC cho toàn bộ thuật toán là ta đi tối ưu tại mỗi một điểm trên đường curves (mỗi một điểm c là một hàm loss) trong khi đi ROC cho bài toán phân loại chỉ tối ưu 1 điểm trên cả đường curves (chỉ có một hàm loss duy nhất)
