
/* WARNING: Removing unreachable block (ram,0x00555a9e) */

undefined4 * FUN_00555a00(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *in_ECX;
  undefined4 *puVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00929560;
  local_10 = ExceptionList;
  puVar3 = *(undefined4 **)(param_1 + 4);
  if (*(char *)((int)puVar3[1] + 0x21) == '\0') {
    puVar1 = (undefined4 *)puVar3[1];
    do {
      if ((int)puVar1[3] < *in_ECX) {
        puVar2 = (undefined4 *)puVar1[2];
      }
      else {
        puVar2 = (undefined4 *)*puVar1;
        puVar3 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x21) == '\0');
  }
  if ((puVar3 != *(undefined4 **)(param_1 + 4)) && ((int)puVar3[3] <= *in_ECX)) {
    return puVar3 + 4;
  }
  local_8 = 1;
  ExceptionList = &local_10;
  FUN_004fcae0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  FUN_005562b0(param_1,puVar3);
  ExceptionList = local_10;
  return (undefined4 *)(param_1 + 0x10);
}

