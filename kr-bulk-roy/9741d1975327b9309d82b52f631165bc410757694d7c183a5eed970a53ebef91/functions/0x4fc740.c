
/* WARNING: Removing unreachable block (ram,0x004fc7de) */

undefined4 * FUN_004fc740(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int *in_ECX;
  undefined4 *puVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090b4a0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar4 = (undefined4 *)param_1[1];
  if (*(char *)((int)puVar4[1] + 0x21) == '\0') {
    puVar1 = (undefined4 *)puVar4[1];
    do {
      if ((int)puVar1[3] < *in_ECX) {
        puVar2 = (undefined4 *)puVar1[2];
      }
      else {
        puVar2 = (undefined4 *)*puVar1;
        puVar4 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x21) == '\0');
  }
  if ((puVar4 == (undefined4 *)param_1[1]) || (*in_ECX < (int)puVar4[3])) {
    local_8 = 1;
    uVar3 = FUN_004fcae0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    FUN_004fc9c0(puVar4,uVar3);
    puVar4 = param_1;
  }
  ExceptionList = local_10;
  return puVar4 + 4;
}

