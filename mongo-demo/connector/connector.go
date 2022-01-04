package main

import (
	"fmt"
	"go.mongodb.org/mongo-driver/bson"
	"go.mongodb.org/mongo-driver/bson/primitive"
	"go.mongodb.org/mongo-driver/mongo"
	"go.mongodb.org/mongo-driver/mongo/options"
	"go.mongodb.org/mongo-driver/mongo/readpref"
)

type dbWrapper struct {
	client *mongo.Client
}

func InitDb() {
	ctx, _ := context.WithTimeout(context.Background(), 10*time.Second)
	clientOptions := options.Client().ApplyURI("mongodb://localhost:27017")
	var err error
	db.client, err = mongo.Connect(ctx, clientOptions)

	// context needs to be canceled to avoid memory leak
	defer cancel()

	// check if the connection was successful
	// Ping the primary
	if err := db.client.Ping(ctx, readpref.Primary()); err != nil {
		panic(err)
	}
}

func (db *dbWrapper) Connect(dbName string, col string) {
	return db.client.Database(dbName).Collection(col)
}

func (db *dbWrapper) update(dbName string, col string) {

	collection := db.client.Database(dbName).Collection(col)

}

func (db *dbWrapper) find(dbName string, col string) {

	ctx, _ := context.WithTimeout(context.Background(), 10*time.Second)
	collection := db.client.Database(dbName).Collection(col)
	collection.find(ctx, bson.D{"createdAt": startDate,
		"totalCount": {"$gt": minCount,
			"$lt": maxCount}})

}
