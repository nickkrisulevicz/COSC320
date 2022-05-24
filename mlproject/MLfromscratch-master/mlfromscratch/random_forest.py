#Nick Krisulevicz
#COSC 320
#Machine Learning Project
#Random Forest Algorithm
#05/13/2022
#Python 3 code using Python Libraries to Implement Random Forest
#

from collections import Counter
import numpy as np
from .decision_tree import DecisionTree

#define a function to bootstrap the subtrees
def bootstrap_sample(X, y):
    n_samples = X.shape[0]
    idxs = np.random.choice(n_samples, n_samples, replace=True)
    return X[idxs], y[idxs]

#define a function to create the criteria for the majority trend for the outcome
def most_common_label(y):
    counter = Counter(y)
    most_common = counter.most_common(1)[0][0]
    return most_common

#the random forest class and fucntions
class RandomForest:
    def __init__(self, n_trees=10, min_samples_split=2, max_depth=100, n_feats=None):
        self.n_trees = n_trees
        self.min_samples_split = min_samples_split
        self.max_depth = max_depth
        self.n_feats = n_feats
        self.trees = []

    #function to fit the data from the data set into the trees
    def fit(self, X, y):
        self.trees = []
        for _ in range(self.n_trees):
            tree = DecisionTree(
                min_samples_split=self.min_samples_split,
                max_depth=self.max_depth,
                n_feats=self.n_feats,
            )
            X_samp, y_samp = bootstrap_sample(X, y)
            tree.fit(X_samp, y_samp)
            self.trees.append(tree)

    #function to predict the outcome based on what the result of the trees says
    def predict(self, X):
        tree_preds = np.array([tree.predict(X) for tree in self.trees])
        tree_preds = np.swapaxes(tree_preds, 0, 1)
        y_pred = [most_common_label(tree_pred) for tree_pred in tree_preds]
        return np.array(y_pred)


# Testing
if __name__ == "__main__":
    # Imports
    from sklearn import datasets
    from sklearn.model_selection import train_test_split

    def accuracy(y_true, y_pred):
        accuracy = np.sum(y_true == y_pred) / len(y_true)
        return accuracy
    #load the breast cancer data set
    data = datasets.load_breast_cancer()
    X = data.data
    y = data.target

    #train the forest
    X_train, X_test, y_train, y_test = train_test_split(
        X, y, test_size=0.2, random_state=1234
    )
    
    #set the parameters for each tree, in this case there are 3 trees with a max depth of 10
    clf = RandomForest(n_trees=3, max_depth=10)

    #fit the data to the tres
    clf.fit(X_train, y_train)
    #predict the result from the data
    y_pred = clf.predict(X_test)
    #deliver the accuracy of the results
    acc = accuracy(y_test, y_pred)

    #return the accuracy of the random forest
    print("Accuracy:", acc)
    print("The resulting matrix from the subtrees")
    print(y_pred)
