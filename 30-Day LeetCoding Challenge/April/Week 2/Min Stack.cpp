class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> m_nStack;
    int m_nMinValue;
    int m_nMinIdx;
    
    bool m_bInit;
    
    MinStack() {
        m_nMinValue = 0;
        m_nMinIdx = -1;
    }
    
    void push(int x) {
        m_nStack.push_back(x);
        
        if( -1 == m_nMinIdx || x < m_nMinValue ) {
            m_nMinValue = x;
            m_nMinIdx = m_nStack.size()-1;
        }
    }
    
    void pop() {
        vector<int>::iterator itFind = m_nStack.begin() + m_nStack.size() - 1;
        int nTemp = *itFind;
        
        if( m_nMinIdx == m_nStack.size() - 1 ) {
            m_nMinIdx = -1;
        }
        
        m_nStack.erase(itFind);
        
        // find min value
        if( 0 < m_nStack.size() && -1 == m_nMinIdx ) {
            m_nMinValue = m_nStack[0];
            m_nMinIdx = 0;
            for( int i = 1; i < m_nStack.size(); ++i ) {
                if( m_nMinValue > m_nStack[i] ) {
                    m_nMinValue = m_nStack[i];
                    m_nMinIdx = i;
                }
            }
        }
    }
    
    int top() {
        return( m_nStack[m_nStack.size()-1] );
    }
    
    int getMin() {
        return( m_nMinValue );
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */