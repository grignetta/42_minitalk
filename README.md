# minitalk (with bonus)

A tiny client–server IPC using **UNIX signals**.  
The **server** prints any message sent by the **client**, transmitting data **bit‑by‑bit** with `SIGUSR1`/`SIGUSR2`.

---

## Clone (with submodules)

> `ft_printf` is a Git submodule. It also contains `libft` as a **nested** submodule.  
> Clone **recursively** to pull everything in one go.

```bash
git clone --recurse-submodules https://github.com/grignetta/42_ft_printf.git minitalk
git submodule update --init --recursive
```

---

## Build
Use **make** to create 'server' and 'client' executables
The Makefile automatically builds `lib/ft_printf`.

---

## Usage

1. Start the **server** (it prints its PID):

   ```bash
   ./server
   # Example:
   # Server PID: 42421
   ```

2. In another shell, run the **client** with the server PID and your message:

   ```bash
   ./client 42421 "Hello from minitalk!"
   ```

3. The message appears in the server terminal.

**Notes**

- Quote messages that contain spaces.
- Works on the **same machine** (signals are local to the OS instance).
- The client exits after it sends the full message (ending with `'\0'`).

---

## Features

- **Pure signals IPC** — no sockets, no pipes; just `SIGUSR1`/`SIGUSR2`.
- **Bit encoding** — client sends `1` as `SIGUSR1` and `0` as `SIGUSR2`.
- **Dynamic buffering** — the server grows its internal buffer automatically, so **long messages** are supported.
- **Multiple clients handling** — the server can print messages sequentially, one after another from different clients.

---

## Bonus (included in normal make)

This project includes the typical Minitalk bonus improvements:

- ✅ **Per‑bit acknowledgments** - the server answers each received bit with an acknowledgement message (`SIGUSR1`), and the client waits before sending the next bit.
- ✅ **UTF-8 "Unicode" strings supported** — bytes are forwarded intact; make sure your terminal uses UTF-8.


---

## Protocol (quick overview)

- The client converts each character into 8 bits (MSB → LSB).  
  - **1** → `SIGUSR1`  
  - **0** → `SIGUSR2`
- The server accumulates bits into a byte. When 8 bits are collected:
  - If the byte is `\\0`, the server prints the current buffer and resets for the next message.
  - Otherwise it appends the byte to its buffer.
- After **each bit**, the server sends an acknowledgement message (`SIGUSR1`) back to the client (bonus part).
- The client waits for the acknowledgement message before sending the next bit.
