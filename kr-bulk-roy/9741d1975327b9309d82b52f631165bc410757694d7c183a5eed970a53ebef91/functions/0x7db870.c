
void FUN_007db870(int *param_1,int *param_2)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  uint uStack_6c;
  
  uVar9 = 0;
  if ((param_1 != (int *)0x0) && (param_2 != (int *)0x0)) {
    iVar2 = (**(code **)(*param_1 + 4))();
    if (*(int *)(iVar2 + 4) == -0x5eed0000) {
      if ((param_2[0x37] - param_2[0x36] & 0xfffffffcU) != 0) {
        piVar4 = (int *)FUN_0077f090();
        iVar2 = (**(code **)(*piVar4 + 4))();
        if (*(int *)(iVar2 + 4) == -0x5ed90000) {
          piVar4 = param_2 + 2;
          if (0xf < (uint)param_2[7]) {
            piVar4 = (int *)*piVar4;
          }
          iVar2 = __stricmp((char *)piVar4,"Dummy_head");
          if (iVar2 == 0) {
            return;
          }
          FUN_00780150(param_1,0);
          FUN_0077ef30();
          FUN_0077ea00();
          pcVar1 = *(code **)(*param_2 + 0x34);
          param_2[0x30] = 0;
          uVar9 = (*pcVar1)();
          uVar3 = (**(code **)(*param_1 + 0x34))();
          if (uVar9 != uVar3) {
            return;
          }
          uStack_6c = 0;
          if (uVar9 == 0) {
            return;
          }
          do {
            piVar4 = (int *)(**(code **)(*param_1 + 0x30))(uStack_6c);
            iVar2 = (**(code **)(*piVar4 + 4))();
            if ((*(int *)(iVar2 + 4) == -0x5eed0000) &&
               (iVar2 = (**(code **)(*param_2 + 0x30))(uStack_6c),
               (*(int *)(iVar2 + 0xdc) - *(int *)(iVar2 + 0xd8) & 0xfffffffcU) != 0)) {
              piVar4 = (int *)FUN_0077f090();
              iVar5 = (**(code **)(*piVar4 + 4))();
              if (*(int *)(iVar5 + 4) == -0x5edf0000) {
                uVar6 = (**(code **)(*param_1 + 0x30))(uStack_6c);
                FUN_007db870(uVar6,iVar2);
              }
            }
            uStack_6c = uStack_6c + 1;
          } while (uStack_6c < uVar9);
          return;
        }
      }
      FUN_00780150(param_1,0);
      FUN_0077ef30();
      FUN_0077ea00();
      param_2[0x30] = 0;
      uVar3 = param_1[0x37] - param_1[0x36] >> 2;
      if (uVar3 != 0) {
        do {
          if (uVar9 < (uint)(param_2[0x37] - param_2[0x36] >> 2)) {
            uVar6 = *(undefined4 *)(param_2[0x36] + uVar9 * 4);
          }
          else {
            uVar6 = 0;
          }
          if (uVar9 < (uint)(param_1[0x37] - param_1[0x36] >> 2)) {
            uVar7 = *(undefined4 *)(param_1[0x36] + uVar9 * 4);
          }
          else {
            uVar7 = 0;
          }
          FUN_007db870(uVar7,uVar6);
          uVar9 = uVar9 + 1;
        } while (uVar9 < uVar3);
      }
      uVar9 = (**(code **)(*param_1 + 0x34))();
      uVar3 = 0;
      if (uVar9 != 0) {
        do {
          uVar8 = uVar3;
          uVar6 = (**(code **)(*param_2 + 0x30))(uVar3);
          uVar6 = (**(code **)(*param_1 + 0x30))(uVar3,uVar6);
          FUN_007db870(uVar6,uVar8);
          uVar3 = uVar3 + 1;
        } while (uVar3 < uVar9);
      }
    }
    else if (*(int *)(iVar2 + 4) == -0x5edf0000) {
      (**(code **)(*param_1 + 0x1c))(0);
      FUN_00780150(param_1,param_1[0xc]);
      FUN_008606c0();
      uVar3 = param_2[0x23] - param_2[0x22] >> 2;
      uVar8 = param_1[0x23] - param_1[0x22] >> 2;
      if (uVar8 <= uVar3) {
        uVar3 = uVar8;
      }
      if (uVar3 != 0) {
        do {
          FUN_007db870(*(undefined4 *)(param_1[0x22] + uVar9 * 4),
                       *(undefined4 *)(param_2[0x22] + uVar9 * 4));
          uVar9 = uVar9 + 1;
        } while (uVar9 < uVar3);
        return;
      }
    }
  }
  return;
}

