//
//  map.h
//  SDP
//
//  Created by Miroslav Mironov on 12/10/15.
//  Copyright © 2015 Miroslav Mironov. All rights reserved.
//

#ifndef map_h
#define map_h

#include "list.h"
#include "pair.h"
#include "hash_function.h"

template <typename K, typename V>
class HashMap {
    static const int CAPACITY = 1024;
    
    List< Pair<K, V> > map[CAPACITY];
    
    HashFunction<K>* hashFunction;
public:
    
    void insert(const K& key, const V& value)
    {
        int hash = hashFunction->hash(key) % CAPACITY;
        
        List< Pair<K, V> >& pairs = map[hash];
        
        Pair<K, V>* pair = find(key);
        
        if (pair == 0)
        {
            Pair<K, V> newPair;
            newPair.key = key;
            newPair.value = value;
            pairs.add(newPair);
        }
        else
        {
            pair->value = value;
        }
    }
    
    void remove(const K& key)
    {
        int hash = hashFunction->hash(key) % CAPACITY;
        
        List< Pair<K, V> >& pairs = map[hash];

        for(int i=0; i < pairs.size(); ++i)
        {
            if (pairs.get(i).key == key)
            {
                pairs.remove(i);
                break;
            }
        }

    }
    
    bool contains(const K& key)
    {
        return find(key) != 0;
    }
    
    Pair<K, V>* find(const K& key)
    {
        int hash = hashFunction->hash(key) % CAPACITY;
        
        List< Pair<K, V> >& pairs = map[hash];
        
        for(int i=0; i < pairs.size(); ++i)
        {
            if (pairs.get(i).key == key)
            {
                return &pairs.get(i);
            }
        }
        
        return 0;
    }
    
    void setHashFunction(HashFunction<K>* function)
    {
        hashFunction = function;
    }
};

#endif /* map_h */
