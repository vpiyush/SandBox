package dbconnector

import (
	"context"
	"fmt"
	"go.mongodb.org/mongo-driver/bson"
	"go.mongodb.org/mongo-driver/mongo"
	"time"
)

type Record struct {
	Key        string    `json:"key"`
	CreatedAt  time.Time `json:"createdAt"`
	TotalCount int       `json:"totalCount"`
}

type RecordModel struct {
	RecCollection *mongo.Collection
}

func (r RecordModel) Find(startDate string, endDate string, minCount int, maxCount int) ([]Record, error) {
	ctx, _ := context.WithTimeout(context.Background(), 10*time.Second)
	sDate, _ := time.Parse("2006-01-02", startDate)
	eDate, _ := time.Parse("2006-01-02", endDate)
	fmt.Println("startDate: ", sDate)
	fmt.Println("endDate: ", eDate)
	pipeline := mongo.Pipeline{
		{
			{"$match", bson.D{
				{"createdAt", bson.D{
					{"$lte", eDate},
					{"$gte", sDate},
				}},
			}},
		},
		{
			{"$project", bson.D{
				{"_id", 0},
				{"key", 1},
				{"createdAt", 1},
				{"totalCount", bson.D{{"$sum", "$counts"}}},
			}},
		},
		{
			{"$match", bson.D{
				{"totalCount", bson.D{
					{"$lte", maxCount},
					{"$gte", minCount},
				}},
			}},
		},
	}

	/*
		projectStage := bson.D{
			{"$project", bson.D{
				{"_id", 0},
				{"key", 1},
				{"creatdAt", 1},
				{"totalCount", bson.D{
					{"$sum", "$counts"},
				}},
			}},
		}

		matchStage := bson.D{
			{"$match", bson.D{
				{"totalCount", bson.D{
					{"$gt", minCount},
					{"$lt", maxCount},
				}},
			}},
		}
		/*
			groupStage := bson.D{
				{"$group", bson.D{
					{"_id", "$createdat"},
					{"totalCount", bson.D{
						{"$sum", "$counts"},
					}},
				}},
			}*/
	cursor, err := r.RecCollection.Aggregate(ctx, pipeline)
	fmt.Println("Aggregation done ")
	if err != nil {
		fmt.Println("Error ", err)
		return nil, err
	}
	defer cursor.Close(ctx)
	var records []Record
	for cursor.Next(ctx) {
		var rec Record
		cursor.Decode(&rec)
		fmt.Println(rec)
		records = append(records, rec)
	}
	fmt.Println("returning records")
	return records, err
}
