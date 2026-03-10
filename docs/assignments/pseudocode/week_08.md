# Pseudocode — Week 08


UniquePtr:
  owns exactly one pointer
  move transfers ownership

SharedPtr:
  holds pointer + ref count
  copy increments count
  destruction decrements count
  delete object when count reaches zero
