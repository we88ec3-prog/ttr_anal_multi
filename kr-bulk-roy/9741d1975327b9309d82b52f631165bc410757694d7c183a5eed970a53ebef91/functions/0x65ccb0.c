
void FUN_0065ccb0(void)

{
  undefined4 uVar1;
  int in_ECX;
  undefined4 *puVar2;
  int iVar3;
  int local_228;
  undefined4 local_218;
  undefined1 local_214 [512];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091f5be;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_0046b6f0(100,local_14);
  FUN_0046b6f0(200);
  FUN_0046b6f0(400);
  FUN_0046b6f0(500);
  FUN_0046b6f0(700);
  FUN_0046b6f0(800);
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_8 = 0;
    FUN_005c3de0();
    _atexit((_func_4879 *)&LAB_00bccc30);
    local_8 = 0xffffffff;
  }
  iVar3 = DAT_00f943ac;
  local_218 = 0x2f;
  FUN_0082ef00(&local_218);
  if (local_228 == *(int *)(iVar3 + 8)) {
    local_218 = 0;
  }
  else {
    local_218 = *(undefined4 *)(local_228 + 0x10);
  }
  puVar2 = (undefined4 *)(in_ECX + 0x98);
  iVar3 = 0;
  do {
    FUN_0040aeb0(L"Num01_%d",iVar3);
    uVar1 = FUN_00763360(local_214);
    *puVar2 = uVar1;
    iVar3 = iVar3 + 1;
    puVar2 = puVar2 + 1;
  } while (iVar3 < 10);
  iVar3 = *(int *)(in_ECX + 0x80);
  FUN_007444b0(0xbf6b);
  *(undefined1 *)(iVar3 + 0xa4) = 1;
  iVar3 = *(int *)(in_ECX + 0x84);
  FUN_007444b0(0xbf6b);
  *(undefined1 *)(iVar3 + 0xa4) = 1;
  iVar3 = *(int *)(in_ECX + 0x88);
  FUN_007444b0(0xbf6b);
  *(undefined1 *)(iVar3 + 0xa4) = 1;
  iVar3 = *(int *)(in_ECX + 0x8c);
  FUN_007444b0(0xbf6b);
  *(undefined1 *)(iVar3 + 0xa4) = 1;
  iVar3 = *(int *)(in_ECX + 0x90);
  FUN_007444b0(0xbf6b);
  *(undefined1 *)(iVar3 + 0xa4) = 1;
  iVar3 = *(int *)(in_ECX + 0x94);
  FUN_007444b0(0xbf6b);
  *(undefined1 *)(iVar3 + 0xa4) = 1;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

