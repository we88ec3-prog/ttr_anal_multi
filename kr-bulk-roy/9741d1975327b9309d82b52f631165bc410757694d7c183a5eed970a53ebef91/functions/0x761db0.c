
void FUN_00761db0(int *param_1)

{
  int iVar1;
  int iVar2;
  char cVar3;
  undefined4 *puVar4;
  
  cVar3 = (**(code **)(*param_1 + 0x1b0))();
  if (cVar3 == '\0') {
    iVar2 = param_1[0x53];
    if (0 < iVar2) {
      iVar1 = iVar2 + -1;
      if (*(char *)((int)param_1 + 0x141) == '\0') {
        FUN_00757e40(iVar2 - iVar1,iVar1);
      }
      else {
        FUN_006ee170(iVar1);
        FUN_00757e40(param_1[0x53] - iVar1,iVar1);
      }
      param_1[0x53] = iVar1;
      if (iVar1 < param_1[0x5a]) {
        param_1[0x5a] = iVar1;
      }
      puVar4 = (undefined4 *)FUN_00891268(0x14);
      if (puVar4 != (undefined4 *)0x0) {
        *puVar4 = FoxUI::FXUIEvent::vftable;
        puVar4[1] = 0xffffffff;
        puVar4[2] = 0xffffffff;
        puVar4[3] = 0;
        puVar4[4] = 0x3ec;
      }
      FUN_00748900();
    }
    param_1[0x58] = param_1[0x53];
    param_1[0x59] = param_1[0x53];
    FUN_00761800();
    return;
  }
  puVar4 = (undefined4 *)FUN_00891268(0x14);
  if (puVar4 == (undefined4 *)0x0) {
    FUN_00748900();
    FUN_00761800();
    return;
  }
  *puVar4 = FoxUI::FXUIEvent::vftable;
  puVar4[1] = 0xffffffff;
  puVar4[2] = 0xffffffff;
  puVar4[3] = 0;
  puVar4[4] = 0x3ec;
  FUN_00748900();
  FUN_00761800();
  return;
}

