package inmemdb

import (
	"fmt"
	"sync"
)

type cache struct {
	items map[string]string
	mu    sync.RWMutex
}

var Cache *cache

func init() {
	Cache = &cache{
		items: make(map[string]string),
		mu:    sync.RWMutex{},
	}
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

func (c *cache) Print() {
	c.mu.RLock()
	defer c.mu.RUnlock()
	for k, v := range c.items {
		fmt.Println("key:", k, " value:", v)

	}
}
