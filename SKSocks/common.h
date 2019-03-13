#pragma once

// SK ������ַ�� https://www.fou.ink/

/*

	Copyright [2019] [Saurik QQ 1764655874]

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

	http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

		ʹ�ã����߼�����á����ա����ƣ����ļ������������ݣ�����Ŀ�������ע����Դ�����ұ���������λ������ �����˱��ļ���

		�����ע�����ԭ�����Լ���ϸ��ϵ��ʽ��

		����������շ�����������������˵��������ǿ�����ѻ�õģ��û�֧�����Ǽ���������ã�����˰��
		Saurik�����������������������߹����������ı�Ĳ�Ʒ�����������Ľ�����������ӭ��SaurikǢ̸��

*/

/*
	***********************************************************
	* �����޸ı��ļ����κ����ݡ����ļ�ΪSK Socks�����ļ���
	* �����ʹ���˱��ļ�����ע�Ȿ�ļ���ֹ���޸ġ�
	* ��л������⡣

	* ��ʵ��
	* �������
	* Զ������
	* ֱ��3+2
	* ����վ����
	* ��������΢�š�QQ��
	* ��������
	* ��ZFB����ʶ��V���޶��ȡ
	* DDOSѹ������
	* �߱��������
	* �������ļ��ף���SFZ���Ƕܡ�YH�ǡ��绰�ǣ�
	* ˢQQ��Ա��QQ��
	* ����Ҫʵ�����������ۣ�7��8GB��10Ԫ15GB��20Ԫ40GB��30Ԫ60GB��40Ԫ100G��50Ԫ150G��60Ԫ200G��
	* ����ר��170�����ֻ�˽��ʵ���ڿ�
	* WEB��ȫ���ԣ�����Ȩ����getshell
	* SK�Ŷ� רҵ��ֹ�߱�
	* ����ϵ QQ 1764655874

*/

#ifndef _WIN32
#define INVALID_SOCKET  (SOCKET)(~0)
#define SOCKET_ERROR            (-1)
#define SOCKADDR sockaddr
#define SOCKADDR_IN sockaddr_in
#define strcpy_s strcpy
#define sprintf_s sprintf
#endif

#define BUFF_SIZE 500ULL   //����ת��������
#define TIME_OUT 6000000UL //���ø���IO��ʱ
#define CLIENT_TIME_OUT 6000000UL
#define PKG_TRANSFER_TIME_OUT 5000UL

#define SK_Halo "SK Socket!"

#define SK_Conn 1001
#define SK_ServerConfigFile "server.hpp"
#define SK_ClientConfigFile "client.hpp"
#define SK_ServerUserFile "ufile.txt"

#define SK_Conn_IPV6 0x1
#define SK_Conn_IPV4 0x2 // IPV4
#define SK_Conn_LocalIPV4 0x4 // ����IPV4�����Է��ʹ�����IPV6
#define SK_Crypt_Xor 0x1 // ���
#define SK_Crypt_RSA 0x2 // RSA
#define SK_Crypt_AES 0x4
#define SK_Crypt_DES 0x8
#define SK_Crypt_RSA_AES 0x10 // RSA����AES�ܳף��Ƽ�����ȫ��
#define SK_AUTH_NO 0x1ULL
#define SK_AUTH_IMAGE 0x2ULL // ͼƬ��֤��
#define SK_AUTH_USER 0x4ULL // �û�������
#define SK_AUTH_IMAGE_USER 0x8ULL // �û��������Լ�ͼƬ��֤�루�Ƽ���

typedef struct SK_ConnInfo
{
	typedef unsigned char CBYTE;
	CBYTE cConnIPFlag = SK_Conn_IPV4;
	CBYTE cConnCryptType = SK_Crypt_Xor;
	CBYTE cConnAuthType = SK_AUTH_NO;
	CBYTE cConnReserve = 0; //����
	unsigned short cConnPort = 0;
	char theDomain[0xff] = { 0 };
}SK_ConInfo, *PSK_ConInfo;

#define SK_Pkg_Crypted 1ULL
#define SK_Pkg_Decrypted 0ULL
typedef struct SK_Package
{
	typedef unsigned long long uint64_t;
	typedef unsigned char CBYTE;
	CBYTE qwType = SK_Pkg_Decrypted;
	CBYTE qwCryptType = SK_Crypt_Xor;
	char lpMemory[BUFF_SIZE] = { 0 };
	char ExtraData[64ULL] = { 0 };
	uint64_t qwVerify = 0ULL;
	uint64_t qwDataLen = 0ULL;
	uint64_t qwReserve = 0ULL;
} SK_Pkg, *PSK_Pkg;

#define SK_Auth_Session 1ULL
#define SK_Auth_First 2ULL
#define SK_Auth_Once 3ULL
#define SK_Auth_Always 4ULL
#define SK_Auth_Captcha 5ULL
#define SK_Auth_Failed 6ULL
#define SK_Auth_Success 7ULL
#define SK_Auth_Success_And_GetSession 8ULL
#define SK_Auth_Success_And_GetToken 9ULL
#define SK_Auth_UserNamePwd 10ULL
#define SK_Auth_IP_Restrict 11ULL
#define SK_Auth_Master 12ULL
#define SK_Auth_GetSession 13ULL
#define SK_Auth_Version "1.0"

#define SK_Auth_Incorrect 0ULL
#define SK_Auth_Ok 1ULL
#define SK_Auth_Need_Captcha 2ULL
#define SK_Auth_Need_User 3ULL
#define SK_Auth_Need_User_And_Captcha 4ULL

#define SK_Session_Key_Len 16ULL
#define SK_Auth_UNAME_PWD_Len 32ULL

typedef struct SK_Auth_Session_Pkg
{
	char lpUserSession[SK_Session_Key_Len] = { 0 };
}SK_Session_Pkg, *PSK_Session_Pkg;

typedef struct SK_OAuth_Pkg
{
	typedef unsigned long long UINT64;
	char lpUserData[SK_Auth_UNAME_PWD_Len] = { 0 };
	char lpPassword[SK_Auth_UNAME_PWD_Len] = { 0 };
	UINT64 lpReserve = 0ULL;
}SK_Auth_Pkg, *PSK_Auth_Pkg;


