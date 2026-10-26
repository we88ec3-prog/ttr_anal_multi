
void FUN_00711820(void)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  int unaff_ESI;
  int local_24;
  int local_1c;
  
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  piVar2 = *(int **)(unaff_ESI + 0x30);
  FUN_0070f580();
  if (local_24 == 0xd) {
    puVar1 = (uint *)(*(int *)(*piVar2 + 0xc) + local_1c * 4);
    *puVar1 = *puVar1 & 0xff807fff | 0x4000;
    __security_check_cookie(uVar3 ^ (uint)&stack0xfffffffc);
    return;
  }
  FUN_0070fed0();
  __security_check_cookie(uVar3 ^ (uint)&stack0xfffffffc);
  return;
}

