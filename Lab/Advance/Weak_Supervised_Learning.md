- __Weakly Supervised Learning__ 

 Có 3 loại của phương pháp học này:
  * __Incomplete supervision__: When only a subset of training data are labelled, For example: in image categorization the ground-truth labels are given by human annotators; it is easy to get a huge number of images from the Internet, whereas only a small subset of images can be annotated due to the human cost
  * __Inexact supervision__: when the training data are given with labels but not as exact as desidered, i.e. only coarse-grained labels are given. Consider the image categorization task again. It is desirable to have every object in the images annotated; however, usually we only have image-level labels rather than object-level labels. 
  * __Inaccurate supervision__: when in the training data there are some labels with mistakes, i.e. the given labels are not always ground-truth. Such a situation occurs, e.g. when the image annotator is careless or weary, or some images are difficult to categorize.

 1. __Incomplete supervision__:
  - There are two major techniques for *Incomplete supervision*, i.e. __active learning__ and __semi-supervised learning__.

   - __Active learning__ :The goal of active learning is to minimize the number of queries such that the labeling cost for training a good model can be minimized.Given a small set of labeled data and abundant unlabeled data, active learning attempts to select the most valuable unlabeled instance to query. There are two widely used selection criteria, i.e. *informativeness* and *representativeness* . *Informativeness* measures how well an unlabeled instance helps reduce the uncertainty of a statistical model, whereas  *representativeness* measures how well an instance helps represent the structure of input patterns. (Từ labeled data sau đó xây dựng mô hình để lựa chọn(dùng các Query Strategy) unlabeled data để query *human intervention* để label data sau đó dùng data đó để cải thiện mô hình) 
  <img src = ""/>
     * __Informativeness__: *Uncertainty sampling* and *query-by-committee* are representative approaches based on informativeness. The former trains a single learner and then queries the unlabeled instance on which the learner has the least confidence . The latter generates multiple learners and then queries the unlabeled instance on which the learners disagree the most 
     [Read for Uncertainty and query-bycommittee](http://burrsettles.com/pub/settles.activelearning.pdf)
     * __Representativeness__: Approaches based on representativeness generally aim to exploit the cluster structure of unlabeled data, usually by a clustering method.
     * __Weakness__:The main weakness of informativeness-based approaches lies in the fact that they rely seriously on labeled data for constructing the initial model to select the query instance, and the performance is often unstable when there are only a few labeled examples available. The main weakness of representativeness-based approaches lies in the fact that the performance heavily depends on the clustering results dominated by unlabeled data, especially when there are only a few labeled examples. Thus, several recent active learning approaches try to leverage informativeness and representativeness

   - __Semi-supervised learning__ :attempts to exploit unlabeled data without querying human experts. Here, although the unlabeled data points do not explicitly have label information, they implicitly convey some information about data distribution that can be helpful for predictive modeling.
    * Actually, in semi-supervised learning there are two basic assumptions, i.e. the *cluster assumption* and the *manifold assumption*; both are about data distribution. The former assumes that data have inherent cluster structure, and thus, instances falling into the same cluster have the same class label. The latter assumes that data lie on a manifold, and thus, nearby instances have similar predictions. *The essence of both assumptions lies in the belief that similar data points should have similar outputs, whereas unlabeled data can be helpful to disclose which data points are similar.*
    * There are four major categories of semi-supervised learning approaches, i.e. **generative methods*, *graph-based methods*, *low-density separation methods* and *disagreement-based methods*.

 2.__INEXACT SUPERVISION__ 
  - Được xem xét như bài toán multi-instance learning.

  - *however, in contrast to drug-activity prediction where there are natural formations of instances in a bag (i.e. shapes of a molecule), the instances need to be generated for each bag. A bag generator specifies how instances are generated to constitute a bag.* các instance được sinh ra từ bản thân các Bag  
  - Although bag generators have a significant influence on learning performance, only recently has an extensive study about image bag generators been reported [59]; this study discloses that some simple dense-sampling bag generators perform better than complicated ones. Figure 5 shows two simple yet effective image bag generators.

 3. __Innacurate supervision__: the approach is to use several learners (ensemble) to identify unlabeled examples and then check it with training data trying to make some correction. An helpful strategy is the crowdsourcing, more precisely, unlabeled instances are outsourced to a large group of workers to label. It’s a cost-saving way to collect labels for training data.  
  


[Reference](https://academic.oup.com/nsr/article/5/1/44/4093912)
