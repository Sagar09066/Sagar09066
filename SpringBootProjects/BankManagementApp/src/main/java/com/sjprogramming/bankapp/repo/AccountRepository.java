package com.sjprogramming.bankapp.repo;

import org.springframework.data.jpa.repository.JpaRepository;

import com.sjprogramming.bankapp.entty.Account;

public interface AccountRepository extends JpaRepository<Account, Long>{
	
	
}
