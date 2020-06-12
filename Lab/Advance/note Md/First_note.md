- __Information extration__:  
  - __Definition:__
    - Is the task of automatically extracting structured information from unstructured and/or semi-structured machine-readable documents. In most of the cases this activity concerns processing human language texts by means of natural language processing (NLP). Recent activities in multimedia document processing like automatic annotation and content extraction out of images/audio/video/documents could be seen as information extraction
    - IE deals with tasks in between both IR and NLP. In terms of input, IE assumes the existence of a set of documents in which each document follows a template, i.e. describes one or more entities or events in a manner that is similar to those in other documents but differing in the details.
  - __Present significance:__
    The present significance of IE pertains to the growing amount of information available in unstructured form. Tim Berners-Lee, inventor of the world wide web, refers to the existing Internet as the web of documents [5] and advocates that more of the content be made available as a web of data.[6] Until this transpires, the web largely consists of unstructured documents lacking semantic metadata. Knowledge contained within these documents can be made more accessible for machine processing by means of transformation into relational form, or by marking-up with XML tags. An intelligent agent monitoring a news data feed requires IE to transform unstructured data into something that can be reasoned with. A typical application of IE is to scan a set of documents written in a natural language and populate a database with the information extracted
[Reference](https://en.wikipedia.org/wiki/Information_extraction)


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

- __Active Learning and Passive learning__
  - __Active Learning__: 
   * The promise of AL is that by iteratively increasing the size of our carefully selected labeled data, it is possible to achieve similar (or greater [2]) performance to using a fully supervised data-set with a fraction of the cost or time that it takes to label all the data., The main hypothesis in *active learning is that if a learning algorithm can choose the data it wants to learn from*, it can perform better than traditional methods with substantially less data for training. 
  * In active learning terminology, we call this small labelled dataset the seed.
  * Có thể nói không chỉ là thu thập dữ liệu mà ta có thể lựa chọn dữ liệu phù hợp một số tiêu chí để đưa vào huấn luyện.

  - But what are these traditional methods exactly?
  - __Passive Learning__: These are tasks which involve *gathering a large amount of data randomly sampled from the underlying distribution* and using this large dataset to train a model that can perform some sort of prediction, "where the learner receives no feedback from the instructor"

[Reference](https://towardsdatascience.com/active-learning-tutorial-57c3398e34d)
[Reference](https://en.wikipedia.org/wiki/Passive_learning)
[Reference](https://www.datacamp.com/community/tutorials/active-learning)
[Cần đọc về Uncertainty Sampling](http://burrsettles.com/pub/settles.activelearning.pdf)

- __Statistical classification__: Là bài toán classification được giải quyết thông qua cách tiếp cận các phương pháp thống kê. Có 2 loại của phương pháp này
  - __Discriminative model__:
    * also referred to as conditional models, *are a class of models used in statistical classification*, especially in supervised machine learning. A discriminative classifier tries to model by just depending on the observed data while learning how to do the classification from the given statistics. (Là mô hình đưa ra output dạng xác suất)
    * A discriminative model is a model of the conditional probability of the target Y, given an observation x, symbolically, {\displaystyle P(Y|X=x)}{\displaystyle P(Y|X=x)}; and Classifiers computed without using a probability model are also referred to loosely as "discriminative". 
    * Mô hình được đưa về việc đánh giá xác suất có điều kiện của X thông qua công thức  BayEt   
  - __Generative model__:
    * Given an observable variable X and a target variable Y, a generative model is a statistical model of the joint probability distribution on X × Y, {\displaystyle P(X,Y)}{\displaystyle P(X,Y)}
    * a generative model is a model of the conditional probability of the observable X, given a target y, symbolically, {\displaystyle P(X|Y=y)}{\displaystyle P(X|Y=y)}

- __Empirical Risk Minimization(ERM)__: 
 - Now how can we measure the effectiveness of this chosen function given that we don’t know what the actual distribution looks like? Bear in mind that all the potential functions can achieve the given goal. How do we find the function that’s the best representative of the true solution?
 -True risk computes the average loss over all the possibilities. But the problem in the real world is that we don’t know what “all the possibilities” would look like. In mathematical terms, we say that we don’t know the true distribution over all the inputs and outputs. If we did, then we wouldn’t need machine learning in the first place.

 - We assume that our samples come from this distribution and use our dataset as an approximation. If you compute the loss using the data points in our dataset, it’s called *empirical risk*. It’s “empirical” and not “true” because we are using a dataset that’s a subset of the whole population.

 - When we build our learning model, we need to pick the function that minimizes the empirical risk i.e. the delta between the predicted output and the actual output for the data points in our dataset. This process of finding this function is called *empirical risk minimization*. Ideally, we would like to minimize the true risk. But we don’t have the information that allows us to achieve that, so our hope is that this empiricial risk will almost be the same as the true empirical risk. Hence by minimizing it, we aim to minimize the true risk.

__NLP (Natural Language Processing)__: 
 - Natural Language Processing (NLP) is a branch of AI that helps computers to understand, interpret and manipulate human language.

 - NLP helps developers to organize and structure knowledge to perform tasks like translation, summarization, named entity recognition, relationship extraction, speech recognition, topic segmentation, etc.

 - NLP is a way of computers to analyze, understand and derive meaning from a human languages such as English, Spanish, Hindi, etc.
 - Components of NLP: Five main Component of Natural Language processing are:

   * Morphological and Lexical Analysis
   * Syntactic Analysis (ngữ pháp )
   * Semantic Analysis (Ngĩa đen)
   * Discourse Integration (Nghĩa theo contex - ví dụ dựa trên câu trước )
   * Pragmatic Analysis 
 [Reference](https://www.guru99.com/nlp-tutorial.html)

- __Babble Labble:__
  - *We propose Babble Labble, a framework for generating labels for large training sets from natural language explanations* 
  - Babble labble là một phần trong nhiệm vụ programing data
  - Babble Labble là một framework (thành phần chính dựa trên **semantic parser* - phân tích nghĩa đen của câu) *chuyển từ các explanations (natural language) thành các  formal programs (Labeling functions )* tự động (thông qua semantic parser)
  - Một explanation có thể sinh ra nhiều formal programs (trong đó có thể có các formal program không diễn tả đúng nghĩa đen của explanation) và không phải tất cả các formal program sinh ra được dùng hết mà nó sẽ được thông qua một bộ lọc để loại đi những formal program không có ích.
  - Kết quả của Babble Labble (nói trong context của Snorkel) là công cụ để tự động sinh ra các Labeling Function từ các explanations (natural language). 

  <img src = "https://www.snorkel.org/doks-theme/assets/images/2018-05-15-babble/semantic_parser.png"/>

  - Trong bài tham khảo còn nói về một số lí do việc kết hợp các formal program (dù với một explanation ta đưa ra một số formal program và chỉ một trong số đó là diễn tả đúng nghĩa đen của explanations) vẫn đưa ra một kết quả tốt 

  [Reference](https://www.snorkel.org/blog/babble)


-  __Named entity__: 
  - In information extraction, a named entity is a real-world object, such as persons, locations, organizations, products, etc., that can be denoted with a proper name. It can be abstract or have a physical existence. Examples of named entities include Barack Obama, New York City, Volkswagen Golf, or anything else that can be named. Named entities can simply be viewed as entity instances (e.g., New York City is an instance of a city).

  [Reference](https://en.wikipedia.org/wiki/Named_entity)

- __NER__ (Named-entity recognition): 
  - Nhận diện thực thể là một subtask của Information extration, cụ thể là tìm kiếm vị trí và gắn nhãn cho *"Named-entity"* trong unstructured text, nhận diện (ví trí và lớp ) của *"Named-entity"* trong unstructured text.
Ví dụ:
<img src ="https://i.imgur.com/8taUisM.png" />

- __Entity linking__ ( also referred to as named-entity linking (NEL),[1] named-entity disambiguation (NED), named-entity recognition and disambiguation (NERD) or named-entity normalization (NEN)):
  - In natural language processing, entity linking, also referred to as named-entity linking (NEL),[1] named-entity disambiguation (NED), named-entity recognition and disambiguation (NERD) or named-entity normalization (NEN)[2] is the task of assigning a unique identity to entities (such as famous individuals, locations, or companies) mentioned in text. For example, given the sentence "Paris is the capital of France", the idea is to determine that "Paris" refers to the city of Paris and not to Paris Hilton or any other entity that could be referred to as "Paris". Entity linking is different from named-entity recognition (NER) in that NER identifies the occurrence of a named entity in text but it does not identify which specific entity it is 
  - Xác định *"Named-entity"* được nhắc đến trong unstructured cụ thể là gì (định danh) trong thế giới (earth) 

  [Differences from other techniques](https://en.wikipedia.org/wiki Entity_linking#Differences_from_other_techniques)
  [Reference](https://en.wikipedia.org/wiki/Entity_linking)


- __Deep Learning and Convolutional Neural Networks__ 

  [Machine Learning is Fun! Part 3: Deep Learning and Convolutional Neural Networks](https://medium.com/@ageitgey/machine-learning-is-fun-part-3-deep-learning-and-convolutional-neural-networks-f40359318721)
  [The best explanation of Convolutional Neural Networks on the Internet! on Medium](https://medium.com/technologymadeeasy/the-best-explanation-of-convolutional-neural-networks-on-the-internet-fbb8b1ad5df8)
  
