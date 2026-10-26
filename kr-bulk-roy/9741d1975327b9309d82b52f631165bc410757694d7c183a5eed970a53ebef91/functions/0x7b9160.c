
void FUN_007b9160(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9,undefined4 param_10,undefined4 param_11,int param_12)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  int *piVar4;
  int iVar5;
  char *in_ECX;
  int local_38;
  int local_34;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009284c8;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffffff00;
  pcVar3 = in_ECX;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  local_14 = uVar2;
  FUN_00402a70(in_ECX,(int)pcVar3 - (int)(in_ECX + 1));
  local_8 = 0;
  local_34 = FUN_007b6f30(local_30);
  if ((local_34 == *(int *)(param_1 + 0x70)) || (cVar1 = FUN_0049ae30(uVar2), cVar1 != '\0')) {
    local_38 = *(int *)(param_1 + 0x70);
    piVar4 = &local_38;
  }
  else {
    piVar4 = &local_34;
  }
  iVar5 = *piVar4;
  local_8 = 0xffffffff;
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffffff00;
  if (iVar5 != *(int *)(param_1 + 0x70)) {
    FUN_007e3c50();
    iVar5 = FUN_00891268(0x80);
    if (iVar5 == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_007e4200();
    }
    local_34 = iVar5;
    if (param_12 == -1) {
      FUN_007b88a0();
      param_12 = FUN_007dd9f0();
    }
    *(int *)(iVar5 + 0x1c) = param_12;
    pcVar3 = in_ECX;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(in_ECX,(int)pcVar3 - (int)(in_ECX + 1));
    *(undefined4 *)(iVar5 + 0x28) = param_2;
    *(undefined4 *)(iVar5 + 0x2c) = param_3;
    *(undefined4 *)(iVar5 + 0x30) = param_4;
    *(undefined4 *)(iVar5 + 0x4c) = 1;
    *(undefined4 *)(iVar5 + 0x50) = 1;
    *(undefined4 *)(iVar5 + 0x34) = param_5;
    *(undefined4 *)(iVar5 + 0x38) = param_6;
    *(undefined4 *)(iVar5 + 0x4c) = 1;
    *(undefined4 *)(iVar5 + 0x50) = 1;
    *(undefined4 *)(iVar5 + 0x3c) = param_7;
    *(undefined4 *)(iVar5 + 0x40) = param_8;
    *(undefined4 *)(iVar5 + 0x44) = param_9;
    *(undefined4 *)(iVar5 + 0x4c) = 1;
    *(undefined4 *)(iVar5 + 0x50) = 1;
    *(undefined4 *)(iVar5 + 0x48) = param_10;
    *(undefined4 *)(iVar5 + 0x54) = param_11;
    FUN_007bb350();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

