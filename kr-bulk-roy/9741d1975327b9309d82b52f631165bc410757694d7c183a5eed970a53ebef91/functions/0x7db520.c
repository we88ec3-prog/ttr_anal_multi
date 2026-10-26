
void FUN_007db520(int *param_1,int *param_2,undefined4 param_3)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  uint uStack_44;
  uint uStack_40;
  
  if (param_1 == (int *)0x0) {
    return;
  }
  if (param_2 == (int *)0x0) {
    return;
  }
  iVar2 = (**(code **)(*param_1 + 4))();
  if (*(int *)(iVar2 + 4) != -0x5eed0000) {
    if (*(int *)(iVar2 + 4) != -0x5edf0000) {
      return;
    }
    (**(code **)(*param_1 + 0x1c))(param_3);
    FUN_00780150(param_1,param_1[0xc]);
    FUN_008606c0();
    uVar8 = param_1[0xf];
    uStack_44 = 0;
    if (uVar8 != 0) {
      do {
        uVar3 = FUN_007800e0(param_3);
        (**(code **)(*param_2 + 0x20))(uVar3);
        uStack_44 = uStack_44 + 1;
      } while (uStack_44 < uVar8);
    }
    uStack_44 = param_2[0x23] - param_2[0x22] >> 2;
    uVar8 = param_1[0x23] - param_1[0x22] >> 2;
    if (uVar8 <= uStack_44) {
      uStack_44 = uVar8;
    }
    uVar8 = 0;
    if (uStack_44 == 0) {
      return;
    }
    do {
      FUN_007db520(*(undefined4 *)(param_1[0x22] + uVar8 * 4),
                   *(undefined4 *)(param_2[0x22] + uVar8 * 4),param_3);
      uVar8 = uVar8 + 1;
    } while (uVar8 < uStack_44);
    return;
  }
  uVar8 = param_1[0xf];
  uStack_40 = 0;
  if (uVar8 != 0) {
    do {
      uVar3 = FUN_007800e0(param_3);
      (**(code **)(*param_2 + 0x20))(uVar3);
      uStack_40 = uStack_40 + 1;
    } while (uStack_40 < uVar8);
    if (uVar8 != 0) goto LAB_007db7b6;
  }
  if ((param_2[0x37] - param_2[0x36] & 0xfffffffcU) != 0) {
    if (param_2[0x37] - param_2[0x36] >> 2 == 0) {
      piVar5 = (int *)0x0;
    }
    else {
      piVar5 = *(int **)param_2[0x36];
    }
    iVar2 = (**(code **)(*piVar5 + 4))();
    if (*(int *)(iVar2 + 4) == -0x5ed90000) {
      piVar5 = param_2 + 2;
      if (0xf < (uint)param_2[7]) {
        piVar5 = (int *)*piVar5;
      }
      iVar2 = __stricmp((char *)piVar5,"Dummy_head");
      if (iVar2 == 0) {
        return;
      }
      FUN_00780150(param_1,param_3);
      FUN_0077ef30();
      FUN_0077ea00();
      pcVar1 = *(code **)(*param_2 + 0x34);
      param_2[0x30] = 0;
      uVar8 = (*pcVar1)();
      uVar4 = (**(code **)(*param_1 + 0x34))();
      if (uVar8 != uVar4) {
        return;
      }
      uStack_40 = 0;
      if (uVar8 == 0) {
        return;
      }
      do {
        piVar5 = (int *)(**(code **)(*param_1 + 0x30))(uStack_40);
        iVar2 = (**(code **)(*piVar5 + 4))();
        if ((*(int *)(iVar2 + 4) == -0x5eed0000) &&
           (iVar2 = (**(code **)(*param_2 + 0x30))(uStack_40),
           (*(int *)(iVar2 + 0xdc) - *(int *)(iVar2 + 0xd8) & 0xfffffffcU) != 0)) {
          piVar5 = (int *)FUN_0077f090();
          iVar6 = (**(code **)(*piVar5 + 4))();
          if (*(int *)(iVar6 + 4) == -0x5edf0000) {
            uVar3 = (**(code **)(*param_1 + 0x30))(uStack_40);
            FUN_007db520(uVar3,iVar2,param_3);
          }
        }
        uStack_40 = uStack_40 + 1;
      } while (uStack_40 < uVar8);
      return;
    }
  }
LAB_007db7b6:
  uVar4 = 0;
  uVar8 = param_1[0x37] - param_1[0x36] >> 2;
  if (uVar8 != 0) {
    do {
      if (uVar4 < (uint)(param_2[0x37] - param_2[0x36] >> 2)) {
        uVar3 = *(undefined4 *)(param_2[0x36] + uVar4 * 4);
      }
      else {
        uVar3 = 0;
      }
      if (uVar4 < (uint)(param_1[0x37] - param_1[0x36] >> 2)) {
        uVar7 = *(undefined4 *)(param_1[0x36] + uVar4 * 4);
      }
      else {
        uVar7 = 0;
      }
      FUN_007db520(uVar7,uVar3,param_3);
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar8);
  }
  uVar8 = (**(code **)(*param_1 + 0x34))();
  uVar4 = 0;
  if (uVar8 != 0) {
    do {
      uVar9 = uVar4;
      uVar3 = param_3;
      uVar7 = (**(code **)(*param_2 + 0x30))(uVar4,param_3);
      uVar7 = (**(code **)(*param_1 + 0x30))(uVar4,uVar7);
      FUN_007db520(uVar7,uVar9,uVar3);
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar8);
  }
  return;
}

