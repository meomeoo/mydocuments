### 5/1/2020

## 2.1 Exploratory Data Analysis for Regression

#### Video1 - Data Exploration

- Hiểu và trực quan hóa dữ liệu là vô cùng quan trọng trước khi bước bức vào xây dựng mô hình cũng như train trong ML
- Cần hiểu mỗi quan hễ giữa các featrue và các lable và phải hiểu nội dung của dữ liệu để giải quyết vấn đề 
- Càng bỏ thời gian để phân tích và hiểu dữ liệu thì sẽ cảng giảm tỉ lệ tốn thời gian cho xây dựng sai mô hình và thu được kết quả không tin cậy 
- Cần phỉa biết thành phần nào của dữ liệu là quan trọng, thành phần nào là dư thừa, là nhiễu

- Những điều bạn cần xem xét:
 * Đặc điểm của dữ liệu: kích thước, kiểu dữ liệu, số lượng featrue,lable là số hay là chữ,..
 * Một số giá trị thống kê của dataset: mean, medium,.
 * Tìm liểu error và outline: đôi khi outline là một gía trị thú vị 
 * Sự phân phối (sự phân vùng) của các featrue và lable
 * Tìm tần suất xuất hiện hành cho categorical variables

- Việc lặp lại các bước:
 * Môi khi tìm thấy lỗi và sữa lỗi hay quay lại để visualize để xem có lỗi khác phát sinh không
 * Trước và sau khi mỗi bước preparation data
 * Trước và sau khi chỉnh model ML: Xem lỗi là do sự thay đổi ngẫu nhiên của dữ liệu hay do các bước bạn preparation data
 * Để đánh giá model ML
- Thực hiển nhiều ý tưởng: Và xem xét cái nào thực hiện được cái nào không

- Sử dụng một số thứ đẻ xử lí việc biễu diễn các trưỡng dữ liệu lớn hơn 2;
  * Vị trí: dành cho categorical and numeric values
  * Độ dài: numeric or categorical values (sử dụng nếu categorical có thể xếp theo một thứ tự)
  * Hình dạng: thường cho categorical variables.
  * Size: numeric variables
  * Màu (nên sử dụng như giải pháp cuối cùng): categorical variables nhưng có thể cho cả numeric    
- Hoặc sử dụng nhiều trục:
  * multiple axis plot
  * một thứ được sử dụng với nhiều tên: conditioned plots, faceted plots, small multiple plots     



### 6/1/2020 

#### Visualizing Data Relationships video4
- Relationship between numeric variables
- Xem xét quan giữa các featrue và label
- Sử dụng biểu đồ plot_scatter
- Nhưng đôi khi ở những khoảng trên biểu đồ có những đoạn không rõ ràng, các điểm hiển thị bị chồng lên nhau - overplotting
- Để giải quyết overplot ta có thể dử dụng
 * Ở mức độ tập dữ liệu nhỏ và vừa:
  + Sử dụng transparency để giải quyết vấn đề này với tham số alpha là nghịch đảo của transparency, alpha =1 là hoàn toàn mờ, alpha = 0 là hoàn toàn tốt vì vậy chúng ta sử dụng giá trị alpha khá thấp  
 * Ở mức độ dữ liệu lớn hơn:
  +  kernel density estimate
  +  contour plots and the hex bin plots which are the 2D equivalent of a histogram.

#### Visualizing Categorical Relationships video5

- Relationship between categorical variables and numeric variables using box plots or violin plots

#### Using Aesthetics to Visualize High Dimensions video6 
- Giới thiệu công cụ 

## 2.2 Exploratory Data Analysis for Classification

#### Visualizing for Classification video1

- Giới thiệu các hàm để biểu diễn các featrue và các label thuộc categorical variables  
- Người ta quan đêm đến label có dạng categorical variables và mối quan hệ giữa các label với 2 loại numeric variables và categorical variables. Để xác định xem featrue nào trong 2 lại varicables là hữu ích cho model. 
- Visualize class separation by numeric features đượng sử dụng thông qua plot_box, sữ khác biệt giữa phạm vi của từng feature trong các categorical của label được xem là hữu ích cho model 
- Visualize class separation by categorical features được thực hiện bằng bar chart và xem xét tần số xuất hiện các categorical của từng featrue sẽ như nào tronng từng categorical của label, xự khác biệt càng lớn về tần suất giữa giữa các categorical của featrue trên từng categorical của label thì càng hữu ích cho mô hình.

#### Frequency Tables

- Giới thiệu hàm để biểu diễn tần suất của xuất hiện của các biến trong categorical variables

## Lab for this module

### note:
- Nếu median < mean thì distribution có dạng right-skewed 
- Display a frequency table using the `value_counts` method of  Pandas
ex:
```
def count_unique(auto_prices, cols):
    for col in cols:
        print('\n' + 'For column ' + col)
        print(auto_prices[col].value_counts())

cat_cols = ['make', 'fuel_type', 'aspiration', 'num_of_doors', 'body_style', 
            'drive_wheels', 'engine_location', 'engine_type', 'num_of_cylinders', 
            'fuel_system']
count_unique(auto_prices, cat_cols)
```
  * một số điều có thể rút ra từ frequncy table:
    + Featrue nào có nhiều cateorical
    + Sự mất cân bằng giữa những tần suất xuất hiện của các categorical trong các feature
    + Một số categorical có thể chuyển đồi sang dạng numeric 

- matplotlib là một thư viện để cung cấp công cụ để visual data
- Pandas và Seaborn là 2 thư viện để cúng cấp thêm chi tiết cho việc visual data, nó hoạt động dựa trên matplotib nên ta có thể thêm vào các chi tiết để mọi lúc.

- distributions that are right-skewed là tốt cho model ML 
 ### ??? tải sao 2 featrue cùng có quan hệ tuyến tính với lable và chúng có quan hệ tuyến tính với nhau thì 2 featrue đó phụ thuộc tuyến tính

 ## 9/1/2020

### ??? Xem featrue nào là quan trọng trong việc đưa vòa model để predic label 