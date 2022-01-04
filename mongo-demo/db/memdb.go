package memdb

import (
	"sync"
)

type Cache struct {
	// wrap the cache to expose to users
	*cache
}

type cache struct {
	items map[string]string
	mu    sync.RWMutex
}

var memDb map[string]string

func NewCache() *Cache {
	c := &cache{
		items: make(map[string]string),
		mu:    sync.RWMutex{},
	}
	return &Cache{c}
}

func (c *cache) Insert(key string, value string) {
	c.mu.Lock()
	c.items[key] = value
	c.mu.Unlock()
}

func (c *cache) Get(key string) (string, bool) {
	c.mu.RLock()
	defer c.mu.RUnlock()
	if value, ok := c.items[key]; ok {
		return value, true
	}
	return "", false
	//return "", errors.New("Key Not Found")
}
