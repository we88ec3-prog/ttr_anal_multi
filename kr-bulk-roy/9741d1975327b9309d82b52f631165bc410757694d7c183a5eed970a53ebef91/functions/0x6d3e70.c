
/* WARNING: Removing unreachable block (ram,0x006d41d5) */
/* WARNING: Removing unreachable block (ram,0x006d41e0) */

void FUN_006d3e70(int param_1)

{
  byte bVar1;
  undefined1 uVar2;
  uint uVar3;
  int *piVar4;
  char cVar5;
  uint uVar6;
  int iVar7;
  undefined1 *puVar8;
  byte *pbVar9;
  char *pcVar10;
  char cVar11;
  byte bVar12;
  int *piVar13;
  int *piVar14;
  int iVar15;
  undefined1 local_48 [4];
  undefined4 *local_44;
  undefined4 local_40;
  undefined **local_38 [3];
  char *local_2c;
  int local_28;
  int *local_24;
  int local_20;
  int local_1c;
  char local_15;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090a912;
  local_10 = ExceptionList;
  uVar6 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(param_1 + 0x270) == 0) {
    *(int *)(param_1 + 0x270) = param_1 + 4;
  }
  if (DAT_00fba80c == 0) {
    iVar7 = FUN_00891268(0x57c,uVar6);
    if (iVar7 == 0) {
      DAT_00fba80c = 0;
    }
    else {
      DAT_00fba80c = FUN_006f1370();
    }
  }
  if (*(int *)(DAT_00fba80c + 0x20) == 0) {
    iVar7 = DAT_00fba80c + 0x260;
  }
  else {
    iVar7 = DAT_00fba80c + 0x60;
  }
  piVar14 = *(int **)(param_1 + 0x28);
  piVar13 = (int *)*piVar14;
  local_40 = 0;
  local_24 = piVar14;
  local_1c = iVar7;
  local_44 = (undefined4 *)FUN_00891268(0x18,uVar6);
  if (local_44 == (undefined4 *)0x0) {
    local_2c = (char *)0x0;
    std::exception::exception((exception *)local_38,&local_2c);
    local_38[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_38,&DAT_00c857a8);
  }
  *local_44 = local_44;
  local_44[1] = local_44;
  local_44[2] = local_44;
  *(undefined1 *)(local_44 + 5) = 1;
  *(undefined1 *)((int)local_44 + 0x15) = 1;
  local_8 = 0;
  local_15 = '\0';
  if ((*(char *)(iVar7 + 0x1d) != '\0') || (*(char *)(iVar7 + 0x9d) != '\0')) {
    local_15 = '\x01';
  }
  if (piVar13 != piVar14) {
    do {
      local_20 = piVar13[3];
      iVar7 = piVar13[5] - piVar13[4] >> 2;
      local_28 = iVar7;
      puVar8 = (undefined1 *)FUN_006d44b0();
      iVar15 = 0;
      *puVar8 = 0;
      if (0 < iVar7) {
        do {
          uVar3 = *(uint *)(piVar13[4] + iVar15 * 4);
          cVar11 = '\x01';
          cVar5 = (char)(uVar3 >> 0x10);
          if (cVar5 == '\x1d') {
            if (*(char *)(local_1c + 0x9d) == '\0') goto LAB_006d3fc9;
            cVar11 = *(char *)(local_1c + 0x9d);
          }
          else if (cVar5 == -99) {
            if (*(char *)(local_1c + 0x1d) == '\0') {
LAB_006d3fc9:
              cVar11 = *(char *)((uVar3 >> 0x10 & 0xff) + local_1c);
            }
            else {
              cVar11 = *(char *)(local_1c + 0x1d);
            }
          }
          else {
            if (cVar5 != '\0') goto LAB_006d3fc9;
            if (local_15 != '\0') {
              cVar11 = '\0';
            }
          }
          if (((char)uVar3 != '\0') && (cVar11 != '\0')) {
            pbVar9 = (byte *)FUN_006d44b0();
            *pbVar9 = *pbVar9 | *(byte *)((uVar3 & 0xff) + local_1c);
          }
          iVar15 = iVar15 + 1;
        } while (iVar15 < local_28);
      }
      pcVar10 = (char *)FUN_006d44b0();
      if (*pcVar10 != '\0') {
        puVar8 = (undefined1 *)FUN_006d44b0();
        *puVar8 = 0x80;
      }
      if (*(char *)((int)piVar13 + 0x21) == '\0') {
        piVar14 = (int *)piVar13[2];
        if (*(char *)((int)piVar14 + 0x21) == '\0') {
          cVar11 = *(char *)(*piVar14 + 0x21);
          piVar13 = piVar14;
          piVar14 = (int *)*piVar14;
          while (cVar11 == '\0') {
            cVar11 = *(char *)(*piVar14 + 0x21);
            piVar13 = piVar14;
            piVar14 = (int *)*piVar14;
          }
        }
        else {
          cVar11 = *(char *)(piVar13[1] + 0x21);
          piVar4 = (int *)piVar13[1];
          piVar14 = piVar13;
          while ((piVar13 = piVar4, cVar11 == '\0' && (piVar14 == (int *)piVar13[2]))) {
            cVar11 = *(char *)(piVar13[1] + 0x21);
            piVar4 = (int *)piVar13[1];
            piVar14 = piVar13;
          }
        }
      }
    } while (piVar13 != local_24);
  }
  if (DAT_00fba80c == 0) {
    iVar7 = FUN_00891268(0x57c,uVar6);
    if (iVar7 == 0) {
      DAT_00fba80c = 0;
    }
    else {
      DAT_00fba80c = FUN_006f1370();
    }
  }
  local_24 = *(int **)(param_1 + 0x28);
  piVar14 = (int *)*local_24;
  if (piVar14 != local_24) {
    do {
      pbVar9 = (byte *)FUN_006d44b0();
      bVar12 = *pbVar9;
      pbVar9 = (byte *)FUN_006d44b0();
      bVar1 = *pbVar9;
      if (bVar1 == bVar12) {
        bVar12 = bVar1 >> 6 & 2;
      }
      else {
        bVar12 = (byte)((bVar1 | 0x40) >> 6);
      }
      pbVar9 = (byte *)FUN_006d44b0();
      *pbVar9 = bVar12;
      if (*(char *)((int)piVar14 + 0x21) == '\0') {
        piVar13 = (int *)piVar14[2];
        if (*(char *)((int)piVar13 + 0x21) == '\0') {
          cVar11 = *(char *)(*piVar13 + 0x21);
          piVar14 = piVar13;
          piVar13 = (int *)*piVar13;
          while (cVar11 == '\0') {
            cVar11 = *(char *)(*piVar13 + 0x21);
            piVar14 = piVar13;
            piVar13 = (int *)*piVar13;
          }
        }
        else {
          cVar11 = *(char *)(piVar14[1] + 0x21);
          piVar4 = (int *)piVar14[1];
          piVar13 = piVar14;
          while ((piVar14 = piVar4, cVar11 == '\0' && (piVar13 == (int *)piVar14[2]))) {
            cVar11 = *(char *)(piVar14[1] + 0x21);
            piVar4 = (int *)piVar14[1];
            piVar13 = piVar14;
          }
        }
      }
    } while (piVar14 != local_24);
  }
  if ((undefined1 *)(param_1 + 0x260) != local_48) {
    FUN_005540c0(**(undefined4 **)(param_1 + 0x264),*(undefined4 **)(param_1 + 0x264));
    FUN_006d45c0(local_48);
  }
  uVar6 = 0;
  if (*(int *)(param_1 + 0x280) - *(int *)(param_1 + 0x27c) >> 3 != 0) {
    do {
      local_28 = *(int *)(*(int *)(param_1 + 0x27c) + uVar6 * 8);
      uVar2 = *(undefined1 *)(*(int *)(param_1 + 0x27c) + 4 + uVar6 * 8);
      puVar8 = (undefined1 *)FUN_006d44b0();
      *puVar8 = uVar2;
      uVar6 = uVar6 + 1;
    } while (uVar6 < (uint)(*(int *)(param_1 + 0x280) - *(int *)(param_1 + 0x27c) >> 3));
  }
  if (*(int *)(param_1 + 0x27c) != *(int *)(param_1 + 0x280)) {
    *(int *)(param_1 + 0x280) = *(int *)(param_1 + 0x27c);
  }
  local_8 = 1;
  FUN_005540c0(*local_44,local_44);
  FUN_0089120c(local_44);
  ExceptionList = local_10;
  return;
}

