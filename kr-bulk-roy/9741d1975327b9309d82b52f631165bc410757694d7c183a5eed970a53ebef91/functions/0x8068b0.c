
undefined4 FUN_008068b0(undefined4 *param_1,int param_2,int param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  int iVar2;
  DWORD DVar3;
  int in_ECX;
  
  if (((param_2 == 0) || (param_3 == 0)) || (param_1[0x282a] != 0)) {
    return 0xffffffff;
  }
  param_1[0x2814] = 0;
  param_1[0x2815] = 0;
  param_1[0x2816] = 0;
  param_1[0x2817] = 0;
  param_1[0x2818] = 0;
  param_1[0x281a] = param_2;
  param_1[0x2819] = param_3;
  param_2 = 0;
  iVar2 = WSASend(*param_1,param_1 + 0x2819,1,&param_2,0,param_1 + 0x2814,0);
  *param_4 = param_2;
  if (iVar2 != -1) {
    InterlockedIncrement(param_1 + 0x282e);
    return 1;
  }
  iVar2 = WSAGetLastError();
  if (iVar2 != 0x3e5) {
    if (*(int *)(in_ECX + 0x58) != 0) {
      uVar1 = *param_1;
      DVar3 = timeGetTime();
      FUN_006f0400(2,
                   "SendPost : SOCKET_ERROR, NOT WSA_IO_PENDING %d, Error : %d Close Socket, Uptime[%d]"
                   ,uVar1,iVar2,DVar3);
    }
    return 0;
  }
  InterlockedIncrement(param_1 + 0x282e);
  return 2;
}

