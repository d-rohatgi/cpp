# Pseudocode — Week 03


Class BankAccount:
  owner
  balance

deposit(amount):
  if amount invalid:
    fail
  else:
    increase balance

withdraw(amount):
  if amount invalid or too large:
    fail
  else:
    decrease balance
