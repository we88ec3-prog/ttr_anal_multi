
void FUN_004d76c0(void)

{
  ushort ****ppppuVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  ushort ****ppppuVar7;
  ushort uVar8;
  ushort ****ppppuVar9;
  uint local_14c [4];
  undefined4 local_13c;
  uint local_138;
  ushort ***local_130 [4];
  int local_120;
  uint local_11c;
  char local_114 [256];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092b0c6;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar3 = (int *)FUN_00714770("Table/Filter.txt",&DAT_00c0cd90,local_14);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 0x34))(3,0);
    while (iVar4 = (**(code **)(*piVar3 + 8))(local_114,0xff), iVar4 != 0) {
      pcVar5 = local_114;
      pcVar6 = local_114 + 1;
      do {
        cVar2 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar2 != '\0');
      if ((pcVar5[(int)(local_114 + (-1 - (int)pcVar6))] == '\r') ||
         (pcVar5[(int)(local_114 + (-1 - (int)pcVar6))] == '\n')) {
        pcVar5[(int)(local_114 + (-1 - (int)pcVar6))] = '\0';
      }
      pcVar5 = local_114;
      pcVar6 = local_114 + 1;
      do {
        cVar2 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar2 != '\0');
      if ((pcVar5[(int)(local_114 + (-1 - (int)pcVar6))] == '\r') ||
         (pcVar5[(int)(local_114 + (-1 - (int)pcVar6))] == '\n')) {
        pcVar5[(int)(local_114 + (-1 - (int)pcVar6))] = '\0';
      }
      pcVar6 = local_114;
      do {
        cVar2 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar2 != '\0');
      if ((int)pcVar6 - (int)(local_114 + 1) != 0) {
        local_138 = 0xf;
        local_13c = 0;
        local_14c[0] = local_14c[0] & 0xffffff00;
        FUN_00402a70(local_114,(int)pcVar6 - (int)(local_114 + 1));
        local_8 = 0;
        FUN_004028b0(local_14c);
        local_8 = CONCAT31(local_8._1_3_,2);
        if (0xf < local_138) {
          FUN_0089120c(local_14c[0]);
        }
        local_138 = 0xf;
        local_13c = 0;
        local_14c[0] = local_14c[0] & 0xffffff00;
        ppppuVar9 = (ushort ****)local_130[0];
        if (local_11c < 8) {
          ppppuVar9 = local_130;
        }
        ppppuVar1 = (ushort ****)((int)ppppuVar9 + local_120 * 2);
        ppppuVar7 = (ushort ****)local_130[0];
        if (local_11c < 8) {
          ppppuVar7 = local_130;
        }
        if (ppppuVar7 != ppppuVar1) {
          iVar4 = (int)ppppuVar9 - (int)ppppuVar7;
          do {
            uVar8 = *(ushort *)ppppuVar7;
            if (uVar8 - 0x41 < 0x1a) {
              uVar8 = uVar8 + 0x20;
            }
            *(ushort *)(iVar4 + (int)ppppuVar7) = uVar8;
            ppppuVar7 = (ushort ****)((int)ppppuVar7 + 2);
          } while (ppppuVar7 != ppppuVar1);
        }
        FUN_0049c120();
        local_8 = 0xffffffff;
        if (7 < local_11c) {
          FUN_0089120c(local_130[0]);
        }
        local_11c = 7;
        local_120 = 0;
        local_130[0] = (ushort ***)((uint)local_130[0] & 0xffff0000);
      }
    }
    (**(code **)(*piVar3 + 4))();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

