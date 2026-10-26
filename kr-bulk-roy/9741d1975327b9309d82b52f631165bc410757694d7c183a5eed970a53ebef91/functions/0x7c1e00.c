
void FUN_007c1e00(int param_1)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  int iVar4;
  undefined4 ****ppppuVar5;
  int *piVar6;
  char *unaff_ESI;
  undefined4 ***local_150 [4];
  undefined4 local_140;
  uint local_13c;
  undefined4 ***local_134 [4];
  undefined4 local_124;
  uint local_120;
  char local_118 [260];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00918a72;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_13c = 0xf;
  local_140 = 0;
  local_150[0] = (undefined4 ***)((uint)local_150[0] & 0xffffff00);
  pcVar3 = unaff_ESI;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  local_14 = uVar2;
  FUN_00402a70(unaff_ESI,(int)pcVar3 - (int)(unaff_ESI + 1));
  local_8._0_1_ = 0;
  local_8._1_3_ = 0;
  FUN_00401fc0(&DAT_00c4fd34,4);
  ppppuVar5 = (undefined4 ****)local_150[0];
  if (local_13c < 0x10) {
    ppppuVar5 = local_150;
  }
  if ((DAT_00fe1df8 & 1) == 0) {
    DAT_00fe1df8 = DAT_00fe1df8 | 1;
    local_8._0_1_ = 1;
    FUN_00716be0(uVar2);
    _atexit((_func_4879 *)&LAB_00bcf1a0);
    local_8._0_1_ = 0;
  }
  iVar4 = FUN_00716740(ppppuVar5);
  if (iVar4 != 0) {
    local_120 = 0xf;
    local_124 = 0;
    local_134[0] = (undefined4 ***)((uint)local_134[0] & 0xffffff00);
    pcVar3 = unaff_ESI;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(unaff_ESI,(int)pcVar3 - (int)(unaff_ESI + 1));
    local_8._0_1_ = 2;
    FUN_00401fc0(&DAT_00c4fd34,4);
    ppppuVar5 = (undefined4 ****)local_134[0];
    if (local_120 < 0x10) {
      ppppuVar5 = local_134;
    }
    FID_conflict__wprintf(" IS3D: Loading FLD File... %s\n",ppppuVar5);
    iVar4 = FUN_00891268(0x30);
    local_8._0_1_ = 3;
    if (iVar4 == 0) {
      piVar6 = (int *)0x0;
    }
    else {
      piVar6 = (int *)FUN_007e9ff0(iVar4);
    }
    local_8._0_1_ = 0;
    if (0xf < local_120) {
      FUN_0089120c(local_134[0]);
    }
    local_120 = 0xf;
    local_124 = 0;
    local_134[0] = (undefined4 ***)((uint)local_134[0] & 0xffffff00);
    if (piVar6 != (int *)0x0) {
      pcVar3 = (char *)(DAT_00fba838 + 0x20);
      if (0xf < *(uint *)(DAT_00fba838 + 0x34)) {
        pcVar3 = *(char **)pcVar3;
      }
      __splitpath(pcVar3,(char *)0x0,(char *)0x0,local_118,(char *)0x0);
      iVar4 = __stricmp(local_118,unaff_ESI);
      if (iVar4 == 0) {
        FID_conflict__wprintf(&DAT_00c4fd7c);
        if (param_1 != 0) {
          FID_conflict__wprintf(&DAT_00c4fd9c);
          goto LAB_007c200f;
        }
        FID_conflict__wprintf(&DAT_00c4fdb0);
      }
      else {
LAB_007c200f:
        (**(code **)(*piVar6 + 4))();
      }
      (**(code **)*piVar6)(1);
      goto LAB_007c2022;
    }
  }
  FID_conflict__wprintf(&DAT_00c4fd5c);
LAB_007c2022:
  if (0xf < local_13c) {
    FUN_0089120c(local_150[0]);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

