
void FUN_00761c70(int *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  cVar1 = (**(code **)(*param_1 + 0x1b0))();
  if (cVar1 == '\0') {
    uVar4 = param_1[0x53];
    if ((uint)param_1[0x46] <= uVar4) {
LAB_00761d3b:
      FUN_007619a0();
      param_1[0x58] = param_1[0x53];
      param_1[0x59] = param_1[0x53];
      FUN_00761800();
      return;
    }
    FUN_00671e60();
    if (uVar4 <= (uint)param_1[0x46]) {
      if ((int)uVar4 < 0) {
        uVar4 = 0;
      }
      iVar2 = FUN_00776f20(param_1 + 0x42,uVar4);
      if (-1 < iVar2) {
        if (*(char *)((int)param_1 + 0x141) == '\0') {
          FUN_00757e40(iVar2,param_1[0x53]);
        }
        else {
          FUN_00757e40(iVar2,param_1[0x53]);
          FUN_006ee170(param_1[0x53]);
        }
        puVar3 = (undefined4 *)FUN_00891268(0x14);
        if (puVar3 != (undefined4 *)0x0) {
          *puVar3 = FoxUI::FXUIEvent::vftable;
          puVar3[1] = 0xffffffff;
          puVar3[2] = 0xffffffff;
          puVar3[3] = 0;
          puVar3[4] = 0x3ec;
        }
        FUN_00748900();
        goto LAB_00761d3b;
      }
    }
  }
  else {
    puVar3 = (undefined4 *)FUN_00891268(0x14);
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = FoxUI::FXUIEvent::vftable;
      puVar3[1] = 0xffffffff;
      puVar3[2] = 0xffffffff;
      puVar3[3] = 0;
      puVar3[4] = 0x3ec;
    }
    FUN_00748900();
    FUN_00761800();
  }
  return;
}

