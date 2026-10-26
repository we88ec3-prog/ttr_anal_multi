
void FUN_008fd110(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_ESI;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (*(char *)(unaff_ESI + 0x30) != '\0') {
    if (*(int *)(unaff_ESI + 0x2c) != 0) {
      (**(code **)(**(int **)(unaff_ESI + 0x2c) + 4))();
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    local_18 = 0;
    local_14 = 0;
    local_10 = 0x80;
    local_c = 0x100;
    iVar1 = **(int **)(unaff_ESI + 0x10);
    uVar2 = FUN_008fed10(&local_18,0xffffffff);
    uVar2 = FUN_008fed10(uVar2);
    (**(code **)(iVar1 + 0x20))(uVar2);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

