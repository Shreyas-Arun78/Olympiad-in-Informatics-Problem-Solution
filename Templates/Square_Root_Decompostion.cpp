using ll = long long;
struct sqrtDecomposition
{
    ll n;
    ll numBlocks, blockSize;
    vector<ll> v, blocks;
    sqrtDecomposition(const vector<ll> &arr)
    {
        n = arr.size();
        blockSize = sqrt(n);
        v = arr;
        if ((blockSize * blockSize) < n)
        {
            blockSize++;
        }
        numBlocks = (n + blockSize - 1) / blockSize;
        blocks.assign(numBlocks, 0);
        build();
    }
    // building blocks
    void build()
    {
        for (int i = 0; i < n; i++)
        {
            blocks[i / blockSize] += v[i];
        }
    }

    // updates

    void update(ll idx, ll val)
    {
        blocks[idx / blockSize] += (val - v[idx]);
        v[idx] = val;
    }

    // query

    ll query(ll l, ll r)
    {
        ll sum = 0;
        while (l <= r && (l % blockSize) != 0)
        {
            sum += v[l++];
        }
        while (l + blockSize - 1 <= r)
        {
            sum += (blocks[l / blockSize]);
            l += blockSize;
        }
        while (l <= r)
        {
            sum += v[l++];
        }
        return sum;
    }
};
