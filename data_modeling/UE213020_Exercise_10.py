import random
import numpy as np
import pandas as pd
from sklearn import datasets
from sklearn.neighbors import KNeighborsClassifier
from sklearn.linear_model import LogisticRegression
from sklearn import metrics
from sklearn.model_selection import train_test_split
from sklearn import svm
from sklearn import gaussian_process
from sklearn.tree import DecisionTreeClassifier
from sklearn.ensemble import RandomForestClassifier
from sklearn.neural_network import MLPClassifier
from sklearn.ensemble import AdaBoostClassifier
from sklearn.naive_bayes import GaussianNB
from sklearn.discriminant_analysis import QuadraticDiscriminantAnalysis

import warnings
warnings.filterwarnings('ignore')

def get_accuracies(classifier,X_train, X_test, y_train, y_test,dataset:str):
    global results
    classifier[0].fit(X_train,y_train)
    y_pred=classifier[0].predict(X_test)
    accuracy=metrics.accuracy_score(y_test, y_pred)
    df = pd.DataFrame([[classifier[1],accuracy]],columns=["Classifier",dataset.capitalize()+" Accuracy"])
    
    results[dataset] = pd.concat([results[dataset],df],ignore_index=True)


if(__name__=="__main__"):
    
    classifiers =   [
                        [KNeighborsClassifier(3),"KNeighborsClassifier(3)"],
                        [svm.SVC(C=0.025, kernel='linear'),"SVC(kernel='linear', C=0.025)"],
                        [svm.SVC(gamma=2,C=1),"SVC(gamma=2, C=1)"],
                        [gaussian_process.GaussianProcessClassifier(1.0 * gaussian_process.kernels.RBF(1.0)),"GaussianProcessClassifier(1.0 * RBF(1.0))"],
                        [DecisionTreeClassifier(max_depth=5),"DecisionTreeClassifier(max_depth=5)"],
                        [RandomForestClassifier(max_depth=5, n_estimators=10, max_features=1),"RandomForestClassifier(max_depth=5, n_estimators=10, max_features=1)"],
                        [MLPClassifier(alpha=1),"MLPClassifier(alpha=1)"],
                        [AdaBoostClassifier(),"AdaBoostClassifier()"],
                        [GaussianNB(),"GaussianNB()"],
                        [QuadraticDiscriminantAnalysis(),"QuadraticDiscriminantAnalysis()"]
                    ]
    
    results = {
        "iris":pd.DataFrame(columns=["Classifier","Iris Accuracy"]),
        "digits":pd.DataFrame(columns=["Classifier","Digits Accuracy"]),
        "boston":pd.DataFrame(columns=["Classifier","Boston Accuracy"])
    }

    iris = datasets.load_iris()
    X = iris.data
    y = iris.target
    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.4, random_state=4)

    for classifier in classifiers:
        get_accuracies(classifier,X_train, X_test, y_train, y_test,"iris")

    digits = datasets.load_digits()
    X = digits.data
    y = digits.target
    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.4, random_state=4)

    for classifier in classifiers:
        get_accuracies(classifier,X_train, X_test, y_train, y_test,"digits")

    boston = datasets.load_boston()
    X = pd.DataFrame(boston.data, columns=boston.feature_names)
    y = pd.Series(boston.target, name='Medv')
    y_ranges = pd.cut(y, bins=[0, 15, 30, 50, float('inf')])
    y_ranges_labels = y_ranges.astype(str)
    X_train, X_test, y_train, y_test = train_test_split(X, y_ranges_labels, test_size=0.4, random_state=4)
    y_train_categorical = pd.Categorical(y_train)
    y_test_categorical = pd.Categorical(y_test)


    for classifier in classifiers:
        get_accuracies(classifier,X_train, X_test, y_train_categorical, y_test_categorical,"boston")
    
    final_result = pd.merge(results["iris"],results["digits"],on="Classifier",how="inner")
    final_result = pd.merge(final_result,results["boston"],on="Classifier",how="inner")
    print(final_result)
    print()
    print("*"*100)

    print(f"\nBest Classifier for Iris is: {final_result.loc[final_result['Iris Accuracy'].idxmax(),'Classifier']} with value {final_result['Iris Accuracy'].max()}")
    print(f"Best Classifier for Digits is: {final_result.loc[final_result['Digits Accuracy'].idxmax(),'Classifier']} with value {final_result['Digits Accuracy'].max()}")
    print(f"Best Classifier for Boston is: {final_result.loc[final_result['Boston Accuracy'].idxmax(),'Classifier']} with value {final_result['Boston Accuracy'].max()}")
