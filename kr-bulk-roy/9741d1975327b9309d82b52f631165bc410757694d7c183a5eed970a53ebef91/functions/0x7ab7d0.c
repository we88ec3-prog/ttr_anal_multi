
void FUN_007ab7d0(int *param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  int *piVar8;
  undefined4 *local_144;
  undefined4 uStack_140;
  int *local_13c;
  undefined4 uStack_138;
  uint local_134;
  int *local_130;
  int *local_12c;
  int iStack_128;
  undefined1 auStack_124 [4];
  char local_120 [260];
  uint local_1c;
  undefined4 uStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00935581;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_144;
  ExceptionList = &local_14;
  local_12c = param_1;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_c = 0;
    FUN_00798de0(DAT_00d61f20 ^ (uint)&stack0xfffffeb0);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  local_c = 0xffffffff;
  local_130 = DAT_00fb76a8;
  local_134 = 0;
  if (param_1[0x51] - param_1[0x50] >> 2 != 0) {
    do {
      piVar8 = local_130;
      uVar4 = local_134;
      local_13c = (int *)0x0;
      _sprintf(local_120,"Panel/NumberPanel%d.gb3",local_134);
      iVar5 = FUN_00714550(local_120);
      if (iVar5 == 0) {
        _sprintf(local_120,"Panel/NumberPanel%d.emf",uVar4);
        iVar5 = FUN_007cc280(piVar8,&local_13c);
      }
      else {
        iVar5 = FUN_007cc0a0(piVar8,&local_13c);
      }
      piVar8 = local_13c;
      if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_006edc70(&DAT_00c4f38c);
      }
      local_13c[0xf] = 1;
      FUN_0084d9e0(local_13c);
      local_144 = (undefined4 *)FUN_00891268(0xc0);
      local_c = 1;
      if (local_144 == (undefined4 *)0x0) {
        local_13c = (int *)0x0;
      }
      else {
        local_13c = (int *)FUN_00845c60(local_144);
      }
      piVar6 = local_13c;
      local_c = 0xffffffff;
      puVar2 = (undefined4 *)local_13c[0x1e];
      if (puVar2 != (undefined4 *)0x0) {
        piVar1 = puVar2 + 1;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          (**(code **)*puVar2)(1);
        }
      }
      piVar6[0x1e] = (int)piVar8;
      iVar5 = (**(code **)(*piVar8 + 8))();
      if (iVar5 == 0) {
        iVar5 = (**(code **)(*(int *)piVar6[0x1e] + 0xc))();
        piVar6[0x1e] = iVar5;
      }
      *(int *)(piVar6[0x1e] + 4) = *(int *)(piVar6[0x1e] + 4) + 1;
      piVar8 = (int *)0x0;
      piVar6[0x2e] = 0;
      local_144 = (undefined4 *)FUN_00891268(0x1d0);
      local_c = 2;
      if (local_144 != (undefined4 *)0x0) {
        piVar8 = (int *)FUN_00854c30(local_144);
      }
      local_c = 0xffffffff;
      uStack_140 = 0x3f800000;
      uStack_138 = 0x3f800000;
      local_144 = (undefined4 *)0x3f800000;
      FUN_008551d0();
      local_144 = (undefined4 *)0x3f800000;
      uStack_138 = 0x3f800000;
      uStack_140 = 0x3f800000;
      FUN_00855110();
      local_144 = (undefined4 *)0x3f800000;
      uStack_138 = 0x3f800000;
      uStack_140 = 0x3f800000;
      FUN_00855050();
      piVar8[0x73] = 0x3f800000;
      (**(code **)(*local_130 + 0xa0))(auStack_124,"panel");
      piVar8[0x59] = (int)local_12c;
      iVar5 = FUN_00891268(0xbc);
      local_14 = (void *)0x3;
      if (iVar5 == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = FUN_00856910();
      }
      local_14 = (void *)0xffffffff;
      *(undefined4 *)(iVar5 + 0xb8) = 0;
      FUN_00843fa0(piVar8,1);
      piVar6 = (int *)(**(code **)(*piVar8 + 0xc))();
      puVar3 = local_144;
      puVar2 = (undefined4 *)local_144[0x1d];
      if (puVar2 != (undefined4 *)0x0) {
        piVar1 = puVar2 + 1;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          (**(code **)*puVar2)(1);
        }
      }
      puVar3[0x1d] = piVar6;
      if (piVar6 != (int *)0x0) {
        iVar5 = (**(code **)(*piVar6 + 8))();
        if (iVar5 == 0) {
          uVar7 = (**(code **)(*(int *)puVar3[0x1d] + 0xc))();
          puVar3[0x1d] = uVar7;
        }
        *(int *)(puVar3[0x1d] + 4) = *(int *)(puVar3[0x1d] + 4) + 1;
      }
      (**(code **)*piVar8)(1);
      iVar5 = FUN_00891268(0xe8);
      uStack_18 = 4;
      if (iVar5 == 0) {
        piVar8 = (int *)0x0;
      }
      else {
        piVar8 = (int *)FUN_0077ebb0();
      }
      puVar3[1] = puVar3[1] + 1;
      uStack_18 = 5;
      FUN_0077f8f0();
      uStack_18 = 0xffffffff;
      if (puVar3 != (undefined4 *)0x0) {
        piVar6 = puVar3 + 1;
        *piVar6 = *piVar6 + -1;
        if (*piVar6 == 0) {
          (**(code **)*puVar3)(1);
        }
      }
      (**(code **)(*piVar8 + 0x58))(local_13c);
      *(undefined4 *)(local_13c[0x1d] + 0x24) = 0;
      iVar5 = local_13c[0x1d];
      local_144 = (undefined4 *)0x1;
      FUN_008438c0(&local_144);
      if (iStack_128 == *(int *)(iVar5 + 0x174)) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)(iStack_128 + 0x10);
      }
      *(undefined4 *)(iVar5 + 0x24) = 0;
      *(int **)(local_12c[0x50] + local_134 * 4) = piVar8;
      local_134 = local_134 + 1;
      param_1 = local_12c;
    } while (local_134 < (uint)(local_12c[0x51] - local_12c[0x50] >> 2));
  }
  piVar8 = *(int **)*param_1;
  if (piVar8 != (int *)*param_1) {
    do {
      FUN_007be770(piVar8[2]);
      piVar8 = (int *)*piVar8;
    } while (piVar8 != (int *)*param_1);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_144);
  return;
}

