
void FUN_00737d40(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  undefined4 ****ppppuVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int *in_ECX;
  char *in_EDX;
  int local_58;
  int *local_54;
  int local_50;
  undefined4 ***local_4c [5];
  uint local_38;
  uint local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00922770;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_54 = in_ECX;
  local_14 = uVar2;
  iVar3 = FUN_00714550();
  if (iVar3 == 0) {
    local_1c = 0xf;
    local_20 = 0;
    local_30 = local_30 & 0xffffff00;
    pcVar4 = in_EDX;
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(in_EDX,(int)pcVar4 - (int)(in_EDX + 1));
    local_8 = 0;
    FUN_00714aa0(uVar2);
    local_8 = CONCAT31(local_8._1_3_,2);
    if (0xf < local_1c) {
      FUN_0089120c(local_30);
    }
    local_1c = 0xf;
    local_20 = 0;
    local_30 = local_30 & 0xffffff00;
    ppppuVar5 = (undefined4 ****)local_4c[0];
    if (local_38 < 0x10) {
      ppppuVar5 = local_4c;
    }
    piVar6 = (int *)FUN_00714770(ppppuVar5,&DAT_00bed1e0);
    if (piVar6 == (int *)0x0) {
      if (0xf < local_38) {
        FUN_0089120c(local_4c[0]);
      }
    }
    else {
      iVar7 = (**(code **)(*piVar6 + 0x2c))();
      iVar8 = FUN_0087dc3d(iVar7);
      (**(code **)(*piVar6 + 0x10))(iVar8,iVar7,1);
      (**(code **)(*piVar6 + 4))();
      local_50 = 0;
      iVar9 = FUN_00716eb0(iVar8,iVar7,&local_50,&local_58);
      iVar3 = local_50;
      if (iVar9 < 0) {
        local_58 = iVar7;
        iVar3 = iVar8;
      }
      FUN_00733e60(local_58);
      (**(code **)(*local_54 + 4))(iVar3 + 8,local_58 + -8);
      if (iVar8 != 0) {
        FUN_00891d3d(iVar8);
      }
      if (local_50 != 0) {
        FUN_00891d3d(local_50);
      }
      if (0xf < local_38) {
        FUN_0089120c(local_4c[0]);
      }
    }
  }
  else {
    (**(code **)*in_ECX)();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

