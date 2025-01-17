package com.sjprogramming.bankapp.service;

import java.util.List;

import com.sjprogramming.bankapp.entty.Account;

public interface AccountService {
	
	public Account createAccount(Account account);
	public Account getAccountDetailsByAccountNumber(Long accountnumber);
	public List<Account> getAllAccountDetails();
	public Account depositAmount(Long accountnumber, Double amount);
	public Account withdrawAmount(Long accountNumber, Double amount);
	public void closeAccount(Long accountNumber);
	
}
