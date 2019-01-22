#include "iostream"
using namespace std;
struct Node{
    int childNum=0;
    Node* lc = nullptr;
    Node* rc = nullptr;
};
int getChild(Node *pNode){
    if(pNode != nullptr){
        pNode->childNum += getChild(pNode->lc);
        pNode->childNum += getChild(pNode->rc);
        return pNode->childNum+1;
    }
    return 0;
}
int main(){
    Node* l1[262144];
    Node* l2[524288];
    Node* root;
    Node* node;
    int n, leftChild, rightChild, cnt=0, cnt2=0, layerNum=2, pow=1;
    bool isRoot = true;
    cin >> n;
    root = new Node;
    for(int i=0;i<n; ++i) {
        if(isRoot)
            node = root;
        else {
            node = l1[cnt2];
            ++cnt2;
        }
        cin >> leftChild >> rightChild;
        if (leftChild != 0) {
            node->lc = new Node;
            l2[cnt] = node->lc;
            ++cnt;
        }
        if (rightChild != 0) {
            node->rc = new Node;
            l2[cnt] = node->rc;
            ++cnt;
        }
        if(cnt>=layerNum){
            for(int j=0; j<cnt; ++j)
                l1[j] = l2[j];
            isRoot = false;
            pow*=2;
            layerNum += pow;
            cnt = 0;
            cnt2 = 0;
        }
    }
    getChild(root);
    Node* next = root;
    cnt = 1;
    while(next != nullptr){
        if(next->lc != nullptr && next->rc != nullptr){
            next = next->lc->childNum >= next->rc->childNum ? next->rc : next->lc;
            ++cnt;
        }
        else
            break;
    }
    cout << cnt;
    return 0;
}