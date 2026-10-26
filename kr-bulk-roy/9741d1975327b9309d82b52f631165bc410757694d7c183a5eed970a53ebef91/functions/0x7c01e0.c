
/* WARNING: Removing unreachable block (ram,0x007c029a) */

undefined4 * FUN_007c01e0(undefined4 *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  uint *in_EDX;
  undefined4 *puVar4;
  undefined4 *puVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00911860;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar4 = (undefined4 *)((undefined4 *)param_1[1])[1];
  cVar1 = *(char *)((int)puVar4 + 0x29);
  puVar5 = (undefined4 *)param_1[1];
  while (cVar1 == '\0') {
    if (((int)in_EDX[1] < (int)puVar4[5]) ||
       (((int)in_EDX[1] <= (int)puVar4[5] && (*in_EDX <= (uint)puVar4[4])))) {
      puVar2 = (undefined4 *)*puVar4;
    }
    else {
      puVar2 = (undefined4 *)puVar4[2];
      puVar4 = puVar5;
    }
    puVar5 = puVar4;
    puVar4 = puVar2;
    cVar1 = *(char *)((int)puVar2 + 0x29);
  }
  if (puVar5 != (undefined4 *)param_1[1]) {
    if (((int)puVar5[5] < (int)in_EDX[1]) ||
       (((int)puVar5[5] <= (int)in_EDX[1] && ((uint)puVar5[4] <= *in_EDX)))) goto LAB_007c02a3;
  }
  local_8 = 1;
  uVar3 = FUN_007c1d30(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  FUN_007c10e0(&param_1,puVar5,uVar3);
  puVar5 = param_1;
LAB_007c02a3:
  ExceptionList = local_10;
  return puVar5 + 6;
}

