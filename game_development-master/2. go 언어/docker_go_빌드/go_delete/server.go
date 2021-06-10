package main

import (
	"context"
	"fmt"
	"net/http"
	"os"
	"os/signal"
	"syscall"
	"time"
)

func main() {
	h := &HTTPHandler{}
	server := &http.Server{Addr: ":1202", Handler: h}
	if err := server.ListenAndServe(); err != nil {
		fmt.Printf("error: %v\n", err)
	}
}

type HTTPHandler struct{}

func (h *HTTPHandler) ServeHTTP(res http.ResponseWriter, req *http.Request) {
	res.WriteHeader(http.StatusOK)
	res.Write([]byte("OK\n"))
}
