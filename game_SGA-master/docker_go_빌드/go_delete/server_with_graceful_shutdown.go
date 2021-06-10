package main

import (
	"context"
	"log"
	"net/http"
	"os"
	"os/signal"
	"syscall"
	"time"
)

var logger = log.New(os.Stdout, "", log.LstdFlags)

func main() {
	h := &HTTPHandler{}
	server := &http.Server{Addr: ":1202", Handler: h}

	// goroutine으로 서버 실행
	go func() {
		logger.Println("Start Server...")
		if err := server.ListenAndServe(); err != nil {
			logger.Printf("error: %v\n", err)
		}
	}()
	// OS SIGNAL을 수신할 chanel 생성
	signalChan := make(chan os.Signal, 1)
	// KILL, INTERRUPT, QUIT, TERM SIGNAL 수신 등록
	signal.Notify(
		signalChan,
		os.Interrupt,
		os.Kill,
		syscall.SIGQUIT, // kill -SIGQUIT XXXX
		syscall.SIGTERM,
	)
	// SIGNAL 수신
	sig := <-signalChan
	logger.Printf("Received SIGNAL: %v\n", sig)
	// timeout을 위한 context 생성
	ctx, cancel := context.WithTimeout(context.Background(), 10*time.Second)
	defer cancel()
	logger.Println("Close Server...")
	// context에 지정한 timeout만큼 shutdown 지연
	if err := server.Shutdown(ctx); err != nil {
		logger.Printf("error: %v\n", err)
	}
}

type HTTPHandler struct{}

func (h *HTTPHandler) ServeHTTP(res http.ResponseWriter, req *http.Request) {
	logger.Println("Receive Request...")
	time.Sleep(5 * time.Second)
	res.WriteHeader(http.StatusOK)
	res.Write([]byte("OK\n"))
	logger.Println("Send Response...")
}
