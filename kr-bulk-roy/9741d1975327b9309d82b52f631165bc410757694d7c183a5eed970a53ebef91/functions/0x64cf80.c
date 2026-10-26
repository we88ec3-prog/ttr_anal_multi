
void FUN_0064cf80(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int *in_ECX;
  int local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091f70e;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = 0xb;
  FUN_0082ef00(&local_14);
  if (local_18 == in_ECX[0x14]) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(local_18 + 0x10);
  }
  in_ECX[0x20] = iVar3;
  FUN_0064d880(uVar2);
  FUN_0064cc30();
  FUN_0064d970();
  FUN_00643ce0(20000);
  FUN_00643ce0(30000);
  FUN_0064da60();
  FUN_0064db50();
  local_14 = CONCAT31(local_14._1_3_,1);
  if ((DAT_00faaf7c & 1) == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_8 = 0;
    FUN_0058d410();
    _atexit((_func_4879 *)&LAB_00bccdc0);
    local_8 = 0xffffffff;
  }
  FUN_0058eb30(L"MoveLock",&local_14);
  cVar1 = (char)local_14;
  (**(code **)(*in_ECX + 0x16c))((char)local_14 == '\0');
  if (cVar1 == '\0') {
    if ((in_ECX[10] & 4U) != 0) {
      in_ECX[10] = in_ECX[10] ^ 4;
    }
  }
  else {
    in_ECX[10] = in_ECX[10] | 4;
  }
  iVar3 = in_ECX[0x20];
  if (cVar1 == '\0') {
    if ((*(uint *)(iVar3 + 0x28) & 4) != 0) {
      *(uint *)(iVar3 + 0x28) = *(uint *)(iVar3 + 0x28) ^ 4;
    }
  }
  else {
    *(uint *)(iVar3 + 0x28) = *(uint *)(iVar3 + 0x28) | 4;
  }
  (**(code **)(*(int *)in_ECX[0x41] + 0xa0))(local_14);
  ExceptionList = local_10;
  return;
}

