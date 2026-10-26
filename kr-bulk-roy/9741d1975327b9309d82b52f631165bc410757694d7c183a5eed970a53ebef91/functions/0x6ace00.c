
/* WARNING: Removing unreachable block (ram,0x006acfed) */

void FUN_006ace00(int param_1)

{
  short sVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  short *psVar9;
  short *psVar10;
  uint uVar11;
  int *piVar12;
  int local_6c;
  uint local_68;
  uint local_54;
  uint local_4c;
  uint local_38;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092c348;
  local_10 = ExceptionList;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar6 = FUN_0048a740(uVar5);
  iVar7 = *(int *)(*(int *)(param_1 + 0xec) + 0xcc);
  uVar4 = (*(int *)(iVar6 + 0x24) - *(int *)(iVar6 + 0x20)) / 0x33;
  if (iVar7 != 0) {
    FUN_00408920(iVar7,uVar4);
  }
  uVar11 = 0;
  if (uVar4 != 0) {
    local_6c = 0;
    piVar12 = (int *)(param_1 + 0xf0);
    do {
      iVar7 = *(int *)(*(int *)(param_1 + 0xec) + 0xcc);
      if ((((iVar7 == 0) || ((int)uVar11 < 0)) ||
          (*(int *)(iVar7 + 0xac) - *(int *)(iVar7 + 0xa8) >> 2 <= (int)uVar11)) ||
         (piVar8 = *(int **)((int)piVar12 + *(int *)(iVar7 + 0xa8) + (-0xf0 - param_1)),
         piVar8 == (int *)0x0)) {
LAB_006acef2:
        piVar8 = (int *)0x0;
      }
      else {
        iVar7 = (**(code **)(*piVar8 + 4))();
        if (iVar7 != 0x12d) {
          MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
          goto LAB_006acef2;
        }
      }
      uVar11 = uVar11 + 1;
      *piVar12 = (int)piVar8;
      FUN_00420070();
      local_8 = 0;
      iVar7 = *(int *)(iVar6 + 0x20) + local_6c;
      psVar10 = (short *)(iVar7 + 4);
      psVar9 = psVar10;
      do {
        sVar1 = *psVar9;
        psVar9 = psVar9 + 1;
      } while (sVar1 != 0);
      FUN_00402160(psVar10,(int)psVar9 - (iVar7 + 6) >> 1);
      local_8._0_1_ = 1;
      FUN_00757710();
      FUN_00757710();
      FUN_00412df0();
      local_8 = CONCAT31(local_8._1_3_,2);
      FUN_00757710();
      if (7 < local_54) {
        FUN_0089120c(local_68);
      }
      local_54 = 7;
      local_68 = local_68 & 0xffff0000;
      local_8 = 0xffffffff;
      if (7 < local_38) {
        FUN_0089120c(local_4c);
      }
      local_6c = local_6c + 0x33;
      local_38 = 7;
      piVar12 = piVar12 + 1;
      local_4c = local_4c & 0xffff0000;
    } while (uVar11 < uVar4);
  }
  piVar12 = *(int **)(param_1 + 0xec);
  puVar2 = (undefined4 *)piVar12[0x19];
  for (puVar3 = (undefined4 *)*puVar2; puVar3 != puVar2; puVar3 = (undefined4 *)*puVar3) {
    iVar7 = puVar3[2];
    if ((*(int *)(iVar7 + 0x60) != 0) && ((*(int **)(iVar7 + 0x1c))[2] != 6)) {
      (**(code **)(**(int **)(iVar7 + 0x1c) + 0x30))(iVar7);
    }
  }
  (**(code **)(*piVar12 + 0x128))();
  (**(code **)(**(int **)(param_1 + 0xec) + 200))();
  ExceptionList = local_10;
  __security_check_cookie(uVar5 ^ (uint)&stack0xfffffffc);
  return;
}

