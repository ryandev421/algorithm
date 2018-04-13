#include <stdio.h>
#include <algorithm>
#include <stack>
#define MAX_N 100000
using namespace std;

FILE *fin = stdin;
FILE *fout = stdout;

int N;
int Arr[MAX_N + 1];
stack<int> st;
int Ans;

int main()
{
    int i;

    fscanf(fin,"%d",&N);
    for(i=1;i<=N;i++) fscanf(fin,"%d",&Arr[i]);

    for(i=1;i<=N;i++) {
        while(!st.empty() && Arr[i] < Arr[st.top()]) {
            int pos = st.top();
            st.pop();
            int width = !st.empty() ? i - st.top() - 1 : i - 1;
            int area = Arr[pos] * width;
            Ans = Ans < area ? area : Ans;
        }
        st.push(i);
    }
    while(!st.empty()) {
        int pos = st.top();
        st.pop();
        int width = !st.empty() ? N - st.top() : N;
        int area = Arr[pos] * width;
        Ans = Ans < area ? area : Ans;
    }
    fprintf(fout,"%d",Ans);
    return 0;
}
