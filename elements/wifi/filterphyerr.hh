#ifndef CLICK_FILTERPHYERR_HH
#define CLICK_FILTERPHYERR_HH
#include <click/element.hh>
#include <click/etheraddress.hh>
#include <click/bighashmap.hh>
#include <click/glue.hh>
CLICK_DECLS

/*
=c
FilterPhyErr([I<KEYWORDS>])

=s Wifi

Filters packets that failed the 802.11 CRC check.

=d
Filters out packets that have the phy err annotation set
in the wifi_extra_header, and sends these packets to output 1 
if it is present.

=a ExtraDecap, ExtraEncap
*/


class FilterPhyErr : public Element { public:
  
  FilterPhyErr();
  ~FilterPhyErr();
  
  const char *class_name() const		{ return "FilterPhyErr"; }
  const char *processing() const		{ return "a/ah"; }

  void notify_noutputs(int);
  int configure(Vector<String> &, ErrorHandler *);

  void add_handlers();
  Packet *simple_action(Packet *);  


  int _drops;


};

CLICK_ENDDECLS
#endif