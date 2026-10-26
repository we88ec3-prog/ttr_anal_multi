
void FUN_00760c80(void)

{
  int *piVar1;
  int *in_ECX;
  int iStack_24;
  undefined4 uStack_20;
  int local_1c;
  undefined4 uStack_18;
  int iStack_14;
  uint uStack_10;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&iStack_24;
  (**(code **)(*in_ECX + 0x178))(&local_1c);
  piVar1 = (int *)in_ECX[0x3b];
  iStack_24 = local_1c;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0xbc))(uStack_20,local_1c,uStack_18,(piVar1[5] - piVar1[3]) + local_1c);
    local_1c = iStack_24 + (*(int *)(in_ECX[0x3b] + 0x14) - *(int *)(in_ECX[0x3b] + 0xc));
  }
  if (in_ECX[0x20] != 0) {
    iStack_24 = local_1c;
    if (local_1c <= iStack_14) {
      iStack_24 = iStack_14;
    }
    (**(code **)(*(int *)in_ECX[0x20] + 0xbc))(uStack_20,local_1c,uStack_18,iStack_24);
  }
  __security_check_cookie(uStack_10 ^ (uint)&stack0xffffffd8);
  return;
}

