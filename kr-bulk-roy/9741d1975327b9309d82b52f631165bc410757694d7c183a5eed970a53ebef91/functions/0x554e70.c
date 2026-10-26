
void FUN_00554e70(int param_1)

{
  char cVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  uint local_4c;
  uint local_38;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009295d0;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  if (param_1 != 0) {
    piVar3 = (int *)FUN_0072e2e0("Tooltip");
    while (piVar3 != (int *)0x0) {
      iVar4 = (**(code **)(*piVar3 + 0x14))(uVar2);
      if (iVar4 != 0) {
        iVar4 = FUN_007300a0(&DAT_00c10014);
        if (iVar4 == 0) {
          pcVar6 = (char *)0x0;
        }
        else {
          pcVar6 = (char *)(iVar4 + 0x30);
          if (0xf < *(uint *)(iVar4 + 0x44)) {
            pcVar6 = *(char **)pcVar6;
          }
        }
        local_1c = 0xf;
        local_20 = 0;
        local_30[0] = local_30[0] & 0xffffff00;
        pcVar5 = pcVar6;
        do {
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        FUN_00402a70(pcVar6,(int)pcVar5 - (int)(pcVar6 + 1));
        local_8 = 0;
        FUN_004028b0(local_30);
        local_8._0_1_ = 1;
        FUN_00555920();
        local_8 = (uint)local_8._1_3_ << 8;
        if (7 < local_38) {
          FUN_0089120c(local_4c);
        }
        local_38 = 7;
        local_4c = local_4c & 0xffff0000;
        piVar3 = (int *)FUN_0072e3c0();
        local_8 = 0xffffffff;
        if (0xf < local_1c) {
          FUN_0089120c(local_30[0]);
        }
        local_1c = 0xf;
        local_20 = 0;
        local_30[0] = local_30[0] & 0xffffff00;
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

