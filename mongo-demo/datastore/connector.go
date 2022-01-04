package dbconnector

import (
	"context"
	"fmt"
	"go.mongodb.org/mongo-driver/mongo"
	"go.mongodb.org/mongo-driver/mongo/options"
	"go.mongodb.org/mongo-driver/mongo/readpref"
	"time"
)

var Client *mongo.Client

func init() {
	//con.Connect("mongodb://localhost:27017", )
	fmt.Println("Connecting to mongo..")
	ctx, _ := context.WithTimeout(context.Background(), 10*time.Second)
	clientOptions := options.Client().ApplyURI("mongodb+srv://challengeUser:WUMglwNBaydH8Yvu@challenge-xzwqd.mongodb.net/getircase-study?retryWrites=true")
	Client, _ = mongo.Connect(ctx, clientOptions)
	fmt.Println("Connected to mongo db")
	// check if the connection was successful
	// Ping the primary
	if err := Client.Ping(ctx, readpref.Primary()); err != nil {
		panic(err)
	}
	// context needs to be canceled to avoid memory leak
	//REVIEW
	//defer cancel()
}
