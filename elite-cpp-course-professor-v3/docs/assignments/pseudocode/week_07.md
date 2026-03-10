# Pseudocode — Week 07


Vector stores:
  raw pointer
  size
  capacity

push_back(value):
  if full:
    grow
  construct value at next slot
  increase size

grow():
  allocate larger raw storage
  move/copy live elements
  destroy old live elements
  free old storage
  update pointer and capacity
