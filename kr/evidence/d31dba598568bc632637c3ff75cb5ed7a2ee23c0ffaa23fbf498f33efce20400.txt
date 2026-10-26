
/* WARNING: Removing unreachable block (ram,0x007a0d0e) */
/* WARNING: Removing unreachable block (ram,0x007a0d1a) */
/* WARNING: Removing unreachable block (ram,0x007a0d2e) */

undefined4 * FUN_007a0c70(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  uint *in_EDX;
  undefined4 *puVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0090c5a0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar3 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar3[1] + 0x19) == '\0') {
    puVar1 = (undefined4 *)puVar3[1];
    do {
      if ((uint)puVar1[3] < *in_EDX) {
        puVar2 = (undefined4 *)puVar1[2];
      }
      else {
        puVar2 = (undefined4 *)*puVar1;
        puVar3 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x19) == '\0');
  }
  if ((puVar3 == *(undefined4 **)(in_ECX + 4)) || (*in_EDX < (uint)puVar3[3])) {
    local_8 = 1;
    uStack_7 = 0;
    FUN_007a35f0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    FUN_007a2a10(in_ECX,puVar3);
  }
  ExceptionList = local_10;
  return puVar3 + 4;
}

