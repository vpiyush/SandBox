package main

import (
	"bytes"
	"fmt"
	"mongo-demo/datastore"
	memdb "mongo-demo/inmemdb"
	"net/http"
	"net/http/httptest"
	"strings"
	"testing"
)

func TestGetRecords(t *testing.T) {
	var jsonStr = []byte(`{"startDate": "2016-01-26","endDate": "2018-02-02","minCount": 2700,"maxCount": 3000 }`)
	req, err := http.NewRequest("POST", "/records", bytes.NewBuffer(jsonStr))
	if err != nil {
		t.Fatal(err)
	}
	fmt.Println("Executing Test Get Records")
	collection := dbconnector.Client.Database("getir-case-study").Collection("records")
	env = &Env{
		records: dbconnector.RecordModel{RecCollection: collection},
	}
	//env := Env{records: &mockRecordModel{}}
	rr := httptest.NewRecorder()
	handler := http.HandlerFunc(env.GetRecords)
	handler.ServeHTTP(rr, req)
	if status := rr.Code; status != http.StatusOK {
		t.Errorf("handler returned wrong status code: got %v want %v",
			status, http.StatusOK)
	}

	fmt.Println(rr.Body.String())
	// Check the response body is what we expect.
	/*	expected := `{"key":"active-tabs","value":"getir"}`
		if strings.TrimSuffix(rr.Body.String(), "\n") != string(expected) {
			t.Errorf("handler returned unexpected body: got %v want %v",
				rr.Body.String(), expected)
		}*/
}

func TestGetPair(t *testing.T) {
	memdb.Cache.Insert("active-tabs", "getir")
	req, err := http.NewRequest("GET", "/pair?key=active-tabs", nil)
	if err != nil {
		t.Fatal(err)
	}
	rr := httptest.NewRecorder()
	handler := http.HandlerFunc(HandlePair)
	handler.ServeHTTP(rr, req)
	if status := rr.Code; status != http.StatusOK {
		t.Errorf("handler returned wrong status code: got %v want %v",
			status, http.StatusOK)
	}

	// Check the response body is what we expect.
	expected := `{"key":"active-tabs","value":"getir"}`
	if strings.TrimSuffix(rr.Body.String(), "\n") != string(expected) {
		t.Errorf("handler returned unexpected body: got %v want %v",
			rr.Body.String(), expected)
	}
}

func TestGetPairNotFound(t *testing.T) {
	req, err := http.NewRequest("GET", "/pair?key=active", nil)
	if err != nil {
		t.Fatal(err)
	}
	rr := httptest.NewRecorder()
	handler := http.HandlerFunc(HandlePair)
	handler.ServeHTTP(rr, req)
	if status := rr.Code; status != http.StatusBadRequest {
		t.Errorf("handler returned wrong status code: got %v want %v",
			status, http.StatusOK)
	}
}

func TestInsertPair(t *testing.T) {
	var jsonStr = []byte(`{"key":"active-tabs","value":"getir"}`)
	req, err := http.NewRequest("POST", "/pair", bytes.NewBuffer(jsonStr))
	if err != nil {
		t.Fatal(err)
	}
	rr := httptest.NewRecorder()
	handler := http.HandlerFunc(HandlePair)
	handler.ServeHTTP(rr, req)
	if status := rr.Code; status != http.StatusOK {
		t.Errorf("handler returned wrong status code: got %v want %v",
			status, http.StatusOK)
	}

	// Check the response body is what we expect.
	expected := `{"key":"active-tabs","value":"getir"}`
	if strings.TrimSuffix(rr.Body.String(), "\n") != string(expected) {
		t.Errorf("handler returned unexpected body: got %v want %v",
			rr.Body.String(), expected)
	}
}
