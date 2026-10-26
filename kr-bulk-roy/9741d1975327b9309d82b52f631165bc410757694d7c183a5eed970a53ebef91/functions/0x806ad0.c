
void FUN_00806ad0(char *param_1,u_short param_2,int param_3,SOCKET param_4)

{
  HANDLE FileHandle;
  int iVar1;
  SOCKET *CompletionKey;
  hostent *phVar2;
  SOCKET s;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int in_ECX;
  undefined1 auStack_2c [4];
  char local_28 [4];
  int local_24;
  SOCKET *local_20;
  sockaddr local_1c;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)auStack_2c;
  local_24 = in_ECX;
  if (DAT_00fba858 == 0) {
    if (DAT_00fba85c == 0) {
      FUN_0049b000();
    }
    else {
      FUN_0049af60();
    }
  }
  CompletionKey = (SOCKET *)FUN_00805950(1);
  if (CompletionKey != (SOCKET *)0x0) {
    CompletionKey[0x282d] = 2;
    CompletionKey[0x2820] = param_4;
    phVar2 = gethostbyname(param_1);
    FID_conflict__memcpy(local_1c.sa_data + 2,*phVar2->h_addr_list,(int)phVar2->h_length);
    local_1c.sa_family = 2;
    local_1c.sa_data._0_2_ = htons(param_2);
    s = WSASocketA(2,1,0,0,0,1);
    *CompletionKey = s;
    iVar3 = connect(s,&local_1c,0x10);
    if (iVar3 == -1) {
      if (*(int *)(in_ECX + 0x58) != 0) {
        iVar3 = WSAGetLastError();
        FUN_006f0400(2,"Connection failed : Errorcode[%d]",iVar3);
      }
      if (DAT_00fba858 == 0) {
        if (DAT_00fba85c != 0) {
          FUN_0049af60();
          FUN_00805af0(CompletionKey);
          __security_check_cookie(local_c ^ (uint)auStack_2c);
          return;
        }
        FUN_0049b000();
      }
      FUN_00805af0(CompletionKey);
    }
    else {
      FileHandle = (HANDLE)*CompletionKey;
      local_28[0] = '\0';
      local_28[1] = '\0';
      local_28[2] = '\0';
      local_28[3] = '\0';
      iVar3 = setsockopt((SOCKET)FileHandle,6,1,local_28,4);
      if (iVar3 != -1) {
        local_28[0] = '\0';
        local_28[1] = '@';
        local_28[2] = '\0';
        local_28[3] = '\0';
        iVar3 = setsockopt((SOCKET)FileHandle,0xffff,0x1002,local_28,4);
        if (iVar3 != -1) {
          local_28[0] = '\0';
          local_28[1] = -0x80;
          local_28[2] = '\0';
          local_28[3] = '\0';
          iVar3 = setsockopt((SOCKET)FileHandle,0xffff,0x1001,local_28,4);
          if (iVar3 != -1) {
            puVar4 = (undefined4 *)FUN_00806620();
            CreateIoCompletionPort(FileHandle,(HANDLE)*puVar4,(ULONG_PTR)CompletionKey,0);
            iVar1 = local_24;
            iVar3 = local_24 + 0x18;
            FUN_008438c0(&param_3);
            if (local_24 != *(int *)(iVar1 + 0x1c)) {
              FUN_007b6890(iVar3,&local_24,local_24);
            }
            local_24 = param_3;
            local_20 = CompletionKey;
            uVar5 = FUN_0057ef20();
            FUN_0057e850(iVar3,uVar5);
            goto LAB_00806cd7;
          }
        }
      }
    }
    __security_check_cookie(local_c ^ (uint)auStack_2c);
    return;
  }
LAB_00806cd7:
  __security_check_cookie(local_c ^ (uint)auStack_2c);
  return;
}

