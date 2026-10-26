
void FUN_007a0f60(uint *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  char cVar6;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090a242;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)param_1[1];
  if ((in_ECX < puVar1) && (puVar2 = (undefined4 *)*param_1, puVar2 <= in_ECX)) {
    if (puVar1 == (undefined4 *)param_1[2]) {
      FUN_007a11d0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    puVar3 = (undefined4 *)param_1[1];
    puVar1 = (undefined4 *)(*param_1 + ((int)in_ECX - (int)puVar2 >> 3) * 8);
    local_8 = 0;
    if (puVar3 == (undefined4 *)0x0) goto LAB_007a102b;
    *puVar3 = 0;
    puVar3[1] = 0;
    iVar4 = puVar1[1];
    uVar5 = *puVar1;
    if (iVar4 == 0) goto LAB_007a102b;
    cVar6 = FUN_0047c250();
  }
  else {
    if (puVar1 == (undefined4 *)param_1[2]) {
      FUN_007a11d0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    puVar1 = (undefined4 *)param_1[1];
    local_8 = 1;
    if (puVar1 == (undefined4 *)0x0) goto LAB_007a102b;
    *puVar1 = 0;
    puVar1[1] = 0;
    iVar4 = in_ECX[1];
    uVar5 = *in_ECX;
    if (iVar4 == 0) goto LAB_007a102b;
    cVar6 = FUN_0047c250();
  }
  if (cVar6 != '\0') {
    FUN_007a31c0(uVar5,iVar4);
  }
LAB_007a102b:
  param_1[1] = param_1[1] + 8;
  ExceptionList = local_10;
  return;
}

