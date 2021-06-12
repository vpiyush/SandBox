package main

import (
	"encoding/json"
	"fmt"
	"github.com/gorilla/mux"
	"log"
	"net/http"
)

type container struct {
	containerType string   `json:"container_type"` // course/subject
	name          string   `json:"name"`
	desc          string   `json:"desc"`
	videos        []string `json:"videos"`
	webinars      []string `json:"webinars"`
}

type tags struct {
	name string
}

type content struct {
	contentType string   `json:"content_type"` // video/webinar
	title       string   `json:"title"`
	desc        string   `json:"desc"`
	courses     []string `json:"courses"`
	subjects    []string `json:"subjects"`
	tagNames    []string `json:"tags"`
}

type managerDb struct {
	containers []container
	contents   []content
}

type Manager struct {
	mxRouter *mux.Router
	mDb      *managerDb
}

func (this *Manager) Initialize() {
	this.mxRouter = mux.NewRouter()
	this.mDb = new(managerDb)
	this.mxRouter.HandleFunc("/create", this.createCourse)
	this.mxRouter.HandleFunc("/list", this.listCourse)
	this.mxRouter.HandleFunc("/upload", this.upload)
}

func (this *Manager) Start(listener string) {
	log.Fatal(http.ListenAndServe(listener, this.mxRouter))
}

func sendJsonResponse(w http.ResponseWriter, code int, respLoad interface{}) {
	resp, _ := json.Marshal(respLoad)
	w.Header().Set("Content-Type", "application/json")
	w.WriteHeader(code)
	w.Write(resp)
}

func sendErrorResponse(w http.ResponseWriter, code int, message string) {
	respLoad := map[string]string{"error": message}
	sendJsonResponse(w, code, respLoad)
}

func (this *Manager) createCourse(w http.ResponseWriter, r *http.Request) {
	var course container
	decoder := json.NewDecoder(r.Body)
	if err := decoder.Decode(&course); err != nil {

		sendErrorResponse(w, http.StatusBadRequest, "Malformed Request Payload")
	}
	this.mDb.containers = append(this.mDb.containers, course)
	fmt.Println("creating course")
}

func (this *Manager) listCourse(w http.ResponseWriter, r *http.Request) {
	fmt.Println("listing all courses")
	sendJsonResponse(w, 200, this.mDb.containers)
}

func (this *Manager) upload(w http.ResponseWriter, r *http.Request) {
	var video content
	decoder := json.NewDecoder(r.Body)
	if err := decoder.Decode(&video); err != nil {

		sendErrorResponse(w, http.StatusBadRequest, "Malformed Request Payload")
	}
	this.mDb.contents = append(this.mDb.contents, video)
	fmt.Println("uploading video/webinar")
}

func (*Manager) findContent(w http.ResponseWriter, r *http.Request) {
	fmt.Println("listing all courses")
}
