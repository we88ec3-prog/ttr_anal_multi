
void FUN_00551b80(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  char *in_ECX;
  int in_EDX;
  int local_34;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00914bf8;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffffff00;
  pcVar4 = in_ECX;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  local_14 = uVar3;
  FUN_00402a70(in_ECX,(int)pcVar4 - (int)(in_ECX + 1));
  local_8 = 0;
  FUN_00552400(&local_34,local_30);
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0],uVar3);
  }
  if (local_34 != *(int *)(in_EDX + 0x34)) {
    if (param_1 < 0) {
      param_1 = 0;
    }
    iVar2 = *(int *)(local_34 + 0x24);
    FUN_008438c0(&param_1);
    if (local_34 != *(int *)(iVar2 + 4)) {
      iVar2 = *(int *)(local_34 + 0x10);
      iVar7 = *(int *)(iVar2 + 8);
      if (iVar7 != 0) {
        if (param_2 < 0) {
          if (*(int *)(iVar2 + 0x10) == 1) {
            iVar5 = FUN_0089289d();
            iVar5 = iVar5 % iVar7;
            local_34 = **(int **)(iVar2 + 4);
            iVar7 = local_34;
            if (0 < iVar5) {
              do {
                FUN_0049e6a0();
                iVar5 = iVar5 + -1;
                iVar7 = local_34;
              } while (iVar5 != 0);
            }
          }
          else {
            iVar7 = **(int **)(iVar2 + 4);
          }
        }
        else {
          piVar6 = (int *)FUN_008438c0(&param_2);
          iVar7 = *piVar6;
        }
        if (iVar7 != *(int *)(iVar2 + 4)) {
          FUN_008438c0(iVar7 + 0x10);
        }
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

