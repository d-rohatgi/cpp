# Pseudocode — Week 06


Node:
  value
  next

push_front(x):
  allocate node
  point node.next to head
  update head

clear():
  while head exists:
    save next
    delete current
    advance
