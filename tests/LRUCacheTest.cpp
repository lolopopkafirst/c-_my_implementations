
#include <gtest/gtest.h>
#include "LRUCache.hpp"

TEST(LRUCacheTest, PutValue){
    Cache cache{3, 100};
    cache.put(1, 10);
    EXPECT_EQ(cache.get(1), 10);
}

TEST(LRUCacheTest, UpdateValue){
    Cache cache{3, 100};
    cache.put(1, 10);
    cache.put(1, 20);
    EXPECT_EQ(cache.get(1), 20);
}

TEST(LRUCacheTest, ReplaceLastRecentlyUsedValue){
    Cache cache{2, 100};
    cache.put(1, 10);
    cache.put(2, 20);
    cache.put(3, 30);

    EXPECT_EQ(cache.get(3), 30);
    EXPECT_EQ(cache.get(2), 20);
    EXPECT_EQ(cache.get(1), -1);
}

TEST(LRUCacheTest, UpdatedValueNotReplaced){
    Cache cache{2, 100};
    cache.put(1, 10);
    cache.put(2, 11);
    cache.put(1, 20);
    cache.put(3, 30);
   
    EXPECT_EQ(cache.get(3), 30);
    EXPECT_EQ(cache.get(1), 20);
    EXPECT_EQ(cache.get(2), -1);
}

TEST(LRUCacheTest, MissingKey){
    Cache cache{2, 100};
    EXPECT_EQ(cache.get(1), -1);
}

TEST(LRUCacheTest, GetThenReplace){
    Cache cache{2, 100};

    cache.put(1, 10);
    cache.put(2, 20);
    cache.get(1);
    cache.put(3, 30);
    EXPECT_EQ(cache.get(2), -1);
    EXPECT_EQ(cache.get(3), 30);
    EXPECT_EQ(cache.get(1), 10);
}