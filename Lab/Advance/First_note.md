- __Information extration__: Là nhiệm vụ tự động khai thác được thông tin có câu trúc từ nguồn thông tin không/bán cấu trúc (thường là văn bản -text), nó là một hoạt động liên quan đến quá trình xử lí ngôn ngữ tự nhiên (NPL)
- __NER__ (Named-entity recognition): Nhận diện thực thể là một subtask của Information extration, cụ thể là tìm kiếm vị trí và gắn nhãn cho thực thể trong unstructured text 
Ví dụ:
<img src ="https://i.imgur.com/8taUisM.png" />

- __ML | Semi-Supervised Learning__ :Là phương pháp học khắc phục nhược điểm của supervised-learning và unsupervised-learning (cũng có thể nói là sự kết hợp của 2 cái) với đặc điểm data set có 1 phần được gắn nhãn và một phần không được gán nhãn (thông thường phần không gán những thường chiếm tỉ lệ ít hơn).
    + Thủ tục thường được thực hiện đầu tiên là: Phân cụm similar data thành các cụm sử dụng unsupervised-learning (Ví dụ K-mean Cluster,..), sau đó dựa trên những dữ liệu đã gán nhãn để gán nhãn thành phần còn lại của dữ liệu. __Note:__ Cố một đặc điểm chung với kiểu làm như này là: Việc thu thập dữ liệu unlabeled thường có chi phi rẻ còn việc gán nhãn dữ liệu thì có chi phí cao.
    + Những giả định của semi-supervised learning: 
      * Continuity Assumption: Những point data gần nhau thì có chung lable 
      * Cluster Assumtion: Data set có thể chia các data point thành các cluster thì các point ở cùng một cluster thì sẽ có chung lable
      * Manifold Assumption: Data sẽ nằm xấp xỉ trên môn không gian có số chiều nhỏ hơn (manifold) so với số chiều của dữ liệu ở input
      __Một cách giải thích khác:__ 


      ```
      Imagine that you have a bunch of seeds fastened on a glass plate, which is resting horizontally on a table. Because of the way we typically think about space, it would be safe to say that these seeds live in a two-dimensional space, more or less, because each seed can be identified by the two numbers that give that seed's coordinates on the surface of the glass.

      Now imagine that you take the plate and tilt it diagonally upwards, so that the surface of the glass is no longer horizontal with respect to the ground. Now, if you wanted to locate one of the seeds, you have a couple of options. If you decide to ignore the glass, then each seed would appear to be floating in the three-dimensional space above the table, and so you'd need to describe each seed's location using three numbers, one for each spatial direction. But just by tilting the glass, you haven't changed the fact that the seeds still live on a two-dimensional surface. So you could describe how the surface of the glass lies in three-dimensional space, and then you could describe the locations of the seeds on the glass using your original two dimensions.

      In this thought experiment, the glass surface is akin to a low-dimensional manifold that exists in a higher-dimensional space : no matter how you rotate the plate in three dimensions, the seeds still live along the surface of a two-dimensional plane.

      Examples
      More generally, a low-dimensional manifold embedded in a higher-dimensional space is just a set of points that, for whatever reason, are considered to be connected or part of the same set. Notably, the manifold might be contorted somehow in the higher-dimensional space (e.g., perhaps the surface of the glass is warped into a bowl shape instead of a plate shape), but the manifold is still basically low-dimensional. Especially in high-dimensional space, this manifold could take many different forms and shapes, but because we live in a three-dimensional world, it's difficult to imagine examples that have more than three dimensions. Just as a sample, though, consider these examples :

      a piece of glass (planar, two-dimensional) in physical space (three-dimensional)
      a single thread (one-dimensional) in a piece of fabric (two-dimensional)
      a piece of fabric (two-dimensional) crumpled up in the washing machine (three-dimensional)
      Common examples of manifolds in machine learning (or at least sets that are hypothesized to live along low-dimensional manifolds) include :

      images of natural scenes (typically you do not see images of white noise, for instance, meaning that "natural" images do not occupy the entire space of possible pixel configurations)
      natural sounds (similar argument)
      human movements (the human body has hundreds of degrees of freedom, but movements appear to live in a space that can be represented effectively using ~10 dimensions)
      Learning the manifold
      The manifold assumption in machine learning is that, instead of assuming that data in the world could come from every part of the possible space (e.g., the space of all possible 1-megapixel images, including white noise), it makes more sense to assume that training data come from relatively low-dimensional manifolds (like the glass plate with the seeds). Then learning the structure of the manifold becomes an important task; additionally, this learning task seems to be possible without the use of labeled training data.

      There are many, many different ways of learning the structure of a low-dimensional manifold. One of the most widely used approaches is PCA, which assumes that the manifold consists of a single ellipsoidal "blob" like a pancake or cigar shape, embedded in a higher-dimensional space. More complicated techniques like isomap, ICA, or sparse coding relax some of these assumptions in various ways.

      Semi-supervised learning
      The reason the manifold assumption is important in semi-supervised learning is two-fold. For many realistic tasks (e.g., determining whether the pixels in an image show a 4 or a 5), there is much more data available in the world without labels (e.g., images that might have digits in them) than with labels (e.g., images that are explicitly labeled "4" or "5"). In addition, there are many orders of magnitude more information available in the pixels of the images than there are in the labels of the images that have labels. But, like I described above, natural images aren't actually sampled from the uniform distribution over pixel configurations, so it seems likely that there is some manifold that captures the structure of natural images. But if we assume further that the images containing 4s all lie on their own manifold, while the images containing 5s likewise lie on a different but nearby manifold, then we can try to develop representations for each of these manifolds using just the pixel data, hoping that the different manifolds will be represented using different learned features of the data. Then, later, when we have a few bits of label data available, we can use those bits to simply apply labels to the already-identified manifolds.

      Most of this explanation comes from work in the deep and feature learning literature. Yoshua Bengio and Yann LeCun -- see the Energy Based Learning Tutorial have particularly accessible arguments in this area.
      ```
- __Bootstrapping__: is a statistical procedure that resamples a single dataset to create many simulated samples. This process allows you to calculate standard errors, construct confidence intervals, and perform hypothesis testing for numerous types of sample statistics. Bootstrap methods are alternative approaches to traditional hypothesis testing and are notable for being easier to understand and valid for more conditions.
[Reference](https://statisticsbyjim.com/hypothesis-testing/bootstrapping/)
- __Ensemble Methods in Machine Learning__ :Ensemble methods is a machine learning technique that combines several base models in order to produce one optimal predictive model  
 Example with decision tree:
 * Types of Ensemble Methods:
  1. BAGGing, or Bootstrap AGGregating: BAGGing gets its name because it combines Bootstrapping and Aggregation to form one ensemble model. Sử dụng Bootstrapping để tạo nhiều sample con từ dataset ban đầu. ví dụ với cây quyết định thì sử dụng *cùng cách lựa chọn các feature* để tạo tree trên các sample sau đó tổng hợp chọn cây tốt nhất.
  2.Random Forest Models: Việc tạo các cây gần giống với BAGG những khác ở một số điểm, *BAGGed Decision Trees have the full disposal of features to choose from. Therefore, although the bootstrapped samples may be slightly different, the data is largely going to break off at the same features throughout each model. In contrary, Random Forest models decide where to split based on a random selection of features. Rather than splitting at similar features at each node throughout, Random Forest models implement a level of differentiation because each tree will split based on different features. This level of differentiation provides a greater ensemble to aggregate over, ergo producing a more accurate predictor.*

  [Reference](https://towardsdatascience.com/ensemble-methods-in-machine-learning-what-are-they-and-why-use-them-68ec3f9fef5f)

- __Text classification__: is the automated grouping of textual or partially textual entities. Document retrieval, categorization, routing, filtering, and clustering, as well as natural language processing tasks such as tagging, word sense disambiguation, *and some aspects of understanding can be formulated as text classification*.

- __Active Learning__: The promise of AL is that by iteratively increasing the size of our carefully selected labeled data, it is possible to achieve similar (or greater [2]) performance to using a fully supervised data-set with a fraction of the cost or time that it takes to label all the data.
[Reference](https://towardsdatascience.com/active-learning-tutorial-57c3398e34d)