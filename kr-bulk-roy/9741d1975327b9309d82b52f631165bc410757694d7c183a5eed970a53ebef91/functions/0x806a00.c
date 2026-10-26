
undefined4 FUN_00806a00(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  DWORD DVar4;
  int *in_ECX;
  undefined4 local_8;
  
  puVar2 = param_1;
  param_1[0x280c] = 0;
  param_1[0x280d] = 0;
  param_1[0x280e] = 0;
  param_1[0x280f] = 0;
  param_1[0x2810] = 0;
  param_1[0x2812] = param_1[0x1406];
  param_1[0x2811] = 0x1000;
  local_8 = 0;
  iVar3 = WSARecv(*param_1,param_1 + 0x2811,1,&param_1,&local_8,param_1 + 0x280c,0);
  if (iVar3 == -1) {
    iVar3 = WSAGetLastError();
    if (iVar3 != 0x3e5) {
      (**(code **)(*in_ECX + 0x24))(puVar2,0);
      puVar2[0x282a] = 1;
      if (in_ECX[0x16] != 0) {
        uVar1 = *puVar2;
        DVar4 = timeGetTime();
        FUN_006f0400(2,
                     "RecvPost : SOCKET_ERROR, NOT WSA_IO_PENDING %d, Error : %d Close Socket. Uptime[%d]"
                     ,uVar1,iVar3,DVar4);
      }
      return 0;
    }
  }
  iVar3 = FUN_008065b0();
  if (iVar3 == 1) {
    (**(code **)(*in_ECX + 0x24))(puVar2,0);
  }
  return 1;
}

