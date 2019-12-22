/*
 * QEMU TCP Tunnelling
 *
 * Copyright (c) 2019 Lev Aronsky <aronsky@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef HW_ARM_GUEST_SERVICES_SOCKET_H
#define HW_ARM_GUEST_SERVICES_SOCKET_H

#include "qemu/osdep.h"

#define MAX_BUF_SIZE (4096)

typedef struct __attribute__((packed)) {
    int32_t domain;
    int32_t type;
    int32_t protocol;
} qc_socket_args_t;

typedef struct __attribute__((packed)) {
    int32_t socket;
    struct sockaddr *addr;
    socklen_t *addrlen;
} qc_accept_args_t;

typedef struct __attribute__((packed)) {
    int32_t socket;
    struct sockaddr *addr;
    socklen_t addrlen;
} qc_bind_args_t;

typedef struct __attribute__((packed)) {
    int32_t socket;
    struct sockaddr *addr;
    socklen_t addrlen;
} qc_connect_args_t;

typedef struct __attribute__((packed)) {
    int32_t socket;
    int32_t backlog;
} qc_listen_args_t;

typedef struct __attribute__((packed)) {
    int32_t socket;
    void *buffer;
    size_t length;
    int flags;
} qc_recv_args_t;

typedef struct __attribute__((packed)) {
    int32_t socket;
    void *buffer;
    size_t length;
    int flags;
} qc_send_args_t;

typedef struct __attribute__((packed)) {
    int32_t socket;
} qc_close_args_t;

int32_t qc_socket(CPUState *cpu, int32_t domain, int32_t type,
                  int32_t protocol);
int32_t qc_accept(CPUState *cpu, int32_t sckt, struct sockaddr *addr,
                  socklen_t *addrlen);
int32_t qc_bind(CPUState *cpu, int32_t sckt, struct sockaddr *addr,
                socklen_t addrlen);
int32_t qc_connect(CPUState *cpu, int32_t sckt, struct sockaddr *addr,
                   socklen_t addrlen);
int32_t qc_listen(CPUState *cpu, int32_t sckt, int32_t backlog);
int32_t qc_recv(CPUState *cpu, int32_t sckt, void *buffer, size_t length,
                int32_t flags);
int32_t qc_send(CPUState *cpu, int32_t sckt, void *buffer, size_t length,
                int32_t flags);
int32_t qc_close(CPUState *cpu, int32_t sckt);

extern int32_t qemu_socket_errno;

#endif // HW_ARM_GUEST_SERVICES_SOCKET_H