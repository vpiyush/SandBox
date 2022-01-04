package main

import (
	"encoding/json"
	"fmt"
	"gopkg.in/go-playground/validator.v9"
	"mongo-demo/datastore"
	memdb "mongo-demo/inmemdb"
	"net/http"
)

type Env struct {
	records interface {
		Find(string, string, int, int) ([]dbconnector.Record, error)
	}
}

var env *Env

type ErrorResponse struct {
	StatusCode   int    `json:"status"`
	ErrorMessage string `json:"message"`
}

type RecordResponse struct {
	Code    int                  `json:"code"`
	Msg     string               `json:"msg"`
	Records []dbconnector.Record `json:"records"`
}

type Request struct {
	StartDate string `validate:"required" json:"startdate" bson:"startdate"`
	EndDate   string `validate:"required" json:"enddate" bson:"enddate"`
	MinCount  int    `validate:"required" json:"mincount" bson:"mincount"`
	MaxCount  int    `validate:"required" json:"maxcount" bson:"maxcount"`
}

type Pair struct {
	Key   string `validate:"required"json:"key"`
	Value string `validate:"required"json:"value"`
}

func validatePair(pair *Pair) error {
	validate := validator.New()
	err := validate.Struct(pair)
	if err != nil {
		for _, err := range err.(validator.ValidationErrors) {
			fmt.Println(err.Field())
			fmt.Println(err.StructField())
			fmt.Println(err.Value())
		}
		return err
	}
	//TODO: validate variable
	return nil
}

func validateRequest(req *Request) error {
	validate := validator.New()
	err := validate.Struct(req)
	if err != nil {
		for _, err := range err.(validator.ValidationErrors) {
			fmt.Println(err.Field())
			fmt.Println(err.StructField())
			fmt.Println(err.Value())
		}
		return err
	}
	//TODO: validate variable
	return nil
}

/*
func CreateRecord() {
	rec := Record{
		key:       "abc",
		value:     "abc",
		createdAt: "2012-10-10",
	}
	collection := client.Database("mongoDemo").Collection("people")
	ctx, _ := context.WithTimeout(context.Background(), 10*time.Second)
	result, _ := collection.InsertOne(ctx, rec)
	fmt.Println(result)
}*/

func (env *Env) GetRecords(response http.ResponseWriter, request *http.Request) {
	response.Header().Set("content-type", "application/json")
	fmt.Println("Invoking Get Records")
	var req Request
	_ = json.NewDecoder(request.Body).Decode(&req)
	validateRequest(&req)
	fmt.Println(req)

	records, err := env.records.Find(req.StartDate, req.EndDate, req.MinCount, req.MaxCount)
	var res RecordResponse
	if err != nil {
		res.Code = -1
		res.Msg = "Bad Request"
	} else {
		res.Code = 0
		res.Msg = "Success"
	}
	res.Records = records
	fmt.Println(res)
	json.NewEncoder(response).Encode(res)
}

func InsertPair(response http.ResponseWriter, request *http.Request) {
	response.Header().Set("content-type", "application/json")
	var pair Pair
	_ = json.NewDecoder(request.Body).Decode(&pair)
	validatePair(&pair)
	memdb.Cache.Insert(pair.Key, pair.Value)
	json.NewEncoder(response).Encode(pair)
}

/*
func GetError(err error) {
	var errRsp = ErrorResponse{
		ErrorMessage: err.Error(),
		StatusCode:   http.StatusBadRequest,
	}
	json.NewEncoder(response).Encode(errRsp)
}*/

func GetPair(response http.ResponseWriter, request *http.Request) {
	fmt.Println("Entering GetPair ")
	response.Header().Set("content-type", "application/json")
	var pair Pair
	validatePair(&pair)
	memdb.Cache.Print()
	pair.Key = request.FormValue("key")
	fmt.Println("received key ", pair.Key)
	val, ok := memdb.Cache.Get(pair.Key)
	if !ok {
		var errRsp = ErrorResponse{
			ErrorMessage: "Key not Found",
			StatusCode:   http.StatusBadRequest,
		}
		response.WriteHeader(http.StatusBadRequest)
		json.NewEncoder(response).Encode(errRsp)
		return
	}

	pair.Value = val
	json.NewEncoder(response).Encode(pair)
}

func HandlePair(response http.ResponseWriter, request *http.Request) {
	switch request.Method {
	case "GET":
		GetPair(response, request)
	case "POST":
		InsertPair(response, request)
	default:
		//TODO: error
	}
}

func main() {
	fmt.Println("Starting the application....")
	collection := dbconnector.Client.Database("getir-case-study").Collection("records")
	env = &Env{
		records: dbconnector.RecordModel{RecCollection: collection},
	}
	http.HandleFunc("/records", env.GetRecords)
	http.HandleFunc("/pair", HandlePair)
	// create router
	http.ListenAndServe("172.16.8.169:12345", nil)
}
