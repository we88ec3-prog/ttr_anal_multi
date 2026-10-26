
void FUN_0072e770(int *param_1,undefined4 param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  char *in_ECX;
  char *pcVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00918aeb;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar3 = FUN_007300a0(param_2);
  if (iVar3 != 0) {
    pcVar4 = in_ECX;
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(in_ECX,(int)pcVar4 - (int)(in_ECX + 1));
    ExceptionList = local_10;
    return;
  }
  iVar3 = FUN_00891268(0x54,uVar2);
  local_8 = 0;
  if (iVar3 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_0072da90(iVar3,param_2,in_ECX);
  }
  local_8 = 0xffffffff;
  if (iVar3 != 0) {
    *(int **)(iVar3 + 0x50) = param_1 + 0x11;
    *(int *)(iVar3 + 0x4c) = param_1[0x24];
    *(int *)(param_1[0x24] + 0x50) = iVar3;
    param_1[0x24] = iVar3;
    ExceptionList = local_10;
    return;
  }
  if (param_1 != (int *)0x0) {
    while( true ) {
      iVar3 = (**(code **)(*param_1 + 0x10))();
      if (iVar3 != 0) break;
      param_1 = (int *)param_1[4];
      if (param_1 == (int *)0x0) {
        ExceptionList = local_10;
        return;
      }
    }
    iVar3 = (**(code **)(*param_1 + 0x10))();
    if (iVar3 != 0) {
      FUN_00732010(3,0,0,0);
    }
  }
  ExceptionList = local_10;
  return;
}

