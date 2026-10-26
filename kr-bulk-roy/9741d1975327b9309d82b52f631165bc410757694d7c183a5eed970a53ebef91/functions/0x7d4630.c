
void FUN_007d4630(int param_1)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 in_ECX;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int local_9c [13];
  uint local_68;
  undefined4 local_58;
  uint local_54;
  int local_4c [13];
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00914a48;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = uVar2;
  local_9c[0xc] = FUN_007e8a00(in_ECX);
  if ((local_9c[0xc] == *(int *)(param_1 + 4)) || (cVar1 = FUN_0049ae30(uVar2), cVar1 != '\0')) {
    local_9c[1] = 0;
    local_9c[2] = 0;
    local_9c[0xb] = 1;
    local_9c[3] = 0;
    local_54 = 0xf;
    local_9c[4] = 0;
    local_58 = 0;
    local_9c[5] = 0;
    local_68 = local_68 & 0xffffff00;
    local_9c[6] = 0;
    local_9c[7] = 0x3f800000;
    local_9c[8] = 0x3f800000;
    local_9c[9] = 0x3f800000;
    local_9c[10] = 0x3f800000;
    FUN_00402bb0(in_ECX);
    piVar5 = local_9c;
    piVar6 = local_4c;
    for (iVar4 = 0xc; iVar4 != 0; iVar4 = iVar4 + -1) {
      *piVar6 = *piVar5;
      piVar5 = piVar5 + 1;
      piVar6 = piVar6 + 1;
    }
    local_8 = 0;
    uVar3 = FUN_007d4c20();
    FUN_007d4750(local_9c[0xc],uVar3);
    if (0xf < local_54) {
      FUN_0089120c(local_68);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

