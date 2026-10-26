
void FUN_00654ce0(void)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int in_ECX;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 local_21c;
  int local_218;
  undefined1 local_214 [512];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091f5fe;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar4 = 90000;
  piVar5 = (int *)(in_ECX + 0xf8);
  local_218 = in_ECX;
  local_14 = uVar2;
  do {
    FUN_0046b6f0(iVar4,uVar2);
    iVar1 = *piVar5;
    FUN_007444b0(0xbf6b);
    iVar4 = iVar4 + 10000;
    piVar5 = piVar5 + 1;
    *(undefined1 *)(iVar1 + 0xa4) = 1;
  } while (iVar4 < 130000);
  FUN_0046b6f0(130000,uVar2);
  FUN_0046b6f0(140000);
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_8 = 0;
    FUN_005c3de0();
    _atexit((_func_4879 *)&LAB_00bccc30);
    local_8 = 0xffffffff;
  }
  local_21c = 0x2c;
  FUN_0082ef00(&local_21c);
  iVar4 = 0;
  puVar6 = (undefined4 *)(local_218 + 0x138);
  do {
    FUN_0040aeb0(L"ChaLadder%02d",iVar4);
    uVar3 = FUN_00763360(local_214);
    puVar6[-10] = uVar3;
    FUN_0040aeb0(L"ChaLadder1%01d",iVar4);
    uVar3 = FUN_00763360(local_214);
    *puVar6 = uVar3;
    iVar4 = iVar4 + 1;
    puVar6 = puVar6 + 1;
  } while (iVar4 < 10);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

