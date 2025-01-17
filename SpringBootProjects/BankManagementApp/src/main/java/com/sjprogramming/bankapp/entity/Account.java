package com.sjprogramming.bankapp.entty;

import jakarta.persistence.Entity;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.GenerationType;
import jakarta.persistence.Id;
import jakarta.persistence.Table;

@Entity
@Table(name = "Account")
public class Account {
	
	@Id
	@GeneratedValue(strategy = GenerationType.IDENTITY)
	private Long acount_number;
	private String account_holder_name;
	private Double account_balance;
	
	public Account() {
		super();
		// TODO Auto-generated constructor stub
	}
	
	public Account(String account_holder_name, Double account_balance) {
		super();
		this.account_holder_name = account_holder_name;
		this.account_balance = account_balance;
	}
	
	public Long getAcount_number() {
		return acount_number;
	}
	
	public void setAcount_number(Long acount_number) {
		this.acount_number = acount_number;
	}
	
	public String getAccount_holder_name() {
		return account_holder_name;
	}
	
	public void setAccount_holder_name(String account_holder_name) {
		this.account_holder_name = account_holder_name;
	}
	
	public Double getAccount_balance() {
		return account_balance;
	}
	
	public void setAccount_balance(Double account_balance) {
		this.account_balance = account_balance;
	}
	
	@Override
	public String toString() {
		return "Account [acount_number=" + acount_number + ", account_holder_name=" + account_holder_name
				+ ", account_balance=" + account_balance + "]";
	}
}
