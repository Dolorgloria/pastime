#pragma once

/*********************************************************************************
  *Copyright(C),2019-2020,Clementi.Inc
  *roughlogin.h: 
  *Author: Things brush away, deep in merit and name.
  *Version:v0.99  
  *Date:2020/9/13  
  *Description:  
  Function - loging in
  Interface - Account(string id, string passwd, bool invalidCharInId = false, bool invalidCharInPasswd = false, 
							int encryptionType = 0, int idMaxSize = 20, int passwdMaxSize = 20, int unique = -1)
  *Class List:  
     1.Account:Account is used to login in
     2.Passwd:Passwd stores passwords from account
	 3.Identity:Identity stores ID from account
  *History: 
     1.Date:
       Author:
       Modification:
     2.…………
**********************************************************************************/

/*********************************************************************************
 *	you are not expected to understand this,									 * 
 *  it's just a perfunctory.													 *
 *	for any troubles in using, just solve it by yourself.						 *
 *	Thank you for playing my code.												 *
 *											---  a heartful but unknow coder	 *
 *********************************************************************************/

#include<iostream>
#include<conio.h>
#include<string>
#include<stdlib.h>

//--Virginia--
#ifndef	_VIRGINIA 
#define key_VIRGINIA
	static std::string key_Virginia = "lemon";

void SetVirginaKey(std::string newKey);

std::string GetVirginaKey(void);
int GetVirginaKeySize(void);

std::string encryptVirginia(std::string beforeEncrypt);
std::string decryptVirginia(std::string beforeDecrypt);


void SetVirginaKey(std::string newKey) { key_Virginia = newKey; }

std::string GetVirginaKey(void) { return key_Virginia; }

int GetVirginaKeySize(void) { return key_Virginia.size(); }

std::string encryptVirginia(std::string beforeEncrypt) {
	std::string key;
	key.resize(beforeEncrypt.size()); 
	for(int i = 0; i < beforeEncrypt.size(); i++)
		key[i] = key_Virginia[i % key_Virginia.size()];

	for(int i = 0; i < beforeEncrypt.size(); i++)
		beforeEncrypt[i] = (beforeEncrypt[i] + key[i]) % 128;
	
	return beforeEncrypt;
}

std::string decryptVirginia(std::string beforeDecrypt) {
	std::string key;
	key.resize(beforeDecrypt.size());
	for(int i = 0; i < beforeDecrypt.size(); i++)
		key[i] = key_Virginia[i % key_Virginia.size()];

	for(int i = 0; i < beforeDecrypt.size(); i++)
		beforeDecrypt[i] = (beforeDecrypt[i] - key[i] + 128) % 128;

	return beforeDecrypt;
}
#endif

//--Caesar--
#ifndef _CAESAR
#define fun_CAESAR
	static int DEFAULT_OFFSET = 3;

int fun_Caesar(int letterToBeConvert);
	static auto caesarEncryptFun = &fun_Caesar;
int fun_arcCaesar(int letterConverted);
	static auto caesarDecryptFun = &fun_arcCaesar;

std::string GetCaesarEncryptFunInfo(void);
std::string GetCaesarDecryptFunInfo(void);
int GetCaesarOffset(void);

std::string encryptCaesar(std::string beforeEncrypt);
std::string decryptCaesar(std::string beforeDecrypt);


int fun_Caesar(int letterToBeConvert) {
	return (letterToBeConvert + DEFAULT_OFFSET) % 128;
}

int fun_arcCaesar(int letterConverted) {
	return (letterConverted - DEFAULT_OFFSET + 128) % 128;
}

std::string GetCaesarEncryptFunInfo(void) {
	if (caesarEncryptFun == &fun_Caesar)
		return std::string("default");
	else
		return std::string("custom");
}

std::string GetCaesarDecryptFunInfo(void) {
	if (caesarDecryptFun == &fun_arcCaesar)
		return std::string("default");
	else
		return std::string("custom");
}

int GetCaesarOffset(void) { return DEFAULT_OFFSET; }

std::string encryptCaesar(std::string beforeEncrypt) {
	for(int i = 0; i < beforeEncrypt.size(); i++)
		beforeEncrypt[i] = caesarEncryptFun((int)beforeEncrypt[i]);
	return beforeEncrypt;
}

std::string decryptCaesar(std::string beforeDecrypt) {
	for(int i = 0; i < beforeDecrypt.size(); i++)
		beforeDecrypt[i] = caesarDecryptFun((int)beforeDecrypt[i]);
	return beforeDecrypt;
}
#endif

//--Fence--
#ifndef _FENCE
#define _key_FENCE
	static int key_Fence = 4;	//default arrange infoemation to be enfencrypted as key_fence rows

int GetFenceEncryptKey(void);

std::string FormatStrForFence(std::string beforeFormat);

std::string encryptFence(std::string beforeEncrypt);
std::string decryptFence(std::string beforeDecrypt);


int GetFenceEncryptKey(void) { return key_Fence; }

std::string FormatStrForFence(std::string beforeFormat) {
	while(1)
	{
		size_t pos = beforeFormat.find(" "); 
		if(pos == beforeFormat.npos)
			 return beforeFormat;

		beforeFormat.erase(pos, 1);
	}
}

std::string encryptFence(std::string beforeEncrypt) {
	int offset = (beforeEncrypt.size() + key_Fence - 1) % key_Fence;
	std::string afterEncrypt(beforeEncrypt);
	int counter = 0;
	for (int i = 0; i < beforeEncrypt.size(); i++)
	{
		for (int j = 0; j < offset; j++)
		{
			afterEncrypt[j + counter * offset] = beforeEncrypt[i];
			counter++; 
			i++;
		}
		counter = 0;
	}
	return afterEncrypt;
}

std::string decryptFence(std::string beforeDecrypt) {
	int offset = (beforeDecrypt.size() + key_Fence - 1) % key_Fence;
	std::string afterDecrypt(beforeDecrypt);
	int counter = 0;
	for (int i = 0; i < beforeDecrypt.size(); i++)
	{
		for (int j = 0; j < offset; j++)
		{
			afterDecrypt[j + counter * offset] = beforeDecrypt[i];
			counter++;
			i++;
		}
		counter = 0;
	}
	return afterDecrypt;
}
#endif //_FENCE

#ifndef PASSWD_H
#define PASSWD_H
class Passwd
{
public:
	Passwd();
	Passwd(std::string passwdNo, int encryptionType = 0);
	Passwd(const Passwd& p);
	~Passwd();

	void setPasswd(std::string newPasswd);
	void setType(int newType);

	std::string getPasswd(void); 
	int getPasswdLenth(void);
	int getEncryptionType(void);

private:
	std::string PasswdNo;
	int EncryptionType;

/*
 *
 *
 *
 *EncryptionType means:
 * 0: no encryption, PasswdNo is plaintext
 * 1: Virginia encryption
 * 2: Caesar encryption
 * 3: Fence encryption
 * 4: ...
 * to be continued...
 *
 *
 */

};

Passwd::Passwd() { EncryptionType = 0; }

Passwd::Passwd(std::string a, int b = 0):PasswdNo(a),EncryptionType(b) { ; }

Passwd::Passwd(const Passwd& p) : PasswdNo(p.PasswdNo), EncryptionType(p.EncryptionType) { ; }

Passwd::~Passwd() { ; }

void Passwd::setPasswd(std::string a) { PasswdNo = a; }

void Passwd::setType(int a) { EncryptionType = a; }

std::string Passwd::getPasswd() { return PasswdNo; }

int Passwd::getPasswdLenth() { return PasswdNo.size(); }

int Passwd::getEncryptionType() { return EncryptionType; }
#endif


#ifndef _IDENTITY
#define _IDENTITY
class Identity
{
public:
	Identity();
	~Identity();
	Identity(std::string strIdentity);
	Identity(const Identity& I);

	void setIdentityStr(std::string newIdentityStr);

	int getIdentityLengh(void);
	std::string getIdentityStr(void);

private:
	std::string	IdentityStr;
};

Identity::Identity() { ; }

Identity::~Identity() { ; }

Identity::Identity(std::string strIdentity) :IdentityStr(strIdentity) { ; }

Identity::Identity(const Identity& I) : IdentityStr(I.IdentityStr) { ;  }

void Identity::setIdentityStr(std::string newIdentityStr) { IdentityStr = newIdentityStr; }

std::string Identity::getIdentityStr(void) { return IdentityStr; }

int Identity::getIdentityLengh(void) { return IdentityStr.size(); }

#endif //_IDENTITY

#ifndef _CHAR_TYPE	//some kinds of sensitive characters used in account is included here
#define _CHAR_TYPE	
	
	#ifndef _invalid_char
	char INVALID_CHAR[] = //the ASCII of invalid char
	{32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,
	 58,59,60,61,62,63,64,
	 91,92,93,94,95,96,
	 123,124,125,126};
	static int SUM_INVALID_CHAR = sizeof(INVALID_CHAR) / sizeof(char);
	#endif

	#ifndef _valid_char
	char VALID_CHAR[] =
	{
		// 0 ~ 9 
		48,49,50,51,52,53,54,55,56,57,
		// a ~ z
		65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,
		// A ~ Z
		97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122 };
	static int SUM_VALID_CHAR = sizeof(VALID_CHAR) / sizeof(char);
	#endif
#endif //_CHAR_TYPE


#ifndef _ACCOUNT
#define _ACCOUNT
	#ifndef DEFAULT_ACCOUNT_MAX_SIZE
		static int defaultPasswdMaxSize = 20;
		static int defaultIdMaxSize = 20;
	#endif

class Account
{
private:
	int Unique;
	Identity id;
	Passwd passwd;
	int idMaxSize;
	int passwdMaxSize;
	bool invalidPasswd;
	bool invalidIdentity;

public:
	Account();
	Account(std::string id, std::string passwd, bool invalidCharInId = false, bool invalidCharInPasswd = false,
		int encryptionType = 0, int idMaxSize = defaultIdMaxSize, int passwdMaxSize = defaultPasswdMaxSize, int unique = -1);
	Account(const Account& A);
	~Account();

	void setPasswd(std::string newPasswd);
	void setPasswd(Passwd newPasswd);
	void setId(std::string NewId);
	void setId(Identity newId);
	void setEncrytionType(int newType);
	void setUnique(int newUnique);

	int getUnique(void);
	int getIdMaxSize(void);
	int getPasswdMaxSize(void);
	int	getPasswdEncryptionType(void);
	std::string getPasswd_str(void);
	std::string getId_str(void);
	Identity	getId(void);
	Passwd	getPasswd(void);
};

Account::Account():id(),passwd()
{
	Unique = -1;
	passwdMaxSize = defaultPasswdMaxSize;
	idMaxSize = defaultIdMaxSize;
	invalidPasswd = false;
	invalidIdentity = false;
}

Account::Account(std::string id, std::string passwd, bool invalidCharInId = false, bool invalidCharInPasswd = false, int encryptionType = 0, int idMaxSize = defaultIdMaxSize, int passwdMaxSize = defaultPasswdMaxSize, int unique = -1)
	:id(id),passwd(passwd)
{
	Unique = unique;
	passwdMaxSize = passwdMaxSize;
	idMaxSize = idMaxSize;
	invalidIdentity = invalidCharInId;
	invalidPasswd = invalidCharInPasswd;
}

Account::Account(const Account& a) :id(a.id), passwd(a.passwd)
{
	Unique = a.Unique;
	passwdMaxSize = a.passwdMaxSize;
	idMaxSize = a.idMaxSize;
	invalidIdentity = a.invalidIdentity;
	invalidPasswd = a.invalidPasswd;
}

Account::~Account() { ; }

void Account::setUnique(int a) { srand((unsigned int)&a); Unique = rand(); }

void Account::setId(std::string newId) { id.setIdentityStr(newId); }

void Account::setId(Identity newId) { id = newId; }

void Account::setPasswd(std::string newPasswd) { passwd.setPasswd(newPasswd); }

void Account::setPasswd(Passwd newPasswd) { passwd = newPasswd; }

int Account::getUnique(void) { return Unique; }

int Account::getIdMaxSize(void) { return idMaxSize; }

int Account::getPasswdMaxSize(void) { return passwdMaxSize; }

int	Account::getPasswdEncryptionType(void) { return passwd.getEncryptionType(); }

std::string Account::getPasswd_str(void) { return passwd.getPasswd(); }

std::string Account::getId_str(void) { return id.getIdentityStr(); }

Identity Account::getId(void) { return id; }

Passwd Account::getPasswd(void) { return passwd; }

#endif _ACCOUNT

//public function list
bool checkInvalidCharInStr(std::string String);

bool checkInvalidCharInId(Account account);
bool checkInvalidCharInId(Identity Identity);

bool checkInvalidCharInPasswd(Account& account);
bool checkInvalidCharInPasswd(Passwd& passwd);


bool checkInvalidCharInStr(std::string String) {
	for(int i = 0; i < SUM_INVALID_CHAR; i++)
	{	if(String.find(INVALID_CHAR[i]) != String.npos) return true; }
	return false;
}

bool checkInvalidCharInId(Account account) {
	return checkInvalidCharInStr(account.getId_str());
}

bool checkInvalidCharInId(Identity identity) {
	return checkInvalidCharInStr(identity.getIdentityStr()); 
}

bool checkInvalidCharInPasswd(Account& account) {
	return checkInvalidCharInStr(account.getPasswd_str());
}

bool checkInvalidCharInPasswd(Passwd& passwd) {
	return checkInvalidCharInStr(passwd.getPasswd());
}


#ifdef UNIT_TEST_debug
	//examples:
std::string enterPasswd()
{
	int index = 0;
	while (1)
	{
		std::string newPasswd;
		std::cout << "请输入密码";
		char ch;
		while ((ch = _getch()) != '\r') {
			if (ch != '\b') {
				printf("*");
				newPasswd[index++] = ch;
			}
			else {
				printf("\b \b");
				index--;
			}
		}
	}
}

void enterAccount()
{
	std::string myPasswd, myId;
	Account myAccount;
	while (1)
	{
		while (1)
		{
			std::cout << "请输入账号：";
			std::cin >> myId;
			if (checkInvalidCharInStr(myId))
			{
				myAccount.setId(myId);
				break;
			}
			else
			{
				std::cout << "账号含有非法字符！请重新输入" << std::endl;
				continue;
			}
		}
		while (1)
		{
			myPasswd = enterPasswd();

			if (checkInvalidCharInStr(myPasswd))
			{
				std::cout << "欢迎进入！" << std::endl;
				break;
			}
			else
			{
				std::cout << "密码含有非法字符！请重新输入" << std::endl;
				continue;
			}
		}
	}
}

#endif //UNIT_TEST_debug

#ifdef UNIT_TEST_REALSE




#endif // UNIT_TEST_REALSE
