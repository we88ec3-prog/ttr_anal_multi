
void FUN_007f68b0(void)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  undefined4 uVar4;
  int iVar5;
  int in_ECX;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  int local_cc;
  char *pcStack_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  int iStack_b8;
  uint uStack_b4;
  undefined4 uStack_a4;
  uint uStack_a0;
  uint uStack_98;
  undefined4 uStack_88;
  uint uStack_84;
  uint auStack_7c [4];
  undefined4 uStack_6c;
  uint uStack_68;
  char acStack_60 [68];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  uint uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0092a525;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&uStack_d4;
  ExceptionList = &local_14;
  if (*(int *)(in_ECX + 0x30) != 0) {
    local_cc = in_ECX;
    uStack_d4 = (**(code **)(**(int **)(in_ECX + 0x30) + 0xc))
                          (DAT_00d61f20 ^ (uint)&stack0xffffff20);
    uStack_d0 = (**(code **)(**(int **)(in_ECX + 0x34) + 0xc))();
    pcStack_c8 = (char *)0x0;
    uStack_c4 = 0;
    uStack_c0 = 0;
    uStack_c = 0;
    uStack_68 = 0xf;
    uStack_6c = 0;
    auStack_7c[0] = auStack_7c[0] & 0xffffff00;
    FUN_00402a70(&DAT_00c504d0,1);
    pcVar3 = (char *)(in_ECX + 4);
    uStack_c._0_1_ = 1;
    if (0xf < *(uint *)(in_ECX + 0x18)) {
      pcVar3 = *(char **)pcVar3;
    }
    uStack_84 = 0xf;
    uStack_88 = 0;
    uStack_98 = uStack_98 & 0xffffff00;
    pcVar2 = pcVar3;
    do {
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(pcVar3,(int)pcVar2 - (int)(pcVar3 + 1));
    uStack_c = CONCAT31(uStack_c._1_3_,2);
    FUN_007da6b0(&pcStack_c8,auStack_7c);
    if (0xf < uStack_84) {
      FUN_0089120c(uStack_98);
    }
    uStack_c = uStack_c & 0xffffff00;
    uStack_84 = 0xf;
    uStack_88 = 0;
    uStack_98 = uStack_98 & 0xffffff00;
    if (0xf < uStack_68) {
      FUN_0089120c(auStack_7c[0]);
    }
    pcVar3 = pcStack_c8;
    if (0xf < *(uint *)(pcStack_c8 + 0x14)) {
      pcVar3 = *(char **)pcStack_c8;
    }
    __splitpath(pcVar3,(char *)0x0,(char *)0x0,acStack_60,(char *)0x0);
    pcVar3 = acStack_60;
    uStack_a0 = 0xf;
    uStack_a4 = 0;
    uStack_b4 = uStack_b4 & 0xffffff00;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(acStack_60,(int)pcVar3 - (int)(acStack_60 + 1));
    uStack_c._0_1_ = 3;
    FUN_00401fc0(&DAT_00c50c8c,4);
    if ((DAT_00fe32bc & 1) == 0) {
      DAT_00fe32bc = DAT_00fe32bc | 1;
      uStack_c._0_1_ = 4;
      FUN_007dda50();
      _atexit((_func_4879 *)&LAB_00bd0ac0);
      uStack_c._0_1_ = 3;
    }
    uVar4 = FUN_007ddcf0();
    iStack_b8 = FUN_00891268(0x90);
    uStack_c._0_1_ = 5;
    if (iStack_b8 == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_007fde30(iStack_b8,uStack_d4,uStack_d0,uVar4);
    }
    uStack_c = CONCAT31(uStack_c._1_3_,3);
    if (*(int *)(local_cc + 0x3c) != 0) {
      uVar4 = FUN_007fdaf0(*(int *)(local_cc + 0x3c));
      *(undefined4 *)(iVar5 + 0x88) = uVar4;
    }
    *(undefined4 *)(iVar5 + 0x84) = *(undefined4 *)(local_cc + 0x38);
    if (0xf < uStack_a0) {
      FUN_0089120c(uStack_b4);
    }
    pcVar3 = pcStack_c8;
    uStack_a4 = 0;
    uStack_b4 = uStack_b4 & 0xffffff00;
    uStack_a0 = 0xf;
    FUN_00440a80();
    FUN_0089120c(pcVar3);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&uStack_d4);
  return;
}

