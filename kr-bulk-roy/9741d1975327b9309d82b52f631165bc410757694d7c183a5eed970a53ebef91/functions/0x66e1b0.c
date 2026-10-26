
void FUN_0066e1b0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  FILE *pFVar3;
  int iVar4;
  undefined4 *puVar5;
  int in_ECX;
  
  iVar4 = *(int *)(param_1 + 0x10);
  if (iVar4 == 0x3ea) {
    if ((*(int *)(param_1 + 8) != *(int *)(*(int *)(in_ECX + 0xf0) + 0x20)) &&
       (*(int *)(param_1 + 8) != *(int *)(*(int *)(in_ECX + 0xf4) + 0x20))) {
      return;
    }
    FUN_0066de20();
    iVar4 = *(int *)(in_ECX + 0x24);
    *(undefined4 *)(iVar4 + 0x13dc) = 0;
    *(undefined1 *)(iVar4 + 0x13d9) = 1;
    return;
  }
  if (iVar4 == 0x3eb) {
    iVar4 = *(int *)(in_ECX + 0xf0);
    iVar1 = *(int *)(in_ECX + 0xf4);
    if (*(int *)(param_1 + 8) == *(int *)(iVar4 + 0x20)) {
      iVar4 = *(int *)(in_ECX + 0x24);
      *(undefined1 *)(iVar4 + 0x13d9) = 1;
      *(int *)(iVar4 + 0x13dc) = iVar1;
      return;
    }
    if (*(int *)(param_1 + 8) != *(int *)(iVar1 + 0x20)) {
      return;
    }
    iVar1 = *(int *)(in_ECX + 0x24);
    *(undefined1 *)(iVar1 + 0x13d9) = 1;
    *(int *)(iVar1 + 0x13dc) = iVar4;
    return;
  }
  if (iVar4 != 0x578) {
    return;
  }
  iVar4 = *(int *)(param_1 + 8);
  if (iVar4 == *(int *)(*(int *)(in_ECX + 0xf8) + 0x20)) {
    if ((*(uint *)(*(int *)(in_ECX + 0x104) + 0x28) >> 9 & 1) == 0) {
      FUN_0066ddd0();
      DeleteFileA("save.data");
    }
    else {
      uVar2 = FUN_00761500();
      FUN_0066ddd0();
      FUN_004026e0(uVar2,0,0xffffffff);
      pFVar3 = _fopen("save.data","wbc");
      if (pFVar3 != (FILE *)0x0) {
        FUN_0047a5a0(pFVar3);
        FUN_0066de20();
        return;
      }
    }
    FUN_0066de20();
    return;
  }
  if (iVar4 == *(int *)(*(int *)(in_ECX + 0x104) + 0x20)) {
    return;
  }
  if (iVar4 == *(int *)(*(int *)(in_ECX + 0x108) + 0x20)) {
    iVar4 = FUN_00404ba0();
    *(undefined4 *)(iVar4 + 0x68c8) = 1;
  }
  else {
    if (iVar4 != *(int *)(*(int *)(in_ECX + 0x10c) + 0x20)) {
      if (iVar4 == *(int *)(*(int *)(in_ECX + 0xfc) + 0x20)) {
        puVar5 = (undefined4 *)FUN_00891268(0x14);
        if (puVar5 != (undefined4 *)0x0) {
          *puVar5 = FoxUI::FXUIEvent::vftable;
          puVar5[1] = 0xffffffff;
          puVar5[2] = 0xffffffff;
          puVar5[3] = 0;
          puVar5[4] = 0xf4338;
          FUN_004072a0();
          return;
        }
      }
      else {
        if (iVar4 != *(int *)(*(int *)(in_ECX + 0x100) + 0x20)) {
          return;
        }
        puVar5 = (undefined4 *)FUN_00891268(0x14);
        if (puVar5 != (undefined4 *)0x0) {
          *puVar5 = FoxUI::FXUIEvent::vftable;
          puVar5[1] = 0xffffffff;
          puVar5[2] = 0xffffffff;
          puVar5[3] = 0;
          puVar5[4] = 0xf4339;
          FUN_004072a0();
          return;
        }
      }
      goto LAB_0066e36c;
    }
    iVar4 = FUN_00404ba0();
    *(undefined4 *)(iVar4 + 0x68c8) = 2;
  }
  puVar5 = (undefined4 *)FUN_00891268(0x18);
  if (puVar5 != (undefined4 *)0x0) {
    puVar5[1] = 0xffffffff;
    puVar5[2] = 0xffffffff;
    puVar5[3] = 0;
    puVar5[4] = 0xf4332;
    *puVar5 = FoxUI::FXUIEventB1::vftable;
    *(undefined1 *)(puVar5 + 5) = 1;
    FUN_004072a0();
    return;
  }
LAB_0066e36c:
  FUN_004072a0();
  return;
}

