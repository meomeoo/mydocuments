- __Snorkel__ là một hệ thống để lập trình cho việc xây dựng và quản lí trainning data. Hiện tại Snorkel cung cấp 3 hoạt động chính là:
  * Labeling data: Gán nhãn cho bộ dữ liệu mà không cần cung cấp hay thực hiện label cho data.
  * Transforming data
  * Slicing data
 - Hiện tại em tập chung tìm hiểu vào hoạt động Labeling data

- Kiến trục của hoạt động Labeling data gồm 3 gia đoạn. (Những việc label chỉ tập chung ở 2 giai đoạn đầu)
 1. Writing labeling functions
 2. Modeling Accuracies and Correlations
 3. Training a discriminative model 

### 1. __Writing labeling fuctions__:
 - Việc viết các LFs( Labeling fuctions) chính là việc ta encode các weak supervision sources: patterns, heuristics, external knowledge bases, crowdsourced labels, etc. , từ đó có sử dụng nhiều giả thiết để gán label cho mỗi điểm dữ liệu (mỗi điểm sẽ có thể có số nhãn bằng với số LF)
 - Hay nói cách khoác các LFs là các hướng tiếp cận(khác nhau) của  weak supervision để label dữ liệu, ví dụ như có thể là các rule, heuristics do SM (hệ chuyên gia hay con người) viết dựa trên data cụ thể, hay các mô hình phân loại đã được train sẵn (được sửa đổi để phù hợp với bài toán cụ thể), 
 - Các LFs sẽ label data theo hướng là tạo ra các nhãn chất lượng chứ không phải là phải label hết tất cả các điểm dữ liệu (với mỗi LF) nên sẽ có những điểm dữ liệu mà được LF này gán label nhưng lại không được LF khác gán nhãn, mỗi LF sẽ gán nhãn được một phần nào đấy của data set, từ đó dẫn đến có những trường hợp những điểm dữ liệu được các các LF gán cùng nhãn (OVERLAPS) hoặc khác nhãn (Conflicts)
 - Kết quả của các LFS sẽ là một ma trận label cho tập dữ liệu (mỗi điểm được gán nhãn nhiều lần vì mỗi LF gán 1 nhãn)

 <img src = "https://i.imgur.com/IAAozOs.png"/>

### 2. __Modeling Accuracies and Correlations__
 - Việc thực hiện trong bước này thực chất rất đơn giản (phần phức tạp là Generative model đã được thực hiện bởi đội phát triển của Snorkel)
 - Công việc này chính là kết hợp tất cả các LFs và tạo ra một mô hình thống nhất để đưa ra một  probabilistic labels trong đừng điểm dữ liệu (một giá trị label cho mỗi điểm dữ liệu)
 - Việc kết hợp này có thể thực hiện đơn giản trong Sorkel bằng 2 cách: majority vote hoặc Generative model (sinh ra một mô hình từ việc đánh giá độ chính xác(accuracies of the labeling functions without any labeled data),độ tương đồng giữa các giá trị label,.. ) thông qua 2 đối tượng `LabelModel` và `MajorityLabelVoter` trong thư viện của snorkel.

### 3. __Training a discriminative model__ 
 - Là bước sử dụng các end model (ML hay Deep learning) phù hợp để train data set đã có nhãn (ta vừa thực hiện gán nhãn)
 - Một số trường hợp việc làm ở bước 2 không mang đến độ chính xác cần thiết thì ta có thể kết hợp end model ở bước 3 với bước 2 để tiếp tục cả thiện mô hình.

#### ?? Một số câu hỏi
- Em thấy hình như bài toán của mình đang làm là bài toán con của xử lí ngôn ngữ tự nhiên? A có thể gửi cho em một số tài liệu để em có mộ ít kiến thức nền xung quanh việc bài toán cụ thể mà mình đang giải quyết hay những kiểu bài toán chung chung liên quan đến bài toán mà mình đang xử lí cần phải biết được không ạ? (Ví dụ như: NER, autoface, tạo bộ từ điển, datagram,.. hay những cái nào khác cần biết nữa không ạ ) để đến lúc a phân tích thì e có thể hiểu rõ hơn những cái được phân tích ạ.
- Về việc viết các LFs thì em thấy tùy vào bài toán mà mình sẽ có những hướng hay cách tiếp cận viết LFs khác nhau thì a có thể gửi cho em tài liệu về những cái như v trong bài toán của mình không ạ ?
- Trong phần snorkel em thấy có khá nhiều cái tutorial ví dụ như: Multi-Task Learning (MTL) Basics Tutorial, Snorkel can be used for Information Extraction,.. thì có những phần nào mà cần phải đọc vì nó liên quan đến cái bài toán của mình không ạ ??
- Trong bài tóm tắt của em có phần nào cần đọc sâu hoặc hiểu sai a note giúp em được không ạ ?


