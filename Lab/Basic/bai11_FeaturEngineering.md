### Ngày 19/1/2020 

<img src = "https://i.imgur.com/gnFHZXt.png"/>
Là bước xử lí draw data đầu vào để trở thành bộ data đã phù hợp để đưa vào model để training.

- Một số cách feature engineering

 1. Trực tiếp lấy raw data : kéo dài từ matran thành vertor, đặt các hàng, cột chồng lên(cạnh nhau) đẻ tạo thành một vector dài 
 2. Feature selection: Chỉ chọn các feature cần thiết, phù hợp và cần thiết cho mô hình để đưa vào model 
 3. Dimensionality reduction: Giảm số chiều của data set bằng cách chọn một ma trận chiếu (projection matrix) ngẫu        nhiên (ma trận béo) rồi nhân nó với từng điểm dữ liệu (giả sử dữ liệu ở dạng vector cột) để được các              vector có số chiều thấp hơn.
        Ví dụ, vector ban đầu có số chiều là 784, chọn ma trận chiếu có kích thước (100x784), khi đó nếu nhân ma trận chéo này với vector ban đầu, ta sẽ được một vector mới có số chiều là 100, nhỏ hơn số chiều ban đầu rất nhiều. Lúc này, có thể ta không có tên gọi cho mỗi feature nữa vì các feature ở vector ban đầu đã được trộn lẫn với nhau theo một tỉ lệ nào đó rồi lưu và vector mới này. Mỗi thành phần của vector mới này được coi là một feature (không tên).
 4. Bag-of-words

<img src = "https://i.imgur.com/kfLOf7O.png"/>

 5. Feature Scaling and Normalization

<img src = "https://i.imgur.com/qyhsXP1.png"/>


