
void FUN_0081e800(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar7;
  int *unaff_FS_OFFSET;
  undefined8 uVar8;
  uint local_14c;
  int local_13c;
  uint local_138;
  uint local_130 [4];
  undefined4 local_120;
  uint local_11c;
  char local_114 [256];
  uint local_14;
  int local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092a326;
  local_10 = *unaff_FS_OFFSET;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  *unaff_FS_OFFSET = (int)&local_10;
  local_14 = uVar2;
  uVar8 = FUN_00714770();
  uVar7 = (undefined4)((ulonglong)uVar8 >> 0x20);
  piVar3 = (int *)uVar8;
  if (piVar3 != (int *)0x0) {
    cVar1 = FUN_00714ac0(uVar2);
    if (cVar1 == '\0') {
      FUN_006edbe0(&DAT_00c53194);
      uVar7 = extraout_EDX;
    }
    else {
      (**(code **)(*piVar3 + 0x34))(3,0);
      while( true ) {
        iVar4 = (**(code **)(*piVar3 + 8))(local_114,0xff);
        if (iVar4 == 0) break;
        pcVar5 = local_114;
        pcVar6 = local_114 + 1;
        do {
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        if ((pcVar5[(int)(local_114 + (-1 - (int)pcVar6))] == '\r') ||
           (pcVar5[(int)(local_114 + (-1 - (int)pcVar6))] == '\n')) {
          pcVar5[(int)(local_114 + (-1 - (int)pcVar6))] = '\0';
        }
        pcVar5 = local_114;
        pcVar6 = local_114 + 1;
        do {
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        if ((pcVar5[(int)(local_114 + (-1 - (int)pcVar6))] == '\r') ||
           (pcVar5[(int)(local_114 + (-1 - (int)pcVar6))] == '\n')) {
          pcVar5[(int)(local_114 + (-1 - (int)pcVar6))] = '\0';
        }
        pcVar6 = local_114;
        do {
          cVar1 = *pcVar6;
          pcVar6 = pcVar6 + 1;
        } while (cVar1 != '\0');
        if ((int)pcVar6 - (int)(local_114 + 1) != 0) {
          local_11c = 0xf;
          local_120 = 0;
          local_130[0] = local_130[0] & 0xffffff00;
          FUN_00402a70(local_114,(int)pcVar6 - (int)(local_114 + 1));
          local_8 = 0;
          FUN_004028b0(local_130);
          local_8 = CONCAT31(local_8._1_3_,2);
          if (0xf < local_11c) {
            FUN_0089120c(local_130[0]);
          }
          local_11c = 0xf;
          local_120 = 0;
          local_130[0] = local_130[0] & 0xffffff00;
          if (local_13c != 0) {
            FUN_0049c120();
          }
          local_8 = 0xffffffff;
          if (7 < local_138) {
            FUN_0089120c(local_14c);
          }
          local_138 = 7;
          local_13c = 0;
          local_14c = local_14c & 0xffff0000;
        }
      }
      (**(code **)(*piVar3 + 4))();
      uVar7 = extraout_EDX_00;
    }
  }
  *unaff_FS_OFFSET = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc,uVar7,param_1);
  return;
}

