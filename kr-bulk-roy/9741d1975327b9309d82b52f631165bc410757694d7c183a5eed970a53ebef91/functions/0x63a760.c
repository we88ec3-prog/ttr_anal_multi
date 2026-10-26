
/* WARNING: Removing unreachable block (ram,0x0063a7fe) */

undefined4 * FUN_0063a760(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  byte *in_ECX;
  undefined4 *puVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090b4a0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar3 = (undefined4 *)param_1[1];
  if (*(char *)((int)puVar3[1] + 0x21) == '\0') {
    puVar1 = (undefined4 *)puVar3[1];
    do {
      if (*(byte *)(puVar1 + 3) < *in_ECX) {
        puVar2 = (undefined4 *)puVar1[2];
      }
      else {
        puVar2 = (undefined4 *)*puVar1;
        puVar3 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x21) == '\0');
  }
  if ((puVar3 == (undefined4 *)param_1[1]) || (*in_ECX < *(byte *)(puVar3 + 3))) {
    local_8 = 1;
    FUN_004dc160(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    FUN_0063a8e0(param_1,puVar3);
    puVar3 = param_1;
  }
  ExceptionList = local_10;
  return puVar3 + 4;
}

