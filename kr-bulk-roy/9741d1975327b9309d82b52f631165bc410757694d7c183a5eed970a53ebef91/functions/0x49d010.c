
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_0049d010(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  int *in_ECX;
  undefined2 local_100c [2048];
  uint local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_100c[0] = 0x12;
  puVar1 = (undefined4 *)*in_ECX;
  uVar3 = 2;
  local_c = 2;
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    if (uVar3 + 2 < 0x1001) {
      *(undefined2 *)((int)local_100c + uVar3) = *(undefined2 *)(puVar2[2] + 4);
      uVar3 = local_c + 2;
      local_c = uVar3;
    }
  }
  if (2 < uVar3) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,local_100c,uVar3);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

