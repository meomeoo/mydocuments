__Weak Supervisie__
*The above paradigms potentially allow us to avoid asking our SME collaborators for additional training labels. But what if–either in addition, or instead–we could ask them for various types of higher-level, or otherwise less precise, forms of supervision, which would be faster and easier to provide? For example, what if our radiologists could spend an afternoon specifying a set of heuristics or other resources, that–if handled properly–could effectively replace thousands of training labels? This is the key practical motivation for weak supervision approaches, which we describe next.*

<img src = "https://i.imgur.com/vlksVKU.png" /> 

- Có 2 công đoạn chính:
 1. Unify and model these disparate weak supervision sources 
 2. Used to train the end model–in the standard ERM context

- Đôi khi kết quả ở bước 1 không được tốt thì ta phải chú ý xây dựng bức 2 (end model) dựa trên. For example, researchers have considered expectation criteria (Mann and McCallum 2010), learning with constraints (Becker and Hinton 1992; Stewart and Ermon 2017), building task-specific noise models (Mnih and Hinton 2012), and learning noise models simultaneously during training (Xiao et al. 2015).  
- However, in most cases we want to generalize beyond the coverage of our weak supervision sources. For example, we might have a set of precise but overly narrow rules, or pre-trained classifiers defined over features not always available at test time (such as models trained over text radiology reports, when our goal is to train an image classifier)–thus we aim to train an end model that can learn a more general representation.