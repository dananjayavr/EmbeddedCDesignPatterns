cmake_minimum_required(VERSION 3.15)

project(EmbeddedDesignPatterns
  VERSION 1.0
  DESCRIPTION "Code along with the book"
  LANGUAGES C)

add_executable(sensor chapter_1/sensor.c chapter_1/sensor.h chapter_1/sensor_main.c)
add_executable(queue chapter_1/queue.c chapter_1/queue.h chapter_1/queue_main.c)