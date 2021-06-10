package main

import (
	"github.com/gin-gonic/gin"
)

func main() {
	//gin.SetMode(gin.ReleaseMode) 릴리즈 모드 활성화 하고 싶으면 주석 해제
	r := gin.Default()
	r.GET("/ping", func(c *gin.Context) {
		c.JSON(200, gin.H{
			"message": "pong",
		})
	})	
	r.Run(":3000") // port
}

