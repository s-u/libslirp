SRC=$(wildcard *.c)
OBJ=$(SRC:%.c=%.o)

RANLIB=ranlib

libslirp.a: $(OBJ)
	rm -f $@
	$(AR) -q $@ $(OBJ)
	$(RANLIB) $@

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c -I. $<

clean:
	rm -f $(OBJ) libslirp.a

arp_table.o: arp_table.c slirp.h debug.h util.h glib.h libslirp.h \
  libslirp-version.h ip.h ip6.h tcp.h tcp_var.h tcpip.h tcp_timer.h \
  udp.h socket.h misc.h sbuf.h ip_icmp.h ip6_icmp.h mbuf.h if.h main.h \
  bootp.h tftp.h
bootp.o: bootp.c slirp.h debug.h util.h glib.h libslirp.h \
  libslirp-version.h ip.h ip6.h tcp.h tcp_var.h tcpip.h tcp_timer.h \
  udp.h socket.h misc.h sbuf.h ip_icmp.h ip6_icmp.h mbuf.h if.h main.h \
  bootp.h tftp.h
cksum.o: cksum.c slirp.h debug.h util.h glib.h libslirp.h \
  libslirp-version.h ip.h ip6.h tcp.h tcp_var.h tcpip.h tcp_timer.h \
  udp.h socket.h misc.h sbuf.h ip_icmp.h ip6_icmp.h mbuf.h if.h main.h \
  bootp.h tftp.h
dhcpv6.o: dhcpv6.c slirp.h debug.h util.h glib.h libslirp.h \
  libslirp-version.h ip.h ip6.h tcp.h tcp_var.h tcpip.h tcp_timer.h \
  udp.h socket.h misc.h sbuf.h ip_icmp.h ip6_icmp.h mbuf.h if.h main.h \
  bootp.h tftp.h dhcpv6.h
dnssearch.o: dnssearch.c slirp.h debug.h util.h glib.h libslirp.h \
  libslirp-version.h ip.h ip6.h tcp.h tcp_var.h tcpip.h tcp_timer.h \
  udp.h socket.h misc.h sbuf.h ip_icmp.h ip6_icmp.h mbuf.h if.h main.h \
  bootp.h tftp.h
glib.o: glib.c glib.h
if.o: if.c slirp.h debug.h util.h glib.h libslirp.h libslirp-version.h \
  ip.h ip6.h tcp.h tcp_var.h tcpip.h tcp_timer.h udp.h socket.h misc.h \
  sbuf.h ip_icmp.h ip6_icmp.h mbuf.h if.h main.h bootp.h tftp.h
ip6_icmp.o: ip6_icmp.c slirp.h debug.h util.h glib.h libslirp.h \
  libslirp-version.h ip.h ip6.h tcp.h tcp_var.h tcpip.h tcp_timer.h \
  udp.h socket.h misc.h sbuf.h ip_icmp.h ip6_icmp.h mbuf.h if.h main.h \
  bootp.h tftp.h
ip6_input.o: ip6_input.c slirp.h debug.h util.h glib.h libslirp.h \
  libslirp-version.h ip.h ip6.h tcp.h tcp_var.h tcpip.h tcp_timer.h \
  udp.h socket.h misc.h sbuf.h ip_icmp.h ip6_icmp.h mbuf.h if.h main.h \
  bootp.h tftp.h
ip6_output.o: ip6_output.c slirp.h debug.h util.h glib.h libslirp.h \
  libslirp-version.h ip.h ip6.h tcp.h tcp_var.h tcpip.h tcp_timer.h \
  udp.h socket.h misc.h sbuf.h ip_icmp.h ip6_icmp.h mbuf.h if.h main.h \
  bootp.h tftp.h
ip_icmp.o: ip_icmp.c slirp.h debug.h util.h glib.h libslirp.h \
  libslirp-version.h ip.h ip6.h tcp.h tcp_var.h tcpip.h tcp_timer.h \
  udp.h socket.h misc.h sbuf.h ip_icmp.h ip6_icmp.h mbuf.h if.h main.h \
  bootp.h tftp.h
ip_input.o: ip_input.c slirp.h debug.h util.h glib.h libslirp.h \
  libslirp-version.h ip.h ip6.h tcp.h tcp_var.h tcpip.h tcp_timer.h \
  udp.h socket.h misc.h sbuf.h ip_icmp.h ip6_icmp.h mbuf.h if.h main.h \
  bootp.h tftp.h
ip_output.o: ip_output.c slirp.h debug.h util.h glib.h libslirp.h \
  libslirp-version.h ip.h ip6.h tcp.h tcp_var.h tcpip.h tcp_timer.h \
  udp.h socket.h misc.h sbuf.h ip_icmp.h ip6_icmp.h mbuf.h if.h main.h \
  bootp.h tftp.h
mbuf.o: mbuf.c slirp.h debug.h util.h glib.h libslirp.h \
  libslirp-version.h ip.h ip6.h tcp.h tcp_var.h tcpip.h tcp_timer.h \
  udp.h socket.h misc.h sbuf.h ip_icmp.h ip6_icmp.h mbuf.h if.h main.h \
  bootp.h tftp.h
misc.o: misc.c slirp.h debug.h util.h glib.h libslirp.h \
  libslirp-version.h ip.h ip6.h tcp.h tcp_var.h tcpip.h tcp_timer.h \
  udp.h socket.h misc.h sbuf.h ip_icmp.h ip6_icmp.h mbuf.h if.h main.h \
  bootp.h tftp.h
ncsi.o: ncsi.c slirp.h debug.h util.h glib.h libslirp.h \
  libslirp-version.h ip.h ip6.h tcp.h tcp_var.h tcpip.h tcp_timer.h \
  udp.h socket.h misc.h sbuf.h ip_icmp.h ip6_icmp.h mbuf.h if.h main.h \
  bootp.h tftp.h ncsi-pkt.h
ndp_table.o: ndp_table.c slirp.h debug.h util.h glib.h libslirp.h \
  libslirp-version.h ip.h ip6.h tcp.h tcp_var.h tcpip.h tcp_timer.h \
  udp.h socket.h misc.h sbuf.h ip_icmp.h ip6_icmp.h mbuf.h if.h main.h \
  bootp.h tftp.h
sbuf.o: sbuf.c slirp.h debug.h util.h glib.h libslirp.h \
  libslirp-version.h ip.h ip6.h tcp.h tcp_var.h tcpip.h tcp_timer.h \
  udp.h socket.h misc.h sbuf.h ip_icmp.h ip6_icmp.h mbuf.h if.h main.h \
  bootp.h tftp.h
slirp.o: slirp.c slirp.h debug.h util.h glib.h libslirp.h \
  libslirp-version.h ip.h ip6.h tcp.h tcp_var.h tcpip.h tcp_timer.h \
  udp.h socket.h misc.h sbuf.h ip_icmp.h ip6_icmp.h mbuf.h if.h main.h \
  bootp.h tftp.h
socket.o: socket.c slirp.h debug.h util.h glib.h libslirp.h \
  libslirp-version.h ip.h ip6.h tcp.h tcp_var.h tcpip.h tcp_timer.h \
  udp.h socket.h misc.h sbuf.h ip_icmp.h ip6_icmp.h mbuf.h if.h main.h \
  bootp.h tftp.h
state.o: state.c slirp.h debug.h util.h glib.h libslirp.h \
  libslirp-version.h ip.h ip6.h tcp.h tcp_var.h tcpip.h tcp_timer.h \
  udp.h socket.h misc.h sbuf.h ip_icmp.h ip6_icmp.h mbuf.h if.h main.h \
  bootp.h tftp.h vmstate.h stream.h
stream.o: stream.c stream.h libslirp.h libslirp-version.h glib.h
tcp_input.o: tcp_input.c slirp.h debug.h util.h glib.h libslirp.h \
  libslirp-version.h ip.h ip6.h tcp.h tcp_var.h tcpip.h tcp_timer.h \
  udp.h socket.h misc.h sbuf.h ip_icmp.h ip6_icmp.h mbuf.h if.h main.h \
  bootp.h tftp.h
tcp_output.o: tcp_output.c slirp.h debug.h util.h glib.h libslirp.h \
  libslirp-version.h ip.h ip6.h tcp.h tcp_var.h tcpip.h tcp_timer.h \
  udp.h socket.h misc.h sbuf.h ip_icmp.h ip6_icmp.h mbuf.h if.h main.h \
  bootp.h tftp.h
tcp_subr.o: tcp_subr.c slirp.h debug.h util.h glib.h libslirp.h \
  libslirp-version.h ip.h ip6.h tcp.h tcp_var.h tcpip.h tcp_timer.h \
  udp.h socket.h misc.h sbuf.h ip_icmp.h ip6_icmp.h mbuf.h if.h main.h \
  bootp.h tftp.h
tcp_timer.o: tcp_timer.c slirp.h debug.h util.h glib.h libslirp.h \
  libslirp-version.h ip.h ip6.h tcp.h tcp_var.h tcpip.h tcp_timer.h \
  udp.h socket.h misc.h sbuf.h ip_icmp.h ip6_icmp.h mbuf.h if.h main.h \
  bootp.h tftp.h
tftp.o: tftp.c slirp.h debug.h util.h glib.h libslirp.h \
  libslirp-version.h ip.h ip6.h tcp.h tcp_var.h tcpip.h tcp_timer.h \
  udp.h socket.h misc.h sbuf.h ip_icmp.h ip6_icmp.h mbuf.h if.h main.h \
  bootp.h tftp.h
udp.o: udp.c slirp.h debug.h util.h glib.h libslirp.h libslirp-version.h \
  ip.h ip6.h tcp.h tcp_var.h tcpip.h tcp_timer.h udp.h socket.h misc.h \
  sbuf.h ip_icmp.h ip6_icmp.h mbuf.h if.h main.h bootp.h tftp.h
udp6.o: udp6.c slirp.h debug.h util.h glib.h libslirp.h \
  libslirp-version.h ip.h ip6.h tcp.h tcp_var.h tcpip.h tcp_timer.h \
  udp.h socket.h misc.h sbuf.h ip_icmp.h ip6_icmp.h mbuf.h if.h main.h \
  bootp.h tftp.h dhcpv6.h
util.o: util.c util.h glib.h libslirp.h libslirp-version.h
version.o: version.c libslirp.h libslirp-version.h
vmstate.o: vmstate.c glib.h stream.h libslirp.h libslirp-version.h \
  vmstate.h slirp.h debug.h util.h ip.h ip6.h tcp.h tcp_var.h tcpip.h \
  tcp_timer.h udp.h socket.h misc.h sbuf.h ip_icmp.h ip6_icmp.h mbuf.h \
  if.h main.h bootp.h tftp.h
