package com.sjprogramming.bankapp.controller;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import com.sjprogramming.bankapp.entty.Account;
import com.sjprogramming.bankapp.service.AccountService;

@RestController
@RequestMapping("/account")
public class AccountController {
	
	// Create the account
	
	@Autowired
	AccountService service;

	@PostMapping("/create")
	public ResponseEntity<Account> createAccount(@RequestBody Account account ) {
		
		Account createAccount = service.createAccount(account);
		return ResponseEntity.status(HttpStatus.CREATED).body(createAccount);
	}
	
	@GetMapping("/accountDetails/{accountNumber}")
	public Account getAccountByAccountNumber(@PathVariable Long accountNumber) {
		Account account = service.getAccountDetailsByAccountNumber(accountNumber);
		return account;
	}
	
	@GetMapping("/{getAllAccounts}")
	public List<Account> getAllAccountDetals(){
		List<Account> allAccountDetals = service.getAllAccountDetails();
		return allAccountDetals;
	}
	
	@PutMapping("/depost/{accountNumber}/{amount}")
	public Account depositAccount(@PathVariable Long accountNumber, @PathVariable Double amount) {
		
		Account account = service.depositAmount(accountNumber, amount);
		return account;
	}
	
	@PutMapping("/withdraw/{accountNumber}/{amount}")
	public Account withdrawAmount(@PathVariable Long accountNumber, @PathVariable Double amount) {
		
		Account account = service.withdrawAmount(accountNumber,amount);
		return account;
	}
	
	@DeleteMapping("/delete/{accountNumber}")
	public ResponseEntity<String> deleteAccount(@PathVariable Long accountNumber){
		service.closeAccount(accountNumber);
		return ResponseEntity.status(HttpStatus.OK).body("Account Closed");
		
	}
}
