
void FUN_00502270(int param_1)

{
  char cVar1;
  ushort uVar2;
  code *pcVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  int *piVar7;
  char *pcVar8;
  float in_ECX;
  uint uVar9;
  char *pcVar10;
  float fVar11;
  float10 fVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  uint *puVar15;
  uint local_b4;
  float local_b0;
  undefined4 local_ac;
  uint local_98;
  undefined4 local_90;
  uint local_7c;
  uint local_74 [4];
  undefined4 local_64;
  uint local_60;
  uint local_58 [4];
  undefined4 local_48;
  uint local_44;
  undefined4 local_34;
  char *local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  float local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009441a8;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_b0 = in_ECX;
  local_14 = uVar4;
  if (*(int *)(param_1 + 4) == 0) {
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 0;
      FUN_00587480(uVar4);
      _atexit((_func_4879 *)&LAB_00bcccc0);
    }
    local_8 = 0xffffffff;
    puVar5 = (undefined4 *)FUN_00891268(0x18);
    if (puVar5 == (undefined4 *)0x0) {
      puVar5 = (undefined4 *)0x0;
    }
    else {
      uVar13 = *(undefined4 *)(param_1 + 4);
      puVar5[1] = 0xffffffff;
      puVar5[2] = 0xffffffff;
      puVar5[3] = 0;
      puVar5[4] = 0xf4281;
      *puVar5 = FoxUI::FXUIEventI1::vftable;
      puVar5[5] = uVar13;
    }
    FUN_0058aa50(puVar5);
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 1;
      FUN_00587480(uVar4);
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_8 = 0xffffffff;
    }
    puVar5 = (undefined4 *)FUN_00891268(0x18);
    if (puVar5 == (undefined4 *)0x0) {
      puVar5 = (undefined4 *)0x0;
    }
    else {
      uVar2 = *(ushort *)(param_1 + 2);
      puVar5[1] = 0xffffffff;
      puVar5[2] = 0xffffffff;
      puVar5[3] = 0;
      puVar5[4] = 0xf438b;
      *puVar5 = FoxUI::FXUIEventI1::vftable;
      puVar5[5] = (uint)uVar2;
    }
    FUN_0058aa50(puVar5);
    FUN_00500110();
    iVar6 = FUN_0040f060();
    FUN_00500240(local_b0,*(undefined4 *)(iVar6 + 0x8c));
    fVar11 = (float)(uint)*(ushort *)(param_1 + 2);
    iVar6 = *(int *)((int)local_b0 + 0x5eac);
    local_b0 = fVar11;
    FUN_00503d20(&local_b0);
    uVar4 = local_b4;
    if ((local_b4 == *(uint *)(iVar6 + 4)) || (local_b4 == 0xfffffff0)) goto LAB_005027ac;
    if (*(int *)(local_b4 + 0x4c) == 2) {
      uVar13 = *(undefined4 *)(local_b4 + 0x50);
      FUN_00422f40(fVar11,uVar13);
      FUN_00561760(fVar11,uVar13);
    }
    else if (*(int *)(local_b4 + 0x4c) == 3) {
      FUN_004054c0();
      puVar5 = (undefined4 *)FUN_00891268(0x18);
      if (puVar5 == (undefined4 *)0x0) {
        FUN_0058aa50(0);
      }
      else {
        uVar13 = *(undefined4 *)(uVar4 + 0x50);
        puVar5[1] = 0xffffffff;
        puVar5[2] = 0xffffffff;
        puVar5[3] = 0;
        puVar5[4] = 0xf4306;
        *puVar5 = FoxUI::FXUIEventI1::vftable;
        puVar5[5] = uVar13;
        FUN_0058aa50(puVar5);
      }
      goto LAB_005027ac;
    }
    piVar7 = (int *)(**(code **)(*DAT_00fba7a4 + 0x20))();
    if (piVar7 != (int *)0x0) {
      puVar5 = (undefined4 *)(**(code **)(*piVar7 + 0x4c))();
      local_20 = *puVar5;
      local_1c = puVar5[1];
      local_18 = (float)puVar5[2];
      if ((piVar7[0x57] == 0) || (piVar7[0xdc] == 0)) {
        local_b0 = 0.0;
      }
      else {
        fVar12 = (float10)FUN_007a7100();
        local_b0 = (float)fVar12;
      }
      puVar5 = &local_20;
      uVar9 = (uint)*(ushort *)(piVar7 + 1);
      local_18 = local_b0 + 2.6 + local_18;
      local_34 = 0;
      local_30 = "QUESTSTATE";
      local_2c = 0;
      local_28 = 0;
      local_24 = 0;
      uVar14 = 0x3f800000;
      uVar13 = 0;
      FUN_0049b140(uVar9,puVar5,0,0x3f800000);
      FUN_00551f20(uVar9,puVar5,uVar13,uVar14);
    }
    local_b4 = *(uint *)(local_b4 + 0x38);
    iVar6 = FUN_004ffd90();
    FUN_005740f0(&local_b4);
    if (local_b0 != *(float *)(iVar6 + 4)) {
      pcVar10 = (char *)((int)local_b0 + 0x10);
      if (0xf < *(uint *)((int)local_b0 + 0x24)) {
        pcVar10 = *(char **)pcVar10;
      }
      if (pcVar10 != (char *)0x0) {
        FUN_00402b70("Event/CameraWorks/");
        local_8 = 2;
        pcVar8 = pcVar10;
        do {
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        FUN_00401fc0(pcVar10,(int)pcVar8 - (int)(pcVar10 + 1));
        piVar7 = (int *)FUN_00434130();
        *piVar7 = (int)(piVar7 + 1);
        FUN_00796ee0();
        piVar7 = (int *)FUN_00434130();
        if ((int *)*piVar7 != (int *)0x0) {
          (**(code **)(*(int *)*piVar7 + 8))();
        }
        local_8 = 0xffffffff;
        FUN_00402c50();
      }
    }
    local_b4 = FUN_00891268(0xc4);
    local_8 = 3;
    if (local_b4 != 0) {
      piVar7 = (int *)(uVar4 + 0x5c);
      if (7 < *(uint *)(uVar4 + 0x70)) {
        piVar7 = (int *)*piVar7;
      }
      FUN_005016f0(piVar7,0);
    }
    uVar14 = 0;
    local_8 = 0xffffffff;
    uVar13 = FUN_00422ed0(0);
    FUN_005536e0(uVar13,uVar14);
    local_b4 = 0x11;
    iVar6 = FUN_005855b0();
    FUN_005740f0(&local_b4);
    if (local_b0 == *(float *)(iVar6 + 4)) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    puVar5 = (undefined4 *)FUN_004ed610();
    local_8 = 4;
    if (7 < (uint)puVar5[5]) {
      puVar5 = (undefined4 *)*puVar5;
    }
    FUN_00402250(puVar5);
    puVar15 = local_58;
    local_8 = CONCAT31(local_8._1_3_,5);
    FUN_0040f8c0(puVar15);
    FUN_004d6b30(puVar15);
    if (7 < local_44) {
      FUN_0089120c(local_58[0]);
    }
    local_44 = 7;
    local_48 = 0;
    local_58[0] = local_58[0] & 0xffff0000;
    local_ac = local_90;
    local_98 = local_7c;
  }
  else {
    if (*(int *)(param_1 + 4) != 1) goto LAB_005027ac;
    local_b4 = (uint)*(ushort *)(param_1 + 2);
    iVar6 = *(int *)((int)in_ECX + 0x5eac);
    FUN_00503d20(&local_b4);
    if ((local_b0 == *(float *)(iVar6 + 4)) || (local_b0 == -NAN)) goto LAB_005027ac;
    uVar13 = 0x12;
    FUN_005855b0(0x12);
    FUN_00585330(uVar13);
    puVar5 = (undefined4 *)FUN_004ed610();
    local_8 = 6;
    if (7 < (uint)puVar5[5]) {
      puVar5 = (undefined4 *)*puVar5;
    }
    FUN_00402250(puVar5);
    puVar15 = local_74;
    local_8 = CONCAT31(local_8._1_3_,7);
    FUN_0040f8c0(puVar15);
    FUN_004d6b30(puVar15);
    if (7 < local_60) {
      FUN_0089120c(local_74[0]);
    }
    local_60 = 7;
    local_64 = 0;
    local_74[0] = local_74[0] & 0xffff0000;
  }
  if (7 < local_98) {
    FUN_0089120c(local_ac);
  }
LAB_005027ac:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

