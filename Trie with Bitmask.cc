sstruct trie
{
    struct node {
        node* a[2];
        int cnt ;

        node() {
            a[0] = a[1] = NULL;
            cnt = 0;
        }
    };
    node* root;
    trie() {
        root = new node;
    }

    void add(int x) {

        node* cur = root;
        for (int i = 30 ; i >= 0 ; i--) {
            int b = x & (1 << i);
            if (b > 0)b = 1;
            if (cur->a[b] == NULL)
                cur->a[b] = new node;
            cur = cur->a[b];
            cur-> cnt ++;
        }
    }

    void remove(int x) {
        node* cur = root;
        for (int i = 30 ; i >= 0 ; i--) {
            int b = x & (1 << i);
            if (b > 0)b = 1;

            cur = cur->a[b];
            cur->cnt--;

        }
    }

    int maxxor(int x) {
        int ans = 0;
        node*cur = root;

        for (int i = 30 ; i >= 0 ; i--) {

            int b = x & (1 << i);
            if (b > 0)b = 1;

            int opp = b ^ 1;

            if (cur->a[opp] != NULL and cur->a[opp]->cnt > 0) {
                cur = cur -> a[opp];
                ans += (1 << i);
            }
            else if (cur->a[b]  != NULL) {
                cur = cur-> a[b];
            }
        }
        return ans;
    }

};


//////// MIN-XOR /////////////
int minxor(int x) {
    int ans = 0;
    node*cur = root;

    for (int i = 30 ; i >= 0 ; i--) {

        int b = x & (1 << i);
        if (b > 0)b = 1;

        if (cur->a[b] != NULL and cur->a[b]->cnt > 0) {
            cur = cur->a[b];
        }
        else if (cur->a[b ^ 1]  != NULL) {
            ans += (1 << i);
            cur = cur -> a[b ^ 1];
        }
    }
    return ans;
}

