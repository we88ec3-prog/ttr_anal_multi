
void FUN_007fc380(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  int in_ECX;
  char *pcVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093a12b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar2 = FUN_00891268(0xb8,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007d2db0(iVar2,param_2);
  }
  local_8 = 0xffffffff;
  *(undefined4 *)(param_1 + 0x34) = uVar3;
  *(int *)(param_1 + 0x38) = in_ECX;
  *(undefined4 *)(param_1 + 0x40) = param_3;
  *(undefined4 *)(param_1 + 0x2c) = param_4;
  if (*(uint *)(in_ECX + 0x1c) < 0x10) {
    pcVar5 = (char *)(in_ECX + 8);
  }
  else {
    pcVar5 = *(char **)(in_ECX + 8);
  }
  pcVar4 = pcVar5;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(pcVar5,(int)pcVar4 - (int)(pcVar5 + 1));
  iVar2 = *(int *)(param_1 + 0x34);
  FUN_007ee950();
  FUN_007ee9a0(*(undefined4 *)(iVar2 + 0x10));
  FUN_007eebf0();
  iVar2 = *(int *)(param_1 + 0x34);
  *(undefined4 *)(iVar2 + 4) = 0xf;
  *(undefined4 *)(iVar2 + 8) = 0x12;
  *(undefined4 *)(iVar2 + 0xc) = 8;
  ExceptionList = local_10;
  return;
}

