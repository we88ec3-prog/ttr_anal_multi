
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00552fc0(void)

{
  char cVar1;
  ushort uVar2;
  char *pcVar3;
  int iVar4;
  undefined4 ****ppppuVar5;
  int *piVar6;
  undefined4 uVar7;
  int in_ECX;
  undefined4 ****ppppuVar8;
  char *pcVar9;
  uint uVar10;
  uint local_50;
  undefined4 ***local_4c [4];
  uint local_3c;
  uint local_38;
  undefined4 ***local_30 [4];
  int local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_00929685;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_38 = 0xf;
  local_3c = 0;
  local_4c[0] = (undefined4 ***)((uint)local_4c[0] & 0xffffff00);
  local_8 = 0;
  local_8._1_3_ = 0;
  if (*(char *)(in_ECX + 2) == '\0') {
    if ((DAT_00fb75b0 & 1) == 0) {
      DAT_00fb75b0 = DAT_00fb75b0 | 1;
      local_8._0_1_ = 1;
      FUN_004f3d80(local_14);
      _atexit((_func_4879 *)&LAB_00bcd1e0);
      local_8 = (uint)local_8._1_3_ << 8;
    }
    uVar2 = *(ushort *)(in_ECX + 3);
    pcVar3 = (char *)FUN_004f7df0();
    pcVar9 = pcVar3;
    if (0xf < *(uint *)(pcVar3 + 0x14)) {
      pcVar3 = *(char **)pcVar3;
      pcVar9 = pcVar3;
    }
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
  }
  else {
    if (*(char *)(in_ECX + 2) != '\x02') goto LAB_005532a5;
    if ((DAT_00fb75b0 & 1) == 0) {
      DAT_00fb75b0 = DAT_00fb75b0 | 1;
      local_8._0_1_ = 2;
      FUN_004f3d80(local_14);
      _atexit((_func_4879 *)&LAB_00bcd1e0);
      local_8 = (uint)local_8._1_3_ << 8;
    }
    uVar2 = *(ushort *)(in_ECX + 3);
    pcVar3 = (char *)FUN_004f7df0();
    pcVar9 = pcVar3;
    if (0xf < *(uint *)(pcVar3 + 0x14)) {
      pcVar3 = *(char **)pcVar3;
      pcVar9 = pcVar3;
    }
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
  }
  local_50 = (uint)uVar2;
  FUN_00402a70(pcVar9,(int)pcVar3 - (int)(pcVar9 + 1));
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = (undefined4 ***)((uint)local_30[0] & 0xffffff00);
  local_8 = CONCAT31(local_8._1_3_,3);
  uVar10 = 0;
  if (local_3c == 0) {
LAB_00553147:
    ppppuVar5 = local_30;
  }
  else {
    do {
      ppppuVar5 = (undefined4 ****)local_4c[0];
      if (local_38 < 0x10) {
        ppppuVar5 = local_4c;
      }
      iVar4 = _tolower((int)*(char *)((int)ppppuVar5 + uVar10));
      local_50 = CONCAT31(local_50._1_3_,(char)iVar4);
      ppppuVar5 = (undefined4 ****)local_30[0];
      if (local_1c < 0x10) {
        ppppuVar5 = local_30;
      }
      ppppuVar8 = (undefined4 ****)local_30[0];
      if (local_1c < 0x10) {
        ppppuVar8 = local_30;
      }
      if ((int)ppppuVar5 + local_20 == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = ((int)ppppuVar5 + local_20) - (int)ppppuVar8;
      }
      FUN_004329c0(iVar4,1,local_50);
      uVar10 = uVar10 + 1;
    } while (uVar10 < local_3c);
    ppppuVar5 = (undefined4 ****)local_30[0];
    if (local_1c < 0x10) goto LAB_00553147;
  }
  ppppuVar8 = (undefined4 ****)local_30[0];
  if (local_1c < 0x10) {
    ppppuVar8 = local_30;
  }
  if ((int)ppppuVar5 + local_20 == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = ((int)ppppuVar5 + local_20) - (int)ppppuVar8;
  }
  FUN_004329c0(iVar4,1,0);
  iVar4 = FUN_00440930(local_30,&DAT_00c0fecc,4);
  if (iVar4 == -1) {
    FUN_00401fc0(&DAT_00c0fecc,4);
  }
  local_8 = local_8 & 0xffffff00;
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  iVar4 = FUN_00891268(0x68);
  local_8._0_1_ = 4;
  if (iVar4 == 0) {
    piVar6 = (int *)0x0;
  }
  else {
    piVar6 = (int *)FUN_00553e90(iVar4,100,0x14,0);
  }
  if ((DAT_00fb7354 & 1) == 0) {
    DAT_00fb7354 = DAT_00fb7354 | 1;
    local_8._0_1_ = 5;
    _eh_vector_constructor_iterator_(&DAT_00fb7358,0x10,4,FUN_00554050,FUN_00843020);
    DAT_00fb7398 = 0;
    DAT_00fb73ac = 0x400;
    DAT_00fb73b0 = 0x300;
    _DAT_00fb73b4 = 1;
    _atexit((_func_4879 *)&LAB_00bcd100);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  (**(code **)(*piVar6 + 4))();
  (**(code **)(*piVar6 + 0x20))(DAT_00fb73ac,DAT_00fb73b0);
  piVar6[0x10] = 0;
  uVar7 = FUN_0057ef20();
  FUN_0082f200(&DAT_00fb7378,uVar7);
  DAT_00fb7398 = DAT_00fb7398 + 1;
  if (0xf < local_38) {
    FUN_0089120c(local_4c[0]);
  }
LAB_005532a5:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

