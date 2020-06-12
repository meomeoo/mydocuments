#### __Named entity__
  - Là một khái niệm trong context của Information Extration
  - Definition: In information extraction, a named entity is a real-world object, such as persons, locations, organizations, products, etc., that can be denoted with a proper name. It can be abstract or have a physical existence. Examples of named entities include Barack Obama, New York City, Volkswagen Golf, or anything else that can be named. Named entities can simply be viewed as entity instances (e.g., New York City is an instance of a city).
  - Giống như kiểu một thể hiện ở trong Ngôn ngữ lập trình 
  - Hoặc cũng có thể định nghĩa theo *rigid designator*, như là "named" là để *hạn chế* sự ảnh hưởng của việc một entity có thể reference đến nhiều(một entity có nhiều rigid designator) "đối thượng cụ thể" trong nhiều context khác nhau. 
  - Tuy nhiên dùng từ *hạn chế* vì sự định nghĩa cho *named entity* là *linh hoạt*.
  - Ví dụ trong một context câu *automotive company created by Henry Ford in 1903* có thể reference đến *Ford* or *Ford Motor Company* mắc dù trong thự tế từ *Ford* có thể có nhiều nghĩa khác nhau.
  - Những entity hoặc các giá trị biều thức có thể được coi là *named entity* (thể hiện sự *linh hoạt* trong định nghĩa)
  -  While some instances of these types are good examples of rigid designators (e.g., the year 2001) there are also many invalid ones (e.g., I take my vacations in “June”). In the first case, the year 2001 refers to the 2001st year of the Gregorian calendar. In the second case, the month June may refer to the month of an undefined year (past June, next June, every June, etc.). It is arguable that the definition of named entity is loosened in such cases for practical reasons. The definition of the term named entity is therefore not strict and often has to be explained in the context in which it is used.



###  __Named-entity recognition__: 

- __Problem definition__: 
  * Xác định khái niệm *named-entity* sẽ dùng cho context của bài toán.
  * Khi giải quyết bài toán được chia làm 2 phần:
    +  Detection of names: Xác định tên thực thể ( chắc là xác định thực thể và các entity có named) This segmentation problem is formally similar to chunking
    +  Classification of the names: Xác định nhãn cho các thực thể đó(type of entity they refer to (e.g. person, organization, location and other[7]), The second phase requires choosing an ontology by which to organize categories of things.

- __Current challenges and research__:
    Despite the high F1 numbers reported on the MUC-7 dataset, the problem of named-entity recognition is far from being solved. The main efforts are directed to reducing the annotation labor by employing semi-supervised learning,[14][19] robust performance across domains[20][21] and scaling up to fine-grained entity types.[10][22] In recent years, many projects have turned to crowdsourcing, which is a promising solution to obtain high-quality aggregate human judgments for supervised and semi-supervised machine learning approaches to NER.[23] Another challenging task is devising models to deal with linguistically complex contexts such as Twitter and search queries.[24]

    There are some researchers who did some comparisons about the NER performances from different statistical models such as HMM (hidden Markov model), ME (maximum entropy), and CRF (conditional random fields), and feature sets.[25] And some researchers recently proposed graph-based semi-supervised learning model for language specific NER tasks.[26]

    A recently emerging task of identifying "important expressions" in text and cross-linking them to Wikipedia[27][28][29] can be seen as an instance of extremely fine-grained named-entity recognition, where the types are the actual Wikipedia pages describing the (potentially ambiguous) concepts. Below is an example output of a Wikification system:

-  __Approaches__
  Currently automatic named entity recognition and extraction systems have become one of the popular research areas. They can be categorized into four classes; Hand-made NER, Rule-based NER, Machine, Learningbased NER and Hybrid NER.

-  __Process__:
  * Từ câu ban đầu
  * Đưa vào  tokenization process để nhận được các token
  * Sau đó thực hiện POS tagging để gán Part-of-Speech cho các token
  [Reference about Learning POS Tagging & Chunking in NLP](https://medium.com/greyatom/learning-pos-tagging-chunking-in-nlp-85f7f811a8cb)
  * Sau đó là chucking: Extration ra các cụm từ thích hợp trong câu và gán cho nó các IOB tags để xác định được cấu trúc của các chuck trong câu 
    [Reference about IOP tags](https://www.geeksforgeeks.org/nlp-iob-tags/)

    + Chunking is a process of extracting phrases from unstructured text. Instead of just simple tokens which may not represent the actual meaning of the text, its advisable to use phrases such as “South Africa” as a single word instead of ‘South’ and ‘Africa’ separate words.
    + Chunking works on top of POS tagging, it uses pos-tags as input and provides chunks as output.
    + Chunking works on top of POS tagging, it uses pos-tags as input and provides chunks as output. Similar to POS tags, there are a standard set of Chunk tags like Noun Phrase(NP), Verb Phrase (VP), etc. Chunking is very important when you want to extract information from text such as Locations, Person Names etc. In NLP called Named Entity Extraction.


    [Reference from wiki for NER](https://en.wikipedia.org/wiki/Named-entity_recognition)
    [Reference about Alphabetical list of part-of-speech tags used in the Penn Treebank Project](https://www.ling.upenn.edu/courses/Fall_2003/ling001/penn_treebank_pos.html)
    [Reference about Learning POS Tagging & Chunking in NLP](https://medium.com/greyatom/learning-pos-tagging-chunking-in-nlp-85f7f811a8cb)
    [Reference about IOP tags](https://www.geeksforgeeks.org/nlp-iob-tags/)
    [Named Entity Recognition with NLTK and SpaCy](https://towardsdáCatascience.com/named-entity-recognition-with-nltk-and-spacy-8c4a7d88e7da)
    
- __Word Vectors__: 

  [Introduction to Word Vectors](https://dzone.com/articles/introduction-to-word-vectors)
  [A Comprehensive Introduction to Word Vector Representations](https://medium.com/ai-society/jkljlj-7d6e699895c4)
  [Word2Vec Tutorial - The Skip-Gram Model](http://mccormickml.com/2016/04/19/word2vec-tutorial-the-skip-gram-model/)

  [Need read about Deep Learning, NLP, and Representations](http://colah.github.io/posts/2014-07-NLP-RNNs-Representations/)

-  __N-Gram Models__ 

  [Modeling Natural Language with N-Gram Models](https://sookocheff.com/post/nlp/n-gram-modeling/)


- __Automated Phrase Mining from Massive Text Corpora__

  - Cải tiến so với các mô hình trước đây bằng việc giảm không có sự trợ giúp của chuyên gia và phân tích thuật ngữ chuyên sâu. *with minimal human effort or reliance on linguistic analyzers1* - *The phrase “minimal human effort” indicates using only existing general knowledge bases without any other human effor*


